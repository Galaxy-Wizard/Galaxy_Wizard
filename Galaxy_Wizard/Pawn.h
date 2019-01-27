#pragma once
#include "Figure.h"
class Pawn :
	public Figure
{
public:
	Pawn(size_t x, size_t y, double Score);
	~Pawn();

	virtual Figure* Clone();
	virtual std::list<Matrix> moves(Matrix, size_t, size_t);
};