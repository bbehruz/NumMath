#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	const unsigned n = 5;  //количество переменных
	float a[n][n]; //начальная матрица
	float c[n]; //расширенная матрицы

	//инициализация
	a[0][0] = 25;   a[0][1] = 4;    a[0][2] = 7;    a[0][3] = -3;    a[0][4] = -1;    c[0] = 32;
	a[1][0] = -8;   a[1][1] = 42;   a[1][2] = 8;    a[1][3] = -9;    a[1][4] = -3;    c[1] = 60;
	a[2][0] = -6;   a[2][1] = 4;    a[2][2] = 34;   a[2][3] = 4;     a[2][4] = -8;    c[2] = 84;
	a[3][0] = -8;   a[3][1] = 4;    a[3][2] = 7;    a[3][3] = 36;    a[3][4] = 9;     c[3] = 96;
	a[4][0] = 6;    a[4][1] = -6;   a[4][2] = -2;   a[4][3] = -4;    a[4][4] = 29;    c[4] = 23;

	//вывод матрицы на экран
	cout << "Матрица A:\n\n";
	for (unsigned i = 0; i < n; i++)
	{
		for (unsigned j = 0; j < n; j++)
			cout << a[i][j] << " \t";
		cout << c[i] << "\t\n";
	}

	int k = 0;  //количество итераций
	float x[n] = {0};
	float xn[n];
	float eps = 0.001;
	float norma;
	//расчёт x-сов
	do
	{
		norma = 0;
		for (unsigned i = 0; i < n; i++)
		{
			xn[i] = c[i];
			for (unsigned j = 0; j < n; j++)
			{
				if (i != j)
					xn[i] -= a[i][j] * x[j];
			}
			xn[i] /= a[i][i];
		}
		for (unsigned i = 0; i < n; i++)
		{
			if (fabs(x[i] - xn[i]) > norma)
				norma = fabs(x[i] - xn[i]); //Вычисление нормы вектора
			x[i] = xn[i];
		}
		k++;

	} while (norma > eps);

	cout << "\n\n";
	for (unsigned i = 0; i < n; i++)
		cout << "x[" << i << "] = " << x[i] << "\n";
	cout << "k = " << k << endl;
	system("pause");
}