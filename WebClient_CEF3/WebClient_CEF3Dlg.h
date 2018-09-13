
// WebClient_CEF3Dlg.h : 头文件
//

#pragma once
#include "WebClient.h"
#include "ClientHandler.h"
#include "string"
#include "GdipButton.h"
#include "fstream"
#include "IpDlg.h"
using namespace std;
// CWebClient_CEF3Dlg 对话框
class CWebClient_CEF3Dlg : public CDialogEx
{
// 构造
public:
	CWebClient_CEF3Dlg(CWnd* pParent = NULL);	// 标准构造函数
	CefRefPtr< ClientHandler>  m_cWebClient;
// 对话框数据
	enum { IDD = IDD_WEBCLIENT_CEF3_DIALOG };
	void Config();
public:
	string Address;
	string Title;
	string IP;
	string Port;

	string ip_url;
	IpDlg ip;
	double zoom;
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	static DWORD WINAPI Observer(LPVOID P);

	bool is_playing;//是否已打开播放smg、unity的播放窗口
	bool is_login;//是否是登陆界面，用于分辨率改变时的判断

	STARTUPINFO infoStart;//子进程窗口参数
	PROCESS_INFORMATION infoProcess;
//	bool fullscreenclr;
//	ofstream out;
// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();

	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnClose();
	afx_msg void OnBnClickedOk();
	CGdipButton m_min;
	CGdipButton m_close;
	afx_msg LRESULT OnMsgHandler(WPARAM, LPARAM);
	afx_msg LRESULT OnMsgHandler2(WPARAM, LPARAM);
	afx_msg LRESULT OnMsgHandlerDown(WPARAM, LPARAM);
	afx_msg LRESULT OnMsgHandlerSmg(WPARAM, LPARAM);
	afx_msg LRESULT OnMsgHandlerClose(WPARAM, LPARAM);
	afx_msg LRESULT OnMsgHandlerFullScreen(WPARAM, LPARAM);
	afx_msg LRESULT OnMsgHandlerExitFullScreen(WPARAM, LPARAM);
	afx_msg LRESULT OnMsgHandlerCheckFullScreen(WPARAM, LPARAM);
	afx_msg long OnHotKey(WPARAM wParam, LPARAM lParam);
	afx_msg void OnBnClickedButtonMin();
	afx_msg void OnBnClickedButtonClose();
	afx_msg void OnSettingChange(UINT uFlags, LPCTSTR lpszSection);
	afx_msg void OnDisplayChange(UINT nImageDepth, int cxScreen, int cyScreen);
//	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnWinIniChange(LPCTSTR lpszSection);
};
