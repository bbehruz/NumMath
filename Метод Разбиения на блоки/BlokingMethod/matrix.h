#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
using namespace std;

using matrixd = vector<vector<double>>;

namespace algebra
{
	enum Error { SizeError, NoElement, ZeroDivision };

    class Matrix
    {
    private:
        matrixd content;
    public:
        Matrix(unsigned m = 0, unsigned n = 0);     //  Создает матрицу нулей

        double element(unsigned i, unsigned j) const;  //  Получение значения из определенной ячейки
        void set_element(double e, unsigned i, unsigned j); //  Изменение значения ячейки
		matrixd GetMatrix() const;  //  вернуть матрицу
		void SetMatrix(matrixd matr); // Задать матрицу

        void same_num(double num);      // Заполняет матрицу одинаковыми значениями

        void random(int a, int b);  // Заполняет матрицу случайными числами

        Matrix operator + (const Matrix &matr) const;       // Сложение матрицы
        Matrix operator - (const Matrix &matr) const;       // Вычитание матрицы
        Matrix operator * (const Matrix &matr) const; // Умножение матриц
        Matrix operator * (double num) const;       // Умножение матрицы на скаляр

        unsigned get_n() const;        // Получить количество столбцов
        unsigned get_m() const;        // Получить количество строк

        void one(); // единичная матрица
        void transpose();  // транспонирование текущей матрицы
		Matrix minor(unsigned i, unsigned j) const;     // Нахождение минора
		double det() const;     // вычисление дискриминанта
		Matrix inverse() const;     // Нахождение обратной матрицы

    };
    void print_matrix(const Matrix &matr);        // Вывод матрицы на экран
}

#endif // MATRIX_H
