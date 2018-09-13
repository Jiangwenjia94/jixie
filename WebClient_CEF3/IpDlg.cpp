// IpDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "IpDlg.h"
#include "afxdialogex.h"
#include <fstream>

// IpDlg �Ի���

IMPLEMENT_DYNAMIC(IpDlg, CDialogEx)

IpDlg::IpDlg(CWnd* pParent /*=NULL*/)
: CDialogEx(IpDlg::IDD, pParent)
{
	is_use = false;
}

IpDlg::~IpDlg()
{
}

void IpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(IpDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &IpDlg::OnBnClickedOk)
//	ON_BN_CLICKED(IDC_BUTTON1, &IpDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// IpDlg ��Ϣ�������


void IpDlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	const CString pre = _T("http://");
	GetDlgItem(IDC_IPADDRESS)->GetWindowTextA(t_ip);
	GetDlgItem(IDC_EDIT_port)->GetWindowTextA(t_port);
	URL += pre;
	URL += t_ip;
	URL += ":";
	URL += t_port;

	//if (t_ip == "0.0.0.0")
	//{
	//	MessageBox("none");
	//	//������config
	//}
	//else
	//{
		std::ofstream out("config\\ini.txt");
		conf[3] = "IP=" + t_ip;
		if (t_port == "")
		{
			conf[4] = "PORT=8080";
			conf[1] = "ADDRESS=" + pre + t_ip + ":8080";
		}
		else
		{
			conf[4] = "PORT=" + t_port;
			conf[1] = "ADDRESS=" + pre + t_ip + ":" + t_port;
		}
		for (int j = 0; j < 5; j++)
		{
			out << conf[j] << std::endl;
		}
		out.close();
//	}
	is_use = true;	
//	MessageBox(URL);
	CDialogEx::OnOK();
}

std::string IpDlg::GetUrl()
{
	std::string m_url;
	m_url = (CStringA)URL;
	
	return m_url;
}

void IpDlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialog::OnCancel();
}


BOOL IpDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	std::ifstream in("config\\ini.txt");
	std::string temp;
	int i = 0;
	while (!in.eof())
	{
		getline(in, temp);
		conf[i] = temp;
		i++;
	}
	in.close();
	ADDRESS = conf[1].substr(8, conf[1].size()).c_str();
	IP = conf[3].substr(3, conf[3].size()).c_str();
	PORT = conf[4].substr(5, conf[4].size()).c_str();
	GetDlgItem(IDC_IPADDRESS)->SetWindowTextA(IP);
	GetDlgItem(IDC_EDIT_port)->SetWindowTextA(PORT);


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
