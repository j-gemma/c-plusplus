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

#include "tchar.h"

//-----------------------------------------------------------------------------
#define szRDS _RXST("SFE")

//-----------------------------------------------------------------------------
//----- ObjectARX EntryPoint
class CDataLinkApp : public AcRxArxApp {

public:
	CDataLinkApp () : AcRxArxApp () {}

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
	// function of the CDataLinkApp class.
	// The function should take no arguments and return nothing.
	//
	// NOTE: ACED_ARXCOMMAND_ENTRY_AUTO has overloads where you can provide resourceid and
	// have arguments to define context and command mechanism.
	
	// ACED_ARXCOMMAND_ENTRY_AUTO(classname, group, globCmd, locCmd, cmdFlags, UIContext)
	// ACED_ARXCOMMAND_ENTRYBYID_AUTO(classname, group, globCmd, locCmdId, cmdFlags, UIContext)
	// only differs that it creates a localized name using a string in the resource file
	//   locCmdId - resource ID for localized command

	// Modal Command with localized name
	// ACED_ARXCOMMAND_ENTRY_AUTO(CDataLinkApp, SFEMyGroup, MyCommand, MyCommandLocal, ACRX_CMD_MODAL)
	static void SFEMyGroupMyCommand () {
		// Put your command code here

	}

	// Modal Command with pickfirst selection
	// ACED_ARXCOMMAND_ENTRY_AUTO(CDataLinkApp, SFEMyGroup, MyPickFirst, MyPickFirstLocal, ACRX_CMD_MODAL | ACRX_CMD_USEPICKSET)
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

	static AcDbTable* selectTableByRange(
		const ACHAR* prompt,
		AcDbObjectId& tblId,
		AcDb::OpenMode openMode
	) {
		ads_name ss;
		ads_point pt1, pt2;

		acutPrintf(prompt);

		// First corner
		if (acedGetPoint(NULL, ACRX_T("\nFirst corner: "), pt1) != RTNORM)
			return nullptr;

		// Second corner
		if (acedGetCorner(pt1, ACRX_T("\nSecond corner: "), pt2) != RTNORM)
			return nullptr;

		//crossing selection
		if (acedSSGet(ACRX_T("C"), pt1, pt2, NULL, ss) != RTNORM) {
			acutPrintf(ACRX_T("Error returning selection set"));
			return nullptr;
		}

		ads_name ent;
		if (acedSSName(ss, 0, ent) != RTNORM)
		{
			acedSSFree(ss);
			return nullptr;
		}

		acedSSFree(ss);

		if (acdbGetObjectId(tblId, ent) != Acad::eOk)
			return nullptr;

		AcDbEntity* pEnt = nullptr;
		if (acdbOpenObject(pEnt, tblId, openMode) != Acad::eOk)
			return nullptr;

		AcDbTable* pTbl = AcDbTable::cast(pEnt);
		if (!pTbl)
		{
			pEnt->close();
			return nullptr;
		}

		return pTbl;

	}

static	AcDbEntity* selectEntity(const ACHAR* prompt, AcDbObjectId& eId, AcDb::OpenMode openMode)
{

		ads_name en;
		ads_point pt;

		if (acedEntSel(prompt, en, pt) != RTNORM)
			return nullptr;

		if (acdbGetObjectId(eId, en) != Acad::eOk)
			return nullptr;

		AcDbEntity* pEnt = nullptr;
		if (acdbOpenObject(pEnt, eId, openMode) != Acad::eOk)
			return nullptr;

		return pEnt;
}


static void SFEMyGroup_DATALINK2()
{
	AcDbObjectId tblId;

	// Select a table
	//AcDbTable *pTbl = NULL;
	//if(NULL == (pTbl =
	//AcDbTable::cast(selectEntity(_T("\nSelect a table: "), tblId, kForWrite)))) 
	//{
	//	acutPrintf(ACRX_T("\nSelected entity was not a table!"));
	//	return;
	//}

	AcDbTable* pTbl = selectTableByRange(
		ACRX_T("\nSelect a table"),
		tblId,
		AcDb::kForWrite
	);

	if (!pTbl) {
		acutPrintf(ACRX_T("\nError: no table found in selection."));
		return;
	}

	// Get an Excel file
	//
	struct resbuf *result; 
	int rc; 
	if ( (result = acutNewRb(RTSTR)) == NULL)
	{
		pTbl->close();
		acutPrintf(ACRX_T("\nUnable to allocate buffer!")); 
		return;
	}
	result->resval.rstring=NULL; 
	rc = acedGetFileD(ACRX_T("Excel File"),	// Title
						ACRX_T("c:/temp"),	// Default pathname  
						ACRX_T("xlsx"),	//Default extension
						16,					// Control flags
						result);	// The path selected by the user.
	if (rc != RTNORM) 
	{
		pTbl->close();
		acutPrintf(ACRX_T("\nError in selecting an EXCEL file!")); 
		return;
	}
	// Retrieve the file name from the ResBuf.
//	ACHAR fileName[MAX_PATH];
//	_tcscpy(fileName, result->resval.rstring);

	ACHAR excelSource[MAX_PATH * 2];
	_stprintf(excelSource,
		ACRX_T("%s!Sheet1"),
		result->resval.rstring
	);


	rc = acutRelRb(result);
	static ACHAR sMyDataLink[MAX_PATH] = ACRX_T("MyDataLinkTest");
	// Get the Data Link Manager.
	Acad::ErrorStatus es;
	AcDbDataLinkManager* pDlMan = acdbHostApplicationServices()->workingDatabase()->getDataLinkManager();
	assert(pDlMan);
	AcDbObjectId idDL;
	AcDbDataLink *pDL = NULL;	
	// Check if a Data Link with the name already exists. If so, remove it.
	if( pDlMan->getDataLink(sMyDataLink, pDL, AcDb::kForRead) == Acad::eOk && pDL)
	{
		pDL->close();
		es = pDlMan->removeDataLink(sMyDataLink, idDL);
		if( es != Acad::eOk )
		{
			pTbl->close();
			acutPrintf(ACRX_T("\nError in removing the Data Link!"));
			return;
		}
	}
	// Create the Data Link with the name.
	es = pDlMan->createDataLink(ACRX_T("AcExcel"), sMyDataLink, ACRX_T("This is a test for Excel type data link."), excelSource, idDL);
	if( es != Acad::eOk )
	{
		pTbl->close();
		acutPrintf(ACRX_T("\nError in creating Data Link!\nPlease check if there is a sheet named 'Sheet1' in the XLS file."));
		return;
	}
	// Open the Data Link.
	es = acdbOpenObject<AcDbDataLink>(pDL, idDL, AcDb::kForWrite);
	if ( es != Acad::eOk || !pDL )
	{
		pTbl->close();
		acutPrintf(ACRX_T("\nError in opening the Data Link object!")); 
		return;
	}
	//  Set options of the Data Link
	es = pDL->setOption(AcDb::kDataLinkOptionPersistCache);
	es = pDL->setUpdateOption(pDL->updateOption() | AcDb::kUpdateOptionAllowSourceUpdate);
	
	// Close the Data Link.
	pDL->close();
	// Set data link to the table object at cell(2,2).
	es = pTbl->setDataLink(0, 0, idDL, true);
	if( es != Acad::eOk )
	{
		pTbl->close();
		acutPrintf(ACRX_T("\nError in setting Data Link to the selected table!\nPlease check if there is a sheet named 'Sheet1' in the XLS file."));
		return;
	}
	// Don't forget to close the table object.
	es = pTbl->close();

}
	// The ACED_ADSFUNCTION_ENTRY_AUTO / ACED_ADSCOMMAND_ENTRY_AUTO macros can be applied to any static member 
	// function of the CDataLinkApp class.
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
	// ACED_ADSFUNCTION_ENTRY_AUTO(CDataLinkApp, MyLispFunction, false)
	static int ads_MyLispFunction () {
		//struct resbuf *args =acedGetArgs () ;
		
		// Put your command code here

		//acutRelRb (args) ;
		
		// Return a value to the AutoCAD Lisp Interpreter
		// acedRetNil, acedRetT, acedRetVoid, acedRetInt, acedRetReal, acedRetStr, acedRetPoint, acedRetName, acedRetList, acedRetVal

		return (RTNORM) ;
	}
	
} ;

//-----------------------------------------------------------------------------
IMPLEMENT_ARX_ENTRYPOINT(CDataLinkApp)

ACED_ARXCOMMAND_ENTRY_AUTO(CDataLinkApp, SFEMyGroup, _DATALINK2, DATALINK2, ACRX_CMD_MODAL, NULL)
//ACED_ARXCOMMAND_ENTRY_AUTO(CDataLinkApp, SFEMyGroup, MyPickFirst, MyPickFirstLocal, ACRX_CMD_MODAL | ACRX_CMD_USEPICKSET, NULL)
//ACED_ARXCOMMAND_ENTRY_AUTO(CDataLinkApp, SFEMyGroup, MySessionCmd, MySessionCmdLocal, ACRX_CMD_MODAL | ACRX_CMD_SESSION, NULL)
//ACED_ADSSYMBOL_ENTRY_AUTO(CDataLinkApp, MyLispFunction, false)

