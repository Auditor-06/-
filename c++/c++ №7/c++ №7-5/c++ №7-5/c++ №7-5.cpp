#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale>
const int m = 3, n = 5;

void inparr(double a[m][n]) {
    setlocale(LC_ALL, "Russian");
    int i, j;
    printf("Введите элементы матрицы (%d x %d):\n", m, n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (scanf("%lf", &a[i][j]) != 1) {
                printf("Ошибка ввода элемента [%d][%d]\n", i, j);
                return;
            }
        }
    }
}

void outarr(double a[m][n]) {
    int i, j;
    printf("Матрица:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%8.2f", a[i][j]);
        }
        printf("\n");
    }
}

// Функция для нахождения суммы наибольших элементов строк
double sumOfMaxInRows(double a[m][n]) {
    int i, j;
    double sum = 0.0;

    // Обрабатываем каждую строку матрицы
    for (i = 0; i < m; i++) {
        double max_in_row = a[i][0];  // Начальное значение максимума — первый элемент строки

        // Ищем максимальный элемент в текущей строке
        for (j = 1; j < n; j++) {
            if (a[i][j] > max_in_row) {
                max_in_row = a[i][j];
            }
        }

        printf("Максимальный элемент в строке %d: %.2f\n", i + 1, max_in_row);
        sum += max_in_row;  // Добавляем максимум строки к общей сумме
    }

    return sum;
}

int main() {
    setlocale(LC_ALL, "Russian");
    double A[m][n];  // Действительная матрица

    // Ввод матрицы A
    inparr(A);
    printf("Исходная матрица A:\n");
    outarr(A);

    // Находим сумму наибольших элементов строк
    double result = sumOfMaxInRows(A);

    // Вывод результата
    printf("Сумма наибольших значений элементов строк: %.2f\n", result);

    return 0;
}