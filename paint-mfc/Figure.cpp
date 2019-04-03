#include "stdafx.h"
#include "Figure.h"
IMPLEMENT_SERIAL (Figure, CObject, 1)
IMPLEMENT_SERIAL (RectangleM, CObject,1)
IMPLEMENT_SERIAL (SquareM, CObject, 1)
IMPLEMENT_SERIAL (EllipseM, CObject, 1)
IMPLEMENT_SERIAL (CircleM, CObject, 1)
IMPLEMENT_SERIAL (ParallelogramM, CObject, 1)
IMPLEMENT_SERIAL (RightTriangleM, CObject, 1)
Figure::Figure(void)
{
}

Figure::~Figure(void)
{
}

CircleM::CircleM(){}
SquareM::SquareM(){}
RectangleM::RectangleM(){}

EllipseM::EllipseM(){}
ParallelogramM::ParallelogramM(){}
RightTriangleM::RightTriangleM(){}