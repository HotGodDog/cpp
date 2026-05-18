#include "BMPImage.h"
#include <iostream>

using namespace std;

BMPImage::BMPImage() : width(0), height(0) {}

bool BMPImage::load(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "Ошибка: не удалось открыть файл " << filename << endl;
        return false;
    }

    BMPFileHeader fileHeader;
    file.read(reinterpret_cast<char*>(&fileHeader), sizeof(fileHeader));

    if (fileHeader.signature[0] != 'B' || fileHeader.signature[1] != 'M') {
        cerr << "Ошибка: файл не является BMP" << endl;
        return false;
    }

    BMPInfoHeader infoHeader;
    file.read(reinterpret_cast<char*>(&infoHeader), sizeof(infoHeader));

    if (infoHeader.bitsPerPixel != 24) {
        cerr << "Ошибка: поддерживаются только 24-битные BMP" << endl;
        return false;
    }

    width = infoHeader.width;
    height = infoHeader.height;

    // Размер строки с учетом выравнивания до 4 байт
    int rowSize = ((width * 3 + 3) / 4) * 4;
    int padding = rowSize - width * 3;

    pixels.resize(width * height);

    // Переходим к данным пикселей
    file.seekg(fileHeader.dataOffset, ios::beg);

    // Читаем снизу вверх (как в BMP)
    for (int y = height - 1; y >= 0; y--) {
        for (int x = 0; x < width; x++) {
            unsigned char bgr[3];
            file.read(reinterpret_cast<char*>(bgr), 3);
            pixels[y * width + x] = Pixel(bgr[2], bgr[1], bgr[0]);
        }
        // Пропускаем padding
        if (padding > 0) {
            file.seekg(padding, ios::cur);
        }
    }

    file.close();
    return true;
}

bool BMPImage::save(const string& filename) const {
    ofstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "Ошибка: не удалось создать файл " << filename << endl;
        return false;
    }

    int rowSize = ((width * 3 + 3) / 4) * 4;
    int padding = rowSize - width * 3;
    int imageSize = rowSize * height;
    int fileSize = sizeof(BMPFileHeader) + sizeof(BMPInfoHeader) + imageSize;

    BMPFileHeader fileHeader;
    fileHeader.signature[0] = 'B';
    fileHeader.signature[1] = 'M';
    fileHeader.fileSize = fileSize;
    fileHeader.reserved1 = 0;
    fileHeader.reserved2 = 0;
    fileHeader.dataOffset = sizeof(BMPFileHeader) + sizeof(BMPInfoHeader);

    BMPInfoHeader infoHeader;
    infoHeader.headerSize = sizeof(BMPInfoHeader);
    infoHeader.width = width;
    infoHeader.height = height;
    infoHeader.planes = 1;
    infoHeader.bitsPerPixel = 24;
    infoHeader.compression = 0;
    infoHeader.imageSize = imageSize;
    infoHeader.xPixelsPerMeter = 0;
    infoHeader.yPixelsPerMeter = 0;
    infoHeader.colorsUsed = 0;
    infoHeader.colorsImportant = 0;

    file.write(reinterpret_cast<const char*>(&fileHeader), sizeof(fileHeader));
    file.write(reinterpret_cast<const char*>(&infoHeader), sizeof(infoHeader));

    // Пишем снизу вверх
    for (int y = height - 1; y >= 0; y--) {
        for (int x = 0; x < width; x++) {
            Pixel p = pixels[y * width + x];
            unsigned char bgr[3] = { p.b, p.g, p.r };
            file.write(reinterpret_cast<const char*>(bgr), 3);
        }
        // Дописываем padding
        for (int i = 0; i < padding; i++) {
            unsigned char zero = 0;
            file.write(reinterpret_cast<const char*>(&zero), 1);
        }
    }

    file.close();
    return true;
}

int BMPImage::getWidth() const {
    return width;
}

int BMPImage::getHeight() const {
    return height;
}

Pixel BMPImage::getPixel(int x, int y) const {
    if (!isInside(x, y)) {
        return Pixel();
    }
    return pixels[y * width + x];
}

void BMPImage::setPixel(int x, int y, const Pixel& pixel) {
    if (isInside(x, y)) {
        pixels[y * width + x] = pixel;
    }
}

bool BMPImage::isInside(int x, int y) const {
    return x >= 0 && x < width && y >= 0 && y < height;
}