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
class CArxProject2App : public AcRxArxApp {

public:
	CArxProject2App () : AcRxArxApp () {}

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
	
	static void SFETest_TEST_DRAW_LINE(void)
	{

		// Prompt for user input for start point
		ads_point startPtInput;
		if (acedGetPoint(NULL, L"\nEnter start point: ", startPtInput) != RTNORM) {
			acutPrintf(L"\nError getting start point.");
			return;
		}
		AcGePoint3d startPt(startPtInput[0], startPtInput[1], startPtInput[2]); // Convert ads_point to AcGePoint3d

		// Prompt for user input for endpoint
		ads_point endPtInput;
		if (acedGetPoint(NULL, L"\nEnter endpoint: ", endPtInput) != RTNORM) {
			acutPrintf(L"\nError getting endpoint.");
			return;
		}
		AcGePoint3d endPt(endPtInput[0], endPtInput[1], endPtInput[2]); // Convert ads_point to AcGePoint3d

		// Make new line object, use points
		AcDbLine* pLine = new AcDbLine(startPt, endPt);

		// Declare pointer to BlockTable
		AcDbBlockTable* pBlockTable;

		// Get the pBlockTable, assign its address(?) to the declared pointer

		// Open block table for reading
		acdbHostApplicationServices()->workingDatabase()
			->getSymbolTable(pBlockTable, AcDb::kForRead);

		AcDbBlockTableRecord* pBlockTableRecord;
		pBlockTable->getAt(ACDB_MODEL_SPACE, pBlockTableRecord,
			AcDb::kForWrite);

		pBlockTable->close();

		AcDbObjectId lineId;
		pBlockTableRecord->appendAcDbEntity(lineId, pLine);
		pBlockTableRecord->close();
		pLine->close();
	}


	static void SFETest_TEST_DRAW_CIRCLE(void)
	{
		AcGePoint3d center(1.0, 1.0, 0.0);
		AcGeVector3d normal(0.0, 1.0, 0.0);
		double radius = 10.0;
		
		AcDbCircle* pCirc = new AcDbCircle(center, normal, radius);

		AcDbBlockTable* pBlockTable;
		acdbHostApplicationServices()->workingDatabase()
			->getSymbolTable(pBlockTable, AcDb::kForRead);
		AcDbBlockTableRecord* pBlockTableRecord;
		pBlockTable->getAt(ACDB_MODEL_SPACE, pBlockTableRecord,
			AcDb::kForWrite);
		pBlockTable->close();
		AcDbObjectId circleId;
		pBlockTableRecord->appendAcDbEntity(circleId, pCirc);
		pBlockTableRecord->close();
		pCirc->close();;
	}

	static void SFETest_TEST_NEW_LAYER(void)
	{
		AcDbLayerTable* pLayerTable;
		acdbHostApplicationServices()->workingDatabase()
			->getSymbolTable(pLayerTable, AcDb::kForWrite);
		AcDbLayerTableRecord* pLayerTableRecord =
			new AcDbLayerTableRecord;
		pLayerTableRecord->setName(L"ASDK_MYLAYER");
		// Defaults are used for other properties of 
		// the layer if they are not otherwise specified.
		//
		pLayerTable->add(pLayerTableRecord);
		pLayerTable->close();
		pLayerTableRecord->close();
	}


	static void SFETest_TEST_CREATE_BLOCK()
	{
		// Create and name a new block table record.
		//
		AcDbBlockTableRecord* pBlockTableRec
			= new AcDbBlockTableRecord();
		pBlockTableRec->setName(L"ASDK-NO-ATTR");
		// Get the block table.
		//
		AcDbBlockTable* pBlockTable = NULL;
		acdbHostApplicationServices()->workingDatabase()
			->getSymbolTable(pBlockTable, AcDb::kForWrite);
		// Add the new block table record to the block table.
		//
		AcDbObjectId blockTableRecordId;
		pBlockTable->add(blockTableRecordId, pBlockTableRec);
		pBlockTable->close();
		// Create and add a line entity to the component's
		// block record.
		//
		AcDbLine* pLine = new AcDbLine();
		AcDbObjectId lineId;
		pLine->setStartPoint(AcGePoint3d(0, 0, 0));
		pLine->setEndPoint(AcGePoint3d(90, 90, 0));
		pLine->setColorIndex(3);
		pBlockTableRec->appendAcDbEntity(lineId, pLine);
		pLine->close();
		pBlockTableRec->close();
	}


	static void SFETest_TEST_CREATE_TABLE_BLOCK()
	{
		// Create and name a new block table record.
		//
		AcDbBlockTableRecord* pBlockTableRec
			= new AcDbBlockTableRecord();
		pBlockTableRec->setName(L"ULOAD CUSTOM");
		// Get the block table.
		//
		AcDbBlockTable* pBlockTable = NULL;
		acdbHostApplicationServices()->workingDatabase()
			->getSymbolTable(pBlockTable, AcDb::kForWrite);
		// Add the new block table record to the block table.
		//
		AcDbObjectId blockTableRecordId;
		pBlockTable->add(blockTableRecordId, pBlockTableRec);
		pBlockTable->close();
		// Create and add a line entity to the component's
		// block record.
		//
		AcDbTable* pTable = new AcDbTable();
		AcDbObjectId tableId;
		pBlockTableRec->appendAcDbEntity(tableId, pTable);
		pTable->close();
		pBlockTableRec->close();
	}


	


} ;

//-----------------------------------------------------------------------------
IMPLEMENT_ARX_ENTRYPOINT(CArxProject2App);

ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, SFETest, _TEST_DRAW_LINE, TEST_DRAW_LINE, ACRX_CMD_MODAL, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, SFETest, _TEST_DRAW_CIRCLE, TEST_DRAW_CIRCLE, ACRX_CMD_MODAL, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, SFETest, _TEST_NEW_LAYER, TEST_NEW_LAYER, ACRX_CMD_MODAL, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, SFETest, _TEST_CREATE_BLOCK, TEST_CREATE_BLOCK, ACRX_CMD_MODAL, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, SFETest, _TEST_CREATE_TABLE_BLOCK, TEST_CREATE_TABLE_BLOCK, ACRX_CMD_MODAL, NULL)