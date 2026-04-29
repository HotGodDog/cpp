#pragma once

#define _USE_MATH_DEFINES
#include <cmath>
#include <string>
#include <vector>


using namespace std;

class Point
{
public:
	double x, y;
	Point(double x = 0, double y = 0);
    bool operator == (const Point& other) const;
    bool operator < (const Point& other) const;
};

class Figure
{
public:
	virtual double calc_area() const = 0;
	virtual double calc_perimeter() const = 0;
	virtual string name() const = 0;
};

class Circle : public Figure
{
private:
    Point center;
    double radius;
public:
    Circle(const Point& c, double r);

    double calc_area() const override;
    double calc_perimeter() const override;
    string name() const override;

    Point get_center() const;
    double get_radius() const;
};

class Ellipse : public Figure
{
private:
    Point center;
    double radius_x, radius_y;
public:
    Ellipse(const Point& c, double rx, double ry);

    double calc_area() const override;
    double calc_perimeter() const override;
    string name() const override;
};

class Triangle : public Figure
{
private:
    Point a, b, c;
public:
    Triangle(const Point& p1, const Point& p2, const Point& p3);
    Triangle(double side1, double side2, double side3);

    double calc_area() const override;
    double calc_perimeter() const override;
    string name() const override;

    vector <Point> get_vertices() const;
};

class Rectangle : public Figure
{
private:
    Point top_left, bottom_right;
public:
    Rectangle(const Point& p1, const Point& p2);
    Rectangle(double width, double height);

    double calc_area() const override;
    double calc_perimeter() const override;
    string name() const override;
};