// SMG.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "WebClient_CEF3.h"
#include "SMG.h"
#include "afxdialogex.h"


// SMG �Ի���

IMPLEMENT_DYNAMIC(SMG, CDialogEx)

SMG::SMG(CWnd* pParent /*=NULL*/)
	: CDialogEx(SMG::IDD, pParent)
{

}

SMG::~SMG()
{
}

SMG::SMG(CString s)
{
	filename = s;
}

void SMG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DSCOMPOSERPLAYERACTIVEXCTRL1, m_smg);
	DDX_Control(pDX, IDC_BUTTON_CLOSE, m_close);
}


BEGIN_MESSAGE_MAP(SMG, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &SMG::OnBnClickedButtonClose)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// SMG ��Ϣ�������


BOOL SMG::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//ȥ��������
	DWORD dwStyle = GetStyle();//��ȡ����ʽ    
	DWORD dwNewStyle = WS_OVERLAPPED | WS_VISIBLE | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
	dwNewStyle &= dwStyle;//��λ�뽫����ʽȥ��    
	SetWindowLong(m_hWnd, GWL_STYLE, dwNewStyle);//���ó��µ���ʽ    
	DWORD dwExStyle = GetExStyle();//��ȡ����չ��ʽ    
	DWORD dwNewExStyle = WS_EX_LEFT | WS_EX_LTRREADING | WS_EX_RIGHTSCROLLBAR;
	dwNewExStyle &= dwExStyle;//��λ�뽫����չ��ʽȥ��    
	SetWindowLong(m_hWnd, GWL_EXSTYLE, dwNewExStyle);//�����µ���չ��ʽ    
	SetWindowPos(&wndNoTopMost, 0, 0, 0, 0, SWP_NOZORDER | SWP_NOMOVE | SWP_NOSIZE | SWP_FRAMECHANGED);
	//
	AdjustControl();

	m_close.SetWindowPos(&wndTopMost, 0, 0, 24, 24, SWP_NOZORDER | SWP_NOMOVE);//�趨��С
	m_close.LoadStdImage(IDB_PNG_PLAYERCLOSE, _T("PNG"));
	m_close.EnableToggle(TRUE);
//	CString s = "lg.smg";
	m_smg.SetFileName(TEXT(filename));



	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void SMG::OnBnClickedButtonClose()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	PostMessage(WM_CLOSE, 0, 0);
}


void SMG::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO:  �ڴ˴������Ϣ����������
	if (nType == 1) return; //��С����ʲô������ 

	//	ChangeSize(pWnd, cx, cy); //����changesize()����
	
}

void SMG::AdjustControl()
{
	int cx = GetSystemMetrics(SM_CXSCREEN);
	int cy = GetSystemMetrics(SM_CYSCREEN);
	//	CWnd::SetWindowPos(NULL, 110, 110, cx * 0.7, cy * 0.7, SWP_NOZORDER);
	//CWnd::SetWindowPos(NULL, width - width * 0.6, height - height * 0.5, width, height, SWP_NOZORDER);
	CWnd::SetWindowPos(NULL, cx - cx * 0.75, cy - cy * 0.7, cx * 0.7, cy * 0.7, SWP_NOZORDER);
//	CWnd::SetWindowPos(NULL, 0, cy - cy * 0.7, cx * 0.7, cy * 0.7, SWP_NOZORDER);
	m_smg.MoveWindow(0, 0, cx * 0.7, cy * 0.7);
	RECT rect;
	GetClientRect(&rect);
	m_close.SetWindowPos(NULL, rect.right - 40, 5, 0, 0, SWP_SHOWWINDOW | SWP_NOSIZE);
}

void SMG::ChangeSize(CWnd * pWnd, int cx, int cy)
{
	if (pWnd)
	{
		CRect rect;
		pWnd->GetWindowRect(&rect);
		ScreenToClient(&rect);
		rect.left = rect.left*cx / m_rect.Width();//�����ؼ���С ��cx/m_rect.Width()Ϊ�Ի����ں���ı仯����
		rect.right = rect.right*cx / m_rect.Width(); //cx�洢���Ǳ仯��Ŀ�ȣ�cy�洢���Ǳ仯��ĸ߶�
		rect.top = rect.top*cy / m_rect.Height(); //m_rect.height()��ʾ���Ǳ仯ǰ������ĸ߶�
		rect.bottom = rect.bottom*cy / m_rect.Height();
		pWnd->MoveWindow(rect);
	}


	// TODO: �ڴ˴������Ϣ����������
}