// Screenshot.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "Screenshot.h"
#include "ScreenshotDlg.h"
#include "CatchScreenDlg.h"
#include <GdiPlus.h>


using namespace Gdiplus;
#pragma comment(lib,"GdiPlus.lib")





#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define SHIFTED 0x8000 


// CScreenshotApp

BEGIN_MESSAGE_MAP(CScreenshotApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CScreenshotApp ����

CScreenshotApp::CScreenshotApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��

}


// Ψһ��һ�� CScreenshotApp ����

CScreenshotApp theApp;


// CScreenshotApp ��ʼ��

BOOL CScreenshotApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();
	
	GdiplusStartupInput input;
	GdiplusStartup(&m_gdiplusToken,&input,NULL);

	AfxEnableControlContainer();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CScreenshotDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

BOOL CScreenshotApp::ProcessMessageFilter(int code, LPMSG lpMsg) 
{
	if(m_hwndDlg != NULL)
	{
		// �����Ϣ�ǴӶԻ��򷢳��Ļ������ӿؼ�������,�ͽ��д���
		if((lpMsg->hwnd == m_hwndDlg) || ::IsChild(m_hwndDlg, lpMsg->hwnd))
		{
			// �����Ϣ��WM_KEYDOWN,�÷��������λ��
			if(lpMsg->message == WM_KEYDOWN)
			{
				CRect rect(0,0,0,0);
				CCatchScreenDlg * pDlg=(CCatchScreenDlg *)AfxGetMainWnd();

				rect = pDlg->m_rectTracker.m_rect;

				if(pDlg->m_bFirstDraw)
				{
					//���Shift�����������������С
					BOOL bIsShiftDown = FALSE;

					if (GetKeyState(VK_SHIFT) & SHIFTED) 
						bIsShiftDown = TRUE;

					////////////////////////////////////////////////////

					switch(lpMsg->wParam)
					{
					case VK_UP:

						//�������Shift,��ֻ����һ��
						if(!bIsShiftDown)
							rect.top-=1;

						rect.bottom-=1;
						pDlg->m_rectTracker.m_rect = rect;
						pDlg->InvalidateRgnWindow();
						break;

					case VK_DOWN:
						rect.top+=1;
						if(!bIsShiftDown)
							rect.bottom+=1;

						pDlg->m_rectTracker.m_rect=rect;
						pDlg->InvalidateRgnWindow();
						break;

					case VK_LEFT:
						if(!bIsShiftDown)
							rect.left-=1;
						rect.right-=1;

						pDlg->m_rectTracker.m_rect=rect;
						pDlg->InvalidateRgnWindow();
						break;

					case VK_RIGHT:
						rect.left+=1;
						if(!bIsShiftDown)
							rect.right+=1;

						pDlg->m_rectTracker.m_rect=rect;
						pDlg->InvalidateRgnWindow();
						break;
					}
				}
			}

		}
	} 

	return CWinApp::ProcessMessageFilter(code, lpMsg);
}
int CScreenshotApp::ExitInstance()
{
	GdiplusShutdown(m_gdiplusToken);

	return CWinApp::ExitInstance();
}
