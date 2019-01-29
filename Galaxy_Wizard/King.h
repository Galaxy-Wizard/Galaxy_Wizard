#pragma once
#include "Figure.h"
class King :
	public Figure
{
public:
	King(DWORD Score);
	~King();

	bool king_not_moved;

	virtual Figure* Clone();
	virtual std::list<Matrix> moves(Matrix, size_t, size_t);
};

