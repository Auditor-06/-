#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x, y;
    cin >> x >> y;

    double d = x * x + y * y;

    if ((d < 1) && (x < -0.4))
        cout << "Точка внутри области";

    else if ((d > 1) || (x > -0.4))
        cout << "Точка вне области";

    else
        cout << "Точка на границе";

    return 0;
}