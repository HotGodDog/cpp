#pragma once

#include <iostream>
#include <cmath>

using namespace std;

// Базовый абстрактный класс для всех функций
class Function {
public:
    virtual ~Function();

    // Каждый потомок реализует свою формулу f(x)
    virtual double calculate(double x) const = 0;

    // Выводит f(x) в заданной точке
    virtual void print(double x) const;

    // Ищет минимум на отрезке [a, b]
    virtual double findMin(double a, double b, int steps = 10000) const;

    // Ищет максимум на отрезке [a, b]
    virtual double findMax(double a, double b, int steps = 10000) const;

    // Численное интегрирование методом трапеций
    virtual double integrate(double a, double b, int steps = 10000) const;

    // Численное дифференцирование (центральная разность)
    virtual double differentiate(double x, double h = 1e-6) const;

    // Выводит название функции и ее формулу
    virtual void printName() const = 0;
};