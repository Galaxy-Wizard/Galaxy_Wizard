#pragma once
#include "Figure.h"
class Queen :
	public Figure
{
public:
	Queen(size_t x, size_t y, double Score);
	~Queen();

	virtual Figure* Clone();
	virtual std::list<Matrix> moves(Matrix, size_t, size_t);
};
