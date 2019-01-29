#pragma once
#include "Figure.h"
class Queen :
	public Figure
{
public:
	Queen(DWORD Score);
	~Queen();

	virtual void make_move(Matrix& matrix, Move move);
	virtual Figure* Clone();
	virtual std::list<Matrix> moves(Matrix, size_t, size_t);
};
