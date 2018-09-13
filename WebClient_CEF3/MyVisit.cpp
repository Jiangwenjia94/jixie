#include "stdafx.h"
#include "MyVisit.h"
#include <fstream>

MyVisitor::MyVisitor(CefRefPtr<CefBrowser> browser)
{
	_browser = browser;
}

MyVisitor::MyVisitor()
{
}

MyVisitor::~MyVisitor()
{
}

void MyVisitor::Visit(CefRefPtr<CefDOMDocument> document)
{
	
	CefRefPtr<CefDOMNode> s = document->GetElementById("loginForSystem");
	if (s.get())
	{
		CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create("getm");
		_browser->SendProcessMessage(PID_BROWSER, message);
	}
	else
	{
		CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create("getf");
		_browser->SendProcessMessage(PID_BROWSER, message);
	}
}