#pragma once

#include <list>

#include "Matrix.h"

class Figure
{
public:
	Figure(size_t x, size_t y, double Score);
	~Figure();

	double Value;
	size_t m, n;

	virtual Figure* Clone() = 0;
	virtual std::list<Matrix> moves(Matrix, size_t, size_t) = 0;
};

