#pragma once

struct EquationRoots
{
	int numRoots;
	double roots[4];
};

// ¬ычисл€ем корни кубического уравнени€ ax^4 + bx^3 + cx^2 + dx + e = 0
EquationRoots Solve4(double a, double b, double c, double d, double e);
EquationRoots Solve3(double a, double b, double c);
EquationRoots Solve2(double b, double c);