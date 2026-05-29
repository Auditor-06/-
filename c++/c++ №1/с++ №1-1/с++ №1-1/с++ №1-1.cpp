#include <iostream> 
#include <math.h>   
using namespace std;
int main()
{
	setlocale(LC_ALL, "russian");
	double A = 5;
	double B = 2.35;
	double L = A / B - B;
	double V = log(A * A + B * B);
	double M = B / 2 - V;
	double Y = acos(L) - M;
	cout << Y << endl;
	return 0;
}