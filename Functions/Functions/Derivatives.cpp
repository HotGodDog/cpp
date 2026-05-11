#include "Derivatives.h"


Parabola::Parabola(double a, double b, double c) : a(a), b(b), c(c) {}

double Parabola::calculate(double x) const {
    return a * x * x + b * x + c;
}

void Parabola::printName() const {
    cout << "Парабола: f(x) = " << a << "x^2 + " << b << "x + " << c << endl;
}


Hiperbola::Hiperbola(double a, double b) : a(a), b(b) {}

double Hiperbola::calculate(double x) const {
    // Гипербола не определена в нуле — бросаем исключение
    if (x == 0) {
        throw runtime_error("Деление на ноль в гиперболе");
    }
    return a / x + b;
}

// Переопределяем integrate, потому что гипербола имеет особенность в x=0
// Если отрезок интегрирования пересекает ноль, интеграл расходится
double Hiperbola::integrate(double a_int, double b_int, int steps) const {
    if ((a_int < 0 && b_int > 0) || (a_int > 0 && b_int < 0))
        throw runtime_error("Интеграл расходится, особенность в x=0 на отрезке");
    
    return Function::integrate(a_int, b_int, steps);
}

void Hiperbola::printName() const {
    cout << "Гипербола: f(x) = " << a << "/x + " << b << endl;
}


Exponenta::Exponenta(double a, double b, double c) : a(a), b(b), c(c) {}

double Exponenta::calculate(double x) const {
    return a * exp(b * x) + c;
}

void Exponenta::printName() const {
    cout << "Экспонента: f(x) = " << a << "*e^(" << b << "x) + " << c << endl;
}


Polinom::Polinom(const vector<double>& coefficients) : coeffs(coefficients) {}

// Вычисляем по схеме Горнера через накопление степеней.
// coeffs[0] — свободный член, coeffs[1] — при x, coeffs[2] — при x^2 и т.д.
double Polinom::calculate(double x) const {
    double result = 0;
    double power = 1;  // x^0 = 1

    for (size_t i = 0; i < coeffs.size(); ++i) {
        result += coeffs[i] * power;
        power *= x;  // на следующей итерации x^(i+1)
    }

    return result;
}

// Выводим полином от старшей степени к младшей
void Polinom::printName() const {
    cout << "Полином: f(x) = ";
    for (int i = coeffs.size() - 1; i >= 0; --i) {
        if (i < (int)coeffs.size() - 1) {
            cout << " + ";
        }
        cout << coeffs[i];
        if (i > 0) {
            cout << "*x";
            if (i > 1) {
                cout << "^" << i;
            }
        }
    }
    cout << endl;
}