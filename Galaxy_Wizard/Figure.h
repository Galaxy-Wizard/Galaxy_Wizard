#pragma once

#include <list>

#include "basic_types.h"
#include "Matrix.h"

class Figure
{
public:
	Figure(size_t x, size_t y, DWORD Score);
	~Figure();

	DWORD Value;
	size_t m, n;

	virtual Figure* Clone() = 0;
	virtual std::list<Matrix> moves(Matrix, size_t, size_t) = 0;
};

