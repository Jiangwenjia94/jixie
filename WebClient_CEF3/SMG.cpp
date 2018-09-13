// SMG.cpp : 实现文件
//

#include "stdafx.h"
#include "WebClient_CEF3.h"
#include "SMG.h"
#include "afxdialogex.h"


// SMG 对话框

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


// SMG 消息处理程序


BOOL SMG::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//去除标题栏
	DWORD dwStyle = GetStyle();//获取旧样式    
	DWORD dwNewStyle = WS_OVERLAPPED | WS_VISIBLE | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
	dwNewStyle &= dwStyle;//按位与将旧样式去掉    
	SetWindowLong(m_hWnd, GWL_STYLE, dwNewStyle);//设置成新的样式    
	DWORD dwExStyle = GetExStyle();//获取旧扩展样式    
	DWORD dwNewExStyle = WS_EX_LEFT | WS_EX_LTRREADING | WS_EX_RIGHTSCROLLBAR;
	dwNewExStyle &= dwExStyle;//按位与将旧扩展样式去掉    
	SetWindowLong(m_hWnd, GWL_EXSTYLE, dwNewExStyle);//设置新的扩展样式    
	SetWindowPos(&wndNoTopMost, 0, 0, 0, 0, SWP_NOZORDER | SWP_NOMOVE | SWP_NOSIZE | SWP_FRAMECHANGED);
	//
	AdjustControl();

	m_close.SetWindowPos(&wndTopMost, 0, 0, 24, 24, SWP_NOZORDER | SWP_NOMOVE);//设定大小
	m_close.LoadStdImage(IDB_PNG_PLAYERCLOSE, _T("PNG"));
	m_close.EnableToggle(TRUE);
//	CString s = "lg.smg";
	m_smg.SetFileName(TEXT(filename));



	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void SMG::OnBnClickedButtonClose()
{
	// TODO:  在此添加控件通知处理程序代码
	PostMessage(WM_CLOSE, 0, 0);
}


void SMG::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO:  在此处添加消息处理程序代码
	if (nType == 1) return; //最小化则什么都不做 

	//	ChangeSize(pWnd, cx, cy); //调用changesize()函数
	
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
		rect.left = rect.left*cx / m_rect.Width();//调整控件大小 ，cx/m_rect.Width()为对话框在横向的变化比例
		rect.right = rect.right*cx / m_rect.Width(); //cx存储的是变化后的宽度，cy存储的是变化后的高度
		rect.top = rect.top*cy / m_rect.Height(); //m_rect.height()表示的是变化前主窗体的高度
		rect.bottom = rect.bottom*cy / m_rect.Height();
		pWnd->MoveWindow(rect);
	}


	// TODO: 在此处添加消息处理程序代码
}