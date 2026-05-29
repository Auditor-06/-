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

    // Динамическое выделение памяти для матрицы X
    int** X = new int* [m];
    for (int i = 0; i < m; i++) {
        X[i] = new int[n];
    }

    // Ввод элементов матрицы X
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Введите элемент X[" << i << "][" << j << "]: ";
            cin >> X[i][j];
        }
    }

    // Вывод исходной матрицы X
    cout << "\nИсходная матрица X:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << X[i][j] << "\t";
        }
        cout << endl;
    }

    // Динамическое выделение памяти для транспонированной матрицы Y (размер n x m)
    int** Y = new int* [n];
    for (int i = 0; i < n; i++) {
        Y[i] = new int[m];
    }

    // Транспонирование: X[i][j] -> Y[j][i]
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            Y[j][i] = X[i][j];
        }
    }

    // Вывод транспонированной матрицы Y
    cout << "\nТранспонированная матрица Y (строки и столбцы поменяны местами):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << Y[i][j] << "\t";
        }
        cout << endl;
    }

    // Освобождение памяти
    for (int i = 0; i < m; i++) {
        delete[] X[i];
    }
    delete[] X;

    for (int i = 0; i < n; i++) {
        delete[] Y[i];
    }
    delete[] Y;

    system("pause");  // только для Windows
    return 0;
}