#include "StdAfx.h"
#include "ConfigReader.h"


CConfigReader::CConfigReader(void)
{
}


CConfigReader::~CConfigReader(void)
{
}

BOOL CConfigReader::ReadConfig()
{
	return TRUE;
}

BOOL CConfigReader::ReadConfig(const std::wstring& strConfigName)
{
	m_uiNum = ::GetPrivateProfileInt(L"Available", L"num", 0, strConfigName.c_str());

	if (m_uiNum==0)
	{
		return FALSE;
	}

	WCHAR cap[32] = { WCHAR('\0') };
	int nread = ::GetPrivateProfileString(
		L"Available", L"caption", L"",
		cap, 32, strConfigName.c_str());
	m_strCaption = cap;

	nread = ::GetPrivateProfileString(
		L"Available", L"icon", L"",
		cap, 32, strConfigName.c_str());
	m_strIcon = cap;

	nread = ::GetPrivateProfileString(
		L"Available", L"leftimg", L"",
		cap, 32, strConfigName.c_str());
	m_strLeftImg = cap;

	for (_ULONGLONG i = 1; i <= m_uiNum; ++i)
	{
		std::wstring strAction = L"Action";
		strAction += std::to_wstring(i);

		WCHAR read[32] = { WCHAR('\0') };
		 int nread = ::GetPrivateProfileString(
			strAction.c_str(), L"Img", L"", 
			read, 32, strConfigName.c_str());

		 m_config[i - 1].m_strImgName = read;

		 nread = ::GetPrivateProfileString(
			 strAction.c_str(), L"exe", L"",
			 read, 32, strConfigName.c_str());

		 m_config[i - 1].m_strExeName = read;

		 nread = ::GetPrivateProfileString(
			 strAction.c_str(), L"caption", L"",
			 read, 32, strConfigName.c_str());

		 m_config[i - 1].m_strCaption = read;

		 nread = ::GetPrivateProfileString(
			 strAction.c_str(), L"caption2", L"",
			 read, 32, strConfigName.c_str());

		 m_config[i - 1].m_strCaption2 = read;

		 nread = ::GetPrivateProfileString(
			 strAction.c_str(), L"vedio", L"",
			 read, 32, strConfigName.c_str());

		 m_config[i - 1].m_strVideo = read;

	}

	return TRUE;
}
