#pragma once
#include "IShape.h"
using namespace std;

class ISolidShape : public IShape
{
public:
	ISolidShape(string const& type);
	virtual ~ISolidShape() = default;
	virtual string GetFillColor() const = 0;
};

