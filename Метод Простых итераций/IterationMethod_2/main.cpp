#include <iostream>
#include <math.h>

using namespace std;

double h(double x)
{
	return sqrt(x) - 3 * x + 1;
}

double hi(double x, double L) 
{
	return  x - L * h(x);
}


int main()
{
	setlocale(0, "RUS");
	unsigned k;
	double x_old, x_new, x0, eps;
	eps = 0.0001;

	double L = -0.4;
	x0 = 0;
	x_old = x0;
	x_new = hi(x_old, L);

	k = 1;
	while (fabs(x_new - x_old) > eps)
	{
		x_old = x_new;
		x_new = hi(x_old, L);
		k++;
	}
	cout << "x_new = " << x_new << endl;
	cout << "Количество итераций: " << k << endl;

}