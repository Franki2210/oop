#include "stdafx.h"
#include "Solve4.h"

using namespace std;

int Sign(const double value)
{
	if (value > 0) return 1;
	if (value < 0) return -1;
	else return 0;
}

EquationRoots MergeRoots(EquationRoots equationRoots1, EquationRoots equationRoots2)
{
	EquationRoots mergeRoots;
	int numRoot = 0;

	for (size_t i = 0; i < equationRoots1.numRoots; i++)
	{
		mergeRoots.roots[numRoot] = equationRoots1.roots[i];
		numRoot++;
	}
	for (size_t i = 0; i < equationRoots2.numRoots; i++)
	{
		mergeRoots.roots[numRoot] = equationRoots2.roots[i];
		numRoot++;
	}
	mergeRoots.numRoots = numRoot;
	return mergeRoots;
}

EquationRoots Solve2(double b, double c)
{
	EquationRoots equationRoots;
	double descriminant = pow(b, 2) - 4 * c;

	if (descriminant == 0)
	{
		equationRoots.numRoots = 1;
		equationRoots.roots[0] = -b / 2;
	}
	else if (descriminant > 0)
	{
		equationRoots.roots[0] = (-b - sqrt(descriminant)) / 2;
		equationRoots.roots[1] = (-b + sqrt(descriminant)) / 2;
		equationRoots.numRoots = 2;
	}
	else
	{
		equationRoots.numRoots = 0;
	}
	return equationRoots;
}

EquationRoots Solve3(double a, double b, double c)
{
	double q = (pow(a, 2) - 3 * b) / 9;
	double r = (2 * pow(a, 3) - 9 * a * b + 27 * c) / 54;

	//cout << q << ' ' << r << ' ' << endl;

	double s = pow(q, 3) - pow(r, 2);

	EquationRoots equationRoots;

	if (s > 0)
	{
		double fi = acos(r / sqrt(pow(q, 3))) / 3;
		equationRoots.numRoots = 3;
		equationRoots.roots[0] = -2 * sqrt(q) * cos(fi) - a / 3;
		equationRoots.roots[1] = -2 * sqrt(q) * cos(fi + 2 * M_PI / 3) - a / 3;
		equationRoots.roots[2] = -2 * sqrt(q) * cos(fi - 2 * M_PI / 3) - a / 3;
	}
	else if (s < 0)
	{
		if (q > 0)
		{
			double fi = acosh(abs(r) / pow(q, 3.0 / 2)) / 3;
			equationRoots.numRoots = 1;
			equationRoots.roots[0] = -2.0 * Sign(r) * sqrt(q) * cosh(fi) - a / 3;
		}
		else
		{
			double fi = asinh(abs(r) / pow(abs(q), 3.0 / 2)) / 3;
			equationRoots.numRoots = 1;
			equationRoots.roots[0] = -2.0 * Sign(r) * sqrt(abs(q)) * sinh(fi) - a / 3;
		}
	}
	else
	{
		equationRoots.numRoots = 2;
		equationRoots.roots[0] = -2 * pow(r, 1.0 / 3) - a / 3;
		equationRoots.roots[1] = pow(r, 1.0 / 3) - a / 3;
	}
	
	return equationRoots;
}

EquationRoots Solve4(double a, double b, double c, double d, double e)
{
	if (a == 0)
	{
		throw invalid_argument("Argument 'a' must be not a zero");
	}

	double a1 = b / a;
	double b1 = c / a;
	double c1 = d / a;
	double d1 = e / a;

	/*double p = b1 - ((3 * pow(a1, 2)) / 8);
	double q = c1 + pow(a1, 3) / 8 - a1 * b1 / 2;
	double r = d1 + pow(a1, 2) * b1 / 16 - 3 * pow(a1, 4) / 256 - c1 * a1 / 4;
	*/

	double n = -b1;
	double p = (a1 * c1) - (4 * d1);
	double q = 4 * (b1 * d1) - (a1 * a1 * d1) - (c1 * c1);

	EquationRoots equationRoots3 = Solve3(n, p, q);

	//EquationRoots equationRoots3 = Solve3(-p / 2, -r, (r * p - pow(q, 2) / 4) / 2);
	/*
	double s = equationRoots3.roots[equationRoots3.numRoots - 1];

	EquationRoots equationRoots21 = Solve2(-sqrt(2 * s - p), q / (2 * sqrt(2 * s - p)) + s);
	EquationRoots equationRoots22 = Solve2(sqrt(2 * s - p), -q / (2 * sqrt(2 * s - p)) + s);
	*/

	n = *max_element(begin(equationRoots3.roots), end(equationRoots3.roots));
	p = sqrt((a1 * a1 / 4) - (b1 - n));
	q = sqrt(abs((n * n / 4) - d1));

	if (((a1 * n / 2) - c1) < 0)
	{
		q *= -1;
	}

	EquationRoots equationRoots21 = Solve2(a1 / 2 + p, n / 2 + q);
	EquationRoots equationRoots22 = Solve2(a1 / 2 - p, n / 2 - q);

	if ((equationRoots21.numRoots == 0) && (equationRoots22.numRoots == 0))
	{
		throw std::domain_error("Equation does not have real roots.");
	}

	return MergeRoots(equationRoots21, equationRoots22);
}