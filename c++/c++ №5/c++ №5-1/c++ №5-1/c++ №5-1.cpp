#include <iostream>
using namespace std;

int main() {
    // Настройка локали для корректного отображения русского текста
    setlocale(LC_ALL, "Russian");

    int m, n;
    cout << "Введите размеры матрицы (строки и столбцы): ";
    cin >> m >> n;

    // Проверка на корректность размеров
    if (m <= 0 || n <= 0) {
        cout << "Ошибка: размеры должны быть положительными!" << endl;
        return 1;
    }

    // Динамическое выделение памяти для матрицы
    int** ar = new int* [m];
    for (int i = 0; i < m; i++) {
        ar[i] = new int[n];
    }

    // Ввод элементов
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Введите элемент [" << i << "][" << j << "]: ";
            cin >> ar[i][j];
        }
    }

    // Вывод матрицы в виде таблицы
    cout << "\nМатрица:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << ar[i][j] << "\t";
        }
        cout << endl;
    }

    // Вычисление суммы положительных элементов по столбцам
    cout << "\nСуммы положительных элементов по столбцам:" << endl;
    for (int j = 0; j < n; j++) {  // перебираем столбцы
        int sum_positive = 0;
        for (int i = 0; i < m; i++) {  // перебираем строки в текущем столбце
            if (ar[i][j] > 0) {  // если элемент положительный
                sum_positive += ar[i][j];
            }
        }
        cout << "Столбец " << j << ": " << sum_positive << endl;
    }

    // Освобождение памяти
    for (int i = 0; i < m; i++) {
        delete[] ar[i];
    }
    delete[] ar;

    system("pause");  // только для Windows
    return 0;
}