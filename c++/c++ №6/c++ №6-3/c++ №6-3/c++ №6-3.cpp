#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <locale>
int main()
{
    setlocale(LC_ALL, "Russian");
    // ваш код с strtok_s() остаётся без изменений
    char str[80] = "кпу/ку";
    char* p;
    char* context = NULL;
    char result[160] = "";
    int wordCount = 0;
    int inserted = 0;

    p = strtok_s(str, "/", &context);

    while (p != NULL) {
        wordCount++;

        if (result[0] != '\0') {
            strcat(result, "/");
        }
        strcat(result, p);

        if (wordCount == 1 && !inserted) {
            strcat(result, "/");
            strcat(result, "НОВОЕ");
            inserted = 1;
        }

        p = strtok_s(NULL, "/", &context);
    }

    printf("Исходная строка: %s\n", str);
    printf("Результат: %s\n", result);

    return 0;
}