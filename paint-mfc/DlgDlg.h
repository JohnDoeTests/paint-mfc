// DlgDlg.h : header file
//

#if !defined(AFX_DLGDLG_H__D02F91E6_1066_4AA4_AE0B_1D16C986AE2C__INCLUDED_)
#define AFX_DLGDLG_H__D02F91E6_1066_4AA4_AE0B_1D16C986AE2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDlgDlg dialog
#include <vector>
#include "Figure.h"
#include "UndoRedo1.cpp"
#include "afxcolorbutton.h"
using namespace std;
class CDlgDlg : public CDialog
{
	enum FIGURES{RECTANGLE,ELLIPSE,SQUARE,PARALLELOGRAM,CIRCLE,RIGHTTRIANGLE};
	int index;
	bool shape,select,copy;
	CPoint lastPoint;
	FIGURES futureFigKIND;
	COLORREF Pen,Brush;
	Figure *f;
	UndoRedo<Figure*> ur;
	CTypedPtrArray< CObArray, Figure*> figs;
	bool isPressed;
	bool isReset;
	CPoint startP;
	CPoint endP;
public:
	CDlgDlg(CWnd* pParent = NULL);	

// Dialog Data
	//{{AFX_DATA(CDlgDlg)
	enum { IDD = IDD_DLG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDlgDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnFileSave();
	afx_msg void OnFileLoad();
	afx_msg void OnEditUndo();
	afx_msg int Find(CPoint point);
	afx_msg void OnEditRedo();
	afx_msg void OnAboutAbout();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio5();
	CMFCColorButton cBrush;
	CMFCColorButton cPen;
	afx_msg void OnBnClickedMfccolorbutton2();
	afx_msg void OnBnClickedMfccolorbutton1();
	afx_msg void OnShapeselectionRectangle();
	afx_msg void OnShapeselectionSquare();
	afx_msg void OnShapeselectionParallelogram();
	afx_msg void OnShapeselectionEllipse();
	afx_msg void OnShapeselectionCircle();
	afx_msg void OnShapeselectionRighttriangle();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnShapeRadioBn();
	afx_msg void OnSelectRadioBn();
	afx_msg void OnCopyRadioBn();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGDLG_H__D02F91E6_1066_4AA4_AE0B_1D16C986AE2C__INCLUDED_)
