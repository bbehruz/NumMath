#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	const unsigned n = 5;  //количество переменных
	float a[n][n]; //начальная матрица
	float c[n]; //расширенная матрицы
	
	float s;
	float b[n][n], t[n][n];
	float x[n], y[n];

	//инициализация
	a[0][0] = -0.74;  a[0][1] = 0.47;   a[0][2] = -0.15;  a[0][3] = -0.3;   a[0][4] = 0.81;   c[0] = -0.97;
	a[1][0] = 0.01;   a[1][1] = -0.65;  a[1][2] = -0.64;  a[1][3] = 0.58;   a[1][4] = -0.04;  c[1] = -0.86;
	a[2][0] = -0.33;  a[2][1] = 0.01;   a[2][2] = -0.61;  a[2][3] = -0.95;  a[2][4] = 0.19;   c[2] = -0.82;
	a[3][0] = -0.96;  a[3][1] = -0.42;  a[3][2] = -0.03;  a[3][3] = 0.68;   a[3][4] = -0.71;  c[3] = 0.99;
	a[4][0] = 0.07;   a[4][1] = 0.73;   a[4][2] = -0.97;  a[4][3] = 0.84;   a[4][4] = -0.35;  c[4] = -0.11;

	//вывод матрицы на экран
	cout << "Матрица A:\n\n";
	for (unsigned i = 0; i < n; i++)
	{
		for (unsigned j = 0; j < n; j++)
			cout << a[i][j] << " \t";
		cout << c[i] << "\t\n";
	}
	
	//вычисление матрицы b и t
	for (unsigned i = 0; i < n; i++) {
		b[i][0] = a[i][0];
		t[0][i] = a[0][i] / b[0][0];
	}
	//вычисление матрицы b и t
	for (unsigned k = 1; k < n; k++) {
		for (unsigned i = k; i < n; i++) {
			s = 0;
			for (unsigned m = 0; m < k; m++)
				s = s + b[i][m] * t[m][k];
			b[i][k] = a[i][k] - s;
		}
		for (unsigned j = k + 1; j < n; j++) {
			s = 0;
			for (unsigned m = 0; m < k; m++)
				s = s + b[k][m] * t[m][j];
			t[k][j] = (a[k][j] - s) / b[k][k];
		}
	}

	//вычисление y и вывод
	y[0] = c[0] / b[0][0];
	for (unsigned i = 1; i < n; i++) {
		s = 0;
		for (unsigned m = 0; m < i; m++)
			s = s + b[i][m] * y[m];
		y[i] = (c[i] - s) / b[i][i];
	}
	cout << "\n\n";
	for (unsigned i = 0; i < n; i++)
		cout << "y[" << i << "] = " << y[i] << "\n";
	
	//вычисление x и вывод
	x[n - 1] = y[n - 1];
	for (int i = n - 2; i > -1; i--) {
		s = 0;
		for (int m = i + 1; m < n; m++)
			s = s + t[i][m] * x[m];
		x[i] = y[i] - s;
	}
	cout << "\n\n";
	for (unsigned i = 0; i < n; i++)
		cout << "x[" << i << "] = " << x[i] << "\n";
	
	system("pause");
}