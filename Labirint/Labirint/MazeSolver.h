#pragma once
#include "BMPImage.h"
#include "Struct.h"
#include <vector>
#include <queue>

using namespace std;

// Класс для поиска пути в лабиринте волновым алгоритмом (BFS)
class MazeSolver {
private:
    BMPImage* image;
    Point start;   // Красная точка — вход
    Point end;     // Зеленая точка — выход

    // Цвета
    static const Pixel WALL_COLOR;      // Черный
    static const Pixel PATH_COLOR;      // Белый
    static const Pixel START_COLOR;     // Красный (237, 28, 36)
    static const Pixel END_COLOR;       // Зеленый (34, 177, 76)
    static const Pixel ROUTE_COLOR;     // Голубой (0, 255, 255)

    // Допуск для определения цвета (±10)
    static bool colorMatch(const Pixel& a, const Pixel& b);

    // Поиск точки заданного цвета (центр круга)
    Point findColor(const Pixel& targetColor);

    // Проверка, что пиксель — проход (белый)
    bool isPassable(int x, int y) const;

    // Проверка, что пиксель — стена (черный)
    bool isWall(int x, int y) const;

    // Рисование широкой точки пути (3x3 пикселя)
    void drawCross(int cx, int cy, int size, const Pixel& color);

public:
    MazeSolver(BMPImage* img);

    // Поиск входа и выхода
    bool findStartAndEnd();

    // Волновой алгоритм (BFS) — поиск кратчайшего пути
    bool solve();

    // Отрисовка найденного пути на изображении
    void drawPath(const vector<Point>& path);

    Point getStart() const;
    Point getEnd() const;
};