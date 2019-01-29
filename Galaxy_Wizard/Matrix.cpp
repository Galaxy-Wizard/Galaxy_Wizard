#include "pch.h"
#include "Matrix.h"
#include "Figure.h"

Matrix::Matrix()
{
	matrix_n = 0;
	matrix_m = 0;

	x_from = y_from = x_to = y_to = size_t(-1);
}

Matrix::Matrix(size_t m, size_t n)
{
	matrix_m = m;
	matrix_n = n;

	x_from = y_from = x_to = y_to = size_t(-1);

	for (size_t c = 0; c < m; c++)
	{
		std::vector<Figure*> line(n);
		for (size_t i = 0; i < n; i++)
		{
			line[i] = nullptr;
		}
		matrix.push_back(line);
	}

	enpassant = size_t(-1);
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
	matrix_m = m.matrix_m;
	matrix_n = m.matrix_n;

	x_from = y_from = x_to = y_to = size_t(-1);

	for (size_t c = 0; c < matrix_m; c++)
	{
		std::vector<Figure*> line(matrix_n);
		for (size_t i = 0; i < matrix_n; i++)
		{
			line[i] = nullptr;
		}
		matrix.push_back(line);
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

	x_from = m.x_from;
	y_from = m.y_from;
	x_to = m.x_to;
	y_to = m.y_to;

	enpassant = m.enpassant;
}

Matrix& Matrix::operator=(const Matrix& m)
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

	for (size_t c = 0; c < matrix_m; c++)
	{
		for (size_t i = 0; i < matrix_n; i++)
		{
			matrix.at(c).pop_back();
		}
		matrix.pop_back();
	}

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

	x_from = m.x_from;
	y_from = m.y_from;
	x_to = m.x_to;
	y_to = m.y_to;

	enpassant = m.enpassant;

	return *this;
}

Matrix& Matrix::put(size_t x, size_t y, Figure* f) throw(Exception)
{
	if (x < matrix_m && y < matrix_n)
	{
		if (f == nullptr)
		{
			if (matrix.at(x).at(y) != nullptr)
			{
				delete matrix.at(x).at(y);

				matrix.at(x).at(y) = nullptr;
			}
		}
		if (matrix.at(x).at(y) != nullptr)
		{
			delete matrix.at(x).at(y);
		}
		if (f == nullptr)
		{
			matrix.at(x).at(y) = f;
		}
		else
		{
			matrix.at(x).at(y) = f->Clone();
		}
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

void Matrix::format_move(std::string &current_move)
{
	char buffer_x_from[4];
	char buffer_y_from[4];
	char buffer_x_to[4];
	char buffer_y_to[4];

	memset(buffer_x_from, 0, sizeof(char) * 4);
	memset(buffer_y_from, 0, sizeof(char) * 4);
	memset(buffer_x_to, 0, sizeof(char) * 4);
	memset(buffer_y_to, 0, sizeof(char) * 4);

	if (x_from != size_t(-1) && x_to != size_t(-1) && y_from != size_t(-1) && y_to != size_t(-1))
	{
		_itoa_s(x_from + 1, buffer_x_from, 10);
		_itoa_s(x_to + 1, buffer_x_to, 10);
		buffer_y_from[0] = char(y_from) + 'a';
		buffer_y_to[0] += char(y_to) + 'a';

		current_move = std::string(" ") + std::string(buffer_y_from) + std::string(buffer_x_from) +
			std::string(buffer_y_to) + std::string(buffer_x_to);
	}
	else
	{
		current_move = std::string("____");
	}
}
