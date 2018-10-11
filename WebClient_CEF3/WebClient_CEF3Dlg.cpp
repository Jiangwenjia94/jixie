
// WebClient_CEF3Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "WebClient.h"
#include "WebClient_CEF3.h"
#include "WebClient_CEF3Dlg.h"
#include "SmgPlayerDlg.h"
#include "afxdialogex.h"

#include <stdio.h>
#include <string>


#include "SMG.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;
// CWebClient_CEF3Dlg �Ի���

//struct SmgUrl
//{
//	string source_url;
//	string index;
//};
//
//DWORD WINAPI ComPlay(LPVOID lpParameter)
//{
//	SmgUrl *tmp = (SmgUrl*)lpParameter;
//	SmgPlayerDlg *smgDlg = new SmgPlayerDlg(tmp->source_url, tmp->index);
//	smgDlg->Create(IDD_DIALOG_SMGPLAYER);
//}

int TaskBarHeight()
{
	HWND hWnd = FindWindow("Shell_TrayWnd", NULL);//������״̬
	RECT rc;
	::GetWindowRect(hWnd, &rc);
	int task = rc.bottom - rc.top;

	int cy = GetSystemMetrics(SM_CYSCREEN);
	int fullcy = GetSystemMetrics(SM_CYFULLSCREEN);

	return cy - fullcy - task;
}

void CWebClient_CEF3Dlg::Config()
{
	ifstream in("config\\ini.txt");
	string temp;

	int i = 0;
	while (!in.eof())
	{
		getline(in, temp);
		conf[i] = temp;
		i++;
	}
	in.close();
	Address = conf[1].substr(8, conf[1].size());
	Title = conf[2].substr(6, conf[2].size());
	IP = conf[3].substr(3, conf[3].size());
	Port = conf[4].substr(5, conf[4].size());
}

HRESULT CWebClient_CEF3Dlg::OnHotKey(WPARAM wParam, LPARAM lParam)//ȫ�ֿ�ݼ�
{
	if (wParam == 199)
	{
		ip.DoModal();
		ip_url = ip.GetUrl();
		if (!ip_url.empty())
		{
			const CefString cefStrUrl(ip_url);
			m_cWebClient->GetBrowser()->GetMainFrame()->LoadURL(cefStrUrl);
		}

	//	CString s = "lg.smg";
		/*string s = "http://localhost:8080/SMG/smgplay.html";
		SmgPlayerDlg *smgDlg = new SmgPlayerDlg(s,Address);
		smgDlg->Create(IDD_DIALOG_SMGPLAYER);
		is_playing = true;*/
	//	PostMessage(WM_SYSCOMMAND, SC_MINIMIZE, 0);
	}
	return TRUE;
}

CWebClient_CEF3Dlg::CWebClient_CEF3Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CWebClient_CEF3Dlg::IDD, pParent)
{
//	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON_MAIN);
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON2);
	zoom = 0.0;
	is_playing = false;
	is_login = false;
	ip_url = "http://localhost:8080";
//	fullscreenclr = false;;
//	out.open("out.txt",ios::app | ios::out);
}

void CWebClient_CEF3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_MIN, m_min);
	DDX_Control(pDX, IDC_BUTTON_CLOSE, m_close);
	//  DDX_Control(pDX, IDC_BUTTON1, test_btn);
}

BEGIN_MESSAGE_MAP(CWebClient_CEF3Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
ON_WM_CREATE()
ON_WM_SIZE()
ON_WM_CLOSE()
ON_BN_CLICKED(IDOK, &CWebClient_CEF3Dlg::OnBnClickedOk)
ON_BN_CLICKED(IDC_BUTTON_MIN, &CWebClient_CEF3Dlg::OnBnClickedButtonMin)
ON_BN_CLICKED(IDC_BUTTON_CLOSE, &CWebClient_CEF3Dlg::OnBnClickedButtonClose)
ON_MESSAGE(WM_HOTKEY, OnHotKey)
ON_MESSAGE(WM_MYMSG, OnMsgHandler)
ON_MESSAGE(WM_MYMSG2, OnMsgHandler2)
ON_MESSAGE(WM_MYMSG_DOWNCP, OnMsgHandlerDown)
ON_MESSAGE(WM_MYMSG_SMG, OnMsgHandlerSmg)
ON_MESSAGE(WM_MYMSG_CLOSE, OnMsgHandlerClose)
ON_MESSAGE(WM_MYMSG_FULLSCREEN, OnMsgHandlerFullScreen)
ON_MESSAGE(WM_MYMSG_EXITFULLSCREEN, OnMsgHandlerExitFullScreen)
ON_MESSAGE(WM_MYMSG_CHECKFULLSCREEN, OnMsgHandlerCheckFullScreen)
ON_WM_SETTINGCHANGE()

//ON_WM_ERASEBKGND()
ON_WM_MOUSEWHEEL()
ON_WM_WININICHANGE()
ON_WM_DISPLAYCHANGE()
//ON_WM_MOUSEMOVE()
//ON_WM_LBUTTONDOWN()
//ON_WM_LBUTTONUP()
END_MESSAGE_MAP()


// CWebClient_CEF3Dlg ��Ϣ�������

BOOL CWebClient_CEF3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS);//�߽������ȼ�
	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	SetWindowText("CEF");
	Config();
	CString t_title(Title.c_str());//���ñ���
	SetWindowText(t_title);
	::RegisterHotKey(m_hWnd, 199, MOD_CONTROL, 'F');//ע���ݼ�ctrl F
	//
	

	//int cx = 0;
	//CWnd *task = FindWindow("Shell_TrayWnd", NULL);//������״̬
	//APPBARDATA state;
	//memset(&state, 0, sizeof(state));
	//state.cbSize = sizeof(state);
	//state.hWnd = FindWindow("Shell_TrayWnd", NULL)->GetSafeHwnd();
	//UINT uState = (UINT)SHAppBarMessage(ABM_GETSTATE, &state);
	//if (uState == 1)
	//{
		int cx = GetSystemMetrics(SM_CXFULLSCREEN);
		int cy = GetSystemMetrics(SM_CYFULLSCREEN);
		CWnd::SetWindowPos(NULL, 0, 0, cx * 0.5, cy * 0.5, SWP_NOZORDER | SWP_NOMOVE);
		CenterWindow();
	//}
	//else
	//{
	//	int cx = GetSystemMetrics(SM_CXFULLSCREEN);
	//	int cy = GetSystemMetrics(SM_CYFULLSCREEN);
	//	int mid = TaskBarHeight();
	//	CWnd::SetWindowPos(NULL, 0, 0, cx, cy + mid, SWP_NOZORDER);
	//}

	//
	RECT mrect;
	GetClientRect(&mrect);

	m_min.SetWindowPos(NULL, 0, 0, 0, 0,SWP_HIDEWINDOW);
	m_close.SetWindowPos(NULL, 0, 0, 0, 0, SWP_HIDEWINDOW);
//	m_min.SetWindowPos(NULL, mrect.right - 41, 5, 0, 0, SWP_SHOWWINDOW | SWP_NOSIZE | SWP_NOZORDER);//�趨λ��
//	m_min.SetWindowPos(NULL, 0, 0, 22, 22, SWP_NOZORDER | SWP_NOMOVE);//�趨��С
//	m_close.SetWindowPos(NULL, mrect.right - 16, 5, 0, 0, SWP_SHOWWINDOW | SWP_NOSIZE);
//	m_close.SetWindowPos(NULL, 0, 0, 22, 22, SWP_NOZORDER | SWP_NOMOVE);//�趨��С

//	out << "Oniti" << mrect.right - 41 << " " << cx << endl;
	/*CDC* pDC = GetDC();
	pDC->SetBkColor(RGB(0,0,255));
	m_close.SetBkGnd(pDC);*///����ͼ�������������֮ǰ������͸��PNGͼƬ��ʾ��ΪMFC�Ի�����ɫ
	/*m_close.LoadStdImage(IDB_PNG_CLOSE, _T("PNG"));
	m_close.EnableToggle(TRUE);
	m_min.LoadStdImage(IDB_PNG_MIN, _T("PNG"));
	m_min.EnableToggle(TRUE);*/



//	UINT A = WinExec("Wscript.exe Script\\ofv.vbs", SW_SHOWNORMAL);
	//ȡ��flash��˸��ʾno sandbox
	TCHAR app_path[MAX_PATH] = { 0 };
	GetModuleFileName(NULL, app_path, MAX_PATH);
	PathRemoveFileSpec(app_path);
	CString temp_a(app_path);
	CComBSTR temp_b(temp_a);
	std::wstring cmd_path(temp_b);
	cmd_path += L"\\cmd.exe";
	SetEnvironmentVariable("ComSpec", (LPSTR)cmd_path.c_str());
	HANDLE hCmd = CreateFile("cmd.exe", GENERIC_ALL, FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hCmd != INVALID_HANDLE_VALUE)
	{
		CloseHandle(hCmd);
		hCmd = NULL;
	}
	//ȡ��flash��˸��ʾno sandbox
	//ShowWindow(SW_MAXIMIZE);//ȫ����ʾ

	//ȥ��������
	//DWORD dwStyle = GetStyle();//��ȡ����ʽ    
	//DWORD dwNewStyle = WS_OVERLAPPED | WS_VISIBLE | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
	//dwNewStyle &= dwStyle;//��λ�뽫����ʽȥ��    
	//SetWindowLong(m_hWnd, GWL_STYLE, dwNewStyle);//���ó��µ���ʽ    
	//DWORD dwExStyle = GetExStyle();//��ȡ����չ��ʽ    
	//DWORD dwNewExStyle = WS_EX_LEFT | WS_EX_LTRREADING | WS_EX_RIGHTSCROLLBAR;
	//dwNewExStyle &= dwExStyle;//��λ�뽫����չ��ʽȥ��    
	//SetWindowLong(m_hWnd, GWL_EXSTYLE, dwNewExStyle);//�����µ���չ��ʽ    
	//SetWindowPos(NULL, 0, 0, 0, 0, SWP_NOZORDER | SWP_NOMOVE | SWP_NOSIZE | SWP_FRAMECHANGED);
	//

	
	//
	//
	RECT rect;
	GetClientRect(&rect);

	RECT rectnew = rect;
	rectnew.top = rect.top;
	rectnew.bottom = rect.bottom;
	rectnew.left = rect.left;
	rectnew.right = rect.right;
	

	CefWindowInfo info;
	CefBrowserSettings b_settings;
	CefRefPtr<ClientHandler> client(new ClientHandler);
	m_cWebClient = client.get();
	std::string site1 = "http://demo.itivy.com/html5-earth/index.html";
	std::string site2 = "https://www.bilibili.com/video/av31206450/?spm_id_from=333.334.home_popularize.2";
	std::string site3 = "chrome://version/";
	std::string site4 = "http://localhost:8080/ABC/index.html";
	std::string site5 = "https://www.youtube.com/watch?v=siOHh0uzcuY&html5=True";
	info.SetAsChild(GetSafeHwnd(), rectnew);
	CefBrowserHost::CreateBrowser(info, client.get(), Address, b_settings, NULL);
	string iip;
	string pt;
	int start = Address.find_last_of("/") + 1;
	int end = Address.find_last_of(":");
	iip = Address.substr(start,end - start);
	pt = Address.substr(end + 1);
	std::ofstream out("config\\ini.txt");
	conf[3] = "IP=" + iip;
	conf[4] = "PORT=" + pt;
	for (int j = 0; j < 5; j++)
	{
		out << conf[j] << std::endl;
	}
	out.close();

	client = NULL;//�ݶ�
	

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CWebClient_CEF3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		/*CPaintDC dc(this);
		CRect rect;
		GetClientRect(rect);
		dc.FillSolidRect(rect,RGB(255,255,255));*/
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CWebClient_CEF3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



int CWebClient_CEF3Dlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	
	return 0;
}


void CWebClient_CEF3Dlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	
	// TODO: �ڴ˴������Ϣ����������
	RECT rect;
	if (nType != SIZE_MINIMIZED)
	{
		GetClientRect(&rect);
		ScreenToClient(&rect);
		if (m_cWebClient.get())
		{
			// MessageBox(L"size");
			CefRefPtr<CefBrowser>browser = m_cWebClient->GetBrowser();
			if (browser)
			{
				CefWindowHandle hwnd = browser->GetHost()->GetWindowHandle();
				//   CWnd::SetWindowPos(NULL, 0, 0, rect.right - rect.left, rect.bottom, SWP_NOZORDER );
				::MoveWindow(hwnd, 0, 0, rect.right - rect.left, rect.bottom - rect.top, true);
			}
		}
	}
}


void CWebClient_CEF3Dlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//	DeleteFile("_mutex_o");
//	DeleteFile("_mutex_t");
	//if (m_cWebClient.get() && m_cWebClient)
	
	//m_cWebClient = NULL;
	//
	//CefShutdown();
//	WinExec("cmd /c taskkill /F /IM SOAR VR���ַ����ѧʵѵƽ̨.exe", SW_HIDE);
	CDialogEx::OnClose();
}


void CWebClient_CEF3Dlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	//CefQuitMessageLoop();
}


void CWebClient_CEF3Dlg::OnBnClickedButtonMin()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	PostMessage(WM_SYSCOMMAND, SC_MINIMIZE, 0);
}


void CWebClient_CEF3Dlg::OnBnClickedButtonClose()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//_CrtDumpMemoryLeaks();
	//if (m_cWebClient->GetBrowser())
	//this->m_cWebClient->DoClose();

	//CWebClient_CEF3Dlg::OnClose()
	
	
		//MessageBox("1");
//	out.close();
	TerminateProcess(infoProcess.hProcess, 0);
	PostMessage(WM_CLOSE,0,0);
}

LRESULT CWebClient_CEF3Dlg::OnMsgHandler(WPARAM w, LPARAM l)//��½����
{

//	int cx = GetSystemMetrics(SM_CXFULLSCREEN);
//	int cy = GetSystemMetrics(SM_CYFULLSCREEN);
	int cx = GetSystemMetrics(SM_CXSCREEN);
	int cy = GetSystemMetrics(SM_CYSCREEN);
	//
	CWnd::SetWindowPos(NULL, 0,0 , cx*0.5, cy*0.5, SWP_NOZORDER | SWP_NOMOVE);
	CenterWindow();
//	CenterWindow();
	RECT rect;
	GetClientRect(&rect);
//	m_min.SetWindowPos(NULL, rect.right - 55, 5, 0, 0, SWP_SHOWWINDOW | SWP_NOSIZE | SWP_NOZORDER);//�趨λ��
//	m_close.SetWindowPos(NULL, rect.right - 30, 5, 0, 0, SWP_SHOWWINDOW | SWP_NOSIZE | SWP_NOZORDER);
//	out << "login" << rect.right - 55<< endl;
	Invalidate(false);
//	out << "login" << endl;
	is_login = true;
//	fullscreenclr = true;
	//	once = 0;
	return 0;
}
LRESULT CWebClient_CEF3Dlg::OnMsgHandler2(WPARAM w, LPARAM l)//ȫ��
{
//	out << "fullscreen" << endl;
//		out << "clr" << endl;
	CRect ClientRect;
	GetClientRect(ClientRect);
	int screenx = GetSystemMetrics(SM_CXSCREEN);
	if (ClientRect.right + 100 > screenx)
		return 0;
	CWnd *task = FindWindow("Shell_TrayWnd", NULL);//������״̬
	APPBARDATA state;
	memset(&state, 0, sizeof(state));
	state.cbSize = sizeof(state);
	state.hWnd = FindWindow("Shell_TrayWnd", NULL)->GetSafeHwnd();
	UINT uState = (UINT)SHAppBarMessage(ABM_GETSTATE, &state);
	//if (uState == 1)
	//{
	//	int cx = GetSystemMetrics(SM_CXSCREEN);
	//	int cy = GetSystemMetrics(SM_CYSCREEN);
	//	CWnd::SetWindowPos(NULL, 0, 0, cx, cy - 1, SWP_NOZORDER);//���е������ת��OnSizes
	//	//	out << "QP1" << endl;
	//}
	//else
	//{
	//	int cx = GetSystemMetrics(SM_CXFULLSCREEN);
	//	int cy = GetSystemMetrics(SM_CYFULLSCREEN);
	//	CWnd::SetWindowPos(NULL, 0, 0, cx, cy + TaskBarHeight(), SWP_NOZORDER);
	//	//	out << "QP2" << endl;
	//}
	ShowWindow(SW_MAXIMIZE);//ȫ����ʾ
	//

	RECT rect;
	GetClientRect(&rect);
//	m_min.SetWindowPos(NULL, rect.right - 55, 5, 0, 0, SWP_SHOWWINDOW | SWP_NOSIZE | SWP_NOZORDER);//�趨λ��
//	m_close.SetWindowPos(NULL, rect.right - 30, 5, 0, 0, SWP_SHOWWINDOW | SWP_NOSIZE);
	is_login = false;
	return 0;
}

LRESULT CWebClient_CEF3Dlg::OnMsgHandlerDown(WPARAM w, LPARAM l)//ͣ�� 
{
	MessageBox("������ɣ�");
	//	once = 0;
	return 0;
}

DWORD WINAPI CWebClient_CEF3Dlg::Observer(LPVOID P)
{
	Sleep(7000);
	CWebClient_CEF3Dlg *tmp = (CWebClient_CEF3Dlg *)P;
	HWND  hwnd = ::FindWindow(NULL, "SOARSOFTPlayer");
	if (NULL != hwnd)//����Ƿ���Դ�
	{
		HINSTANCE hDll = LoadLibrary(_T("user32.dll"));
		CString m_szStatus;
		if (NULL != hDll)
		{
			typedef BOOL(WINAPI *PROCISHUNGAPPWINDOW)(HWND);
			PROCISHUNGAPPWINDOW IsHungAppWindow = (PROCISHUNGAPPWINDOW)GetProcAddress(hDll, "IsHungAppWindow");
			if (IsHungAppWindow(hwnd))
			{
				m_szStatus = "��smg��unity3d�ļ�ʱ����һЩ���⣬������";
				TerminateProcess(tmp->infoProcess.hProcess, 0);
			}
			else
			{
				m_szStatus = "��������";
				return 0;
			}
			AfxMessageBox(m_szStatus);
		}
	}
}

LRESULT CWebClient_CEF3Dlg::OnMsgHandlerSmg(WPARAM w, LPARAM l)
{
	//
//	ofstream out;
//	out.open("out.txt", ios::app | ios::out);
	//
	string *rmsg = (string *)l;
	HWND  hwnd = ::FindWindow(NULL, "SOARSOFTPlayer");
	if (hwnd != NULL)
	{
		CString rm = rmsg->c_str();
		COPYDATASTRUCT cpd;
		cpd.dwData = 0;
		cpd.cbData = rm.GetLength();
		cpd.lpData = (void *)rm.GetBuffer(cpd.cbData);
		::SendMessage(hwnd, WM_COPYDATA, 0, (LPARAM)&cpd);
	}
	else
	{
	//	std::string site5 = "http://192.168.1.105:8087";

		memset(&infoStart, 0, sizeof(infoStart));
		infoStart.cb = sizeof(STARTUPINFO);
		CString player = "SOARSOFTPlayer.exe";
		CString cmdl;
		CString s = rmsg->c_str();
		CString addr = Address.c_str();
		if (ip.is_use)//�ù�
			addr = ip.GetUrl().c_str();
		cmdl = s + " " + addr;
//		out << cmdl << endl;
		
		//�����ӽ���
		CreateProcess(
						player.GetBuffer(), cmdl.GetBuffer(), NULL, NULL, FALSE,
						NORMAL_PRIORITY_CLASS,
						NULL, NULL, &infoStart,
						&infoProcess
				     );
		is_playing = true;
//		out.close();
	}
//	CreateThread(NULL, 0, Observer, this, NULL, NULL);
	return 0;
}

LRESULT CWebClient_CEF3Dlg::OnMsgHandlerClose(WPARAM w, LPARAM l)
{
	//	out.close();

	is_playing = false;
	TerminateProcess(infoProcess.hProcess, 0);
	return 0;
}
#include <fstream>
LRESULT CWebClient_CEF3Dlg::OnMsgHandlerCheckFullScreen(WPARAM w, LPARAM l)
{
	ofstream out;
	out.open("out.txt",ios::app);
	RECT rect;
	GetClientRect(&rect);
	out << rect.top << endl;
	out << rect.bottom << endl;
	out << rect.left << endl;
	out << rect.right<< endl;
	out.close();
	return 0;
}

void CWebClient_CEF3Dlg::OnSettingChange(UINT uFlags, LPCTSTR lpszSection)
{
	CDialogEx::OnSettingChange(uFlags, lpszSection);

	// TODO:  �ڴ˴������Ϣ����������
//	out << "OnSettingChange" << endl;
	if (!is_login)
	{
		CWnd *task = FindWindow("Shell_TrayWnd", NULL);//������״̬
		APPBARDATA state;
		memset(&state, 0, sizeof(state));
		state.cbSize = sizeof(state);
		state.hWnd = FindWindow("Shell_TrayWnd", NULL)->GetSafeHwnd();
		UINT uState = (UINT)SHAppBarMessage(ABM_GETSTATE, &state);
		if (uState == 1) //����������
		{
			/*int cx = GetSystemMetrics(SM_CXSCREEN);
			int cy = GetSystemMetrics(SM_CYSCREEN);
			CWnd::SetWindowPos(NULL, 0, 0, cx, cy - 1, SWP_NOZORDER);
			MessageBox("123");*/
			ShowWindow(SW_MAXIMIZE);//ȫ����ʾ
		}
		else //��ʾ������
		{
			int cx = GetSystemMetrics(SM_CXFULLSCREEN);
			int cy = GetSystemMetrics(SM_CYFULLSCREEN);
			int mid = TaskBarHeight();
			CWnd::SetWindowPos(NULL, 0, 0, cx, cy + mid, SWP_NOZORDER);
		}
	}
}


//void CWebClient_CEF3Dlg::OnBnClickedButton1()
//{
//	// TODO:  �ڴ���ӿؼ�֪ͨ����������
//	DeleteFile("_mutex_o");
//	remove("_mutex_t");
//}


//BOOL CWebClient_CEF3Dlg::OnEraseBkgnd(CDC* pDC)
//{
//	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
//	CRect rect;
//	GetClientRect(rect);
//
//	CMemDC pDevC(pDC, rect);
//
//	/////////////////////////////////////////////////////////////////////////////////
//	// just put something in the background - unrelated to GdipButton
//	/////////////////////////////////////////////////////////////////////////////////
//	SetButtonBackGrounds(pDevC);
//	return CDialogEx::OnEraseBkgnd(pDC);
//}

void ModifyZoom(CefRefPtr<CefBrowser> browser, double delta)
{
	browser->GetHost()->SetZoomLevel(browser->GetHost()->GetZoomLevel() + delta);
}

BOOL CWebClient_CEF3Dlg::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (nFlags == MK_CONTROL)
	{
		zoom += zDelta / 120;
		ModifyZoom(m_cWebClient->GetBrowser(), zoom);
	}
	return CDialogEx::OnMouseWheel(nFlags, zDelta, pt);
}


void CWebClient_CEF3Dlg::OnWinIniChange(LPCTSTR lpszSection)
{
	CDialogEx::OnWinIniChange(lpszSection);
//	out << "ini_change" << endl;
	// TODO:  �ڴ˴������Ϣ����������
}

void CWebClient_CEF3Dlg::OnDisplayChange(UINT nImageDepth, int cxScreen, int cyScreen)
{
	if (!is_login)
	{
		int width = GetSystemMetrics(SM_CXSCREEN);
		int height = GetSystemMetrics(SM_CYSCREEN) - 1;
//		out << "DisChange" << is_login << endl;
		CWnd::SetWindowPos(NULL, 0, 0, width, height, SWP_NOZORDER);

		RECT rect;
		GetClientRect(&rect);
//		m_min.SetWindowPos(NULL, rect.right - 55, 5, 0, 0, SWP_SHOWWINDOW | SWP_NOSIZE | SWP_NOZORDER);//�趨λ��
//		m_close.SetWindowPos(NULL, rect.right - 30, 5, 0, 0, SWP_SHOWWINDOW | SWP_NOSIZE);
	}
}

LRESULT CWebClient_CEF3Dlg::OnMsgHandlerFullScreen(WPARAM, LPARAM)
{
//	m_min.ShowWindow(FALSE);
//	m_close.ShowWindow(FALSE);
	return 0;
}

LRESULT CWebClient_CEF3Dlg::OnMsgHandlerExitFullScreen(WPARAM, LPARAM)
{
//	m_min.ShowWindow(TRUE);
//	m_close.ShowWindow(TRUE);
	return 0;
}

//void CWebClient_CEF3Dlg::OnMouseMove(UINT nFlags, CPoint point)
//{
//	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
//	static CPoint PrePoint = CPoint(0, 0);
//	if (MK_LBUTTON == nFlags)
//	{
//		if (point != PrePoint)
//		{
//			CPoint ptTemp = point - PrePoint;
//			CRect rcWindow;
//			GetWindowRect(&rcWindow);
//			rcWindow.OffsetRect(ptTemp.x, ptTemp.y);
//			MoveWindow(&rcWindow);
//			return;
//		}
//	}
//	PrePoint = point;
//	CDialog::OnMouseMove(nFlags, point);
//	CDialogEx::OnMouseMove(nFlags, point);
//
//}


//void CWebClient_CEF3Dlg::OnLButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
//	SetCapture();
//	CDialogEx::OnLButtonDown(nFlags, point);
//}

//void CWebClient_CEF3Dlg::OnLButtonUp(UINT nFlags, CPoint point)
//{
//	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
//	ReleaseCapture();
//	CDialogEx::OnLButtonUp(nFlags, point);
//}
