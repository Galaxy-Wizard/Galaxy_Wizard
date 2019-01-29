#pragma once
#include "Figure.h"
class Knight :
	public Figure
{
public:
	Knight(DWORD Score);
	~Knight();

	virtual Figure* Clone();
	virtual std::list<Matrix> moves(Matrix, size_t, size_t);
};
