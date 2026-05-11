#include "Board.h"
#include <iostream>

using namespace std;

// Создаём пустое поле 6×7
Board::Board() : grid(ROWS, vector<int>(COLS, 0)) {}

int Board::getRows() const { return ROWS; }
int Board::getCols() const { return COLS; }

// Возвращаем значение ячейки, если координаты кривые возвращаем -1
int Board::getCell(int row, int col) const {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS)
        return -1;

    return grid[row][col];
}

// Проверяем можно ли кинуть фишку в эту колонку — свободна ли верхняя ячейка
bool Board::canDrop(int col) const {
    if (col < 0 || col >= COLS)
        return false;

    return grid[0][col] == 0;
}

// Ищем снизу первую пустую ячейку и ложем туда фишку
// Возвращаем номер строки, куда упала, или -1 если не получилось
int Board::drop(int col, int player) {
    if (!canDrop(col))
        return -1;

    for (int row = ROWS - 1; row >= 0; --row) 
        if (grid[row][col] == 0) {
            grid[row][col] = player;
            return row;
    }
    return -1;
}

// Проверяем, выиграл ли кто-то после хода в (row, col)
// Смотрим в 4 направления: горизонтально, вертикально, две диагонали
bool Board::checkWin(int row, int col, int player) const {
    // Направления: вправо, вниз, вправо-вниз, влево-вниз
    const int dr[4] = { 0, 1, 1, 1 };
    const int dc[4] = { 1, 0, 1, -1 };

    for (int dir = 0; dir < 4; ++dir) {
        int count = 1; // сама фишка уже считается

        // Считаем в одну сторону от точки
        for (int k = 1; k < 4; ++k) {
            int r = row + dr[dir] * k;
            int c = col + dc[dir] * k;
            if (r >= 0 && r < ROWS && c >= 0 && c < COLS && grid[r][c] == player)
                ++count;
            else break; // упёрлись в стену или чужую фишку
        }

        // Считаем в другую сторону
        for (int k = 1; k < 4; ++k) {
            int r = row - dr[dir] * k;
            int c = col - dc[dir] * k;
            if (r >= 0 && r < ROWS && c >= 0 && c < COLS && grid[r][c] == player)
                ++count;
            else break;
        }

        // Если набралось 4+ подряд — победа
        if (count >= 4) return true;
    }
    return false;
}

// Проверка верхнего ряда на заполненость
bool Board::isFull() const {
    for (int j = 0; j < COLS; ++j)
        if (grid[0][j] == 0) return false;
    return true;
}

// Рисуем доску в консоли
void Board::print() const {
    cout << "\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            char c = ' ';
            if (grid[i][j] == 1) c = 'X';       // первый игрок
            else if (grid[i][j] == 2) c = 'O';  // второй игрок
            cout << "| " << c << " ";
        }
        cout << "|\n";

        for (int j = 0; j < COLS; ++j)
            cout << "+---";
        cout << "+\n";
    }

    // Номера колонок под доской
    for (int j = 0; j < COLS; ++j)
        cout << "  " << j + 1 << " ";
    cout << "\n";
}