#pragma once

// Структура для координат точки
struct Point {
    int x;
    int y;
    Point(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

// Структура для RGB-пикселя (24 бита)
#pragma pack(push, 1)
struct Pixel {
    unsigned char b;
    unsigned char g;
    unsigned char r;
    Pixel(unsigned char r_ = 0, unsigned char g_ = 0, unsigned char b_ = 0)
        : r(r_), g(g_), b(b_) {
    }
    bool operator==(const Pixel& other) const {
        return r == other.r && g == other.g && b == other.b;
    }
};
#pragma pack(pop)