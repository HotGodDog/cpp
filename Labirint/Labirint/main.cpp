#include "BMPImage.h"
#include "MazeSolver.h"
#include <iostream>
#include <locale.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    // Путь к входному файлу
    string inputFile = "ДНК_Лабиринт.bmp";
    string outputFile = "ДНК_Лабиринт_Решение.bmp";

    cout << "Решение лабиринта волновым алгоритмом" << endl;
    cout << "Входной файл: " << inputFile << endl;
    cout << "Выходной файл: " << outputFile << endl;
    cout << endl;

    // Загружаем изображение
    BMPImage image;
    if (!image.load(inputFile)) {
        cerr << "Не удалось загрузить изображение. Завершение." << endl;
        return 1;
    }

    cout << "Изображение загружено: " << image.getWidth() << "x" << image.getHeight() << endl;

    // Решаем лабиринт
    MazeSolver solver(&image);
    if (!solver.solve()) {
        cerr << "Не удалось найти путь. Завершение." << endl;
        return 1;
    }

    // Сохраняем результат
    if (!image.save(outputFile)) {
        cerr << "Не удалось сохранить результат. Завершение." << endl;
        return 1;
    }

    cout << endl;
    cout << "Результат сохранен в: " << outputFile << endl;
    cout << "Путь отмечен цветом RGB(0, 255, 255) — голубым" << endl;

    return 0;
}