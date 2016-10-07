// UtilityOneDlg.h : header file
//

#pragma once
#include "afxwin.h"

class CControl;

// CUtilityOneDlg dialog
class CUtilityOneDlg : public CBCGPDialog
{
// Construction
public:
	CUtilityOneDlg(CWnd* pParent = NULL);	// standard constructor

	~CUtilityOneDlg(){
		delete m_control;
	}
// Dialog Data
	enum { IDD = IDD_UTILITYONE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CBCGPButton m_btn1;
	CStatic m_picturebackgroup;
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

private:
	CControl*		m_control;
	BOOL ClickHandler();

public:
	afx_msg void OnBnClickedButton2();
};
