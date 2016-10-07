// UtilityOneDlg.cpp : implementation file
//

#include "stdafx.h"
#include "UtilityOne.h"
#include "UtilityOneDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "Control.h"

// CUtilityOneDlg dialog

CUtilityOneDlg::CUtilityOneDlg(CWnd* pParent /*=NULL*/)
	: CBCGPDialog(CUtilityOneDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_control = new CControl();
	EnableVisualManagerStyle(TRUE, TRUE);
}

void CUtilityOneDlg::DoDataExchange(CDataExchange* pDX)
{
	CBCGPDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_btn1);

	DDX_Control(pDX, IDC_BACKGROUP, m_picturebackgroup);
}

BEGIN_MESSAGE_MAP(CUtilityOneDlg, CBCGPDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CUtilityOneDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CUtilityOneDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON5, &CUtilityOneDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON7, &CUtilityOneDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON9, &CUtilityOneDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON11, &CUtilityOneDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON13, &CUtilityOneDlg::OnBnClickedButton1)

	ON_BN_CLICKED(IDC_BUTTON2, &CUtilityOneDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &CUtilityOneDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON6, &CUtilityOneDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON8, &CUtilityOneDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON10, &CUtilityOneDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON12, &CUtilityOneDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON14, &CUtilityOneDlg::OnBnClickedButton1)
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_BUTTON2, &CUtilityOneDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CUtilityOneDlg message handlers

BOOL CUtilityOneDlg::OnInitDialog()
{
	CBCGPDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	ShowWindow(SW_MINIMIZE);

	// TODO: Add extra initialization here

	m_control->ReadConfig(L"./config.ini");

	m_control->SetCaption(this);
	
	UpdateData(FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CUtilityOneDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CBCGPDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CUtilityOneDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CUtilityOneDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	ClickHandler();
}


BOOL CUtilityOneDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值


	//image.Draw(pDC->m_hDC, 0, 0, image.GetWidth(), image.GetHeight());
	//CRect rect;
	//GetClientRect(&rect);

	//CImage image;
	//image.Load(_T("./res/bg.bmp"));

	//image.Draw(pDC->m_hDC, 0, 0, rect.bottom, rect.right);

	////ReleaseDC(pDC);

	//return TRUE;

	return CBCGPDialog::OnEraseBkgnd(pDC);
}

BOOL CUtilityOneDlg::ClickHandler()
{
	CWnd *pWnd = GetFocus();

	unsigned idc = pWnd->GetDlgCtrlID();

	m_control->Execute(idc);

	return TRUE;
}


void CUtilityOneDlg::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
}
