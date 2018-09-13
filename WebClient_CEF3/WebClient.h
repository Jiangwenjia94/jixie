#pragma once
#include "include/cef_app.h"  
#include "include/cef_client.h" 
#include "MyVisit.h"
// CWebClient

class CWebClient :
	  public  CefApp,
	  CefRenderProcessHandler,
	  public CefBrowserProcessHandler,
	  public MyVisitor,
	  public CefLoadHandler
{
public:
	CWebClient();
	//virtual ~CWebClient(void){};
	CefRefPtr<MyVisitor> visitor;
	virtual CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler() OVERRIDE
	{
		return this;
	}
	CefRefPtr<CefRenderProcessHandler> GetRenderProcessHandler() OVERRIDE  
    {  
        return this;  
    } 
	

    virtual void OnBeforeCommandLineProcessing(const CefString& process_type, CefRefPtr<CefCommandLine> command_line) override;
   
	void OnWebKitInitialized() OVERRIDE;  
	
	virtual CefRefPtr<CefLoadHandler> GetLoadHandler() OVERRIDE{
		return this;
	}
	virtual void OnLoadEnd(CefRefPtr<CefBrowser> browser,
	CefRefPtr<CefFrame> frame,
	int httpStatusCode);

	virtual void OnContextCreated(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		CefRefPtr<CefV8Context> context);
     
    IMPLEMENT_REFCOUNTING(CWebClient);
};


