#pragma once
#include "Struct.h"
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Класс для работы с BMP-изображением (24 бита на пиксель)
class BMPImage {
private:
    int width;
    int height;
    vector<Pixel> pixels;  // Пиксели снизу вверх (как в BMP)

    // Внутренние структуры заголовков BMP
#pragma pack(push, 1)
    struct BMPFileHeader {
        char signature[2];
        unsigned int fileSize;
        unsigned short reserved1;
        unsigned short reserved2;
        unsigned int dataOffset;
    };
    struct BMPInfoHeader {
        unsigned int headerSize;
        int width;
        int height;
        unsigned short planes;
        unsigned short bitsPerPixel;
        unsigned int compression;
        unsigned int imageSize;
        int xPixelsPerMeter;
        int yPixelsPerMeter;
        unsigned int colorsUsed;
        unsigned int colorsImportant;
    };
#pragma pack(pop)

public:
    BMPImage();

    // Загрузка из файла
    bool load(const string& filename);

    // Сохранение в файл
    bool save(const string& filename) const;

    // Получение размеров
    int getWidth() const;
    int getHeight() const;

    // Доступ к пикселю (x, y) — координаты с (0,0) в левом верхнем углу
    Pixel getPixel(int x, int y) const;
    void setPixel(int x, int y, const Pixel& pixel);

    // Проверка, что координаты внутри изображения
    bool isInside(int x, int y) const;
};