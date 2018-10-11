// ClientHandler.cpp : 实现文件
//

#include "stdafx.h"
#include "WebClient_CEF3.h"
#include "ClientHandler.h"

#include "include/cef_app.h"  
#include "include/cef_base.h"  
#include "include/cef_client.h"  
#include "include/cef_command_line.h"  
#include "include/cef_frame.h"  
#include "include/cef_web_plugin.h"
#include "string"
// ClientHandler


ClientHandler::ClientHandler()
{
	is_closing_ = false; 
	is_fullscreen = false;
}

ClientHandler::~ClientHandler()
{
}
bool ClientHandler::DoClose(CefRefPtr<CefBrowser> browser)  
{  
	if (browser_list_.size() == 1) {
		// Set a flag to indicate that the window close should be allowed.
		is_closing_ = true;
	}
    return false;  
}  

void ClientHandler::OnAfterCreated(CefRefPtr<CefBrowser> browser)  
{  
	
    if ( !m_Browser.get() ) {  
        // We need to keep the main child window, but not popup windows  
        m_Browser     = browser;  
        m_BrowserHwnd = browser->GetHost()->GetWindowHandle();  
		browser_list_.push_back(browser);
    }  
}  
      
void ClientHandler::OnBeforeClose(CefRefPtr<CefBrowser> browser)  
{  
//    if ( m_BrowserHwnd == browser->GetHost()->GetWindowHandle() ) {  
        // Free the browser pointer so that the browser can be destroyed  
		/*const CefString cefStrUrl("http://localhost:8080//usermgr/userLoginAction!userLogout");

		m_Browser->GetMainFrame()->LoadURL(cefStrUrl);*/

		m_Browser = NULL;  
	//	CefQuitMessageLoop();
		BrowserList::iterator bit = browser_list_.begin();
		for (; bit != browser_list_.end(); ++bit) {
			if ((*bit)->IsSame(browser)) {
				browser_list_.erase(bit);
				break;
			}
		}

		if (browser_list_.empty()) {
			// All browser windows have closed. Quit the application message loop.
			CefQuitMessageLoop();
		}
 //   }  
}  
bool ClientHandler::OnBeforePopup(CefRefPtr<CefBrowser> browser,
	CefRefPtr<CefFrame> frame,
	const CefString& target_url,
	const CefString& target_frame_name,
	WindowOpenDisposition target_disposition,
	bool user_gesture,
	const CefPopupFeatures& popupFeatures,
	CefWindowInfo& windowInfo,
	CefRefPtr<CefClient>& client,
	CefBrowserSettings& settings,
	bool* no_javascript_access)
{
	switch (target_disposition)
	{
	case WOD_NEW_FOREGROUND_TAB:
	case WOD_NEW_BACKGROUND_TAB:
	case WOD_NEW_POPUP:
	case WOD_NEW_WINDOW:
		browser->GetMainFrame()->LoadURL(target_url);
		return true; //cancel create
	}

	return false;
}

bool ClientHandler::OnProcessMessageReceived(CefRefPtr<CefBrowser> browser,
	CefProcessId source_process,
	CefRefPtr<CefProcessMessage> message)
{
	
	if (message->GetName() == "getm")//小窗口
	{
		HWND hwnd = GetActiveWindow();
		::SendMessage(hwnd, WM_MYMSG, 0, 0);
		is_fullscreen = true;
		return false;
	}
	else if (message->GetName() == "getsmg")//播放smg
	{
		CefRefPtr<CefListValue> args = message->GetArgumentList();
		std::string *strUrl = new std::string(args->GetString(0));
		HWND hwnd = GetActiveWindow();
		::SendMessage(hwnd, WM_MYMSG_SMG, 0, (LPARAM)strUrl);
		return false;
	}
	else
	{
		HWND hwnd = GetActiveWindow();
		//	HWND hWnd = AfxGetMainWnd()->m_hWnd;
		::SendMessage(hwnd, WM_MYMSG2, 0, 0);//全屏
		return false;
	}
}

void ClientHandler::OnBeforeDownload(
	CefRefPtr<CefBrowser> browser,
	CefRefPtr<CefDownloadItem> download_item,
	const CefString& suggested_name,
	CefRefPtr<CefBeforeDownloadCallback> callback)
{
	callback->Continue(download_item->GetURL(), true);
}


void ClientHandler::OnDownloadUpdated(
	CefRefPtr<CefBrowser> browser,
	CefRefPtr<CefDownloadItem> download_item,
	CefRefPtr<CefDownloadItemCallback> callback)
{
	if (download_item->IsComplete())
	{
		AfxMessageBox("下载成功");  
//		HWND hwnd = GetActiveWindow();
//		::SendMessage(hwnd, WM_MYMSG_DOWNCP, 0, 0);
		if (browser->IsPopup() && !browser->HasDocument())
		{
			//browser->GetHost()->ParentWindowWillClose();  
			browser->GetHost()->CloseBrowser(true);
		}
	}
}

CefRefPtr<CefDownloadHandler> ClientHandler::GetDownloadHandler()
{
	return this;
}

void ClientHandler::OnBeforeContextMenu(CefRefPtr<CefBrowser> browser,
	CefRefPtr<CefFrame> frame,
	CefRefPtr<CefContextMenuParams> params,
	CefRefPtr<CefMenuModel> model)
{
	if ((params->GetTypeFlags() & (CM_TYPEFLAG_PAGE | CM_TYPEFLAG_FRAME)) != 0) {
		// Add a separator if the menu already has items.
		if (model->GetCount() > 0)
			model->AddSeparator();
			model->Clear();
		// Add DevTools items to all context menus.
		
		model->AddItem(10, L"默认布局");
		model->AddItem(11, L"刷新");
		
		// Test context menu features.
		//BuildTestMenu(model);
	}
	if (params->GetTypeFlags() & CM_TYPEFLAG_EDITABLE)
	{//编辑框的右键消息		
		if (model->GetCount() > 0)
			model->AddSeparator();
		model->Clear();
		model->AddItem(12, L"剪切");
		model->AddItem(13, L"复制");
		model->AddItem(14, L"粘贴");
		model->AddItem(15, L"删除");
	}

	//	if (delegate_)
	//		delegate_->OnBeforeContextMenu(model);
}

bool ClientHandler::OnContextMenuCommand(CefRefPtr<CefBrowser> browser,
	CefRefPtr<CefFrame> frame,
	CefRefPtr<CefContextMenuParams> params,
	int command_id,
	EventFlags event_flags) {

	if (command_id == 10)
	{
		browser->GetHost()->SetZoomLevel(0.0);
		return true;
	}
	if (command_id == 11)
	{
		browser->Reload();
		return true;
	}
	if (command_id == 12)
	{
		frame->Cut();
		return true;
	}
	if (command_id == 13)
	{
		frame->Copy();
		return true;
	}
	if (command_id == 14)
	{
		frame->Paste();
		return true;
	}
	if (command_id == 15)
	{
		frame->Delete();
		return true;
	}
	return false;
}
//#include <fstream>
void ClientHandler::OnAddressChange(CefRefPtr<CefBrowser> browser,
	CefRefPtr<CefFrame> frame,
	const CefString& url)
{
	CString login = "userLoginAction!getAllCollege";
	CString s;
	s = url.c_str();
	CString right = s.Right(29);
//	std::ofstream out;
//	out.open("url.txt", std::ios::app);
	if (right != login)
	{
		HWND hwnd = GetActiveWindow();
		::SendMessage(hwnd, WM_MYMSG2, 0, 0);
//		out << "kadun: " << right << std::endl;
	}
	
//	out << right << std::endl;
//	out.close();
}

void ClientHandler::OnFullscreenModeChange(CefRefPtr<CefBrowser> browser,
	bool fullscreen)
{
	
	if (fullscreen)
	{
		HWND hwnd = GetActiveWindow();
		::SendMessage(hwnd, WM_MYMSG_FULLSCREEN, 0, 0);
	}
	else
	{
		HWND hwnd = GetActiveWindow();
		::SendMessage(hwnd, WM_MYMSG_EXITFULLSCREEN, 0, 0);
	}
}