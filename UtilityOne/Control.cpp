#include "stdafx.h"

#include<atlconv.h>

#include "Resource.h"
#include "UtilityOneDlg.h"
#include "Control.h"

CControl::CControl()
{
}

CControl::~CControl()
{
}

BOOL CControl::PlayVideo(const std::wstring& strVideoName)
{
	ShellExecute(NULL, _T("open"), strVideoName.c_str(), NULL, NULL, SW_SHOWNORMAL);
	return TRUE;
}


BOOL CControl::RunExe(const std::wstring& strExeName)
{
	/*
	STARTUPINFO si; //一些必备参数设置
	int n = 1;
	memset(&si, 0, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = SW_SHOW;

	PROCESS_INFORMATION pi; //必备参数设置结束

	//是您要运行的程序//的路径
	if (!::CreateProcess(NULL, (LPWSTR)strExeName.c_str(),
		NULL, NULL, false, 0, NULL, NULL, &si, &pi))
	{
		return FALSE;
	}
	*/
	USES_CONVERSION;
	UINT uiResult = WinExec(T2A(strExeName.c_str()), SW_SHOW);
	return TRUE;
}

BOOL CControl::Execute(unsigned idc)
{
	unsigned team = idc / 1000;
	unsigned which = idc % 1000;

	if (team==0 || team>=8 || which>=2)
	{
		return FALSE;
	}

	switch (which)
	{
	case 0:
		RunExe(m_configReader.GetConfig()[team-1].m_strExeName);
		break;
	case 1:
		PlayVideo(m_configReader.GetConfig()[team-1].m_strVideo);
		break;
	default:
		break;
	}
	return TRUE;
}

VOID CControl::SetCaption(CUtilityOneDlg* pDlg)
{
	pDlg->SetWindowText(m_configReader.GetCaption().c_str());

	HBITMAP hBitmap1 = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), m_configReader.GetLeftImg().c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	pDlg->m_picturebackgroup.SetBitmap(hBitmap1);


	for (auto i = 1; i <= MAX_CONFIG;i++)
	{
		HWND hBtn = GetDlgItem(pDlg->m_hWnd, i * 1000);
		std::wstring strCaption = m_configReader.GetConfig()[i - 1].m_strCaption;
		SetWindowText(hBtn, m_configReader.GetConfig()[i-1].m_strCaption.c_str());

		hBtn = GetDlgItem(pDlg->m_hWnd, i * 1000+1);
		SetWindowText(hBtn, m_configReader.GetConfig()[i - 1].m_strCaption2.c_str());

		CImage img;

		HRESULT ret = img.Load(m_configReader.GetConfig()[i - 1].m_strImgName.c_str());

		HBITMAP hb = img.Detach();

		CBCGPButton* pbtn = (CBCGPButton*)(pDlg->GetDlgItem(i*1000));
		pbtn->SetImage(hb);

	}
	
}