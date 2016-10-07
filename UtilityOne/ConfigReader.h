#pragma once

#include "stdafx.h"
#include <string>

using namespace std;

typedef struct CONFIG_T
{
	std::wstring m_strImgName;
	std::wstring m_strExeName;
	std::wstring m_strCaption;
	std::wstring m_strCaption2;
	std::wstring m_strVideo;
}CONFIG,*PCONFIG;

#define MAX_CONFIG 7

class CConfigReader
{
public:
	CConfigReader(void);
	~CConfigReader(void);

	BOOL ReadConfig();
	BOOL ReadConfig(const std::wstring& strConfigName);

	PCONFIG GetConfig(){
		return m_config;
	}

	const std::wstring& GetCaption() const {
		return m_strCaption;
	}
	const std::wstring& GetLeftImg() const {
		return m_strLeftImg;
	}
private:

	unsigned	m_uiNum;

	std::wstring m_strCaption;
	std::wstring m_strIcon;
	std::wstring m_strLeftImg;

	CONFIG		m_config[MAX_CONFIG];


};

