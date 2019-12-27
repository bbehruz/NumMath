#include <iostream>
#include "matrix.h"


using namespace std;
using namespace algebra;

int main()
{
	setlocale(0, "RUS");

	Matrix A;
	A.SetMatrix({
		{ -1, -1, -1, -2 },
		{ 2, 3, 4, 3 },
		{ -2, 0, 1, -6 },
		{ -2, -2, -3, -3 } });

	cout << "Matrix A" << endl;
	print_matrix(A);

	Matrix M, Q, N, P;
	M.SetMatrix({ { -1, -1 }, { 2, 3 } });
	Q.SetMatrix({ { 1, -6 }, { -3, -3 } });
	N.SetMatrix({ { -1, -2 }, { 4, 3 } });
	P.SetMatrix({ { -2, 0 }, { -2, -2 } });

	Matrix MInverse = M.inverse();
	Matrix QInverse = Q.inverse();

	Matrix X;
	X = M - N * QInverse * P;
	X = X.inverse();

	Matrix V;
	V = Q - P * MInverse * N;
	V = V.inverse();

	Matrix U, Y;
	U = V * P * MInverse * (-1);
	Y = X * N * QInverse * (-1);

	cout << "Matrix AInverse" << endl; 

	print_matrix(X);
	print_matrix(Y);
	print_matrix(U);
	print_matrix(V);
}