// Screenshot.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������

// CScreenshotApp:
// �йش����ʵ�֣������ Screenshot.cpp
//

class CScreenshotApp : public CWinApp
{
public:
	CScreenshotApp();

// ��д
	public:
	virtual BOOL InitInstance();


	HWND m_hwndDlg;
	virtual BOOL ProcessMessageFilter(int code, LPMSG lpMsg);

// ʵ��

	DECLARE_MESSAGE_MAP()
private:
	ULONG_PTR m_gdiplusToken;
public:
	virtual int ExitInstance();
};

extern CScreenshotApp theApp;