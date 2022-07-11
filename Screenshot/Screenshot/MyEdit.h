/*****************************************************************************
*  FileName        :   MyEdit.h
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

#if !defined(AFX_MYEDIT_H__A34EEA6D_E8FC_4D15_B03C_BAA42FDF6FCB__INCLUDED_)
#define AFX_MYEDIT_H__A34EEA6D_E8FC_4D15_B03C_BAA42FDF6FCB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif

//-----------------------------------------------------------------------------

#include <afxwin.h>

//-----------------------------------------------------------------------------

class CMyEdit : public CEdit
{
public:
	CMyEdit();
	virtual ~CMyEdit();
	
	BOOL m_bMove;      // ����"����˫������"

protected:
	
	afx_msg int     OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void    OnSetFocus(CWnd* pOldWnd);

	afx_msg void	OnPaint();

	afx_msg void    OnMouseMove(UINT nFlags, CPoint point);

	afx_msg BOOL    OnEraseBkgnd(CDC* pDC);

	DECLARE_MESSAGE_MAP()
};

//////////////////////////////////////////////////////////////////////////////////

#endif 