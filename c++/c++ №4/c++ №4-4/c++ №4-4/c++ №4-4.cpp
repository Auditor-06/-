#include <iostream>
using namespace std;

int main() {
    double a[10];           // Массив для 10 вещественных чисел
    int kol_ge_1_5 = 0;   // Счётчик чисел >= 1,5
    double sum_neg = 0;  // Сумма отрицательных чисел

    cout << "Enter 10 real numbers:\n";
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }

    // Обработка массива
    for (int i = 0; i < 10; i++) {
        // Подсчёт чисел >= 1,5
        if (a[i] >= 1.5) {
            kol_ge_1_5++;
        }

        // Суммирование отрицательных чисел
        if (a[i] < 0) {
            sum_neg += a[i];
        }
    }

    // Вывод результатов
    cout << "\nNumber of elements >= 1.5: " << kol_ge_1_5 << endl;
    cout << "Sum of negative numbers: " << sum_neg << endl;

    return 0;
}
