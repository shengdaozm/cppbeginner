// ScreenshotDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Screenshot.h"
#include "ScreenshotDlg.h"

#include "CatchScreenDlg.h"


#ifdef _DEBUG
//#define new DEBUG_NEW
#endif


// CScreenshotDlg �Ի���


CScreenshotDlg::CScreenshotDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CScreenshotDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CScreenshotDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CScreenshotDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_START, &CScreenshotDlg::OnBnClickedBtnStart)
	ON_WM_CTLCOLOR()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CScreenshotDlg ��Ϣ�������

BOOL CScreenshotDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	// ʹ���������
	::SetWindowPos(GetSafeHwnd(), HWND_TOPMOST, 150, 150, 0, 0, 
		SWP_NOMOVE|SWP_NOSIZE|SWP_NOREDRAW);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CScreenshotDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CScreenshotDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//----------------------------------------------------------------------
// �̺߳���,������ͼ
//
UINT SccreenShot_Thread (LPVOID lpParam)
{
	HWND hWndMain = (HWND) lpParam;
	CCatchScreenDlg dlg;
	dlg.DoModal();

	::ShowWindow(hWndMain,SW_SHOW);
	return 0;
}

void CScreenshotDlg::OnBnClickedBtnStart()
{
	::ShowWindow (m_hWnd, SW_HIDE);
	//ʹ�ñ�����ڳ�����ǰ��           
	::AfxBeginThread (SccreenShot_Thread, (LPVOID)GetSafeHwnd());
	//::ShowWindow (GetSafeHwnd(), SW_SHOW);
}

