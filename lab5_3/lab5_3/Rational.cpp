#include "stdafx.h"
#include "Rational.h"
#include <utility>
#include <stdexcept>

using namespace std;

CRational::CRational(int numerator, int denominator)
	: m_numerator(numerator)
	, m_denominator(denominator)
{
	if (denominator == 0)
	{
		throw invalid_argument("Denominator must not be zero");
	}
	if (denominator < 0)
	{
		m_numerator = -m_numerator;
		m_denominator = -m_denominator;
	}
	Normalize();
}

int CRational::GetNumerator() const
{
	return m_numerator;
}

int CRational::GetDenominator() const
{
	return m_denominator;
}

void CRational::Normalize()
{
	const int gcd = GetGCD(abs(m_numerator), m_denominator);
	m_numerator /= gcd;
	m_denominator /= gcd;
}

int GetGCD(int a, int b) //greatest common divisor
{
	while (b)
	{
		swap(a, b);
		b = b % a;
	}
	return (a != 0) ? a : 1;
}

double CRational::ToDouble() const
{
	return static_cast<double>(m_numerator) / m_denominator;
}

const CRational CRational::operator+() const
{
	return *this;
}
const CRational CRational::operator-() const
{
	return CRational(-m_numerator, m_denominator);
}

const CRational operator+(const CRational & leftNumber, const CRational & rightNumber)
{
	int resultNumerator = leftNumber.GetNumerator() * rightNumber.GetDenominator() + rightNumber.GetNumerator() * leftNumber.GetDenominator();
	int resultDenominator = leftNumber.GetDenominator() * rightNumber.GetDenominator();
	return CRational(resultNumerator, resultDenominator);
}

const CRational operator-(const CRational & leftNumber, const CRational & rightNumber)
{
	int resultNumerator = leftNumber.GetNumerator() * rightNumber.GetDenominator() - rightNumber.GetNumerator() * leftNumber.GetDenominator();
	int resultDenominator = leftNumber.GetDenominator() * rightNumber.GetDenominator();
	return CRational(resultNumerator, resultDenominator);
}

const CRational & CRational::operator+=(const CRational & summand)
{
	if (summand.GetNumerator() == 0)
	{
		return *this;
	}
	m_numerator = m_numerator * summand.GetDenominator() + m_denominator * summand.GetNumerator();
	m_denominator = m_denominator * summand.GetDenominator();
	Normalize();
	return *this;
}

const CRational & CRational::operator-=(const CRational & subtrahend)
{
	if (subtrahend.GetNumerator() == 0)
	{
		return *this;
	}
	m_numerator = m_numerator * subtrahend.GetDenominator() - m_denominator * subtrahend.GetNumerator();
	m_denominator = m_denominator * subtrahend.GetDenominator();
	Normalize();
	return *this;
}

const CRational operator*(CRational const& leftNumber, CRational const& rightNumber)
{
	return CRational(leftNumber.GetNumerator() * rightNumber.GetNumerator(), leftNumber.GetDenominator() * rightNumber.GetDenominator());
}

const CRational operator/(CRational const& leftNumber, CRational const& rightNumber)
{
	return CRational(leftNumber.GetNumerator() * rightNumber.GetDenominator(), leftNumber.GetDenominator() * rightNumber.GetNumerator());
}

CRational const& CRational::operator*=(CRational const& rational)
{
	*this = *this * rational;
	return *this;
}

CRational const& CRational::operator/=(CRational const& rational)
{
	*this = *this / rational;
	return *this;
}

const bool operator==(CRational const & leftNumber, CRational const & rightNumber)
{
	CRational l = leftNumber, r = rightNumber;
	l.Normalize();
	r.Normalize();
	return (((l.GetNumerator() == r.GetNumerator()) && (r.GetDenominator() == l.GetDenominator())));
}

const bool operator!=(CRational const & leftNumber, CRational const & rightNumber)
{
	return !(leftNumber == rightNumber);
}

const bool operator<(CRational const & leftNumber, CRational const & rightNumber)
{
	return (leftNumber.GetNumerator() * rightNumber.GetDenominator() < rightNumber.GetNumerator() * leftNumber.GetDenominator());
}

const bool operator>=(CRational const & leftNumber, CRational const & rightNumber)
{
	return !(leftNumber < rightNumber);
}

const bool operator>(CRational const & leftNumber, CRational const & rightNumber)
{
	return (leftNumber.GetNumerator() * rightNumber.GetDenominator() > rightNumber.GetNumerator() * leftNumber.GetDenominator());
}

const bool operator<=(CRational const & leftNumber, CRational const & rightNumber)
{
	return !(leftNumber > rightNumber);
}

ostream & operator<<(ostream & output, CRational & rational)
{
	output << rational.GetNumerator() << '/' << rational.GetDenominator();
	return output;
}

istream & operator>>(istream & input, CRational & rational)
{
	int numerator = 0;
	int denominator = 1;
	if ((input >> numerator) && (input.get() == '/') && (input >> denominator))
	{
		rational = CRational(numerator, denominator);
	}
	else
	{
		input.setstate(ios_base::failbit);
	}
	return input;
}