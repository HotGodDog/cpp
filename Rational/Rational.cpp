#include "Rational.h"
#include <cmath>
#include <iostream>

using namespace std;

Rational::Rational() {
	num = 1;
	den = 1;
}
Rational::Rational(int n) {
	num = n;
	den = 1;
}
Rational::Rational(int n, int d) {
	num = n;
	den = d;
}

void Rational::simplify() {
	if (den < 0) {
		num = -num;
		den = -den;
	}
	for (int i = 2; i <= abs(den) && i <= abs(num); i++) {
		if (num % i == 0 && den % i == 0) {
			num /= i;
			den /= i;
			i--;
		}
	}
}

Rational& Rational::operator += (const Rational& r) {
	num = num * r.den + den * r.num;
	den = den * r.den;
	simplify();
	return (*this);
}
Rational Rational::operator + (const Rational& r) const {
	Rational R(*this);
	return R += r;
}
Rational Rational::operator - () const {
	Rational r(-num, den);
	return r;
}
Rational& Rational::operator -= (const Rational& r) {
	return (*this += (-r));
}
Rational& Rational::operator ++() {
	num += den;
	return *this;
}
Rational Rational::operator ++(int) {
	Rational r(*this);
	num += den;
	return r;
}
Rational& Rational::operator *= (const Rational& r) {
	num = num * r.num;
	den = den * r.den;
	simplify();
	return (*this);
}
Rational Rational::operator * (const Rational& r) const {
	Rational R(*this);
	return R *= r;
}
Rational& Rational::operator /= (const Rational& r) {
	num = num * r.den;
	den = den * r.num;
	simplify();
	return (*this);
}
Rational Rational::operator / (const Rational& r) const {
	Rational R(*this);
	return R /= r;
}

Rational operator * (const Rational& r, int value) {
	Rational R(r.num * value, r.den);
	return R *= 1;
}
Rational operator * (int value, const Rational& r) {
	Rational R(r.num * value, r.den);
	return R *= 1;
}
Rational operator / (const Rational& r, int value) {
	Rational R(r.num, r.den * value);
	return R *= 1;
}
Rational operator / (int value, const Rational& r) {
	Rational R(r.den * value, r.num);
	return R *= 1;
}

bool Rational::operator == (const Rational& r) const {
	return (num == r.num) && (den == r.den);
}
bool Rational::operator != (const Rational& r) const {
	return !(*this == r);
}
bool Rational::operator > (const Rational& r) const {
	return ((double)num) / den > ((double)r.num) / r.den;
}
bool Rational::operator < (const Rational& r) const {
	return !(*this > r);
}
bool Rational::operator >= (const Rational& r) const {
	return (*this > r) || (*this == r);
}
bool Rational::operator <= (const Rational& r) const {
	return (*this < r) || (*this == r);
}

bool Rational::operator > (int value) const {
	return num > value * den;
}
bool Rational::operator == (int value) const {
	return num == value * den;
}


Rational::operator int() const {
	return num / den;
}
Rational::operator double() const {
	return ((double)num) / den;
}
istream& operator >> (istream& in, Rational& r) {
	in >> r.num >> r.den;
	return in;
}
ostream& operator << (ostream& out, const Rational& r) {
	out << r.num << "/" << r.den;
	return out;
}