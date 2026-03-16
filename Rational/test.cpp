#include "Rational.h"

void test()
{
    cout << "Тестируем + , -, *=, / , <<" << endl;

    Rational a(1, 2), b(-1, 6);

    cout << "\na = " << a << "\nb = " << b << "\na + b = " << a + b << endl;
    cout << "\na(" << a << ") *= b(" << b << ")" << endl;
    a *= b;
    cout << "a = " << a << "\nb = " << b << "\n\na - b = " << a + -b << endl;

    Rational c = 3;

    cout << "\nb = " << b << "\nc = " << c << "\nb / c = " << b / c << endl;
    cout << "\nТестируем >> , !=" << endl;

    Rational e(7, 8), f(5, 12);

    cout << "\ne = " << e << "\nf = " << f << "\ne + f = ?" << endl;
    cout << "\nВведите результат g = m / n в формате: m n" << endl;

    Rational g;

    cin >> g;

    if (e + f != g)
        cout << "\nНеправильно! e + f = " << e + f << endl;
    else
        cout << "\nПравильно!" << endl;

    a = Rational(1, 2);

    cout << "\nТестируем *, / Rational с int\n" << endl;
    
    cout << a << " * 2 = " << a * 2 << endl;
    cout << "2 * " << a << " = " << 2 * a << endl;

    cout << a << " / 2 = " << a / 2 << endl;
    cout << "2 / " << a << " = " << 2 / a << endl;
}