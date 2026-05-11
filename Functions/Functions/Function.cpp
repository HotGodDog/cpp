#include "Function.h"

Function::~Function() = default;

// Вывод значения функции в точке x
void Function::print(double x) const {
    cout << "f(" << x << ") = " << calculate(x) << endl;
}


// Делим отрезок [a, b] на steps частей, вычисляем f(x) в каждой точке и запоминаем наименьшее значение.
double Function::findMin(double a, double b, int steps) const {
    double step = (b - a) / steps;

    // Начинаем с левой границы
    double minVal = calculate(a);

    // Перебираем остальные точки
    for (int i = 1; i <= steps; ++i) {
        double x = a + i * step;
        double y = calculate(x);
        if (y < minVal)
            minVal = y;
    }
    return minVal;
}

// Ищем максимум по аналогии с поиском минимума
double Function::findMax(double a, double b, int steps) const {
    double step = (b - a) / steps;
    double maxVal = calculate(a);

    for (int i = 1; i <= steps; ++i) {
        double x = a + i * step;
        double y = calculate(x);
        if (y > maxVal)
            maxVal = y;
    }
    return maxVal;
}

// Интеграл методом трапеций формула: h * [f(a)/2 + f(b)/2 + сумма f(x_i)]
double Function::integrate(double a, double b, int steps) const {
    double h = (b - a) / steps;

    // Суммируем крайние точки с коэффициентом 1/2
    double sum = 0.5 * (calculate(a) + calculate(b));

    // Добавляем все внутренние точки
    for (int i = 1; i < steps; ++i)
        sum += calculate(a + i * h);

    return sum * h;
}

// Производная через центральную разность f'(x) примерно равно [f(x+h) - f(x-h)] / (2h)
double Function::differentiate(double x, double h) const {
    return (calculate(x + h) - calculate(x - h)) / (2 * h);
}