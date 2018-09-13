
// WebClient_CEF3.cpp : 定义应用程序的类行为。
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


// CWebClient_CEF3App 构造

CWebClient_CEF3App::CWebClient_CEF3App()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 在此处添加构造代码，

	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CWebClient_CEF3App 对象

CWebClient_CEF3App theApp;


// CWebClient_CEF3App 初始化

BOOL CWebClient_CEF3App::InitInstance()
{
	//HANDLE m_hMutex = ::CreateMutex(NULL, TRUE, _T("s互斥名（随便取）"));
	//if (GetLastError() == ERROR_ALREADY_EXISTS) //程序已经运行
	//{
	//	HWND   oldHWnd = NULL;
	//	oldHWnd = ::FindWindow(NULL, _T("程序名")); //查找已经运行的程序
	//	if (oldHWnd)
	//	{
	//		::ShowWindow(oldHWnd, SW_SHOWNORMAL); //激活显示找到的已运行的程序
	//		::SetForegroundWindow(oldHWnd);       //将已运行的程序设置为当前窗口
	//	}
	//	CloseHandle(m_hMutex);
	//	m_hMutex = NULL;
	//	return FALSE;
	//}

	
	HANDLE m_hMutex1 = ::CreateMutex(NULL, TRUE, _T("fir_mutex"));
	DWORD i = GetLastError();
	if (i == ERROR_ALREADY_EXISTS) //程序已经运行
	{
		HANDLE m_hMutex2 = ::CreateMutex(NULL, TRUE, _T("sec_mutex"));
		DWORD j = GetLastError();
		if (j == ERROR_ALREADY_EXISTS)
		{
			HWND   oldHWnd = NULL;
			oldHWnd = ::FindWindow(NULL, _T("Soaraway")); //查找已经运行的程序
			if (oldHWnd)
			{
				::ShowWindow(oldHWnd, SW_SHOWNORMAL); //激活显示找到的已运行的程序
				::SetForegroundWindow(oldHWnd);       //将已运行的程序设置为当前窗口
			}
			CloseHandle(m_hMutex1);
			CloseHandle(m_hMutex2);
			m_hMutex1 = NULL;
			m_hMutex2 = NULL;
			return FALSE;
		}
		
	}
	GdiplusStartup(&m_gdiplusToken, &m_gdiplusStartupInput, NULL);
	
		
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
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
	// 创建 shell 管理器，以防对话框包含
	// 任何 shell 树视图控件或 shell 列表视图控件。
	CShellManager *pShellManager = new CShellManager;

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	CWebClient_CEF3Dlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置处理何时用
		//  “取消”来关闭对话框的代码
	}

	// 删除上面创建的 shell 管理器。
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。

	return FALSE;
}



int CWebClient_CEF3App::ExitInstance()
{
	// TODO:  在此添加专用代码和/或调用基类
	GdiplusShutdown(m_gdiplusToken);
	return CWinApp::ExitInstance();
}
