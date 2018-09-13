// SmgPlayerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "WebClient_CEF3.h"
#include "SmgPlayerDlg.h"
#include "afxdialogex.h"

#include <MsHTML.h>
#include <atlbase.h>
#include <comdef.h>
#include <string>
using namespace std;
// SmgPlayerDlg �Ի���

IMPLEMENT_DYNAMIC(SmgPlayerDlg, CDialogEx)

SmgPlayerDlg::SmgPlayerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(SmgPlayerDlg::IDD, pParent)
{
	r = 255;
	g = 255;
	b = 255;
	m_index = "http://www.baidu.com";
	m_url = "http://www.baidu.com";
	
}

SmgPlayerDlg::SmgPlayerDlg(string &Url, string &Index, CWnd* pParent) : CDialogEx(SmgPlayerDlg::IDD, pParent)
{
	if (Url.empty() || Index.empty())
	{
		m_index = "http://www.baidu.com";
		m_url = "http://www.baidu.com";
	}
	else{
		m_url = Url;
		m_index = Index;
	}
	
	r = 255;
	g = 255;
	b = 255;
	fir_loding = false;
	sen_loding = false;
//	out.open("out.txt", ios::app | ios::out);
}

SmgPlayerDlg::~SmgPlayerDlg()
{
}

void SmgPlayerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_3DVIAPLAYERACTIVEXCTRL1, smgPlayer);
	DDX_Control(pDX, IDC_EXPLORER1, m_ie);
	DDX_Control(pDX, IDC_BUTTON_CLOSE, m_close);
	DDX_Control(pDX, IDC_EXPLORER_PLAYER, m_ie_player);
}


BEGIN_MESSAGE_MAP(SmgPlayerDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &SmgPlayerDlg::OnBnClickedOk)
	ON_WM_SIZE()
	ON_WM_PAINT()
	ON_WM_CLOSE()
	ON_MESSAGE(WM_MYMSG_HOP, OnMsgHandlerHop)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &SmgPlayerDlg::OnBnClickedButtonClose)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// SmgPlayerDlg ��Ϣ�������


void SmgPlayerDlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


BOOL SmgPlayerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	SetWindowText("SOARSOFTPlayer");
	GetClientRect(&m_rect);
	CWnd *pWnd;
	pWnd = GetDlgItem(IDC_EXPLORER_PLAYER);
	pWnd->MoveWindow(m_rect);
	//ȥ��������
	//DWORD dwStyle = GetStyle();//��ȡ����ʽ    
	//DWORD dwNewStyle = WS_OVERLAPPED | WS_VISIBLE | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
	//dwNewStyle &= dwStyle;//��λ�뽫����ʽȥ��    
	//SetWindowLong(m_hWnd, GWL_STYLE, dwNewStyle);//���ó��µ���ʽ    
	//DWORD dwExStyle = GetExStyle();//��ȡ����չ��ʽ    
	//DWORD dwNewExStyle = WS_EX_LEFT | WS_EX_LTRREADING | WS_EX_RIGHTSCROLLBAR;
	//dwNewExStyle &= dwExStyle;//��λ�뽫����չ��ʽȥ��    
	//SetWindowLong(m_hWnd, GWL_EXSTYLE, dwNewExStyle);//�����µ���չ��ʽ    
	//SetWindowPos(&wndNoTopMost, 0, 0, 0, 0, SWP_NOZORDER | SWP_NOMOVE | SWP_NOSIZE | SWP_FRAMECHANGED);
	//
	//
	int cx = GetSystemMetrics(SM_CXSCREEN);
	int cy = GetSystemMetrics(SM_CYSCREEN);
	CWnd::SetWindowPos(&wndTop, cx * 0.23, cy * 0.3, cx * 0.75, cy * 0.68, SWP_SHOWWINDOW);
	//
	COleVariant vaUrl = _T(m_index.c_str());
//	COleVariant vaUrl = _T("http://192.168.1.101:8087");
//	COleVariant vaUrl = _T(m_index.c_str());
	m_ie.put_Silent(true);
//	::ShowWindow(m_ie.GetSafeHwnd(), SW_HIDE);
	m_ie.Navigate2(vaUrl, NULL, NULL, NULL, NULL);
//	out <<"��½��֤��"<<m_index.c_str() << endl;
	m_close.SetWindowPos(&wndTopMost, 0, 0, 24, 24, SWP_NOZORDER | SWP_NOMOVE);//�趨��С
	m_close.LoadStdImage(IDB_PNG_PLAYERCLOSE, _T("PNG"));
	m_close.EnableToggle(TRUE);
//	m_ie_player.MoveWindow(0, 0, 600, 900);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void SmgPlayerDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO:  �ڴ˴������Ϣ����������
	if (nType == 1) return; //��С����ʲô������ 
	CWnd *pWnd;
	pWnd = GetDlgItem(IDC_EXPLORER_PLAYER);
	if (pWnd)
	{
		CRect rect;
		GetClientRect(&rect);
	//	ScreenToClient(&rect);

		//rect.left = rect.left*cx / m_rect.Width();//�����ؼ���С
		//rect.right = rect.right*cx / m_rect.Width();
		//rect.top = rect.top*cy / m_rect.Height();
		//rect.bottom = rect.bottom*cy / m_rect.Height();
		pWnd->MoveWindow(rect);//���ÿؼ���С
	}
	GetClientRect(&m_rect);
}

void SmgPlayerDlg::AdjustControl()
{
	int cx = GetSystemMetrics(SM_CXSCREEN);
	int cy = GetSystemMetrics(SM_CYSCREEN);
//	CWnd::SetWindowPos(NULL, 110, 110, cx * 0.7, cy * 0.7, SWP_NOZORDER);
//CWnd::SetWindowPos(NULL, width - width * 0.6, height - height * 0.5, width, height, SWP_NOZORDER);
	CWnd::SetWindowPos(NULL, cx - cx * 0.75, cy - cy * 0.7, cx * 0.7, cy * 0.7, SWP_NOZORDER);
	m_ie_player.MoveWindow(0, 0, cx * 0.7, cy * 0.7);

	ShowWindow(SW_SHOW);
	RECT rect;
	GetClientRect(&rect);
	m_close.SetWindowPos(NULL, rect.right - 40, 5, 0, 0, SWP_SHOWWINDOW | SWP_NOSIZE);
}

void SmgPlayerDlg::ChangeSize(CWnd * pWnd, int cx, int cy)
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
}BEGIN_EVENTSINK_MAP(SmgPlayerDlg, CDialogEx)
ON_EVENT(SmgPlayerDlg, IDC_EXPLORER1, 259, SmgPlayerDlg::DocumentCompleteExplorer1, VTS_DISPATCH VTS_PVARIANT)
END_EVENTSINK_MAP()



void SmgPlayerDlg::DocumentCompleteExplorer1(LPDISPATCH pDisp, VARIANT* URL)
{
	// TODO:  �ڴ˴������Ϣ����������
//	MessageBox("1");
	int cx = GetSystemMetrics(SM_CXSCREEN) * 0.7;
	int cy = GetSystemMetrics(SM_CYSCREEN) * 0.7;

	IDispatch *pDisp2 = m_ie.get_Document();
	IHTMLDocument2* pDocument;
	IHTMLElementCollection* pCollection;
	pDisp2->QueryInterface(IID_IHTMLDocument2, (void**)&pDocument);
	HRESULT hr;
	hr = pDocument->get_all(&pCollection);

	width = 0;
	height = 0;
	IDispatchPtr disp;
	_variant_t index(0L, VT_I4);
	if (hr == S_OK)
	{
		IHTMLElement *pBody;
		pDocument->get_body(&pBody);
		pBody->get_offsetWidth(&width);
		pBody->get_offsetHeight(&height);
	}
	int zoom_x = 0;
	int zoom_y = 0;
	if (cx >= width)
		zoom_x = cx / width;
	else
		zoom_x = width / cx;

	if (cy >= height)
		zoom_y = cy / height;
	else
		zoom_y = height / cy;

	int zoom_xy = (zoom_x > zoom_y) ? zoom_x : zoom_y;
	int zoom = (10 - zoom_xy) * 8;
	CComVariant varZoom((int)zoom);
	
//	m_ie_player.ExecWB(OLECMDID_OPTICAL_ZOOM, OLECMDEXECOPT_DODEFAULT, &varZoom, NULL);
////	AdjustControl();
//	//��ť͸������
////	ShowWindow(SW_MAXIMIZE);
//	_variant_t color = NULL;
//	pDocument->get_bgColor(&color);
//	string str = (const char*)_bstr_t(color);
//	CString co = str.c_str();
//	sscanf_s(co, "#%2X%2X%2X", &r, &g, &b);
//	
//	Invalidate();	
//	
//	out << "jiazaiwanc" << endl;
	if (!fir_loding)
	{
		CString id = _T("account");
		CString text = _T("3dzhuanyong");
		SetWebEditText(id, text);
		id = _T("password");
		text = _T("3d111");
		SetWebEditText(id, text);

		CString ra_id = _T("manager");
		OnWebRadio(ra_id);
		CString login = _T("loginForSystem");
		OnWebClick(login);
//		out << "fir_loding" << endl;
		
	//����Զ���½��
	//VARIANT vt;
		if (!sen_loding)
		{
			
			COleVariant vaUrl = _T(m_url.c_str());
	//		MessageBox(_T(m_url.c_str()));
	//		out << "sen_loding" <<" "<<m_url.c_str() << endl;
			m_ie_player.Navigate2(vaUrl, NULL, NULL, NULL, NULL);
			/*try
			{
				m_ie_player.Navigate2(vaUrl, NULL, NULL, NULL, NULL);
			}
			catch (...)
			{
				MessageBox(_T("smg��Unity�ļ���ʧ�ܣ�"));
			}*/
			sen_loding = true;
		}
		fir_loding = true;
	}
	
}


void SmgPlayerDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	/*CRect rect;
	GetClientRect(rect);
	dc.FillSolidRect(rect, RGB(255, 255, 255));*/
	/*COLORREF rgb = RGB(r, g, b);
	CRect rect;
	GetClientRect(rect);
	dc.FillSolidRect(rect, rgb);*/
}


void SmgPlayerDlg::OnClose()
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
//	out.close();
	HWND  hwnd = AfxGetMainWnd()->m_hWnd;
	if (hwnd != NULL)
	{
		::SendMessage(hwnd, WM_MYMSG_CLOSE, 0, 0);
	}
	CDialogEx::OnClose();
}

LRESULT SmgPlayerDlg::OnMsgHandlerHop(WPARAM w, LPARAM l)//�Ѵ򿪶Ի�������µ���ת
{
	string *rmsg = (string *)l;
	VARIANT vt;
	COleVariant vaUrl = _T(rmsg->c_str());
	m_ie_player.Navigate2(vaUrl, &vt, &vt, &vt, &vt);
	return 0;
}

void SmgPlayerDlg::OnBnClickedButtonClose()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	PostMessage(WM_CLOSE, 0, 0);
}


HBRUSH SmgPlayerDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	UINT id = pWnd->GetDlgCtrlID();
	if (id == IDC_BUTTON_CLOSE)
	{
		//pDC->SetBkMode(TRANSPARENT);

		//CRect rc;
		//pWnd->GetWindowRect(&rc);
		//ScreenToClient(&rc);

		//CDC* dc = GetDC();

		////pDC->BitBlt(0, 0, rc.Width(), rc.Height(), dc, rc.left, rc.top, SRCCOPY);  //�Ѹ����ڱ���ͼƬ�Ȼ�����ť��
		//pDC->SetBkColor(RGB(0,0,255));
		//ReleaseDC(dc);

		//hbr = (HBRUSH) ::GetStockObject(NULL_BRUSH);
	}
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}


IDispatch* SmgPlayerDlg::GetHTMLElemCollDispatch(const CString& strID)
{
	HRESULT hr = S_OK;
	IDispatch* pDispath = NULL;
	IHTMLElement* pElem = NULL;

	pDispath = m_ie.get_Document();         //m_web��CExplorer Ҳ����webbrowser�ؼ�

	if (pDispath == NULL)
	{
		TRACE(L"pDispath = m_web.get_Document() = NULL");
	}

	IHTMLDocument2* pDoc = NULL;
	hr = pDispath->QueryInterface(IID_IHTMLDocument2, (void**)&pDoc);
	pDispath->Release();
	pDispath = NULL;

	if (pDoc == NULL || hr != S_OK)
	{
		TRACE(L"IHTMLDocument2 pDoc  NULL or hr != S_OK");
		return NULL;
	}

	IHTMLElementCollection* pColl = NULL;
	hr = pDoc->get_all(&pColl);
	pDoc->Release();
	pDoc = NULL;

	ASSERT(pColl != NULL);
	if (pColl == NULL || hr != S_OK)
	{
		TRACE(L"IHTMLElementCollection pColl = NULL or hr != S_OK");
		return NULL;
	}

	IDispatch* pDispath2 = NULL;

	VARIANT index = { 0 };
	V_VT(&index) = VT_I4;
	V_I4(&index) = 0;

	VARIANT varID = { 0 };
	VariantInit(&varID);
	varID.vt = VT_BSTR;

	varID.bstrVal = strID.AllocSysString();

	hr = pColl->item(varID, index, &pDispath2);
	pColl->Release();
	pColl = NULL;

	if (hr != S_OK)
	{
		TRACE(L"");
		pDispath2 = NULL;
	}

	return pDispath2;
}

IHTMLElement* SmgPlayerDlg::GetHTMLElement(const CString& strID)
{
	HRESULT hr = S_OK;
	IDispatch* pDispath = NULL;
	IHTMLElement* pElem = NULL;

	pDispath = GetHTMLElemCollDispatch(strID);

	if (pDispath != NULL)
	{
		hr = pDispath->QueryInterface(IID_IHTMLElement, (void**)&pElem); // ��ѯ��IID_IHTMLElement�Ľӿڣ�������ӿڷ��أ���������ִ��click ��������������

		if (hr != S_OK)
		{
			pElem = NULL;
		}
		pDispath->Release();

	}
	return pElem;
}

IHTMLSelectElement* SmgPlayerDlg::GetHTMLSelectElement(const CString& strID)
{
	HRESULT hr = S_OK;
	IDispatch* pDispath = NULL;
	IHTMLSelectElement* pSelectElem = NULL;

	pDispath = GetHTMLElemCollDispatch(strID);

	if (pDispath != NULL)
	{
		hr = pDispath->QueryInterface(IID_IHTMLSelectElement, (void**)&pSelectElem);
		if (hr != S_OK)
		{
			pSelectElem = NULL;
		}
		pDispath->Release();
	}

	return pSelectElem;
}


void SmgPlayerDlg::SetWebEditText(const CString& strID, const CString& strText)
{
	HRESULT hr = S_OK;
	IHTMLElement* pElem = NULL;
	pElem = GetHTMLElement(strID);
	if (pElem != NULL)
	{
		BSTR s = ::SysAllocString(L"value");
		VARIANT varValue;
		varValue.vt = VT_BSTR;
		varValue.bstrVal = (_bstr_t)strText;
		hr = pElem->setAttribute(s, varValue);
		//	hr = pElem->put_innerText(strText.AllocSysString());
		pElem->Release();
	}
	pElem = NULL;
}

void SmgPlayerDlg::OnWebClick(const CString& strID)
{
	HRESULT hr = S_OK;
	IHTMLElement* pElem = NULL;
	pElem = GetHTMLElement(strID);
	if (pElem != NULL)
	{
		hr = pElem->click();
		pElem->Release();
	}
	pElem = NULL;
}

void SmgPlayerDlg::OnWebSelect(const CString& strID, long lIndex)
{
	HRESULT hr = S_OK;
	IHTMLSelectElement* pSelectElem = NULL;
	pSelectElem = GetHTMLSelectElement(strID);
	if (pSelectElem != NULL)
	{
		hr = pSelectElem->put_selectedIndex(lIndex);
		pSelectElem->Release();
	}
	pSelectElem = NULL;
}

void SmgPlayerDlg::OnWebRadio(const CString& strID)
{
	HRESULT hr = S_OK;
	IHTMLElement* pElem = NULL;
	pElem = GetHTMLElement(strID);
	if (pElem != NULL)
	{
		hr = pElem->click();
		pElem->Release();
	}
	pElem = NULL;
}