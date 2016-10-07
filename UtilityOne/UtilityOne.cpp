// UtilityOne.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "UtilityOne.h"
#include "UtilityOneDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CUtilityOneApp

BEGIN_MESSAGE_MAP(CUtilityOneApp, CBCGPWinApp)
	ON_COMMAND(ID_HELP, CBCGPWinApp::OnHelp)
END_MESSAGE_MAP()


// CUtilityOneApp construction

CUtilityOneApp::CUtilityOneApp()
{
	// Enable Office 2010 look (Blue theme):
	SetVisualTheme(BCGP_VISUAL_THEME_OFFICE_2010_BLUE);

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CUtilityOneApp object

CUtilityOneApp theApp;


// CUtilityOneApp initialization

BOOL CUtilityOneApp::InitInstance()
{
	// InitCommonControls() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	InitCommonControls();

	CBCGPWinApp::InitInstance();

	AfxEnableControlContainer();


	CUtilityOneDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
