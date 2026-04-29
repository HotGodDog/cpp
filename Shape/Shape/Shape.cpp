#include "Shape.h"
#include <vector>

using namespace std;

Point::Point(double x, double y) : x(x), y(y) {}

bool Point::operator == (const Point& other) const
{ 
    return x == other.x && y == other.y;
}
bool Point::operator < (const Point& other) const
{
    return x < other.x || (x == other.x && y < other.y);
}


Circle::Circle(const Point& c, double r) : center(c), radius(r) {}

double Circle::calc_area() const
{
    return M_PI * radius * radius;
}
double Circle::calc_perimeter() const
{
    return 2 * M_PI * radius;
}
string Circle::name() const
{
    return "Circle";
}

Point Circle::get_center() const
{
    return center;
}
double Circle::get_radius() const
{
    return radius;
}


Ellipse::Ellipse(const Point& c, double rx, double ry) : center(c), radius_x(rx), radius_y(ry) {}

double Ellipse::calc_area() const
{
    return M_PI * radius_x * radius_y;
}
double Ellipse::calc_perimeter() const
{
    double h = pow(radius_x - radius_y, 2) / pow(radius_x + radius_y, 2);
    return M_PI * (radius_x + radius_y) * (1 + 3 * h / (10 + sqrt(4 - 3 * h)));
}
string Ellipse::name() const
{
    return "Ellipse";
}


Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3) : a(p1), b(p2), c(p3) {}

Triangle::Triangle(double side1, double side2, double side3)
{
    double x2 = (side1 * side1 + side2 * side2 - side3 * side3) / (2 * side1);
    double y2 = sqrt(side2 * side2 - x2 * x2);
    a = Point(0, 0);
    b = Point(side1, 0);
    c = Point(x2, y2);
}

double Triangle::calc_area() const
{
    return fabs((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y)) / 2.0;
}
double Triangle::calc_perimeter() const
{
    double ab = hypot(b.x - a.x, b.y - a.y);
    double bc = hypot(c.x - b.x, c.y - b.y);
    double ca = hypot(a.x - c.x, a.y - c.y);
    return ab + bc + ca;
}
string Triangle::name() const
{
    return "Triangle";
}

vector <Point> Triangle::get_vertices() const
{
    return { a, b, c };
}


Rectangle::Rectangle(const Point& p1, const Point& p2)
{
    top_left = Point(min(p1.x, p2.x), min(p1.y, p2.y));
    bottom_right = Point(max(p1.x, p2.x), max(p1.y, p2.y));
}
Rectangle::Rectangle(double width, double height) : top_left(0, 0), bottom_right(width, height) {}

double Rectangle::calc_area() const
{
    return (bottom_right.x - top_left.x) * (bottom_right.y - top_left.y);
}
double Rectangle::calc_perimeter() const
{
    return 2 * ((bottom_right.x - top_left.x) + (bottom_right.y - top_left.y));
}
string Rectangle::name() const
{
    return "Rectangle";
}