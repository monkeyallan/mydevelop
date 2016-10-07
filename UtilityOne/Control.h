#pragma once

#include <string>
using namespace std;

#include "ConfigReader.h"

class CUtilityOneDlg;

class CControl
{
public:
	CControl();
	~CControl();

	VOID ReadControl(HWND hDlg);

	BOOL RunExe(const std::wstring& strExeName);
	BOOL PlayVideo(const std::wstring& strVideoName);
	BOOL Execute(unsigned idc);

	BOOL ReadConfig(const std::wstring& strConfigName)
	{
		return m_configReader.ReadConfig(strConfigName);
	}

	VOID SetCaption(CUtilityOneDlg* pDlg);
private:

	CConfigReader	m_configReader;
	CUtilityOneDlg* pDlg;
};

