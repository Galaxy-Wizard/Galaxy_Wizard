#pragma once
#include "Figure.h"
class Knight :
	public Figure
{
public:
	Knight(size_t x, size_t y, DWORD Score);
	~Knight();

	virtual Figure* Clone();
	virtual std::list<Matrix> moves(Matrix, size_t, size_t);
};
