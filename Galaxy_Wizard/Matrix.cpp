#include "pch.h"
#include "Matrix.h"
#include "Figure.h"

Matrix::Matrix()
{
	matrix_n = 0;
	matrix_m = 0;
}

Matrix::Matrix(size_t m, size_t n)
{
	matrix_m = m;
	matrix_n = n;

	for (size_t c = 0; c < m; c++)
	{
		std::vector<Figure*> line(n);
		for (size_t i = 0; i < n; i++)
		{
			line[i] = nullptr;
		}
		matrix.push_back(line);
	}
}


Matrix::~Matrix()
{
	for (size_t c = 0; c < matrix_m; c++)
	{
		for (size_t i = 0; i < matrix_n; i++)
		{
			if (matrix.at(c).at(i) != nullptr)
			{
				delete matrix.at(c).at(i);
				matrix.at(c).at(i) = nullptr;
			}
		}
	}
}

Matrix::Matrix(const Matrix &m)
{
	matrix = m.matrix;
}

Matrix& Matrix::operator=(const Matrix& m) throw(Exception())
{
	if (matrix_m != m.matrix_m)
	{
		if (matrix_m == 0)
		{
			matrix_m = m.matrix_m;
			matrix_n = m.matrix_n;

			for (size_t c = 0; c < matrix_m; c++)
			{
				std::vector<Figure*> line(matrix_n);
				for (size_t i = 0; i < matrix_n; i++)
				{
					line[i] = nullptr;
				}
				matrix.push_back(line);
			}
		}
		else
		{
			throw Exception();
		}
	}

	if (matrix_n != m.matrix_n)
	{
		throw Exception();
	}

	for (size_t c = 0; c < matrix_n; c++)
	{
		for (size_t i = 0; i < matrix_m; i++)
		{
			if (m.matrix.at(c).at(i) != nullptr)
			{
				matrix.at(c).at(i) = m.matrix.at(c).at(i)->Clone();
			}
			else
			{
				matrix.at(c).at(i) = nullptr;
			}
		}
	}

	return *this;
}

Matrix& Matrix::put(size_t x, size_t y, Figure* f) throw(Exception)
{
	if (x < matrix_m && y < matrix_n)
	{
		if (matrix.at(x).at(y) != nullptr)
		{
			delete matrix.at(x).at(y);
		}
		matrix.at(x).at(y) = f;
	}
	else
	{
		throw Exception();
	}

	return *this;
}

Figure* Matrix::get(size_t x, size_t y) throw(Exception)
{
	Figure* value = nullptr;
	if (x < matrix_m && y < matrix_n)
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
