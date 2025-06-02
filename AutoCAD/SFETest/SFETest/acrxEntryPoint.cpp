// (C) Copyright 2002-2012 by Autodesk, Inc. 
//
// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted, 
// provided that the above copyright notice appears in all copies and 
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting 
// documentation.
//
// AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS. 
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE.  AUTODESK, INC. 
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//
// Use, duplication, or disclosure by the U.S. Government is subject to 
// restrictions set forth in FAR 52.227-19 (Commercial Computer
// Software - Restricted Rights) and DFAR 252.227-7013(c)(1)(ii)
// (Rights in Technical Data and Computer Software), as applicable.
//

//-----------------------------------------------------------------------------
//----- acrxEntryPoint.cpp
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "resource.h"

//-----------------------------------------------------------------------------
#define szRDS _RXST("")

//-----------------------------------------------------------------------------
//----- ObjectARX EntryPoint
class CSFETestApp : public AcRxArxApp {

public:
	CSFETestApp () : AcRxArxApp () {}

	virtual AcRx::AppRetCode On_kInitAppMsg (void *pkt) {
		// TODO: Load dependencies here

		// You *must* call On_kInitAppMsg here
		AcRx::AppRetCode retCode =AcRxArxApp::On_kInitAppMsg (pkt) ;
		
		// TODO: Add your initialization code here

		return (retCode) ;
	}

	virtual AcRx::AppRetCode On_kUnloadAppMsg (void *pkt) {
		// TODO: Add your code here

		// You *must* call On_kUnloadAppMsg here
		AcRx::AppRetCode retCode =AcRxArxApp::On_kUnloadAppMsg (pkt) ;

		// TODO: Unload dependencies here

		return (retCode) ;
	}

	virtual void RegisterServerComponents () {
	}

    static void SFETest_BLOCK_WITH_INSERT(void)
    {

	acutPrintf(L"\nError adding text to block table record.");

       
        // Create and name a new block table record
        AcDbBlockTableRecord* pBlockTableRec = new AcDbBlockTableRecord();
        pBlockTableRec->setName(L"TABLE_BLOCK");

        // Get the block table
        AcDbBlockTable* pBlockTable;
        if (acdbHostApplicationServices()->workingDatabase()->getSymbolTable(pBlockTable, AcDb::kForWrite) != Acad::eOk) {
            acutPrintf(L"\nError accessing block table.");
            delete pBlockTableRec;
            return;
        }
        else {
            acutPrintf(L"\nAccessed block table.");
        }

        // Add the new block table record to the block table
        AcDbObjectId blockTableRecordId;
        if (pBlockTable->add(blockTableRecordId, pBlockTableRec) != Acad::eOk) {
            acutPrintf(L"\nError adding block table record.");
            pBlockTable->close();
            delete pBlockTableRec;
            return;
        }
        pBlockTable->close();

        AcDbText* pText = new AcDbText();;
        pText->setTextString(L"HEY!");
        AcDbObjectId tableId;
        if (pBlockTableRec->appendAcDbEntity(tableId, pText) != Acad::eOk) {
            acutPrintf(L"\nError adding text to block table record.");
            pBlockTableRec->close();
            delete pText;
            return;
        }
        pText->close();



        // Create and add a table entity to the block table record
        AcDbTable* pTable = new AcDbTable();
        pTable->setSize(3, 3); // Example: 3 rows, 3 columns
        pTable->setPosition(AcGePoint3d(0.0, 0.0, 0.0));
        pTable->setRowHeight(1.0);
        pTable->setColumnWidth(3.0);
        pTable->setTextString(0, 0, L"Header");
        
        if (pBlockTableRec->appendAcDbEntity(tableId, pTable) != Acad::eOk) {
            acutPrintf(L"\nError adding table to block table record.");
            pBlockTableRec->close();
            delete pTable;
            return;
        }
        pTable->close();

        pBlockTableRec->close();
  
        // Prompt for the insertion point
        ads_point insertPointInput;
        if (acedGetPoint(NULL, L"\nEnter insertion point: ", insertPointInput) != RTNORM) {
            acutPrintf(L"\nError getting insertion point.");
            return;
        }
        AcGePoint3d insertPoint(insertPointInput[0], insertPointInput[1], insertPointInput[2]);

        // Open block table for reading
        acdbHostApplicationServices()->workingDatabase()
            ->getSymbolTable(pBlockTable, AcDb::kForRead);

        AcDbBlockTableRecord* pBlockTableRecord;
        pBlockTable->getAt(ACDB_MODEL_SPACE, pBlockTableRecord,
            AcDb::kForWrite);

        pBlockTable->close();

        // Insert the block into the model space
        AcDbBlockReference* pBlockRef = new AcDbBlockReference(insertPoint, blockTableRecordId);

        // Append the block reference to model space
        AcDbObjectId blockRefId;
        if (pBlockTableRecord->appendAcDbEntity(blockRefId, pBlockRef) != Acad::eOk) {
            acutPrintf(L"\nError inserting block reference into model space.");
            pBlockTableRecord->close();
            delete pBlockRef;
            return;
        }

        // Cleanup
        pBlockRef->close();
        pBlockTableRecord->close();

        acutPrintf(L"\nBlock with table created and inserted successfully.");
    }
} ;

//-----------------------------------------------------------------------------
IMPLEMENT_ARX_ENTRYPOINT(CSFETestApp)

ACED_ARXCOMMAND_ENTRY_AUTO(CSFETestApp, SFETest, _BLOCK_WITH_INSERT, BLOCK_WITH_INSERT, ACRX_CMD_MODAL, NULL)


