#pragma once

#include "Board.h"

// √лавный класс игры, запускает всЄ, следит за очерЄдностью ходов
class ConnectFour {
private:
    Board board;        // само поле
    int currentPlayer;  // чей сейчас ход (1 или 2)
    bool gameOver;      // закончилась ли игра
    int winner;         // 0 Ч ничь€, 1 или 2 Ч победитель

    // ѕередаЄм ход другому игроку
    void switchPlayer();

public:
    ConnectFour();
    void play();        // главный игровой цикл
};