
// WebClient_CEF3.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号
#include "WebClient_CEF3.h"
#include "CustomControlSite.h"
#include "string"
// CWebClient_CEF3App:
// 有关此类的实现，请参阅 WebClient_CEF3.cpp
//

class CWebClient_CEF3App : public CWinApp
{
public:
	CWebClient_CEF3App();

// 重写
public:
	virtual BOOL InitInstance();

// 实现
	GdiplusStartupInput m_gdiplusStartupInput;
	ULONG_PTR m_gdiplusToken;
	class CImpIDispatch* m_pDispOM;
	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
};

extern CWebClient_CEF3App theApp;