#include "matrix.h"
#include <vector>
#include <iostream>
#include <cmath>


using namespace std;

namespace algebra
{

    Matrix::Matrix(unsigned m, unsigned n)
    {
        content.resize(m);
        for (unsigned i = 0; i < m; i++)
                content[i].resize(n);
    }


    double Matrix::element(unsigned i, unsigned j) const
    {
        unsigned m1 = this->content.size();
        unsigned n1 = this->content[0].size();
        if (i > m1 || j > n1)
        {
            throw NoElement;
            //  Такого элемента матрицы нет!!!
        }
        return this->content[i][j];
    }


    void Matrix::set_element(double e, unsigned i, unsigned j)
    {
        unsigned m1 = this->content.size();
        unsigned n1 = this->content[0].size();
        if (i > m1 || j > n1)
        {
            throw NoElement;
            //  Такого элемента матрицы нет!!!
        }
        this->content[i][j] = e;
    }


	matrixd Matrix::GetMatrix() const
	{
		return content;
	}


	void Matrix::SetMatrix(matrixd matr)
	{
		this->content = matr;
	}


    void Matrix::same_num(double num)
    {
        for (unsigned i = 0; i < get_m(); i++)
            for (unsigned j = 0; j < get_n(); j++)
                content[i][j] = num;
    }


    void Matrix::random(int a, int b)
    {
        for (unsigned i = 0; i < get_m(); i++)
            for (unsigned j = 0; j < get_n(); j++)
                content[i][j] = double(rand() % b + a) + rand()/double(RAND_MAX);;
    }


    Matrix Matrix::operator + (const Matrix &matr) const
    {
        // сложение матриц
        unsigned m1 = this->content.size();
        unsigned n1 = this->content[0].size();
        unsigned m2 = matr.content.size();
        unsigned n2 = matr.content[0].size();

        if (m1 != m2 || n1 != n2)
        {
            throw SizeError;
            //  Матрицы имеют разные размеры!!!
        }


        Matrix rezult(m1, n1);

        for (unsigned i = 0; i < m1; i++)
        {
            for (unsigned j = 0; j < n1; j++)
            {
                rezult.content[i][j] = this->content[i][j] + matr.content[i][j];
            }
        }

        return rezult;
    }


    Matrix Matrix::operator - (const Matrix &matr) const
    {
        // вычитание матриц
        unsigned m1 = this->content.size();
        unsigned n1 = this->content[0].size();
        unsigned m2 = matr.content.size();
        unsigned n2 = matr.content[0].size();

        if (m1 != m2 || n1 != n2)
        {
            throw SizeError;
            //  Матрицы имеют разные размеры!!!
        }

        Matrix rezult(m1, n1);

        for (unsigned i = 0; i < m1; i++)
        {
            for (unsigned j = 0; j < n1; j++)
            {
                rezult.content[i][j] = this->content[i][j] - matr.content[i][j];
            }
        }

        return rezult;
    }


    Matrix Matrix::operator * (const Matrix &matr) const
    {
        // умножение матриц
        unsigned m1 = this->content.size();
        unsigned n1 = this->content[0].size();
        unsigned m2 = matr.content.size();
        unsigned n2 = matr.content[0].size();
        Matrix rezult(m1, n2);

        if (n1 != m2)
        {
            throw SizeError;
        }


        for (unsigned i = 0; i < m1; i++)
        {
            for (unsigned j = 0; j < n2; j++)
            {
                for (unsigned k = 0; k < n1; k++)
                {
                    rezult.content[i][j] += this->content[i][k] * matr.content[k][j];
                }
            }
        }

        return rezult;
    }


    Matrix Matrix::operator * (double num) const
    {
        // умножение матрицы на скаляр
        unsigned m = this->content.size();
        unsigned n = this->content[0].size();
        Matrix rezult(m, n);
        for (unsigned i = 0; i < m; i++)
        {
            for (unsigned j = 0; j < n; j++)
            {
                rezult.content[i][j] = this->content[i][j] * num;
            }
        }
        return rezult;
    }


    unsigned Matrix::get_n() const
    {
        return content[0].size();
    }


    unsigned Matrix::get_m() const
    {
        return content.size();
    }


    void Matrix::one()
    {
        unsigned m = content.size();
        unsigned n = content[0].size();
        for (unsigned i = 0; i < m; i++)
        {
            for (unsigned j = 0; j < n; j++)
            {
                if (i == j)
                {
                    content[i][j] = 1.0;
                }
                else
                {
                    content[i][j] = 0.0;
                }
            }
        }
    }


    void Matrix::transpose()
    {
        unsigned m = content.size();
        unsigned n = content[0].size();
        Matrix buf(n, m);
        for (unsigned i = 0; i < n; i++)
             for (unsigned j = 0; j < m; j++)
                 buf.content[i][j] = content[j][i];
        *this = buf;
    }


	Matrix Matrix::minor(unsigned i, unsigned j) const
	{
		// нахождение минора
		Matrix minor;
		unsigned m = content.size();
		unsigned n = content[0].size();
		for (unsigned k = 0; k < m; k++)
		{
			vector<double> line;
			for (unsigned l = 0; l < n; l++)
			{
				if (k != i && l != j)
				{
					double e = content[k][l];
					line.push_back(e);
				}
			}
			if (line.size() > 0)
			{
				minor.content.push_back(line);
			}
		}
		return minor;
	}


	double Matrix::det() const 
	{
		// нахождение определителя
		unsigned n = content.size();
		double _det;
		if (n == 1)
		{
			_det = content[0][0];
			return _det;
		}
		if (n == 2)
		{
			_det = content[0][0] * content[1][1] - content[0][1] * content[1][0];
			return _det;
		}
		else
		{
			_det = 0.0;
			for (unsigned i = 0; i < 1; i++)
			{
				for (unsigned j = 0; j < n; j++)
				{
					Matrix minor = this->minor(i, j);
					_det += pow(-1, i + j) * content[i][j] * minor.det();
				}
			}
			return _det;
		}
	}


	Matrix Matrix::inverse() const
	{
		// нахождение обратной матрицы
		double _det = this->det();
		if (_det == 0.0)
		{
			throw ZeroDivision;
			//   Определитель = 0. Не могу найти обратную матрицу !!!
		}
		else
		{
			unsigned n = content.size();
			Matrix matr_inv;
			matr_inv.content = this->content;
			for (unsigned i = 0; i < n; i++)
			{
				for (unsigned j = 0; j < n; j++)
				{
					Matrix minor = this->minor(i, j);
					matr_inv.content[i][j] = pow(-1, i + j) * minor.det();
				}
			}
			matr_inv.transpose();
			matr_inv = matr_inv * (1 / _det);
			return matr_inv;
		}
	}


    void print_matrix(const Matrix &matr)
    {
        cout << endl;
        for (unsigned i = 0; i < matr.get_m(); i++)
        {
            for (unsigned j = 0; j < matr.get_n(); j++)
            {
                cout << matr.element(i,j) << "	";
            }
            cout << endl;
        }

        cout << endl;
    }

}

