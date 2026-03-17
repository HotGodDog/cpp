#pragma once
#include <iostream>

using namespace std;

class Rational {
private:
	void simplify();

public:
	int num;
	int den;

	Rational();
	Rational(int n);
	Rational(int n, int d);

	Rational& operator += (const Rational& r);
	Rational operator + (const Rational& r) const;
	Rational operator - () const;
	Rational& operator -= (const Rational& r);
	Rational& operator ++();
	Rational operator ++(int);
	Rational& operator *= (const Rational& r);
	Rational operator * (const Rational& r) const;
	Rational& operator /= (const Rational& r);
	Rational operator / (const Rational& r) const;

	friend Rational operator * (const Rational& r, int value);
	friend Rational operator * (int value, const Rational& r);
	friend Rational operator / (const Rational& r, int value);
	friend Rational operator / (int value, const Rational& r);

	bool operator == (const Rational& r) const;
	bool operator != (const Rational& r) const;
	bool operator > (const Rational& r) const;
	bool operator < (const Rational& r) const;
	bool operator >= (const Rational& r) const;
	bool operator <= (const Rational& r) const;

	bool operator > (int value) const;
	bool operator == (int value) const;

	operator int() const;
	operator double() const;

	friend istream& operator >> (istream& in, Rational& r);
	friend ostream& operator << (ostream& out, const Rational& r);
};

void test();