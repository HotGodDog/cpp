#include "Rational.h"
#include <iostream>
#include <locale.h>

using namespace std;

int sqrt(Rational a);
void quadr_equat(Rational a, Rational b, Rational c);

int main()
{
    setlocale(LC_ALL, "RU");

    Rational a = 1, b = -1, c = -12;

    //cout << "Решение квадратного уравнения ax^2 + bx + c = 0" << endl;
    //cout << "Введите коэффициенты a, b, c: ";
    //cin >> a >> b >> c;

    //test();

    quadr_equat(a, b, c);

    //cout << 2 / Rational (1, 2) << endl;

    return 0;
}

int sqrt(Rational a)
{
    Rational x = a;
    int counter = 0;
    cout << "x" << counter << " = " << x << endl;
    while (x.num < INT_MAX / x.den) {
        x = (x + (a / x)) / 2;
        counter++;
        cout << "x" << counter << " = " << x << endl;
        if (x == a)
            break;
    }
    return x;
}

void quadr_equat(Rational a, Rational b, Rational c)
{
    cout << "\nУравнение: (" << a << ")x^2 + (" << b << ")x + " << c << " = 0" << endl;

    Rational d = (b * b) + -4 * a * c;

    cout << "Дискриминант: " << d << endl;

    Rational d_sqrt = sqrt(d);

    cout << "Корень: " << d_sqrt << endl;

    if (d > 0) {
        Rational x1 = (-b + d_sqrt) / (2 * a);
        Rational x2 = (-b + -d_sqrt) / (2 * a);
        cout << "Два корня: x1 = " << x1 << ", x2 = " << x2 << endl;
    }
    else if (d == 0) {
        Rational x = -b / (2 * a);
        cout << "Один корень: x = " << x << endl;
    }
    else {
        cout << "Действительных корней нет" << endl;
    }
}