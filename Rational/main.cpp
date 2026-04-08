#include "Rational.h"
#include <iostream>
#include <locale.h>

using namespace std;

void quadr_equat(Rational a, Rational b, Rational c);

int main()
{
    setlocale(LC_ALL, "RU");

    //2 корня
    //Rational a(1, 1), b(-3, 1), c(2, 1);

    //2 рациональных корня
    //Rational a(6, 1), b(-5, 1), c(1, 1);

    //дискриминант = 0
    //Rational a(1, 1), b(-4, 1), c(4, 1);

    //отрицательный дискриминат
    //Rational a(1, 1), b(1, 1), c(1, 1);

    //иррациональные корни
    //Rational a(1, 1), b(0, 1), c(-2, 1);

    //дробные коэффициенты и иррациональные корни
    //Rational a(1, 2), b(1, 3), c(-1, 4);

    Rational a(2, 1), b(-3, 1), c(-2, 1);

    quadr_equat(a, b, c);

    return 0;
}


void quadr_equat(Rational a, Rational b, Rational c)
{
    cout << "\nУравнение: (" << a << ")x^2 + (" << b << ")x + " << c << " = 0" << endl;

    Rational d = (b * b) + -4 * a * c;
    Rational d_sqrt = sqrtRational(d);

    cout << "Дискриминант: " << d << endl;
    cout << "Корень: " << d_sqrt << endl;

    if (d > 0) 
    {
        Rational x1 = (-b + d_sqrt) / (2 * a);
        Rational x2 = (-b + -d_sqrt) / (2 * a);
        cout << "Два корня: x1 = " << x1 << ", x2 = " << x2 << endl;
    }
    else if (d == 0) 
    {
        Rational x = -b / (2 * a);
        cout << "Один корень: x = " << x << endl;
    }
    else
        cout << "Действительных корней нет" << endl;
}