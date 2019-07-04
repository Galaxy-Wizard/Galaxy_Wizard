#pragma once
#include "Figure.h"
class Knight :
	public Figure
{
public:
	Knight(DWORD Score);
	~Knight();

	virtual void make_move(Matrix& matrix, Move move);
	virtual Figure* Clone();
	virtual std::list<Matrix> moves(Matrix, size_t, size_t);
	virtual bool is_atacking(size_t x, size_t y);
};
