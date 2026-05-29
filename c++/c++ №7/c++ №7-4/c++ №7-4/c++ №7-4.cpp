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

void printArray(int b[m], int size) {
    printf("Массив B:\n");
    for (int i = 0; i < size; i++) {
        printf("%5d", b[i]);
    }
    printf("\n");
}

// Функция для заполнения массива B
void processarr(int a[m][n], int b[m], int C) {
    int i, j;

    // Обрабатываем каждую строку матрицы
    for (i = 0; i < m; i++) {
        int found = 0;  // Флаг: найден ли элемент > C в строке

        // Ищем первый элемент в строке, больший C
        for (j = 0; j < n; j++) {
            if (a[i][j] > C) {
                b[i] = a[i][j];  // Записываем его в массив B
                found = 1;       // Устанавливаем флаг
                break;           // Выходим из цикла — нужен только первый элемент
            }
        }

        // Если в строке не нашли элемента > C, записываем 0
        if (!found) {
            b[i] = 0;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int A[m][n];
    int B[m];      // Массив для результатов
    int C;         // Пороговое значение

    // Ввод порога C
    printf("Введите значение C: ");
    if (scanf("%d", &C) != 1) {
        printf("Ошибка ввода C!\n");
        return 1;
    }

    // Ввод матрицы A
    inparr(A);
    printf("Исходная матрица A:\n");
    outarr(A);

    // Обработка матрицы и заполнение массива B
    processarr(A, B, C);

    // Вывод результатов
    printf("Значение C: %d\n", C);
    printArray(B, m);

    return 0;
}