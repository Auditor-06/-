#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale>
const int m = 3, n = 5;

void inparr(int a[m][n]) {
    setlocale(LC_ALL, "Russian");
    int i, j;
    printf("Введите элементы матрицы X (%d x %d):\n", m, n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (scanf("%d", &a[i][j]) != 1) {
                printf("Ошибка ввода элемента [%d][%d]\n", i, j);
                return;
            }
        }
    }
}

// Универсальный вывод для матриц любого размера
void outarr(int* matrix, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%5d", matrix[i * cols + j]);
        }
        printf("\n");
    }
}

// Функция транспонирования матрицы
void transpose(int X[m][n], int Y[n][m]) {
    int i, j;
    // Заполняем матрицу Y, меняя местами строки и столбцы
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            Y[j][i] = X[i][j];
        }
    }
}

int main() {
    int X[m][n];      // Исходная матрица
    int Y[n][m];      // Транспонированная матрица (размеры поменялись местами)

    // Ввод исходной матрицы
    inparr(X);

    printf("Исходная матрица X (%d x %d):\n", m, n);
    outarr((int*)X, m, n);  // Приводим к int*

    // Транспонирование матрицы
    transpose(X, Y);

    printf("Транспонированная матрица Y (%d x %d):\n", n, m);
    outarr((int*)Y, n, m);  // Приводим к int*

    return 0;
}