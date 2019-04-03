#pragma once  
#include <cmath>

          
class Figure: public CObject 
{
	
	DECLARE_SERIAL (Figure)       
public:
	void Serialize (CArchive& ar)
	{
		CObject::Serialize (ar);
		if (ar.IsStoring ())
		{
			ar << x1;
			ar << x2;
			ar << y1;
			ar << y2;
			ar << penColor;
			ar << brushColor;
			
		}
		else 
		{
			ar >> x1;
			ar >> x2;
			ar >> y1;
			ar >> y2;
			ar >> penColor;
			ar >> brushColor;
			
		}
	}

protected:
public:
	int x1,y1,x2,y2;
	COLORREF penColor;
	COLORREF brushColor;
	Figure();
	Figure(int xx1,int yy1, int xx2, int yy2,COLORREF C1,COLORREF C2)
	{
		x1=xx1;
		x2=xx2;
		y1=yy1;
		y2=yy2;
		penColor=C1;
		brushColor=C2;
	}
                              
	virtual void Draw(CDC *dc){}
	virtual ~Figure(void);
};

class RectangleM:public Figure{
	
	DECLARE_SERIAL (RectangleM)       
	
public:
	RectangleM();  
	RectangleM(int xx1,int yy1, int xx2, int yy2,COLORREF C1,COLORREF C2)
		:Figure(xx1,yy1,xx2,yy2,C1,C2)
	{

	}
	void Draw(CDC *dc)
	{
		CBrush myBrush,*oldBrush;
		myBrush.CreateSolidBrush(brushColor);
		oldBrush=dc->SelectObject( &myBrush );

		CPen myPen1(PS_SOLID, 3, penColor);
		CPen *oldPen;
		oldPen=dc->SelectObject( &myPen1 ); 
		dc->SetROP2(R2_COPYPEN);  

			dc->Rectangle(x1,y1,x2,y2);
			
		dc->SelectObject( oldPen ); 
		dc->SetROP2(R2_COPYPEN);  
		dc->SelectObject( oldBrush ); 
    }
	};
class EllipseM:public Figure{

	DECLARE_SERIAL (EllipseM)     

public:
	EllipseM(); 
	EllipseM(int xx1,int yy1, int xx2, int yy2,COLORREF C1,COLORREF C2)
		:Figure(xx1,yy1,xx2,yy2,C1,C2)
	{
	}
	void Draw(CDC *dc)
	{
		CBrush myBrush,*oldBrush;
		myBrush.CreateSolidBrush(brushColor);
		oldBrush=dc->SelectObject( &myBrush );

		CPen myPen1(PS_SOLID, 3, penColor);
		CPen *oldPen;
		oldPen=dc->SelectObject( &myPen1 ); 
		dc->SetROP2(R2_COPYPEN);  


		dc->Ellipse(x1,y1,x2,y2);

		
		dc->SelectObject( oldPen ); 
		dc->SetROP2(R2_COPYPEN);  
		dc->SelectObject( oldBrush ); 
	}
};

class SquareM:public RectangleM{
	DECLARE_SERIAL (SquareM)
	SquareM(); 
	SquareM(int xx1,int yy1, int xx2, int yy2,COLORREF C1,COLORREF C2)
		:RectangleM(xx1,yy1,xx2,yy2,C1,C2)
	{
	}
	void Draw(CDC *dc)
	{
		CBrush myBrush,*oldBrush;
		myBrush.CreateSolidBrush(brushColor);
		oldBrush=dc->SelectObject( &myBrush );

		CPen myPen1(PS_SOLID, 3, penColor);
		CPen *oldPen;
		oldPen=dc->SelectObject( &myPen1 ); 
		dc->SetROP2(R2_COPYPEN);  

    	if(abs(x2-x1)==abs(y2-y1))
			dc->Rectangle(x1,y1,x2,y2);
		else
		{
			if((abs(x2-x1)>abs(y2-y1)))
			{
				x2=x1+abs(y2-y1);
			}
			else
			{
				y2=y1+abs(x2-x1);
			}
			dc->Rectangle(x1,y1,x2,y2);
		}
		
		dc->SelectObject( oldPen ); 
		dc->SetROP2(R2_COPYPEN);  
		dc->SelectObject( oldBrush ); 
	}
};

class CircleM:public EllipseM{
DECLARE_SERIAL (CircleM)
public:
	CircleM();
	CircleM(int xx1,int yy1, int xx2, int yy2,COLORREF C1,COLORREF C2)
		:EllipseM(xx1,yy1,xx2,yy2,C1,C2)
	{

	}
	void Draw(CDC *dc)
	{
		CBrush myBrush,*oldBrush;
		myBrush.CreateSolidBrush(brushColor);
		oldBrush=dc->SelectObject( &myBrush );

		CPen myPen1(PS_SOLID, 3, penColor);
		CPen *oldPen;
		oldPen=dc->SelectObject( &myPen1 ); 
		dc->SetROP2(R2_COPYPEN);  

		if(abs(x2-x1)==abs(y2-y1))
			dc->Ellipse(x1,y1,x2,y2);
		else
		{
			if((abs(x2-x1)>abs(y2-y1)))
			{
				x2=x1+abs(y2-y1);
			}
			else
			{
				y2=y1+abs(x2-x1);
			}
			dc->Ellipse(x1,y1,x2,y2);
		}
		
		dc->SelectObject( oldPen ); 
		dc->SetROP2(R2_COPYPEN);  
		dc->SelectObject( oldBrush ); 
	}
};

class ParallelogramM:public RectangleM{

	DECLARE_SERIAL(ParallelogramM)
public:
   ParallelogramM();
   ParallelogramM(int xx1,int yy1, int xx2, int yy2,COLORREF C1,COLORREF C2)
	   :RectangleM(xx1,yy1,xx2,yy2,C1,C2)
   {

   }
   void Draw(CDC *dc)
	{
		CBrush myBrush,*oldBrush;
		myBrush.CreateSolidBrush(brushColor);
		oldBrush=dc->SelectObject( &myBrush );

		CPen myPen1(PS_SOLID, 3, penColor);
		CPen *oldPen;
		oldPen=dc->SelectObject( &myPen1 ); 
		dc->SetROP2(R2_COPYPEN);  


	
		CPoint p[4];

		if(x1>x2)
		{
			p[0].x=x1;
			p[0].y=y1;
			p[2].x=x2;
			p[2].y=y2;
			p[1].x=x1-abs(x1-x2)/3;
			p[1].y=y2;
			p[3].x=x2+abs(x1-x2)/3;
			p[3].y=y1;
			
		}
		else
		{
			p[0].x=x1;
			p[0].y=y1;
			p[1].x=x2-abs(x2-x1)/3;
			p[1].y=y1;
			p[2].x=x2;
			p[2].y=y2;
			p[3].x=x2-2*abs(x2-x1)/3;
			p[3].y=y2;
		}
			dc->Polygon(p,4);
		dc->SelectObject( oldPen );
		dc->SetROP2(R2_COPYPEN);  
		dc->SelectObject( oldBrush ); 
	}
};

class RightTriangleM:public Figure{
	DECLARE_SERIAL(RightTriangleM)
public:
	RightTriangleM();
	RightTriangleM(int xx1,int yy1, int xx2, int yy2,COLORREF C1,COLORREF C2)
		:Figure(xx1,yy1,xx2,yy2,C1,C2)
	{

	}
	void Draw(CDC *dc)
	{
		CBrush myBrush,*oldBrush;
		myBrush.CreateSolidBrush(brushColor);
		oldBrush=dc->SelectObject( &myBrush );

		CPen myPen1(PS_SOLID, 3, penColor);
		CPen *oldPen;
		oldPen=dc->SelectObject( &myPen1 ); 
		dc->SetROP2(R2_COPYPEN);
		int x3=x1,y3=y2;
		CPoint p[3];
		p[0].x=x1;
		p[0].y=y1;
	    p[1].x=x2;
		p[1].y=y2;
		p[2].x=x3;
		p[2].y=y3;
		dc->Polygon(p,3);
		dc->SelectObject( oldPen );
		dc->SetROP2(R2_COPYPEN);  
		dc->SelectObject( oldBrush ); 
	}
};