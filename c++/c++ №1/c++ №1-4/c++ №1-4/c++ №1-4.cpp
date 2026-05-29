#include <iostream> 
#include <math.h>   
using namespace std;
int main()
{
	setlocale(LC_ALL, "russian");
	double A = 9.5;
	double B = 1.365;
	double C = 6.6;
	double D = 3;
	double N = (sin(C) * sin(C) * sin(C)) * (cos(A) * cos(A));
	double M = 5 * pow(sin(B), D);
	double Y = N / M;
	cout << Y << endl;
	return 0;
}