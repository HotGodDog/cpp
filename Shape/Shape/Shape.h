#pragma once

#define _USE_MATH_DEFINES
#include <cmath>
#include <string>
#include <vector>


using namespace std;


// Класс Point — представляет точку на плоскости

class Point
{
public:
    double x, y;

    Point(double x = 0, double y = 0);

    bool operator == (const Point& other) const;
    bool operator < (const Point& other) const;
};


// Абстрактный класс «Геометрическая фигура»

class Figure
{
public:
    virtual double calc_area() const = 0;           // расчёт площади
    virtual double calc_perimeter() const = 0;      // расчёт периметра
    virtual string name() const = 0;                // название фигуры

    virtual ~Figure() = default;    // Виртуальный деструктор
};


// Класс Circle

class Circle : public Figure
{
private:
    Point center;
    double radius;

public:
    // Конструкторы с разными типами координат центра
    Circle(const Point& c, double r);
    Circle(double x, double y, double r);
    Circle(float x, float y, double r);
    Circle(int x, int y, double r);

    double calc_area() const override;
    double calc_perimeter() const override;
    string name() const override;

    Point get_center() const;
    double get_radius() const;
};


// Класс Ellipse

class Ellipse : public Figure
{
private:
    Point center;
    double radius_x;
    double radius_y;

public:
    // Конструкторы с разными типами координат центра
    Ellipse(const Point& c, double rx, double ry);
    Ellipse(double x, double y, double rx, double ry);
    Ellipse(float x, float y, double rx, double ry);
    Ellipse(int x, int y, double rx, double ry);

    double calc_area() const override;
    double calc_perimeter() const override;
    string name() const override;
};


// Класс Triangle

class Triangle : public Figure
{
private:
    Point a, b, c;

public:
    // Конструкторы через координаты вершин
    Triangle(const Point& p1, const Point& p2, const Point& p3);
    Triangle(double x1, double y1, double x2, double y2,
             double x3, double y3);
    Triangle(float x1, float y1, float x2, float y2,
             float x3, float y3);
    Triangle(int x1, int y1, int x2, int y2,
             int x3, int y3);

    // Конструкторы через длины сторон
    Triangle(double side1, double side2, double side3);
    Triangle(float side1, float side2, float side3);
    Triangle(int side1, int side2, int side3);

    double calc_area() const override;
    double calc_perimeter() const override;
    string name() const override;

    vector <Point> get_vertices() const;
};


// Класс Rectangle (Прямоугольник)

class Rectangle : public Figure
{
private:
    Point top_left;
    Point bottom_right;

public:
    // Конструкторы через координаты двух противоположных углов
    Rectangle(const Point& p1, const Point& p2);
    Rectangle(double x1, double y1, double x2, double y2);
    Rectangle(float x1, float y1, float x2, float y2);
    Rectangle(int x1, int y1, int x2, int y2);

    // Конструкторы через ширину и высоту
    Rectangle(double width, double height);
    Rectangle(float width, float height);
    Rectangle(int width, int height);

    double calc_area() const override;
    double calc_perimeter() const override;
    string name() const override;
};


// Класс Polygon

class Polygon : public Figure
{
private:
    vector <Point> vertices;    // список вершин

public:
    // Конструктор через вектор точек
    Polygon(const vector <Point>& vertices);

    double calc_area() const override;
    double calc_perimeter() const override;
    string name() const override;

    vector <Point> get_vertices() const;
};