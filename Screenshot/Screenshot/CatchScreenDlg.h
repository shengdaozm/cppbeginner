#if !defined(AFX_CATCHSCREENDLG_H__536FDBC8_7DB2_4BEF_8943_70DBE8AD845F__INCLUDED_)
#define AFX_CATCHSCREENDLG_H__536FDBC8_7DB2_4BEF_8943_70DBE8AD845F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

//--------------------------------------------------------------------------
#include "Resource.h"
#include "MyEdit.h"

#ifndef MYTRACKER_
#include "MyTracker.h"
#endif

#include "MyToolBar.h"
//--------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////
// 
class CCatchScreenDlg : public CDialog
{
public:
	
	CCatchScreenDlg(CWnd* pParent = NULL);	
	
	enum { IDD = IDD_DIALOGFORIMG };
	CMyEdit	m_tipEdit;
	CMyToolBar m_toolBar;

public:
	
	int m_xScreen;
	int m_yScreen;
	

	BOOL m_bLBtnDown;

	BOOL m_bNeedShowMsg;            // ��ʾ��ȡ���δ�С��Ϣ
	BOOL m_bDraw;                   // �Ƿ�Ϊ��ȡ״̬
	BOOL m_bFirstDraw;              // �Ƿ�Ϊ�״ν�ȡ
	BOOL m_bQuit;                   // �Ƿ�Ϊ�˳�
	CPoint m_startPt;				// ��ȡ�������Ͻ�λ��
	
	CMyTracker m_rectTracker;       // ��Ƥ����
	CBrush   m_brush;			
    HCURSOR  m_hCursor;             // ���
	CBitmap* m_pBitmap;             // Edit�����ؼ��ı���λͼ
	HBITMAP m_hBitmap;
	
	CRgn m_rgn;						// ������������

public:
	HBITMAP CopyScreenToBitmap(LPRECT lpRect,BOOL bSave=FALSE);   /* �������浽λͼ */
	void UpdateTipString();                            //��ʾ������ʾ��Ϣ
	void DrawMessage(CRect &inRect,CDC * pDC);       //��ʾ��ȡ������Ϣ
	void InvalidateRgnWindow();                        //�ػ�����
	void UpdateMousePointRGBString();

	CString m_strRgb;
	CString m_strEditTip;

	void SetEidtWndText();
	CString GetEditText();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();
	virtual void OnCancel();

	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);


	DECLARE_MESSAGE_MAP()

	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
};

///////////////////////////////////////////////////////////////////////////////////////////

#endif 
