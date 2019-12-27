#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

double f(double x)
{
	return -2 * pow(x, 3) - 2 * pow(x, 2) + 2 * x + 5;
}

double f1(double x)
{
	return -6 * pow(x, 2) - 4 * x + 2;
}

double f2(double x)
{
	return -12 * x - 4;
}

double _f(double x)
{
	return 4 * x + pow(2, x) + 6;
}

double _f1(double x)
{
	return 4 + pow(2, x) * log(2);
}

double _f2(double x)
{
	return pow(2, x) * log(2) * log(2);
}


int main()
{
	setlocale(0, "RUS");
	unsigned k;
	double a, b, c, d, eps, x;
	eps = 0.001;

	a = -2; b = -1;

	k = 0;
	while (b - a > 2 * eps)
	{
		if (_f(a) * _f2(a) > 0)
		{
			d = a - _f(a) / _f1(a);
			c = (a * _f(b) - b * _f(a)) / (_f(b) - _f(a));
			a = d;
			b = c;
		}
		else
			if (_f(b) * _f2(b) > 0)
			{
				d = b - _f(b) / _f1(b);
				c = (a * _f(b) - b * _f(a)) / (_f(b) - _f(a));
				b = d;
				a = c;
			}
		k++;
	}
	x = (a + b) / 2;
	cout << "x = " << x << endl;
	cout << "Количество итераций: " << k << endl;

	a = 0; b = 2;

	k = 0;
	while (b - a > 2 * eps)
	{
		if (f(a) * f2(a) > 0)
		{
			d = a - f(a) / f1(a);
			c = (a * f(b) - b * f(a)) / (f(b) - f(a));
			a = d;
			b = c;
		}
		else
			if (f(b) * f2(b) > 0)
			{
				d = b - f(b) / f1(b);
				c = (a * f(b) - b * f(a)) / (f(b) - f(a));
				b = d;
				a = c;
			}
		k++;
	}
	x = (a + b) / 2;
	cout << "x = " << x << endl;
	cout << "Количество итераций: " << k << endl;

}