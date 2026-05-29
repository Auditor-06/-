#include <string.h>
#include <locale>
int main()
{
    setlocale(LC_ALL, "Russian");
    char str[80] = "кпу/ку/ркыпк/Апg/спкк/аfwwfw";  // строка с разделителем '/'
    char* p;
    char* context = NULL;  // для хранения контекста между вызовами
    int found = 0;         // флаг: найдены ли слова на 'А'/'A'

    // Разбиваем строку на токены по разделителю '/'
    p = strtok_s(str, "/", &context);

    while (p != NULL) {
        // Проверяем, начинается ли слово с 'А' (кириллица) или 'A' (латиница)
        // Приводим первый символ к верхнему регистру для упрощения проверки
        char firstChar = toupper((unsigned char)p[0]);

        if (firstChar == 'А' || firstChar == 'A') {
            printf("Слово, начинающееся с 'А'/'A': %s\n", p);
            found = 1;
        }

        // Переходим к следующему слову
        p = strtok_s(NULL, "/", &context);
    }

    // Если ни одного слова не найдено, выводим сообщение
    if (!found) {
        printf("В строке нет слов, начинающихся с буквы 'А' или 'A'\n");
    }

    return 0;
}