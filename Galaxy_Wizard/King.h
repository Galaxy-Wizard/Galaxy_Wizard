#pragma once
#include "Figure.h"
class King :
	public Figure
{
public:
	King(DWORD Score);
	~King();

	virtual void make_move(Matrix& matrix, Move move);
	virtual Figure* Clone();
	virtual std::list<Matrix> moves(Matrix, size_t, size_t);
};

