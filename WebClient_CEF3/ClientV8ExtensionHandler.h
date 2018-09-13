#pragma once

//#include "include/cef_app.h"  
#include <include/cef_v8.h>
// ClientV8ExtensionHandler

struct ClientV8ExtensionHandler : public CefV8Handler
{
	ClientV8ExtensionHandler(void); 
	virtual ~ClientV8ExtensionHandler(void);
	bool Execute(const CefString &name, CefRefPtr<CefV8Value> object, const CefV8ValueList &arguments, CefRefPtr<CefV8Value> &retval, CefString &exception) OVERRIDE;

private:
	IMPLEMENT_REFCOUNTING(ClientV8ExtensionHandler);
};


