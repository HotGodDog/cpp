#include "Rational.h"
#include <iostream>
#include <locale.h>

using namespace std;

Rational sqrtNewton(Rational R);
void quadr_equat(Rational a, Rational b, Rational c);

int main()
{
    setlocale(LC_ALL, "RU");

    //Rational a = 1, b = -1, c = -12;

    //quadr_equat(a, b, c);

    cout << sqrtNewton(Rational(1, 4));

    return 0;
}

Rational sqrtNewton(Rational R)
{
    if (R == 0)
        return R;

    Rational x = R;
    while (x.num < INT_MAX / x.den)
    {
        x = (x + (R / x)) / 2;
    }
    return x;
}

void quadr_equat(Rational a, Rational b, Rational c)
{
    cout << "\nУравнение: (" << a << ")x^2 + (" << b << ")x + " << c << " = 0" << endl;

    Rational d = (b * b) + -4 * a * c;

    cout << "Дискриминант: " << d << endl;

    Rational d_sqrt = sqrtNewton(d);

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