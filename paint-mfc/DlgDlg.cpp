// DlgDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Dlg.h"
#include "DlgDlg.h"
#include "afxcolorbutton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////

CDlgDlg::CDlgDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgDlg::IDD, pParent)
{
	futureFigKIND=RECTANGLE;
	f=NULL;
	index=-1;
	isPressed=false;
	isReset=false;
	Brush=RGB(255,0,0);
	Pen=RGB(0,0,255);
	//{{AFX_DATA_INIT(CDlgDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDlgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgDlg)
	// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_MFCCOLORBUTTON2, cBrush);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, cPen);
}

BEGIN_MESSAGE_MAP(CDlgDlg, CDialog)
	//{{AFX_MSG_MAP(CDlgDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_FILE_SAVE32777, &CDlgDlg::OnFileSave)
	ON_COMMAND(ID_FILE_LOAD32778, &CDlgDlg::OnFileLoad)
	ON_COMMAND(ID_EDIT_UNDO32773, &CDlgDlg::OnEditUndo)
	ON_COMMAND(ID_EDIT_REDO32774, &CDlgDlg::OnEditRedo)
	ON_COMMAND(ID_ABOUT_ABOUTTHEPROJECT, &CDlgDlg::OnAboutAbout)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON2, &CDlgDlg::OnBnClickedMfccolorbutton2)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON1, &CDlgDlg::OnBnClickedMfccolorbutton1)
	ON_COMMAND(ID_SHAPESELECTION_RECTANGLE, &CDlgDlg::OnShapeselectionRectangle)
	ON_COMMAND(ID_SHAPESELECTION_SQUARE, &CDlgDlg::OnShapeselectionSquare)
	ON_COMMAND(ID_SHAPESELECTION_PARALLELOGRAM, &CDlgDlg::OnShapeselectionParallelogram)
	ON_COMMAND(ID_SHAPESELECTION_ELLIPSE, &CDlgDlg::OnShapeselectionEllipse)
	ON_COMMAND(ID_SHAPESELECTION_CIRCLE, &CDlgDlg::OnShapeselectionCircle)
	ON_COMMAND(ID_SHAPESELECTION_RIGHTTRIANGLE, &CDlgDlg::OnShapeselectionRighttriangle)
	ON_BN_CLICKED(IDC_BUTTON3, &CDlgDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CDlgDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_RADIO1, &CDlgDlg::OnShapeRadioBn)
	ON_BN_CLICKED(IDC_RADIO2, &CDlgDlg::OnSelectRadioBn)
	ON_BN_CLICKED(IDC_RADIO3, &CDlgDlg::OnCopyRadioBn)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgDlg message handlers

BOOL CDlgDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	CheckRadioButton(IDC_RADIO1,IDC_RADIO3,NULL);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDlgDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDlgDlg::OnPaint() 
{
	CPaintDC dc (this);
	CBrush myBrush,*oldBrush;
		myBrush.CreateSolidBrush(Brush);
		oldBrush=dc.SelectObject( &myBrush );

		CPen myPen1(PS_SOLID, 3, Pen);
		CPen *oldPen;
		oldPen=dc.SelectObject( &myPen1 ); 

	for(int i=0;i<figs.GetSize();i++)
		figs[i]->Draw(&dc);
	dc.SelectObject( oldPen ); 
		dc.SetROP2(R2_COPYPEN);  
		dc.SelectObject( oldBrush ); 
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDlgDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

int CDlgDlg::Find(CPoint point)
{
	for(int i=0;i<figs.GetSize();i++)
	{
		if(( figs[i]->x2>= figs[i]->x1) &&  (figs[i]->y2>= figs[i]->y1))
		{
			if (((point.x >= figs[i]->x1) && (point.x <= figs[i]->x2) ) && 
				((point.y >= figs[i]->y1) && (point.y <= figs[i]->y2) )) 
					return i;	
		}

		else if  (( figs[i]->x2>= figs[i]->x1) &&  (figs[i]->y2<= figs[i]->y1)) 
		{
			if	 (((point.x >= figs[i]->x1) && (point.x <= figs[i]->x2) ) && 
					((point.y <= figs[i]->y1) && (point.y >= figs[i]->y2) )) 
					return i;
		}
		else if(( figs[i]->x2<= figs[i]->x1) &&  (figs[i]->y2>= figs[i]->y1)) 
		{
			 if (((point.x <= figs[i]->x1) && (point.x >= figs[i]->x2) ) && 
				((point.y >= figs[i]->y1) && (point.y <= figs[i]->y2) )) 
					return i;
		}
		else if(( figs[i]->x2<= figs[i]->x1) &&  (figs[i]->y2<= figs[i]->y1)) 
		{
			 if (((point.x <= figs[i]->x1) && (point.x >= figs[i]->x2) ) && 
				((point.y <= figs[i]->y1) && (point.y >= figs[i]->y2) )) 
					return i;
		}

	}
	return -1;
}

void CDlgDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(select)
	{
	 index=Find(point);
		if(index!=-1)
		lastPoint=point;
	}
	else if(copy)
	{
		index=Find(point);
		if(index!=-1)
		lastPoint=point;
	}
	else if(shape)
	{
		isReset=false;
		 endP=startP=point;
	    	isPressed=true;
	}
	CDialog::OnLButtonDown(nFlags, point);
}

void CDlgDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	int diffx,diffy;
	if(select)
	{
		if(index!=-1)
		{
			if(lastPoint.x>point.x)
				diffx=abs(lastPoint.x-point.x)*(-1);
			else
				diffx=abs(lastPoint.x-point.x);
			if(lastPoint.y>point.y)
				diffy=abs(lastPoint.y-point.y)*(-1);
			else
				diffy=abs(lastPoint.y-point.y);
		figs[index]->x1+=diffx;
		figs[index]->x2+=diffx;
		figs[index]->y1+=diffy;
		figs[index]->y2+=diffy;
		Invalidate();
		index=-1;
		}
	}
	else if(shape)
	{
	if(isPressed)
	{

		endP=point;
		isPressed=false;
	
		switch(futureFigKIND)
		{
		case RECTANGLE:
			    
			figs.Add(new RectangleM(startP.x,startP.y,endP.x,endP.y,Pen,Brush));
			ur.addNew(figs[figs.GetSize()-1]);
			break;
		case SQUARE:
			figs.Add(new SquareM(startP.x,startP.y,endP.x,endP.y,Pen,Brush));
			ur.addNew(figs[figs.GetSize()-1]);
			break;
		case ELLIPSE:
			    
			figs.Add(new EllipseM(startP.x,startP.y,endP.x,endP.y,Pen,Brush));
			ur.addNew(figs[figs.GetSize()-1]);
			break;
		case CIRCLE:
			figs.Add(new CircleM(startP.x,startP.y,endP.x,endP.y,Pen,Brush));
			ur.addNew(figs[figs.GetSize()-1]);
			break;
		case PARALLELOGRAM:
			figs.Add(new ParallelogramM(startP.x,startP.y,endP.x,endP.y,Pen,Brush));
			ur.addNew(figs[figs.GetSize()-1]);
			break;
		case RIGHTTRIANGLE:
			figs.Add(new RightTriangleM(startP.x,startP.y,endP.x,endP.y,Pen,Brush));
			ur.addNew(figs[figs.GetSize()-1]);
			break;
		}
		Invalidate();
	}
	}
	else if(copy)
	{
     if(index!=-1)
		{
			if(lastPoint.x>point.x)
				diffx=abs(lastPoint.x-point.x)*(-1);
			else
				diffx=abs(lastPoint.x-point.x);
			if(lastPoint.y>point.y)
				diffy=abs(lastPoint.y-point.y)*(-1);
			else
				diffy=abs(lastPoint.y-point.y);
	    switch(futureFigKIND)
		{
		case RECTANGLE:
			    
			figs.Add(new RectangleM(figs[index]->x1,figs[index]->y1,figs[index]->x2,figs[index]->y2,figs[index]->penColor,figs[index]->brushColor));
			ur.addNew(figs[figs.GetSize()-1]);
			break;
		case SQUARE:
			figs.Add(new SquareM(figs[index]->x1,figs[index]->y1,figs[index]->x2,figs[index]->y2,figs[index]->penColor,figs[index]->brushColor));
			ur.addNew(figs[figs.GetSize()-1]);
			break;
		case ELLIPSE:
			    
			figs.Add(new EllipseM(figs[index]->x1,figs[index]->y1,figs[index]->x2,figs[index]->y2,figs[index]->penColor,figs[index]->brushColor));
			ur.addNew(figs[figs.GetSize()-1]);
			break;
		case CIRCLE:
			figs.Add(new CircleM(figs[index]->x1,figs[index]->y1,figs[index]->x2,figs[index]->y2,figs[index]->penColor,figs[index]->brushColor));
			ur.addNew(figs[figs.GetSize()-1]);
			break;
		case PARALLELOGRAM:
			figs.Add(new ParallelogramM(figs[index]->x1,figs[index]->y1,figs[index]->x2,figs[index]->y2,figs[index]->penColor,figs[index]->brushColor));
			ur.addNew(figs[figs.GetSize()-1]);
			break;
		case RIGHTTRIANGLE:
			figs.Add(new RightTriangleM(figs[index]->x1,figs[index]->y1,figs[index]->x2,figs[index]->y2,figs[index]->penColor,figs[index]->brushColor));
			ur.addNew(figs[figs.GetSize()-1]);
			break;
		}
		figs[index]->x1+=diffx;
		figs[index]->x2+=diffx;
		figs[index]->y1+=diffy;
		figs[index]->y2+=diffy;
		Invalidate();
		index=-1;
		}
	}
	CDialog::OnLButtonUp(nFlags, point);
}

void CDlgDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
    if(isPressed)
	{
		CClientDC dc(this);
		CBrush *oldBrush;
		CPen *oldPen;
		CBrush myBrush;
		CPoint p[4];
		CPoint pts[3];
		myBrush.CreateSolidBrush(Brush);
		oldBrush=dc.SelectObject( &myBrush );

		CPen myPen1(PS_SOLID, 3, Pen);
		oldPen=dc.SelectObject( &myPen1 ); 
		dc.SetROP2(R2_NOTXORPEN); 
		switch(futureFigKIND)
		{
		case RECTANGLE:
			dc.Rectangle(startP.x, startP.y,endP.x, endP.y);
			endP=point;
			dc.Rectangle(startP.x, startP.y,endP.x, endP.y);
			break;
		case SQUARE:
			
			if(abs(endP.x-startP.x)==abs(endP.y-startP.y))
			dc.Rectangle(startP.x,startP.y,endP.x,endP.y);
			else
			{
				if((abs(endP.x-startP.x)>abs(endP.y-startP.y)))
				{
					endP.x=startP.x+abs(endP.y-startP.y);
				}
				else
				{
					endP.y=startP.y+abs(endP.x-startP.x);
				}
				dc.Rectangle(startP.x,startP.y,endP.x,endP.y);
			}
			endP=point;
			
			if(abs(endP.x-startP.x)==abs(endP.y-startP.y))
			dc.Rectangle(startP.x,startP.y,endP.x,endP.y);
			else
			{
				if((abs(endP.x-startP.x)>abs(endP.y-startP.y)))
				{
					endP.x=startP.x+abs(endP.y-startP.y);
				}
				else
				{
					endP.y=startP.y+abs(endP.x-startP.x);
				}
				dc.Rectangle(startP.x,startP.y,endP.x,endP.y);
			}
			break;
		case ELLIPSE:
			dc.Ellipse(startP.x, startP.y,endP.x, endP.y);
			endP=point;
			dc.Ellipse(startP.x, startP.y,endP.x, endP.y);
			break;
		case CIRCLE:
			if(abs(endP.x-startP.x)==abs(endP.y-startP.y))
			dc.Ellipse(startP.x,startP.y,endP.x,endP.y);
			else
			{
				if((abs(endP.x-startP.x)>abs(endP.y-startP.y)))
				{
					endP.x=startP.x+abs(endP.y-startP.y);
				}
				else
				{
					endP.y=startP.y+abs(endP.x-startP.x);
				}
				dc.Ellipse(startP.x,startP.y,endP.x,endP.y);
			}
				endP=point;
				if(abs(endP.x-startP.x)==abs(endP.y-startP.y))
				dc.Ellipse(startP.x,startP.y,endP.x,endP.y);
			else
			{
				if((abs(endP.x-startP.x)>abs(endP.y-startP.y)))
				{
					endP.x=startP.x+abs(endP.y-startP.y);
				}
				else
				{
					endP.y=startP.y+abs(endP.x-startP.x);
				}
				dc.Ellipse(startP.x,startP.y,endP.x,endP.y);
			}
				break;
		case PARALLELOGRAM:
			int x3,x4,y3,y4;
		if(startP.x>endP.x)
		{
			p[0].x=startP.x;
			p[0].y=startP.y;
			p[2].x=endP.x;
			p[2].y=endP.y;
			p[1].x=startP.x-abs(startP.x-endP.x)/3;
			p[1].y=endP.y;
			p[3].x=endP.x+abs(startP.x-endP.x)/3;
			p[3].y=startP.y;
			
		}
		else
		{
			p[0].x=startP.x;
			p[0].y=startP.y;
			p[1].x=endP.x-abs(endP.x-startP.x)/3;
			p[1].y=startP.y;
			p[2].x=endP.x;
			p[2].y=endP.y;
			p[3].x=endP.x-2*abs(endP.x-startP.x)/3;
			p[3].y=endP.y;
		}

		dc.Polygon(p,4);
		endP=point;
		if(startP.x>endP.x)
		{
			p[0].x=startP.x;
			p[0].y=startP.y;
			p[2].x=endP.x;
			p[2].y=endP.y;
			p[1].x=startP.x-abs(startP.x-endP.x)/3;
			p[1].y=endP.y;
			p[3].x=endP.x+abs(startP.x-endP.x)/3;
			p[3].y=startP.y;
			
		}
		else
		{
			p[0].x=startP.x;
			p[0].y=startP.y;
			p[1].x=endP.x-abs(endP.x-startP.x)/3;
			p[1].y=startP.y;
			p[2].x=endP.x;
			p[2].y=endP.y;
			p[3].x=endP.x-2*abs(endP.x-startP.x)/3;
			p[3].y=endP.y;
		}
		dc.Polygon(p,4);
			break;
		case RIGHTTRIANGLE:
			int xx3=startP.x,yy3=endP.y;
		pts[0].x=startP.x;
		pts[0].y=startP.y;
		pts[1].x=endP.x;
		pts[1].y=endP.y;
		pts[2].x=xx3;
		pts[2].y=yy3;
		dc.Polygon(pts,3);
		endP=point;
		xx3=startP.x;
	    yy3=endP.y;
		pts[0].x=startP.x;
		pts[0].y=startP.y;
		pts[1].x=endP.x;
		pts[1].y=endP.y;
		pts[2].x=xx3;
		pts[2].y=yy3;
		dc.Polygon(pts,3);
			break;
		}

		dc.SelectObject( oldPen ); 
		dc.SetROP2(R2_COPYPEN);  
		dc.SelectObject( oldBrush ); 

	}
	CDialog::OnMouseMove(nFlags, point);
}


void CDlgDlg::OnFileSave()
{
	// TODO: Add your command handler code here
    CFile file(_T("File.$$"), CFile::modeWrite);
	CArchive ar (&file, CArchive::store);
	figs.Serialize(ar);
	ar.Close();
	file.Close();
}


void CDlgDlg::OnFileLoad()
{
	// TODO: Add your command handler code here
	CFile file(_T("File.$$"), CFile::modeRead);
	CArchive ar (&file, CArchive::load);
	figs.Serialize(ar);
	ar.Close();
	file.Close();
	Invalidate();
}

void CDlgDlg::OnEditUndo()
{
	if(isReset)
	{
      MessageBox(_T("Cannot Undo,the reset was pressed"), _T("Error"), 
      MB_ICONERROR | MB_OK);
	}
	else
	if(!(ur.uIsEmpty()))
	{
	ur.Delete();
    figs.RemoveAt(figs.GetSize()-1);
    Invalidate();
	}
	else
		MessageBox(_T("Cannot Undo,the undo stack is empty"), _T("Error"), 
      MB_ICONERROR | MB_OK);
}


void CDlgDlg::OnEditRedo()
{
	if(!(ur.rIsEmpty()))
	{
	figs.Add(ur.top());
	ur.DeleteR();
	Invalidate();
	}
	else
		MessageBox(_T("Cannot redo,the redo stack is empty"), _T("Error"), 
      MB_ICONERROR | MB_OK);
}


void CDlgDlg::OnAboutAbout()
{
	// TODO: Add your command handler code here
	CAboutDlg dlgAbout;
    dlgAbout.DoModal();
}

void CDlgDlg::OnBnClickedMfccolorbutton2()
{
	// TODO: Add your control notification handler code here
	Brush=cBrush.GetColor();
}


void CDlgDlg::OnBnClickedMfccolorbutton1()
{
	// TODO: Add your control notification handler code here
	Pen=cPen.GetColor();
}


void CDlgDlg::OnShapeselectionRectangle()
{
	// TODO: Add your command handler code here
	futureFigKIND=RECTANGLE;
}


void CDlgDlg::OnShapeselectionSquare()
{
	// TODO: Add your command handler code here
	futureFigKIND=SQUARE;
}


void CDlgDlg::OnShapeselectionParallelogram()
{
	// TODO: Add your command handler code here
	futureFigKIND=PARALLELOGRAM;
}


void CDlgDlg::OnShapeselectionEllipse()
{
	// TODO: Add your command handler code here
	futureFigKIND=ELLIPSE;
}


void CDlgDlg::OnShapeselectionCircle()
{
	// TODO: Add your command handler code here
	futureFigKIND=CIRCLE;
}


void CDlgDlg::OnShapeselectionRighttriangle()
{
	// TODO: Add your command handler code here
	futureFigKIND=RIGHTTRIANGLE;
}


void CDlgDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	isReset=true;
	for(int i=0;i<figs.GetSize();i++)
	{
		ur.addNew(figs[i]);
		ur.Delete();
	}
	figs.RemoveAll();
	Invalidate();
}


void CDlgDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	
	while(!(ur.rIsEmpty()))
	{
	figs.Add(ur.top());
	ur.DeleteR();
	Invalidate();
	}
}


void CDlgDlg::OnShapeRadioBn()
{
	// TODO: Add your control notification handler code here
	shape=true;
	select=false;
	copy=false;
}


void CDlgDlg::OnSelectRadioBn()
{
	// TODO: Add your control notification handler code here
	select=true;
	shape=false;
	copy=false;
}


void CDlgDlg::OnCopyRadioBn()
{
	// TODO: Add your control notification handler code here
	select=false;
	shape=false;
	copy=true;
}
