#pragma once
#include "Figure.h"
class Pawn :
	public Figure
{
public:
	Pawn(DWORD Score);
	~Pawn();

	virtual void make_move(Matrix& matrix, Move move);
	virtual Figure* Clone();
	virtual std::list<Matrix> moves(Matrix, size_t, size_t);
	virtual bool is_atacking(size_t x, size_t y);
};
