#include "Derivatives.h"
#include "locale.h"
#include <vector>

// Универсальная функция для тестирования любой функции.
// Принимает ссылку на базовый класс — работает с любым потомком.
void demonstrate(const Function& func, double a, double b, double testX);

struct Task {
    Function* func;
    double a, b, testX;
};

int main() {
    setlocale(LC_ALL, "RU");

    cout << "Демонстрация работы функций" << endl;

    // Создаём объекты
    Parabola parabola(2, -3, 1);
    Hiperbola hiperbola(1, 2);
    Exponenta exponenta(2, 0.5, -1);
    Polinom polinom({ -1, 3, -2, 1 });
    Polinom polinom4({ 4, 0, -5, 0, 1 });

    // Заполняем вектор заданий
    vector<Task> tasks = {
        { &parabola, -2,  3, 1 },
        { &hiperbola, 0.5, 5, 2 },
        { &exponenta, 0,   4, 2 },
        { &polinom,   -1,  2, 1 },
        { &polinom4,  -2,  2, 0 }
    };

    // Запускаем в цикле
    for (const auto& task : tasks) {
        demonstrate(*task.func, task.a, task.b, task.testX);
    }

    return 0;
}

void demonstrate(const Function& func, double a, double b, double testX) {
    cout << endl;
    func.printName();
    cout << endl;

    // Проверяем вычисление в конкретной точке
    cout << "Значение в точке:" << endl;
    func.print(testX);

    // Ищем экстремумы на заданном отрезке
    cout << "На отрезке [" << a << ", " << b << "]:" << endl;
    try {
        cout << "  Минимум: " << func.findMin(a, b) << endl;
        cout << "  Максимум: " << func.findMax(a, b) << endl;
    }
    catch (const exception& e) {
        cout << "  Ошибка: " << e.what() << endl;
    }

    // Считаем определенный интеграл
    cout << "Интеграл от " << a << " до " << b << ":" << endl;
    try {
        cout << "  Результат: " << func.integrate(a, b) << endl;
    }
    catch (const exception& e) {
        cout << "  Ошибка: " << e.what() << endl;
    }

    // Считаем производную в точке
    cout << "Производная в точке x = " << testX << ":" << endl;
    cout << "  Результат: " << func.differentiate(testX) << endl;
}
