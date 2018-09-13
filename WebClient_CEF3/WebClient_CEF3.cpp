
// WebClient_CEF3.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "WebClient_CEF3.h"
#include "WebClient_CEF3Dlg.h"
#include <fstream>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWebClient_CEF3App

BEGIN_MESSAGE_MAP(CWebClient_CEF3App, CWinApp)
//	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CWebClient_CEF3App ����

CWebClient_CEF3App::CWebClient_CEF3App()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴���ӹ�����룬

	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CWebClient_CEF3App ����

CWebClient_CEF3App theApp;


// CWebClient_CEF3App ��ʼ��

BOOL CWebClient_CEF3App::InitInstance()
{
	//HANDLE m_hMutex = ::CreateMutex(NULL, TRUE, _T("s�����������ȡ��"));
	//if (GetLastError() == ERROR_ALREADY_EXISTS) //�����Ѿ�����
	//{
	//	HWND   oldHWnd = NULL;
	//	oldHWnd = ::FindWindow(NULL, _T("������")); //�����Ѿ����еĳ���
	//	if (oldHWnd)
	//	{
	//		::ShowWindow(oldHWnd, SW_SHOWNORMAL); //������ʾ�ҵ��������еĳ���
	//		::SetForegroundWindow(oldHWnd);       //�������еĳ�������Ϊ��ǰ����
	//	}
	//	CloseHandle(m_hMutex);
	//	m_hMutex = NULL;
	//	return FALSE;
	//}

	
	HANDLE m_hMutex1 = ::CreateMutex(NULL, TRUE, _T("fir_mutex"));
	DWORD i = GetLastError();
	if (i == ERROR_ALREADY_EXISTS) //�����Ѿ�����
	{
		HANDLE m_hMutex2 = ::CreateMutex(NULL, TRUE, _T("sec_mutex"));
		DWORD j = GetLastError();
		if (j == ERROR_ALREADY_EXISTS)
		{
			HWND   oldHWnd = NULL;
			oldHWnd = ::FindWindow(NULL, _T("Soaraway")); //�����Ѿ����еĳ���
			if (oldHWnd)
			{
				::ShowWindow(oldHWnd, SW_SHOWNORMAL); //������ʾ�ҵ��������еĳ���
				::SetForegroundWindow(oldHWnd);       //�������еĳ�������Ϊ��ǰ����
			}
			CloseHandle(m_hMutex1);
			CloseHandle(m_hMutex2);
			m_hMutex1 = NULL;
			m_hMutex2 = NULL;
			return FALSE;
		}
		
	}
	GdiplusStartup(&m_gdiplusToken, &m_gdiplusStartupInput, NULL);
	
		
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();
	CCustomOccManager *pMgr = new CCustomOccManager;

	// Create an IDispatch class for extending the Dynamic HTML Object Model   
	m_pDispOM = new CImpIDispatch;
	AfxEnableControlContainer(pMgr);

	CefMainArgs main_args(theApp.m_hInstance);
	CefRefPtr<CWebClient> app(new CWebClient());
	int exit_code = CefExecuteProcess(main_args, NULL, NULL);
	if (exit_code >= 0){
		exit(exit_code);
	}
	const char* locale = "zh-CN";

	CefSettings settings;
	CefSettingsTraits::init(&settings);
	settings.log_severity = LOGSEVERITY_DISABLE;
	settings.multi_threaded_message_loop = true;
	settings.single_process = true;
	CefString(&settings.locale).FromASCII(locale);
	cef_string_from_ascii(locale, strlen(locale), &settings.locale);
	CefString(&settings.accept_language_list).FromASCII(locale);
	cef_string_from_ascii(locale, strlen(locale), &settings.accept_language_list);
	CefString(&settings.cache_path) = "./cache";
	CefInitialize(main_args, settings, app, NULL);
	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CWebClient_CEF3Dlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�

	return FALSE;
}



int CWebClient_CEF3App::ExitInstance()
{
	// TODO:  �ڴ����ר�ô����/����û���
	GdiplusShutdown(m_gdiplusToken);
	return CWinApp::ExitInstance();
}
