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

// Функция поиска наименьшего элемента и обнуления строки и столбца
void processarr(int a[m][n]) {
    int i, j;
    int min_val = a[0][0];  // Начальное значение минимума
    int min_row = 0, min_col = 0;  // Координаты минимального элемента

    // Поиск наименьшего элемента и его координат
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (a[i][j] < min_val) {
                min_val = a[i][j];
                min_row = i;
                min_col = j;
            }
        }
    }

    printf("Наименьший элемент: %d (позиция [%d][%d])\n", min_val, min_row, min_col);

    // Обнуление всей строки, где находится минимальный элемент
    for (j = 0; j < n; j++) {
        a[min_row][j] = 0;
    }

    // Обнуление всего столбца, где находится минимальный элемент
    for (i = 0; i < m; i++) {
        a[i][min_col] = 0;
    }
}

int main() {
    int b[m][n];

    inparr(b);
    printf("Исходная матрица:\n");
    outarr(b);

    // Находим наименьший элемент и обнуляем строку и столбец
    processarr(b);

    printf("Матрица после обработки:\n");
    outarr(b);

    return 0;
}