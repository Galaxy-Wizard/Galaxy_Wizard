#pragma once

#include "matrix.h"
#include "Move.h"

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

	void make_move(Move move) throw (Exception());
};

