// LittleRabbitDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LittleRabbit.h"
#include "LittleRabbitDlg.h"
#include <Gdiplus.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CLittleRabbitDlg 对话框




CLittleRabbitDlg::CLittleRabbitDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLittleRabbitDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_LITRABBIT);
}

void CLittleRabbitDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLittleRabbitDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_DESTROY()

	ON_WM_NCPAINT()
	ON_BN_CLICKED(IDOK, &CLittleRabbitDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CLittleRabbitDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CLittleRabbitDlg 消息处理程序

BOOL CLittleRabbitDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	NotifyIconInit();
	
	mcstr = _T("123");

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CLittleRabbitDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CLittleRabbitDlg::OnPaint()
{
	CPaintDC dc(this); // 用于绘制的设备上下文
	if (IsIconic())
	{


		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		//dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
	CString str("etwewtwetwe");
	dc.TextOut(10,10,mcstr);
	dc.DrawIcon(30, 30, m_hIcon);
}

void CLittleRabbitDlg::OnNcPaint()
{
	CWindowDC dc(this);
	if ( GetSafeHwnd() == NULL ) return;
	CRect rtWnd, rtTitle, rtButtons;
	GetWindowRect(&rtWnd); 
	//绘制左边框
	CPoint point;
	point.x = 20;
	point.y = rtWnd.Height();
	dc.FillSolidRect(0, 23, point.x, point.y, RGB(10,10,10));

	dc.SetBkColor((DWORD)(0x10505050));
	dc.SetTextColor(RGB(0, 0, 255));
	CString str("etwewtwetwe");
	dc.TextOut(0,0,mcstr);

}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CLittleRabbitDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CLittleRabbitDlg::OnDestroy()
{
	CDialog::OnDestroy();
	NotifyRealse();
}

void CLittleRabbitDlg::NotifyIconInit()
{
	/* 托盘图标的初始化工作 ************************************************************************/
	//初始化 m_NotifyIconData 内存空间
	memset(&m_NotifyIconData, 0, sizeof(NOTIFYICONDATA));
	//使托盘中图标对应于本窗体,这样它便可以把托盘图标的事件发送给窗体程序
	m_NotifyIconData.hWnd = GetSafeHwnd();
	ASSERT(m_NotifyIconData.hWnd != NULL);
	//定托盘图标产生事件时候发出的事件
	m_NotifyIconData.uCallbackMessage = WM_NOTI;
	//填充结构体的大小
	m_NotifyIconData.cbSize = sizeof(NOTIFYICONDATA);
	//加载托盘图标(这里以默认的资源图标)
	m_NotifyIconData.hIcon = AfxGetApp()->LoadIcon(IDI_LITRABBIT);
	//设置鼠标移动到托盘图标时候的提示文字
	memcpy (m_NotifyIconData.szTip,L"小白兔",sizeof(L"小白兔"));
	//设置托盘图标的属性
	m_NotifyIconData.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
	//设置托盘图标的图标资源 ID
	m_NotifyIconData.uID = IDR_MAINFRAME;

	/* 显示托盘图标 *********************************************************************************/
	Shell_NotifyIcon(NIM_ADD, &m_NotifyIconData);
}

void CLittleRabbitDlg::NotifyRealse()
{
	Shell_NotifyIcon(NIM_DELETE, &m_NotifyIconData);
}
void CLittleRabbitDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//OnOK();
	mcstr = _T("OK");
	Invalidate();
}

void CLittleRabbitDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	//OnCancel();
	mcstr = _T("Cancel");
	Invalidate();
}
