#pragma once
#include "stdafx.h"
#include <include/cef_app.h>
#include <include/cef_dom.h>
#include <include/cef_browser.h>
class MyVisitor :public CefDOMVisitor
{
public:
	explicit MyVisitor(CefRefPtr<CefBrowser> browser);
	MyVisitor();
	~MyVisitor();

	void Visit(CefRefPtr<CefDOMDocument> document) OVERRIDE;
	IMPLEMENT_REFCOUNTING(MyVisitor);

	CefRefPtr<CefBrowser> _browser;
};

