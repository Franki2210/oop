#pragma once
#include "ISolidShape.h"
#include "Point.h"

class CCircle: public ISolidShape
{
public:
	CCircle(Point const& center, double radius, string const& outlineColor, string const& fillColor);
	~CCircle() = default;
	double GetArea() const;
	double GetPerimeter() const;
	string GetOutlineColor() const;
	string GetFillColor() const;
	Point GetCenter() const;
	double GetRadius() const;
protected:
	void AppendProperties(std::ostream & strm) const;
private:
	Point m_center;
	double m_radius = 0;
	string m_outlineColor;
	string m_fillColor;
};

