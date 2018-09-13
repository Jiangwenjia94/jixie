#pragma once
#include "include/cef_render_process_handler.h"  
#include "include/cef_client.h"  
#include "include/cef_v8.h"
#include "include/cef_browser.h"
#include "include/cef_download_handler.h" 
#include "include/cef_display_handler.h"
#include <list>
// ClientHandler

class ClientHandler : public CefClient,
					  public CefLifeSpanHandler,
					  public CefDownloadHandler,
					  public CefContextMenuHandler,
					  public CefDisplayHandler
{

public:
	ClientHandler();
	virtual ~ClientHandler();

	CefRefPtr<CefBrowser> GetBrowser()  
        {  
            return m_Browser;  
        }  
	CefWindowHandle GetBrowserHwnd()  
        {  
            return m_BrowserHwnd;  
        }  
	// CefClient methods  
    virtual CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() OVERRIDE  
        {  
            return this;  
        }  

	virtual CefRefPtr<CefDisplayHandler> GetDisplayHandler() {
			return this;
		}

			CefRefPtr<CefContextMenuHandler> GetContextMenuHandler() OVERRIDE{
			return this;
		}
	void OnBeforeContextMenu(CefRefPtr<CefBrowser> browser,
			CefRefPtr<CefFrame> frame,
			CefRefPtr<CefContextMenuParams> params,
			CefRefPtr<CefMenuModel> model);
	bool OnContextMenuCommand(CefRefPtr<CefBrowser> browser,
			CefRefPtr<CefFrame> frame,
			CefRefPtr<CefContextMenuParams> params,
			int command_id,
			EventFlags event_flags);

      
        // Virutal on CefLifeSpanHandler  
    virtual bool DoClose(CefRefPtr<CefBrowser> browser) OVERRIDE;  
    virtual void OnAfterCreated(CefRefPtr<CefBrowser> browser) ;  
    virtual void OnBeforeClose(CefRefPtr<CefBrowser> browser) ;

	virtual bool OnProcessMessageReceived(CefRefPtr<CefBrowser> browser,
		CefProcessId source_process,
		CefRefPtr<CefProcessMessage> message);

	virtual bool OnBeforePopup(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		const CefString& target_url,
		const CefString& target_frame_name,
		WindowOpenDisposition target_disposition,
		bool user_gesture,
		const CefPopupFeatures& popupFeatures,
		CefWindowInfo& windowInfo,
		CefRefPtr<CefClient>& client,
		CefBrowserSettings& settings,
		bool* no_javascript_access);

	//download
	virtual void OnBeforeDownload(
		CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefDownloadItem> download_item,
		const CefString& suggested_name,
		CefRefPtr<CefBeforeDownloadCallback> callback);

	virtual void OnDownloadUpdated(
		CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefDownloadItem> download_item,
		CefRefPtr<CefDownloadItemCallback> callback);

	virtual CefRefPtr<CefDownloadHandler> GetDownloadHandler() override;
	//download
	bool IsClosing() const { return is_closing_; }

	virtual void OnAddressChange(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		const CefString& url);

	virtual void OnFullscreenModeChange(CefRefPtr<CefBrowser> browser,
		bool fullscreen);
protected:
	// The child browser window  
    CefRefPtr<CefBrowser> m_Browser;  
      
    // The child browser window handle  
    CefWindowHandle m_BrowserHwnd;  
private:
	typedef std::list<CefRefPtr<CefBrowser>> BrowserList;
	BrowserList browser_list_;
	bool is_fullscreen;
	bool is_closing_;
    // /  
    // Macro that provides a reference counting implementation for classes extending  
    // CefBase.  
    // /  
    IMPLEMENT_REFCOUNTING(ClientHandler);  
};


