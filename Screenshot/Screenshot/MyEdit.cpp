/******************************************************************************
*  FileName        :   MyEdit.CPP
*  Author          :   Unknown
*  Mender          :   sudami
*  Time            :   2007/09/09
*  
*  Comment         :  
*--------------------------------------------------------
*         ��ͼ�����е�һ���ؼ���װ��.
*  ���ؼ��͸��������,������ʾ����ǰ��ͼ��һЩ��ʾ��Ϣ 
*--------------------------------------------------------
******************************************************************************/

#include "stdafx.h"
#include "MyEdit.h"
#include "resource.h"

///////////////////////////////////////////////////////////////////////////////
// ���캯������������
//
CMyEdit::CMyEdit()
{
	m_bMove=TRUE;
}

CMyEdit::~CMyEdit()
{

}

BEGIN_MESSAGE_MAP(CMyEdit, CEdit)
    /* 2��С��Ϣ */
	ON_WM_CREATE() 
	ON_WM_PAINT()
	ON_WM_SETFOCUS()
	/* 3������Ϣ */
	ON_WM_MOUSEMOVE()  
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
//
int CMyEdit::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CEdit::OnCreate(lpCreateStruct) == -1)
		return -1;
	return 0;
}


void CMyEdit::OnPaint()
{
	CPaintDC dc(this);

	CDC dcCompatible;
	dcCompatible.CreateCompatibleDC(&dc);

	dcCompatible.SetBkMode(TRANSPARENT);
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP_BK);
	dcCompatible.SelectObject(&bitmap);

	RECT rt = {5,5,0,0};
	RECT rtClient = {0};
	GetClientRect(&rtClient);
	rt.right = rtClient.right;
	rt.bottom = rtClient.bottom;

	CString str;
	GetWindowText(str);
	CFont font;
	CFont * pOldFont;
	font.CreatePointFont(90, _T("����"));
	pOldFont = dcCompatible.SelectObject(&font);
	dcCompatible.DrawText(str,&rt,DT_LEFT);
	dcCompatible.SelectObject(pOldFont);

	CRect rect;
	GetClientRect(&rect);
	dc.BitBlt(0,0,rect.Width(),rect.Height(),&dcCompatible,0,0,SRCCOPY);
}

/////////////////////////////////////////////////////////////////////////////
//              <��Ӧ WM_MOUSEMOVE ��Ϣ>
// ��QQ�Ľ�ͼ����Ч��,ֻҪ���Ų���ÿؼ�����,������ͱ任λ��
//
void CMyEdit::OnMouseMove(UINT nFlags, CPoint point) 
{	
	CEdit::OnMouseMove(nFlags, point);
	CRect rect;
	GetWindowRect(&rect);
	int xScreen = GetSystemMetrics(SM_CXSCREEN);
	if(m_bMove)
	{
		//�ƶ������Ͻ�
		MoveWindow(10,10,rect.Width(),rect.Height());
		m_bMove=FALSE;
	}
	else
	{
		//�ƶ������Ͻ�
		MoveWindow(xScreen-180,10,rect.Width(),rect.Height());
		m_bMove=TRUE;
	}
}

/////////////////////////////////////////////////////////////////////////////
//
void CMyEdit::OnSetFocus(CWnd* pOldWnd) 
{
	CEdit::OnSetFocus(pOldWnd);

	// ���ع����ʾ��
	this->HideCaret();
}

BOOL CMyEdit::OnEraseBkgnd(CDC* pDC) 
{
	return TRUE;
}
