// LittleRabbitDlg.h : 头文件
//

#pragma once

//消息定义
#define WM_NOTI (WM_USER+1)

// CLittleRabbitDlg 对话框
class CLittleRabbitDlg : public CDialog
{
// 构造
public:
	CLittleRabbitDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_LITTLERABBIT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	NOTIFYICONDATA m_NotifyIconData;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	afx_msg void OnDestroy();
};
