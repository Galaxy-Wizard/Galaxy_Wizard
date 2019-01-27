#pragma once
#include "Figure.h"
class Bishop :
	public Figure
{
public:
	Bishop(size_t x, size_t y, double Score);
	~Bishop();

	virtual Figure* Clone();
	virtual std::list<Matrix> moves(Matrix, size_t, size_t);
};