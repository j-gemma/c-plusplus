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
#define szRDS _RXST("SFE")

//-----------------------------------------------------------------------------
//----- ObjectARX EntryPoint
class CImportULOADApp : public AcRxArxApp {

public:
	CImportULOADApp () : AcRxArxApp () {}

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
	
	// The ACED_ARXCOMMAND_ENTRY_AUTO macro can be applied to any static member 
	// function of the CImportULOADApp class.
	// The function should take no arguments and return nothing.
	//
	// NOTE: ACED_ARXCOMMAND_ENTRY_AUTO has overloads where you can provide resourceid and
	// have arguments to define context and command mechanism.
	
	// ACED_ARXCOMMAND_ENTRY_AUTO(classname, group, globCmd, locCmd, cmdFlags, UIContext)
	// ACED_ARXCOMMAND_ENTRYBYID_AUTO(classname, group, globCmd, locCmdId, cmdFlags, UIContext)
	// only differs that it creates a localized name using a string in the resource file
	//   locCmdId - resource ID for localized command

	// Modal Command with localized name
	// ACED_ARXCOMMAND_ENTRY_AUTO(CImportULOADApp, SFEMyGroup, MyCommand, MyCommandLocal, ACRX_CMD_MODAL)
	static void SFEMyGroupMyCommand () {
		// Put your command code here

	}

	// Modal Command with pickfirst selection
	// ACED_ARXCOMMAND_ENTRY_AUTO(CImportULOADApp, SFEMyGroup, MyPickFirst, MyPickFirstLocal, ACRX_CMD_MODAL | ACRX_CMD_USEPICKSET)
	static void SFEMyGroupMyPickFirst () {
		ads_name result ;
		int iRet =acedSSGet (ACRX_T("_I"), NULL, NULL, NULL, result) ;
		if ( iRet == RTNORM )
		{
			// There are selected entities
			// Put your command using pickfirst set code here
		}
		else
		{
			// There are no selected entities
			// Put your command code here
		}
	}

	// Application Session Command with localized name
	// ACED_ARXCOMMAND_ENTRY_AUTO(CImportULOADApp, SFEMyGroup, MySessionCmd, MySessionCmdLocal, ACRX_CMD_MODAL | ACRX_CMD_SESSION)
	static void SFEMyGroupMySessionCmd () {
		// Put your command code here
	}

	// The ACED_ADSFUNCTION_ENTRY_AUTO / ACED_ADSCOMMAND_ENTRY_AUTO macros can be applied to any static member 
	// function of the CImportULOADApp class.
	// The function may or may not take arguments and have to return RTNORM, RTERROR, RTCAN, RTFAIL, RTREJ to AutoCAD, but use
	// acedRetNil, acedRetT, acedRetVoid, acedRetInt, acedRetReal, acedRetStr, acedRetPoint, acedRetName, acedRetList, acedRetVal to return
	// a value to the Lisp interpreter.
	//
	// NOTE: ACED_ADSFUNCTION_ENTRY_AUTO / ACED_ADSCOMMAND_ENTRY_AUTO has overloads where you can provide resourceid.
	
	//- ACED_ADSFUNCTION_ENTRY_AUTO(classname, name, regFunc) - this example
	//- ACED_ADSSYMBOL_ENTRYBYID_AUTO(classname, name, nameId, regFunc) - only differs that it creates a localized name using a string in the resource file
	//- ACED_ADSCOMMAND_ENTRY_AUTO(classname, name, regFunc) - a Lisp command (prefix C:)
	//- ACED_ADSCOMMAND_ENTRYBYID_AUTO(classname, name, nameId, regFunc) - only differs that it creates a localized name using a string in the resource file

	// Lisp Function is similar to ARX Command but it creates a lisp 
	// callable function. Many return types are supported not just string
	// or integer.
	// ACED_ADSFUNCTION_ENTRY_AUTO(CImportULOADApp, MyLispFunction, false)
	static int ads_MyLispFunction () {
		//struct resbuf *args =acedGetArgs () ;
		
		// Put your command code here

		//acutRelRb (args) ;
		
		// Return a value to the AutoCAD Lisp Interpreter
		// acedRetNil, acedRetT, acedRetVoid, acedRetInt, acedRetReal, acedRetStr, acedRetPoint, acedRetName, acedRetList, acedRetVal

		return (RTNORM) ;
	}

	static void SFETest_BLOCK_WITH_INSERT(void)
	{

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
IMPLEMENT_ARX_ENTRYPOINT(CImportULOADApp)

ACED_ARXCOMMAND_ENTRY_AUTO(CImportULOADApp, SFEMyGroup, MyCommand, MyCommandLocal, ACRX_CMD_MODAL, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CImportULOADApp, SFEMyGroup, MyPickFirst, MyPickFirstLocal, ACRX_CMD_MODAL | ACRX_CMD_USEPICKSET, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CImportULOADApp, SFEMyGroup, MySessionCmd, MySessionCmdLocal, ACRX_CMD_MODAL | ACRX_CMD_SESSION, NULL)
ACED_ADSSYMBOL_ENTRY_AUTO(CImportULOADApp, MyLispFunction, false)

