#pragma once

#include <list>

#include "basic_types.h"
#include "Matrix.h"

class Figure
{
public:
	Figure(DWORD Score);
	virtual ~Figure();

	DWORD Value;

	virtual void make_move(Matrix&, Move) = 0;
	virtual Figure* Clone() = 0;
	virtual std::list<Matrix> moves(Matrix, size_t, size_t) = 0;
};

