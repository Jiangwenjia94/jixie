#pragma once

#include "string"
#include "explorer1.h"
#include "GdipButton.h"
#include "Mshtml.h"
#include "afxwin.h"
#include "fstream"
using namespace std;
// SmgPlayerDlg 对话框

class SmgPlayerDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SmgPlayerDlg)

public:
	SmgPlayerDlg(CWnd* pParent = NULL);   // 标准构造函数
	SmgPlayerDlg(string &Url, string &Index,CWnd* pParent = NULL);
	virtual ~SmgPlayerDlg();
	void ChangeSize(CWnd * pWnd, int cx, int cy);
	void AdjustControl();

	IHTMLElement*       GetHTMLElement(const CString& strID); //获取网页元素，通过ID  主要用来获得 button 和 text 控件
	IHTMLSelectElement* GetHTMLSelectElement(const CString& strID); //获取select 控件 元素
	IDispatch*          GetHTMLElemCollDispatch(const CString& strID);  //获取收集所有网页元素的Dispatch

	void SetWebEditText(const CString& strID, const CString& strText);
	void OnWebClick(const CString& strID);
	void OnWebSelect(const CString& strID, long lIndex);
	void OnWebRadio(const CString& strID);

//	std::ofstream out;
	CRect m_rect;
	bool fir_loding;
	bool sen_loding;
// 对话框数据
	enum { IDD = IDD_DIALOG_SMGPLAYER };
	DWORD r, g, b;
	
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
private:
	string m_url;
	string m_index;
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CExplorer1 m_ie;
	CExplorer1 m_ie_player;
	long width;
	long height;
	DECLARE_EVENTSINK_MAP()
	void DocumentCompleteExplorer1(LPDISPATCH pDisp, VARIANT* URL);
	afx_msg void OnPaint();
	afx_msg void OnClose();
	afx_msg LRESULT OnMsgHandlerHop(WPARAM, LPARAM);
	afx_msg void OnBnClickedButtonClose();
	CGdipButton m_close;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	
};
