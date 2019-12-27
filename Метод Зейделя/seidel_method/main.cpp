#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	const unsigned n = 5;  //���������� ����������
	float a[n][n]; //��������� �������
	float c[n]; //����������� �������

	//�������������
	a[0][0] = 25;   a[0][1] = 4;    a[0][2] = 7;    a[0][3] = -3;    a[0][4] = -1;    c[0] = 32;
	a[1][0] = -8;   a[1][1] = 42;   a[1][2] = 8;    a[1][3] = -9;    a[1][4] = -3;    c[1] = 60;
	a[2][0] = -6;   a[2][1] = 4;    a[2][2] = 34;   a[2][3] = 4;     a[2][4] = -8;    c[2] = 84;
	a[3][0] = -8;   a[3][1] = 4;    a[3][2] = 7;    a[3][3] = 36;    a[3][4] = 9;     c[3] = 96;
	a[4][0] = 6;    a[4][1] = -6;   a[4][2] = -2;   a[4][3] = -4;    a[4][4] = 29;    c[4] = 23;

	//����� ������� �� �����
	cout << "������� A:\n\n";
	for (unsigned i = 0; i < n; i++)
	{
		for (unsigned j = 0; j < n; j++)
			cout << a[i][j] << " \t";
		cout << c[i] << "\t\n";
	}

	int k = 0;  //���������� ��������
	float x_old[n] = { 0 };
	float x_new[n];
	float eps = 0.001;
	float s, norma;
	//������ x-���
	do 
	{
		norma = 0;
		for (unsigned i = 0; i < n; i++) {
			s = 0;
			for (unsigned j = 0; j < n; j++) {
				if (j < i)
					s = s + x_new[j] * a[i][j];
				else
				if (j > i)
					s = s + x_old[j] * a[i][j];
			}
			x_new[i] = (c[i] - s) / a[i][i];
		}
		for (unsigned i = 0; i < n; i++)
		{
			if (fabs(x_old[i] - x_new[i]) > norma)
				norma = fabs(x_old[i] - x_new[i]); //���������� ����� �������
			x_old[i] = x_new[i];
		}
		k++;
	} while (norma > eps);
	
	cout << "\n\n";
	for (unsigned i = 0; i < n; i++)
		cout << "x[" << i << "] = " << x_new[i] << "\n";
	cout << "k = " << k << endl;
	system("pause");
}