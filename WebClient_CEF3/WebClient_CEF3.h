
// WebClient_CEF3.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "WebClient_CEF3.h"
#include "CustomControlSite.h"
#include "string"
// CWebClient_CEF3App:
// �йش����ʵ�֣������ WebClient_CEF3.cpp
//

class CWebClient_CEF3App : public CWinApp
{
public:
	CWebClient_CEF3App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	GdiplusStartupInput m_gdiplusStartupInput;
	ULONG_PTR m_gdiplusToken;
	class CImpIDispatch* m_pDispOM;
	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
};

extern CWebClient_CEF3App theApp;