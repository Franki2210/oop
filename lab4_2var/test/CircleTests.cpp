#include "stdafx.h"
#include "PointTest.h"
#include "..\lab4_2var\Circle.h"

struct CircleFixture_
{
	CCircle circle;
	CircleFixture_()
		:circle({ 10, 10 }, 100, "ffffff", "0000ff")
	{}
};

BOOST_FIXTURE_TEST_SUITE(Circle, CircleFixture_)
BOOST_AUTO_TEST_CASE(circle_has_a_area)
{
	BOOST_CHECK(circle.GetArea() == 100 * 100 * M_PI);
}

BOOST_AUTO_TEST_CASE(circle_has_a_perimeter)
{
	BOOST_CHECK(circle.GetPerimeter() == 2 * 100 * M_PI);
}

BOOST_AUTO_TEST_CASE(circle_get_center_point)
{
	IsPointsEqual(circle.GetCenter(), { 10, 10 });
}

BOOST_AUTO_TEST_CASE(circle_get_radius)
{
	BOOST_CHECK(circle.GetRadius() == 100);
}

BOOST_AUTO_TEST_CASE(circle_get_fill_color)
{
	BOOST_CHECK(circle.GetFillColor() == "0000ff");
}

BOOST_AUTO_TEST_CASE(circle_get_outline_color)
{
	BOOST_CHECK(circle.GetOutlineColor() == "ffffff");
}

BOOST_AUTO_TEST_CASE(circle_to_string)
{
	BOOST_CHECK(circle.ToString() == "Circle:   S = 31415.9  P = 628.319  ColorOutline = ffffff  Radius = 100  FillColor = 0000ff");
}
BOOST_AUTO_TEST_SUITE_END()
