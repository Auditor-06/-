#include <stdio.h>
#include <string.h>

int main()
{
    char str[80] = "кпу/ку/ркпк/па/cпккпd";  // строка с разделителем '/'
    char* p;
    char* context = NULL;  // для хранения контекста между вызовами
    size_t maxLen = 0;    // длина самого длинного слова (изначально 0)
    size_t currentLen;      // длина текущего слова

    // Разбиваем строку на токены по разделителю '/'
    p = strtok_s(str, "/", &context);

    while (p != NULL) {
        // Получаем длину текущего слова
        currentLen = strlen(p);

        // Обновляем максимальную длину, если текущее слово длиннее
        if (currentLen > maxLen) {
            maxLen = currentLen;
        }

        // Переходим к следующему слову
        p = strtok_s(NULL, "/", &context);
    }

    // Выводим результат
    if (maxLen > 0) {
        printf("Длина самого длинного слова: %zu\n", maxLen);
    }
    else {
        printf("В строке нет слов\n");
    }

    return 0;
}