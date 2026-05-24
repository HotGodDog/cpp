#include <iostream>
#include <locale.h>
#include <vector>

#include "Shape.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    // Круг
    Circle c(Point(0, 0), 5.0);
    cout << c.name() << ": площадь = " << c.calc_area() << ", периметр = " << c.calc_perimeter() << endl;

    // Эллипс
    Ellipse e(1.0, 2.0, 5.0, 3.0);
    cout << e.name() << ": площадь = " << e.calc_area() << ", периметр = " << e.calc_perimeter() << endl;

    // Треугольник через
    Triangle t(0.0, 0.0, 3.0, 0.0, 0.0, 4.0);
    cout << t.name() << ": площадь = " << t.calc_area() << ", периметр = " << t.calc_perimeter() << endl;

    // Прямоугольник
    Rectangle r(Point(0, 0), Point(4, 3));
    cout << r.name() << ": площадь = " << r.calc_area() << ", периметр = " << r.calc_perimeter() << endl;

    // Многоугольник
    vector<Point> square = { Point(0, 0), Point(4, 0), Point(4, 4), Point(0, 4) };
    Polygon p(square);
    cout << p.name() << ": площадь = " << p.calc_area() << ", периметр = " << p.calc_perimeter() << endl;

    return 0;
}