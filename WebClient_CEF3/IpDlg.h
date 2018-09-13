#pragma once
#include "resource.h"
#include "string"

// IpDlg �Ի���
class IpDlg : public CDialogEx
{
	DECLARE_DYNAMIC(IpDlg)

public:
	IpDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~IpDlg();
	std::string GetUrl();
	// �Ի�������
	enum { IDD = IDD_DIALOG_IP };
	bool is_use;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CString URL;
	CString ADDRESS;
	CString PORT;
	CString IP;
	CString t_ip;
	CString t_port;
	std::string conf[6];
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
};
