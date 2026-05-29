#include <iostream> 
#include <math.h>   
using namespace std;
int main()
{
	setlocale(LC_ALL, "russian");
	double A = 8;
	double B = 5.6;
	double Y = 2 * A * asin(3.14 / B);
	cout << Y << endl;
	return 0;
}