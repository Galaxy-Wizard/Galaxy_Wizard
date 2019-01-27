#pragma once

#include "matrix.h"
#include "Exception.h"

class Board
{
protected:
	Matrix position;
public:
	Board();
	Board(const Matrix m);
	~Board();
	Board(const Board &b);
	Board operator=(const Board b);

	Board move(const Matrix m);
};

