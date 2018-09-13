// WebClient.cpp : 实现文件
//

#include "stdafx.h"
#include "WebClient_CEF3.h"
#include "WebClient.h"
#include "ClientV8ExtensionHandler.h"
#include "ClientHandler.h"  
//#include "ClientV8ExtensionHandler.h"  

CWebClient::CWebClient()
{
	
}

void CWebClient::OnBeforeCommandLineProcessing(const CefString& process_type, CefRefPtr<CefCommandLine> command_line)
{
	command_line->AppendSwitch("process-per-site");
	command_line->AppendSwitch("no-proxy-server");
	command_line->AppendSwitch("--enable-npapi");
	command_line->AppendSwitch("--disable-web-security");
	command_line->AppendSwitch("allow-outdated-plugins");

	//加载flash插件
//	command_line->AppendSwitch("--disable-web-security");//关闭同源策略
//	command_line->AppendSwitch("--enable-system-flash");//使用系统flas

	command_line->AppendSwitchWithValue("ppapi-flash-version", "18.0.0.209");
	command_line->AppendSwitchWithValue("ppapi-flash-path", "PepperFlash\\pepflashplayer.dll");

}

void CWebClient::OnWebKitInitialized()  
{  
	
   /* std::string app_code = 
        "var app;" 
        "if (!app)" 
        "    app = {};" 
        "(function() {" 
        "    app.ChangeTextInJS = function(text) {" 
        "        native function ChangeTextInJS();" 
        "        return ChangeTextInJS(text);" 
        "    };" 
        "})();;"; 
     
    CefRegisterExtension( "v8/app", app_code, new ClientV8ExtensionHandler(this) );  */
}  
//#include <fstream>
void CWebClient::OnLoadEnd(CefRefPtr<CefBrowser> browser,
	CefRefPtr<CefFrame> frame,
	int httpStatusCode)
{
	//std::ofstream out("fffffffffff");
	frame->VisitDOM(new MyVisitor(browser));
	HWND hwnd = GetActiveWindow();
	::SendMessage(hwnd, WM_MYMSG_CHECKFULLSCREEN, 0, 0);
}

void CWebClient::OnContextCreated(CefRefPtr<CefBrowser> browser,
	CefRefPtr<CefFrame> frame,
	CefRefPtr<CefV8Context> context)
{
	CefRefPtr<CefV8Value> window = context->GetGlobal();
	CefRefPtr<ClientV8ExtensionHandler> pJsHandler(new ClientV8ExtensionHandler());
	CefRefPtr<CefV8Value> myFunc = CefV8Value::CreateFunction(_T("smgPlayer"), pJsHandler);
	window->SetValue(_T("smgPlayer"), myFunc, V8_PROPERTY_ATTRIBUTE_NONE);
}