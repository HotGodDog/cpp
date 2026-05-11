#pragma once

#include "Function.h"
#include <vector>

// Парабола: f(x) = ax^2 + bx + c
class Parabola : public Function {
private:
    double a, b, c;
public:
    Parabola(double a = 1, double b = 0, double c = 0);
    double calculate(double x) const override;
    void printName() const override;
};

// Гипербола: f(x) = a/x + b (в x=0 функция не определена)
class Hiperbola : public Function {
private:
    double a, b;
public:
    Hiperbola(double a = 1, double b = 0);
    double calculate(double x) const override;
    double integrate(double a_int, double b_int, int steps = 10000) const override;
    void printName() const override;
};

// Экспонента: f(x) = a * e^(bx) + c
class Exponenta : public Function {
private:
    double a, b, c;
public:
    Exponenta(double a = 1, double b = 1, double c = 0);
    double calculate(double x) const override;
    void printName() const override;
};

// Полином произвольной степени, коэффициенты хранятся в векторе
class Polinom : public Function {
private:
    vector<double> coeffs;
public:
    Polinom(const vector<double>& coefficients);
    double calculate(double x) const override;
    void printName() const override;
};