#pragma once

#include "Matrix.h"
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

	bool legal_move(Move move);

	void set_root_position();

	void set_test_position();
};

