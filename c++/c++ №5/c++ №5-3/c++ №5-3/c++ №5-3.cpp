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
    cout << "\nИсходная матрица:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << ar[i][j] << "\t";
        }
        cout << endl;
    }

    // Поиск наименьшего элемента и его координат
    int min_element = ar[0][0];
    int min_row = 0, min_col = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (ar[i][j] < min_element) {
                min_element = ar[i][j];
                min_row = i;
                min_col = j;
            }
        }
    }

    cout << "\nНаименьший элемент: " << min_element
        << " (находится в строке " << min_row
        << ", столбце " << min_col << ")" << endl;

    // Заполнение нулями строки и столбца с наименьшим элементом
    // Заполняем строку
    for (int j = 0; j < n; j++) {
        ar[min_row][j] = 0;
    }
    // Заполняем столбец
    for (int i = 0; i < m; i++) {
        ar[i][min_col] = 0;
    }

    // Вывод изменённой матрицы
    cout << "\nМатрица после замены строки и столбца с наименьшим элементом на нули:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << ar[i][j] << "\t";
        }
        cout << endl;
    }

    // Освобождение памяти
    for (int i = 0; i < m; i++) {
        delete[] ar[i];
    }
    delete[] ar;

    system("pause");  // только для Windows
    return 0;
}
