#include <iostream>
#include <cmath>

using namespace std;

double f(double x)
{
	return pow(1.3, 2 * x * x - 3 * x + 1);
}


double pass(double a, double b, double eps) {
    double Ymin = f(a), Xmin = 0;
    for (double i = a; i <= b; i = i + eps) {
        if (f(i) < Ymin) { //сравним текущее значение функции с новым
            Ymin = f(i);  //если оно *меньше, то оно записывается в переменную Ymin
            Xmin = i;   //значение аргумента при данном минимуме
        }
    }
    return Xmin;
}


double half_division(double a, double b, double eps) {
    double x1;
    double x2;
    double x3;
    while ((b - a) > (2 * eps)) {
        x1 = (3 * a + b) / 4;
        x2 = (a + b) / 2;
        x3 = (a + 3 * b) / 4;
        if ((f(x1) < f(x2)) && (f(x2) < f(x3)))
            b = x2;
        else
            if ((f(x1) > f(x2)) && (f(x2) > f(x3)))
                a = x2;
            else {
                a = x1;
                b = x3;
            }
    }
    return (a + b) / 2;
}


double gold_section(double a, double b, double eps) {
    double phi = (sqrt(5) - 1) / 2;
    double x1;
    double x2;
    while (b - a > 2 * eps) {
        x1 = phi * a + (1 - phi) * b;
        x2 = (1 - phi) * a + phi * b;
        if (f(x1) < f(x2))
            b = x2;
        else
            if (f(x1) > f(x2))
                a = x1;
    }
    return (a + b) / 2;
}


int main() {
	setlocale(LC_ALL,"Rus");
	double x0, d;
	double a, b;
    cout << "Введите x0: "; cin >> x0;
    cout << "Введите d(d>0): "; cin >> d;

	double xC = x0;
	double xL = x0 - d;
	double xR = x0 + d;
	double xN;
    int k = 0;

    while (!((f(xL) > f(xC)) && (f(xR) > f(xC)))) {
        if ((f(xL) > f(xC)) && (f(xC) > f(xR))) {
            xN = xR + 2 * d;
            xL = xC;
            xC = xR;
            xR = xN;
        }
        else 
            if ((f(xL) < f(xC)) && (f(xC) < f(xR))) {
                xN = xL - 2 * d;
                xR = xC;
                xC = xL;
                xL = xN;
            }
        d = d * 2;
        k++;
    }
    a = xL;
    b = xR;

    cout << "Количество итераций: " << k << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    cout << "Пассивный поиск: " << pass(a, b, 0.001) << endl;
    cout << "Метод половинного деления: " << half_division(a, b, 0.001) << endl;
    cout << "Метод золотого сечения: " << gold_section(a, b, 0.001) << endl;
}