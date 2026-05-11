#include "ConnectFour.h"
#include "locale.h"

int main() {
    setlocale(LC_ALL, "RU");

    ConnectFour game;
    game.play();

    return 0;
}