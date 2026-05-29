#include <iostream>
#include <string>
#include <locale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    string s;
    cout << "Введите текст: ";
    getline(cin, s);

    string word = "";

    for (int i = 0; i <= s.length(); i++) {
        if (s[i] == ' ' || i == s.length()) {
            if (word.find('E') != string::npos) {
                cout << word << endl;
            }
            word = "";
        }
        else {
            word += s[i];
        }
    }

    return 0;
}