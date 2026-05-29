#include <iostream>
using namespace std;

int main() {
    const int SIZE = 10;
    double a[SIZE];                // Массив для 10 вещественного числа
    int kol_zero = 0;            // Счётчик нулей
    double sum_in_range = 0.0;   // Сумма чисел в [-15; 15] (все, т.к. диапазон совпадает)

    cout << "Enter 10 real numbers (will be logically mapped to indices -15..15):\n";
    for (int i = 0; i < SIZE; i++) {
        cin >> a[i];
    }

    // Обработка: считаем нули и сумму (все элементы по условию лежат в [-15;15])
    for (int i = 0; i < SIZE; i++) {
        if (a[i] == 0.0) {
            kol_zero++;
        }
        sum_in_range += a[i];  // все элементы учитываются, т.к. их индексы «соответствуют» [-15;15]
    }

    // Вывод
    cout << "\nNumber of elements equal to zero: " << kol_zero << endl;
    cout << "Sum of all 10 numbers (mapped to -15..15): " << sum_in_range << endl;

    return 0;
}
