#include "Shape.h"
#include <vector>

using namespace std;


// Реализация класса Point

Point::Point(double x, double y) : x(x), y(y) {}

bool Point::operator == (const Point& other) const
{
    return x == other.x && y == other.y;
}

bool Point::operator < (const Point& other) const
{
    return x < other.x || (x == other.x && y < other.y);
}


// Реализация класса Circle

Circle::Circle(const Point& c, double r) : center(c), radius(r) {}

Circle::Circle(double x, double y, double r) : center(Point(x, y)), radius(r) {}

Circle::Circle(float x, float y, double r) : center(Point(static_cast<double>(x), static_cast<double>(y))), radius(r) {}

Circle::Circle(int x, int y, double r) : center(Point(static_cast<double>(x), static_cast<double>(y))), radius(r) {}

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


// Реализация класса Ellipse

Ellipse::Ellipse(const Point& c, double rx, double ry) : center(c), radius_x(rx), radius_y(ry) {}

Ellipse::Ellipse(double x, double y, double rx, double ry)
    : center(Point(x, y)), radius_x(rx), radius_y(ry) {
}

Ellipse::Ellipse(float x, float y, double rx, double ry)
    : center(Point(static_cast<double>(x), static_cast<double>(y))), radius_x(rx), radius_y(ry) {
}

Ellipse::Ellipse(int x, int y, double rx, double ry)
    : center(Point(static_cast<double>(x), static_cast<double>(y))), radius_x(rx), radius_y(ry) {
}

double Ellipse::calc_area() const
{
    return M_PI * radius_x * radius_y;
}

double Ellipse::calc_perimeter() const
{
    // Приближённая формула Рамануджана для периметра эллипса
    double h = pow(radius_x - radius_y, 2) / pow(radius_x + radius_y, 2);
    return M_PI * (radius_x + radius_y) * (1 + 3 * h / (10 + sqrt(4 - 3 * h)));
}

string Ellipse::name() const
{
    return "Ellipse";
}


// Реализация класса Triangle

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3) : a(p1), b(p2), c(p3) {}

Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
    : a(Point(x1, y1)), b(Point(x2, y2)), c(Point(x3, y3)) {
}

Triangle::Triangle(float x1, float y1, float x2, float y2, float x3, float y3)
    : a(Point(static_cast<double>(x1), static_cast<double>(y1))),
    b(Point(static_cast<double>(x2), static_cast<double>(y2))),
    c(Point(static_cast<double>(x3), static_cast<double>(y3))) {
}

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
    : a(Point(static_cast<double>(x1), static_cast<double>(y1))),
    b(Point(static_cast<double>(x2), static_cast<double>(y2))),
    c(Point(static_cast<double>(x3), static_cast<double>(y3))) {
}

Triangle::Triangle(double side1, double side2, double side3)
{
    double x2 = (side1 * side1 + side2 * side2 - side3 * side3) / (2 * side1);
    double y2 = sqrt(side2 * side2 - x2 * x2);
    a = Point(0, 0);
    b = Point(side1, 0);
    c = Point(x2, y2);
}

Triangle::Triangle(float side1, float side2, float side3)
    : Triangle(static_cast<double>(side1), static_cast<double>(side2), static_cast<double>(side3)) {
}

Triangle::Triangle(int side1, int side2, int side3)
    : Triangle(static_cast<double>(side1), static_cast<double>(side2), static_cast<double>(side3)) {
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


// Реализация класса Rectangle

Rectangle::Rectangle(const Point& p1, const Point& p2)
{
    top_left = Point(min(p1.x, p2.x), min(p1.y, p2.y));
    bottom_right = Point(max(p1.x, p2.x), max(p1.y, p2.y));
}

Rectangle::Rectangle(double x1, double y1, double x2, double y2)
    : Rectangle(Point(x1, y1), Point(x2, y2)) {
}

Rectangle::Rectangle(float x1, float y1, float x2, float y2)
    : Rectangle(Point(static_cast<double>(x1), static_cast<double>(y1)),
        Point(static_cast<double>(x2), static_cast<double>(y2))) {
}

Rectangle::Rectangle(int x1, int y1, int x2, int y2)
    : Rectangle(Point(static_cast<double>(x1), static_cast<double>(y1)),
        Point(static_cast<double>(x2), static_cast<double>(y2))) {
}

Rectangle::Rectangle(double width, double height)
    : top_left(0, 0), bottom_right(width, height) {
}

Rectangle::Rectangle(float width, float height)
    : top_left(0, 0), bottom_right(static_cast<double>(width), static_cast<double>(height)) {
}

Rectangle::Rectangle(int width, int height)
    : top_left(0, 0), bottom_right(static_cast<double>(width), static_cast<double>(height)) {
}

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


// Реализация класса Polygon

Polygon::Polygon(const vector <Point>& vertices) : vertices(vertices) {}

// Площадь через формулу Гаусса
double Polygon::calc_area() const
{
    double area = 0.0;
    size_t n = vertices.size();
    for (size_t i = 0; i < n; ++i)
    {
        size_t j = (i + 1) % n;     // следующая вершина (замыкаем контур)
        area += vertices[i].x * vertices[j].y - vertices[j].x * vertices[i].y;
    }
    return fabs(area) / 2.0;
}

double Polygon::calc_perimeter() const
{
    double perim = 0.0;
    size_t n = vertices.size();
    for (size_t i = 0; i < n; ++i)
    {
        size_t j = (i + 1) % n;     // следующая вершина (замыкаем контур)
        perim += hypot(vertices[j].x - vertices[i].x, vertices[j].y - vertices[i].y);
    }
    return perim;
}

string Polygon::name() const
{
    return "Polygon";
}

vector <Point> Polygon::get_vertices() const
{
    return vertices;
}