#include <iostream> 
#include <math.h>   
using namespace std;
int main()
{
	setlocale(LC_ALL, "russian");
	double A = 4;
	double B = 13.6;
	double Y = tan(sqrt(B) + tan(A));
	cout << Y << endl;
	return 0;
}