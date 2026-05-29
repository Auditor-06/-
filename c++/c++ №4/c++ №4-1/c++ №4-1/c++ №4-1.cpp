#include <iostream>
using namespace std;

int main() {
    int a[15], sum = 0, kol = 0;

    cout << "Enter 15 numbers:\n";
    for (int i = 0; i < 15; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < 15; i++) {
        if (a[i] >= -5 && a[i] <= 5) {
            sum += a[i];
        }
        if (a[i] % 2 != 0) {
            kol++;
        }
    }

    cout << "Summa v diapazone [-5, 5] = " << sum << endl;
    cout << "Kolichestvo nechetnih = " << kol << endl;

    return 0;
}
