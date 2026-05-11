#include "Derivatives.h"
#include "locale.h"

// Универсальная функция для тестирования любой функции.
// Принимает ссылку на базовый класс — работает с любым потомком.
void demonstrate(const Function& func, double a, double b, double testX);

int main() {
    setlocale(LC_ALL, "RU");

    cout << "Демонстрация классов функций" << endl;

    // 1. Парабола f(x) = 2x^2 - 3x + 1
    // Ожидаем: ветви вверх, минимум около x = 0.75
    Parabola parabola(2, -3, 1);
    demonstrate(parabola, -2, 3, 1);

    // 2. Гипербола f(x) = 1/x + 2
    // Осторожно: разрыв в x = 0, поэтому отрезок [0.5, 5]
    Hiperbola hiperbola(1, 2);
    demonstrate(hiperbola, 0.5, 5, 2);

    // 3. Экспонента f(x) = 2*e^(0.5x) - 1
    // Монотонно возрастает
    Exponenta exponenta(2, 0.5, -1);
    demonstrate(exponenta, 0, 4, 2);

    // 4. Полином 3-й степени f(x) = x^3 - 2x^2 + 3x - 1
    // Коэффициенты: a0=-1, a1=3, a2=-2, a3=1
    Polinom polinom({ -1, 3, -2, 1 });
    demonstrate(polinom, -1, 2, 1);

    // 5. Полином 4-й степени f(x) = x^4 - 5x^2 + 4
    // Коэффициенты: a0=4, a1=0, a2=-5, a3=0, a4=1
    Polinom polinom4({ 4, 0, -5, 0, 1 });
    demonstrate(polinom4, -2, 2, 0);

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
