#include <iostream>
using namespace std;

int main() {
    double a[15];  // Массив для вещественных чисел
    int kol_otr = 0;  // Счётчик отрицательных чисел

    cout << "Enter 15 real numbers:\n";
    for (int i = 0; i < 15; i++) {
        cin >> a[i];
    }

    cout << "\nSquares of numbers in range [0, 10]:\n";
    for (int i = 0; i < 15; i++) {
        // Подсчёт отрицательных чисел
        if (a[i] < 0) {
            kol_otr++;
        }

        // Для чисел из диапазона [0; 10] — возводим в квадрат и выводим
        if (a[i] >= 0 && a[i] <= 10) {
            double square = a[i] * a[i];
            cout << a[i] << "^2 = " << square << endl;
        }
    }

    cout << "\nNumber of negative numbers = " << kol_otr << endl;

    return 0;
}