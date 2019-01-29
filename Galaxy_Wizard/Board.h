#pragma once

#include "matrix.h"

class Board
{
public:
	Board();
	Board(const Matrix &m);
	~Board();
	Board(const Board &b);
	Board& operator=(const Board& b);

	Board& move(const Matrix &m);

	Matrix position;
};

