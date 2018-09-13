#pragma once
#include "dscomposerplayeractivexctrl1.h"
#include "GdipButton.h"
#include "afxwin.h"

// SMG 对话框

class SMG : public CDialogEx
{
	DECLARE_DYNAMIC(SMG)

public:
	SMG(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~SMG();
	SMG(CString s);
	void ChangeSize(CWnd * pWnd, int cx, int cy);
	void AdjustControl();
	CRect m_rect;
// 对话框数据
	enum { IDD = IDD_DIALOG_SMG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CDscomposerplayeractivexctrl1 m_smg;
	virtual BOOL OnInitDialog();
	CGdipButton m_close;
	afx_msg void OnBnClickedButtonClose();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CString filename;
};
