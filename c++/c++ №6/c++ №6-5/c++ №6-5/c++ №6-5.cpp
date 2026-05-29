#include <iostream>
#include <string>
#include <locale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    string s;
    cout << "Введите текст: ";
    getline(cin, s);

    string words[100];
    int wordCount = 0;
    string word = "";

    for (int i = 0; i <= s.length(); i++) {
        if (s[i] == ' ' || i == s.length()) {
            if (!word.empty()) {
                words[wordCount++] = word;
                word = "";
            }
        }
        else {
            word += s[i];
        }
    }

    if (wordCount >= 3) {
        cout << "Второе слово: " << words[1] << endl;
        cout << "Третье слово: " << words[2] << endl;
    }
    else {
        cout << "В тексте меньше трёх слов." << endl;
    }

    return 0;
}