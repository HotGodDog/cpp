#include "Rational.h"
#include <iostream>
#include <locale.h>

using namespace std;

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
