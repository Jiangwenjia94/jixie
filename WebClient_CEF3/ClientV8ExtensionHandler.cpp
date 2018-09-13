// ClientV8ExtensionHandler.cpp : 实现文件
//

#include "stdafx.h"
#include "WebClient_CEF3.h"
#include "ClientV8ExtensionHandler.h"
#include "string"

// ClientV8ExtensionHandler

ClientV8ExtensionHandler::ClientV8ExtensionHandler(void)  
{  
} 
ClientV8ExtensionHandler::~ClientV8ExtensionHandler(void)
{
}
bool ClientV8ExtensionHandler::Execute(const CefString &name, CefRefPtr<CefV8Value> object, const CefV8ValueList &arguments, CefRefPtr<CefV8Value> &retval, CefString &exception)  
    {  
        //if ( name == "ChangeTextInJS" ) {  
        //    if ( (arguments.size() == 1) && arguments[0]->IsString() ) {  
        //        CefString           text   = arguments[0]->GetStringValue();  
        //        CefRefPtr<CefFrame> frame  = CefV8Context::GetCurrentContext()->GetBrowser()->GetMainFrame();  
        //        std::string         jscall = "ChangeText(‘";  
        //        jscall += text;  
        //        jscall += "‘);";  
        //        frame->ExecuteJavaScript(jscall, frame->GetURL(), 0);  
        //        /* 
        //         * If you want your method to return a value, just use retval, like this: 
        //         * retval = CefV8Value::CreateString("Hello World!"); 
        //         * you can use any CefV8Value, what means you can return arrays, objects or whatever you can create with CefV8Value::Create* methods 
        //         */  
        //        return true;  
        //    }  
        //}  
		if (name == _T("smgPlayer"))
		{
			std::string smgUrl = "";
			if ((arguments.size() == 1) && arguments[0]->IsString()) 
			{
				smgUrl = arguments[0]->GetStringValue();
				retval = CefV8Value::CreateString(smgUrl);

				CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create("getsmg");
				CefRefPtr<CefListValue> args = message->GetArgumentList();
				args->SetSize(1);
				args->SetString(0, smgUrl);
				CefV8Context::GetCurrentContext()->GetBrowser()->SendProcessMessage(PID_BROWSER, message);
				
			}
			
			return true;
		}

        return false;  
    } 

// ClientV8ExtensionHandler 消息处理程序


