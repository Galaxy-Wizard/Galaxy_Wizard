#pragma once
#include "Figure.h"
class King :
	public Figure
{
public:
	King(size_t x, size_t y, double Score);
	~King();

	virtual Figure* Clone();
	virtual std::list<Matrix> moves(Matrix, size_t, size_t);
};

