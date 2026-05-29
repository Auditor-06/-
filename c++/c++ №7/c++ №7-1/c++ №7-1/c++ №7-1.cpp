#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale>
const int m = 3, n = 5;

void inparr(int a[m][n]) {
    setlocale(LC_ALL, "Russian");
    int i, j;
    printf("Введите элементы матрицы (%d x %d):\n", m, n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (scanf("%d", &a[i][j]) != 1) {
                printf("Ошибка ввода элемента [%d][%d]\n", i, j);
                return;
            }
        }
    }
}

void outarr(int a[m][n]) {
    int i, j;
    printf("Матрица:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }
}

void processarr(int a[m][n], int sums[n]) {
    int i, j;

    // Инициализируем массив сумм нулями
    for (j = 0; j < n; j++) {
        sums[j] = 0;
    }

    // Проходим по каждому столбцу
    for (j = 0; j < n; j++) {
        // Проходим по всем строкам текущего столбца
        for (i = 0; i < m; i++) {
            // Если элемент положительный, добавляем его к сумме столбца
            if (a[i][j] > 0) {
                sums[j] += a[i][j];
            }
        }
    }
}

int main() {
    int b[m][n];
    int column_sums[n]; // Массив для хранения сумм положительных элементов каждого столбца

    inparr(b);
    outarr(b);

    // Вычисляем суммы положительных элементов столбцов
    processarr(b, column_sums);

    // Выводим результаты
    printf("Суммы положительных элементов по столбцам:\n");
    for (int j = 0; j < n; j++) {
        printf("Столбец %d: %d\n", j + 1, column_sums[j]);
    }

    return 0;
}