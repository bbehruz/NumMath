#include <iostream>
#include <math.h>

using namespace std;

double f(double x)
{
	return 4 * x + pow(2, x) + 6;
}

double f1(double x)
{
	return -2 * pow(x, 3) - 2 * pow(x, 2) + 2 * x + 5;
}

int main()
{
	setlocale(0, "RUS");
	unsigned k;
	double a, b, c, eps, x;
	eps = 0.001;
	
	a = -2; b = -1; 

	k = 0;
	while (b - a > 2 * eps) 
	{
		c = (a + b) / 2;
		if (f(a) * f(c) < 0)
			b = c;
		else
			if (f(b) * f(c) < 0)
				a = c;
		k++;
	}
	x = (a + b) / 2;
	cout << "x1 = " << x << endl;
	cout << "Количество итераций: " << k << endl;


	a = 0; b = 2;

	k = 0;
	while (b - a > 2 * eps)
	{
		c = (a + b) / 2;
		if (f1(a) * f1(c) < 0)
			b = c;
		else
			if (f1(b) * f1(c) < 0)
				a = c;
		k++;
	}
	x = (a + b) / 2;
	cout << "x2 = " << x << endl;
	cout << "Количество итераций: " << k << endl;
}