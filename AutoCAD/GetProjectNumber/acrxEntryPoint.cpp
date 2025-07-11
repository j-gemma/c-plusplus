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
#include "aced.h"
#include "acdocman.h"
#include "dbsymtb.h"

//-----------------------------------------------------------------------------
#define szRDS _RXST("SFE")

//-----------------------------------------------------------------------------
//----- ObjectARX EntryPoint
class CGetProjectNumberApp : public AcRxArxApp {

public:
	CGetProjectNumberApp () : AcRxArxApp () {}

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
	// function of the CGetProjectNumberApp class.
	// The function should take no arguments and return nothing.
	//
	// NOTE: ACED_ARXCOMMAND_ENTRY_AUTO has overloads where you can provide resourceid and
	// have arguments to define context and command mechanism.
	
	// ACED_ARXCOMMAND_ENTRY_AUTO(classname, group, globCmd, locCmd, cmdFlags, UIContext)
	// ACED_ARXCOMMAND_ENTRYBYID_AUTO(classname, group, globCmd, locCmdId, cmdFlags, UIContext)
	// only differs that it creates a localized name using a string in the resource file
	//   locCmdId - resource ID for localized command

	// Modal Command with localized name
	//ACED_ARXCOMMAND_ENTRY_AUTO(CGetProjectNumberApp, SFEMyGroup, MyCommand, MyCommandLocal, ACRX_CMD_MODAL)
	static void SFESchedule_GetProjectNumber (void) {
		//acutPrintf(L"\nGetting project number...");
		////Get current document pointer
		//AcApDocument* pDoc = acDocManager->curDocument();
		//if (pDoc == nullptr) {
		//	acutPrintf(L"\nNo active document found.");
		//	return;
		//}
		//const ACHAR* docPath = pDoc->fileName();
		//if (docPath == nullptr || docPath[0] == L'0') {
		//	acutPrintf(L"\nDocument has not been saved yet.");
		//}
		//else {
		//	acutPrintf(L"\nDocument path: %ls", docPath);
		//	
		//	acedPrompt(L"\nPrompt");
		//	//acedAlert(L"\nAlert");
		//}
		
		ACHAR input[133];
		acedInitGet(0, NULL); // Initialize input (no keywords here)
		if (acedGetString(Adesk::kFalse, L"\nEnter your name: ", input) == RTNORM) {
			acedPrompt(L"\nYou entered: ");
			acedPrompt(input);  // This will appear in command line area
		}


	}

} ;

//-----------------------------------------------------------------------------
IMPLEMENT_ARX_ENTRYPOINT(CGetProjectNumberApp)

ACED_ARXCOMMAND_ENTRY_AUTO(CGetProjectNumberApp, SFESchedule, _GetProjectNumber, GetProjectNumber, ACRX_CMD_MODAL, NULL)
