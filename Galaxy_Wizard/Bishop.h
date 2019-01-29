#pragma once
#include "Figure.h"
class Bishop :
	public Figure
{
public:
	Bishop(DWORD Score);
	~Bishop();

	virtual void make_move(Matrix& matrix, Move move);
	virtual Figure* Clone();
	virtual std::list<Matrix> moves(Matrix, size_t, size_t);
};
