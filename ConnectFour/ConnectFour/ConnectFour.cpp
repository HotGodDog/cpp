#include "ConnectFour.h"
#include <iostream>

using namespace std;

// В начале ходит первый игрок, игра идёт, победителя нет
ConnectFour::ConnectFour() : currentPlayer(1), gameOver(false), winner(0) {}

// Меняем игрока
void ConnectFour::switchPlayer() {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

// Основной цикл игры — крутится пока кто-то не выиграет или не будет ничьей
void ConnectFour::play() {
    cout << "<== ИГРА \"ЧЕТЫРЕ В РЯД\" ==>\n";
    cout << "Игрок 1: X | Игрок 2: O\n\n";

    while (!gameOver) {
        board.print();  // показываем текущее состояние

        cout << "Ход игрока " << currentPlayer
            << " (" << (currentPlayer == 1 ? 'X' : 'O')
            << "). Выберите колонку (1-7): ";

        int col;
        cin >> col;
        col--;  // переводим в 0-based, а то юзер вводит 1-7

        // Криво ввели — не число или не та колонка
        if (cin.fail() || col < 0 || col >= board.getCols()) {
            cin.clear();
            cin.ignore(10000, '\n'); // вычищаем мусор из потока
            cout << "Ошибка ввода! Попробуйте снова.\n";
            continue;   // просим ввести заново
        }

        // Колонка уже забита доверху
        if (!board.canDrop(col)) {
            cout << "Колонка заполнена! Выберите другую.\n";
            continue;
        }

        // Кидаем фишку, запоминаем куда она упала
        int row = board.drop(col, currentPlayer);

        // Проверяем, есть ли победители
        if (board.checkWin(row, col, currentPlayer)) {
            gameOver = true;
            winner = currentPlayer;
        }
        // Проверяем, есть ли пустые клетки
        else if (board.isFull()) {
            gameOver = true;
            winner = 0; // ничья
        }
        // Ход переходит другому
        else {
            switchPlayer();
        }
    }

    // Игра закончилась, показываем финальную доску и результат
    board.print();
    if (winner == 0)
        cout << "\n*** НИЧЬЯ! Поле заполнено. ***\n";
    else
        cout << "\n*** ПОБЕДА! Игрок " << winner
        << " (" << (winner == 1 ? 'X' : 'O')
        << ") выиграл! ***\n";
}