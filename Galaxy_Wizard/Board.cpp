#include "pch.h"
#include "Board.h"


Board::Board(const Matrix m)
{
	position = m;
}


Board::~Board()
{
}

Board::Board(const Board &b)
{
	position = b.position;
	position = b.position;
}

Board Board::operator=(const Board b)
{
	position = b.position;

	return *this;
}

Board Board::move(const Matrix m)
{
	position = position + m;

	return *this;
}
