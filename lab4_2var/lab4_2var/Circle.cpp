#include "stdafx.h"
#include "Circle.h"


CCircle::CCircle(Point const& center, double radius, string const& outlineColor, string const& fillColor)
	:ISolidShape("Circle")
	, m_center(center)
	, m_radius(radius)
	, m_outlineColor(outlineColor)
	, m_fillColor(fillColor)
{
}

Point CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::GetRadius() const
{
	return m_radius;
}

string CCircle::GetOutlineColor() const
{
	return m_outlineColor;
};

string CCircle::GetFillColor() const
{
	return m_fillColor;
};

double CCircle::GetArea() const
{
	return M_PI * pow(m_radius, 2);
};

double CCircle::GetPerimeter() const
{
	return 2 * M_PI * m_radius;
};

void CCircle::AppendProperties(ostream & strm) const
{
	strm << "  Radius = " << m_radius
		<< "  FillColor = " << GetFillColor();
}
