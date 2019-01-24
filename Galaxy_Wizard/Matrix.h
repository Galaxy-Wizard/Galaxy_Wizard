#pragma once
#include <vector>
#include "Exception.h"

class Matrix
{
protected:
	std::vector<std::vector<double>> matrix;
	size_t matrix_n;
	size_t matrix_m;
public:
	explicit Matrix();
	Matrix(size_t n, size_t m);
	~Matrix();
	Matrix(const Matrix &m);
	Matrix operator=(const Matrix m);

	Matrix put(size_t x, size_t y, double value) throw(Exception);
	double get(size_t x, size_t y) throw(Exception);
	size_t get_matrix_n() const;
	size_t get_matrix_m() const;

	Matrix operator+(const Matrix m) throw(Exception);
};

