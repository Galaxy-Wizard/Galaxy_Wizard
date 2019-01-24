#include "pch.h"
#include "Matrix.h"

Matrix::Matrix()
{
	matrix_n = 0;
	matrix_m = 0;
}

Matrix::Matrix(size_t n, size_t m)
{
	matrix_n = n;
	matrix_m = m;

	for (size_t c = 0; c < n; c++)
	{
		std::vector<double> line;
		for (size_t i = 0; i < m; i++)
		{
			line[i] = 0;
		}
		matrix.push_back(line);
	}
}


Matrix::~Matrix()
{
}

Matrix::Matrix(const Matrix &m)
{
	matrix = m.matrix;
}

Matrix Matrix::operator=(const Matrix m)
{
	matrix = m.matrix;

	return *this;
}

Matrix Matrix::put(size_t x, size_t y, double value) throw(Exception)
{
	if (x < matrix_n && y < matrix_m)
	{
		matrix.at(x).at(y) = value;
	}
	else
	{
		throw Exception();
	}

	return *this;
}

double Matrix::get(size_t x, size_t y) throw(Exception)
{
	double value = 0;
	if (x < matrix_n && y < matrix_m)
	{
		value = matrix.at(x).at(y);
	}
	else
	{
		throw Exception();
	}

	return value;
}

size_t Matrix::get_matrix_n() const
{
	return matrix_n;
}

size_t Matrix::get_matrix_m() const
{
	return matrix_m;
}

Matrix Matrix::operator+(const Matrix m) throw(Exception)
{
	if (matrix_n == m.matrix_n && matrix_m == m.matrix_m)
	{
		for (size_t c = 0; c < matrix_n; c++)
		{
			for (size_t i = 0; i < matrix_m; i++)
			{
				matrix.at(c).at(i) += m.matrix.at(c).at(i);
			}
		}
	}
	else
	{
		throw Exception();
	}

	return *this;
}