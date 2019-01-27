#pragma once
#include "Figure.h"
class Rook :
	public Figure
{
public:
	Rook(size_t x, size_t y, double Score);
	~Rook();

	virtual Figure* Clone();
	virtual std::list<Matrix> moves(Matrix, size_t, size_t);
};
