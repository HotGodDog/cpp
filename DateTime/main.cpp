#include "DateTime.h"
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    cout << "Проверка создания DateTime переменных:" << endl;

    DateTime date1;
    DateTime date2(2026, 3, 30);
    DateTime date3;
    //date3.input();

    cout << "\nДата по умолчанию: ";
    cout << "\n  1 Формат: ";
    date1.basicFormat();
    cout << "\n  2 Формат: ";
    date1.textFormat();
    cout << "\n  3 Формат: ";
    date1.shortFormat();

    cout << "\nДата описанная при создании DateTime переменной: ";
    cout << "\n  1 Формат: ";
    date2.basicFormat();
    cout << "\n  2 Формат: ";
    date2.textFormat();
    cout << "\n  3 Формат: ";
    date2.shortFormat();

    cout << "\nДата введенная с клавиатуры: ";
    cout << "\n  1 Формат: ";
    date3.basicFormat();
    cout << "\n  2 Формат: ";
    date3.textFormat();
    cout << "\n  3 Формат: ";
    date3.shortFormat();

    cout << "\n\nПроверка корректности дат:" << endl;

    DateTime validDate(2024, 2, 29);
    DateTime invalidDate1(2023, 2, 29);
    DateTime invalidDate2(2023, 13, 1);
    DateTime invalidDate3(2023, 4, 31);

    cout << "\n2024-02-29: " << (validDate.isValid() ? "корректна" : "некорректна");
    cout << "\n2023-02-29: " << (invalidDate1.isValid() ? "корректна" : "некорректна");
    cout << "\n2023-13-01: " << (invalidDate2.isValid() ? "корректна" : "некорректна");
    cout << "\n2023-04-31: " << (invalidDate3.isValid() ? "корректна" : "некорректна");

    cout << "\n\nВычисление разницы между датами:" << endl;

    date1.basicFormat();
    cout << " - ";
    date2.basicFormat();
    cout << " = " << date1 - date2;

    cout << "\n\nВычисление дня недели:";

    cout << date1.dayOfWeek();

    return 0;
}
