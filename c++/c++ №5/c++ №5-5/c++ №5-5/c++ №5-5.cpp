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
    double** ar = new double* [m];  // используем double для действительных чисел
    for (int i = 0; i < m; i++) {
        ar[i] = new double[n];
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

    // Нахождение суммы наибольших значений элементов строк
    double sum_of_max = 0.0;

    cout << "\nНаибольшие элементы в каждой строке:" << endl;
    for (int i = 0; i < m; i++) {
        // Инициализируем максимальный элемент первой строкой
        double max_in_row = ar[i][0];

        // Поиск максимального элемента в текущей строке
        for (int j = 1; j < n; j++) {
            if (ar[i][j] > max_in_row) {
                max_in_row = ar[i][j];
            }
        }

        cout << "Строка " << i << ": " << max_in_row << endl;
        sum_of_max += max_in_row;
    }

    // Вывод результата
    cout << "\nСумма наибольших значений элементов строк: " << sum_of_max << endl;

    // Освобождение памяти
    for (int i = 0; i < m; i++) {
        delete[] ar[i];
    }
    delete[] ar;

    system("pause"); // только для Windows
    return 0;
}
