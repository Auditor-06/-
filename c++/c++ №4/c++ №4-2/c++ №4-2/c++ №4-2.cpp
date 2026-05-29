#include <iostream>
using namespace std;

int main() {
    int a[15], kol_chet = 0;

    cout << "Enter 15 numbers:\n";
    for (int i = 0; i < 15; i++) {
        cin >> a[i];
    }

    cout << "Squares of odd numbers in range [1, 11]:\n";
    for (int i = 0; i < 15; i++) {
        // Подсчёт чётных чисел
        if (a[i] % 2 == 0) {
            kol_chet++;
        }

        // Для нечётных чисел из диапазона [1, 11] — возводим в квадрат и выводим
        if (a[i] % 2 != 0 && a[i] >= 1 && a[i] <= 11) {
            int square = a[i] * a[i];
            cout << a[i] << "^2 = " << square << endl;
        }
    }

    cout << "Number of even numbers = " << kol_chet << endl;

    return 0;
}
