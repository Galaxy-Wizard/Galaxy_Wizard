#include "pch.h"
#include "Board.h"


Board::Board()
{
}

Board::Board(const Matrix &m)
{
	position = m;
}


Board::~Board()
{
}

Board::Board(const Board& b)
{
	position = b.position;
}

Board& Board::operator=(const Board& b)
{
	position = b.position;

	return *this;
}

Board& Board::move(const Matrix& m)
{
	position = m;

	return *this;
}
