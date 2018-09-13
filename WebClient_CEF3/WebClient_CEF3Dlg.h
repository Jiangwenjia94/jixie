
// WebClient_CEF3Dlg.h : ͷ�ļ�
//

#pragma once
#include "WebClient.h"
#include "ClientHandler.h"
#include "string"
#include "GdipButton.h"
#include "fstream"
#include "IpDlg.h"
using namespace std;
// CWebClient_CEF3Dlg �Ի���
class CWebClient_CEF3Dlg : public CDialogEx
{
// ����
public:
	CWebClient_CEF3Dlg(CWnd* pParent = NULL);	// ��׼���캯��
	CefRefPtr< ClientHandler>  m_cWebClient;
// �Ի�������
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
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

	static DWORD WINAPI Observer(LPVOID P);

	bool is_playing;//�Ƿ��Ѵ򿪲���smg��unity�Ĳ��Ŵ���
	bool is_login;//�Ƿ��ǵ�½���棬���ڷֱ��ʸı�ʱ���ж�

	STARTUPINFO infoStart;//�ӽ��̴��ڲ���
	PROCESS_INFORMATION infoProcess;
//	bool fullscreenclr;
//	ofstream out;
// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
