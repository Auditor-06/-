#include <iostream> 
#include <math.h>   
using namespace std;
int main()
{
	setlocale(LC_ALL, "russian");
	double A = 6.84;
	double B = 3.22;
	double C = 4;
	double D = 2.5;
	double N = ((A + B) / (C + D)) * ((A + B) / (C + D));
	double Y = N + (B * B);
	cout << Y << endl;
	return 0;
}