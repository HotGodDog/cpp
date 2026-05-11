#pragma once

#include <vector>

using namespace std;

// Игровое поле — доска 6×7
class Board {
private:
    static const int ROWS = 6;
    static const int COLS = 7;

    // Поле храним как вектор векторов 
    // 0 — пусто, 1 — первый игрок, 2 — второй
    vector<vector<int>> grid;

public:
    Board();
    int getRows() const;
    int getCols() const;
    int getCell(int row, int col) const;
    bool canDrop(int col) const;
    int drop(int col, int player);
    bool checkWin(int row, int col, int player) const;
    bool isFull() const;
    void print() const;
};