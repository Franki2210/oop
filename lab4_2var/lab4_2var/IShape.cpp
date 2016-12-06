#include "stdafx.h"
#include "IShape.h"

IShape::IShape(string const& type)
	:m_type(type)
{
}

string IShape::ToString() const
{
	ostringstream strm;
	strm << m_type + ": "
		<< "  S = " << GetArea()
		<< "  P = " << GetPerimeter()
		<< "  ColorOutline = " << GetOutlineColor();
	AppendProperties(strm);
	return strm.str();
}