#pragma once
#include "Figure.h"
class Rook :
	public Figure
{
public:
	Rook(DWORD Score);
	~Rook();

	bool rook_not_moved;

	virtual Figure* Clone();
	virtual std::list<Matrix> moves(Matrix, size_t, size_t);
};
