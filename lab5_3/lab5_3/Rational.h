#pragma once

using namespace std;

//Класс, моделирующий рациональное число
class CRational final
{
public:
	CRational(int numerator = 0, int denominator = 1);

	// Возвращает числитель
	int GetNumerator() const;

	// Возвращает знаменатель
	int GetDenominator() const;

	// Нормализует рациональное число
	void Normalize();

	
	double ToDouble() const;

	const CRational operator+() const;
	const CRational operator-() const;

	
	CRational const& operator+=(const CRational & subtrahend);

	
	CRational const& operator-=(const CRational & subtrahend);

	CRational const& operator*=(CRational const& r);

	CRational const& CRational::operator/=(CRational const& r);
private:
	int m_numerator;
	int m_denominator;
};

int GetGCD(int a, int b);

const CRational operator+(const CRational & leftNumber, const CRational & rightNumber);

const CRational operator-(const CRational & leftNumber, const CRational & rightNumber);

const CRational operator*(CRational const& leftNumber, CRational const& rightNumber);

const CRational operator/(CRational const& leftNumber, CRational const& rightNumber);

const bool operator==(CRational const & leftNumber, CRational const & rightNumber);
const bool operator!=(CRational const & leftNumber, CRational const & rightNumber);

const bool operator<(CRational const & leftNumber, CRational const & rightNumber);
const bool operator>=(CRational const & leftNumber, CRational const & rightNumber);
const bool operator>(CRational const & leftNumber, CRational const & rightNumber);
const bool operator<=(CRational const & leftNumber, CRational const & rightNumber);

ostream & operator<<(ostream & output, CRational & rational);

istream & operator>>(istream & input, CRational & rational);