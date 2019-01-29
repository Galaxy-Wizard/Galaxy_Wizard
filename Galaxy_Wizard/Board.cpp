#include "pch.h"
#include "Board.h"
#include "Figure.h"

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

void Board::make_move(Move move) throw (Exception())
{
	if (move.x_from < position.get_matrix_m() && move.y_from < position.get_matrix_n())
	{
		Figure *figure = position.get(move.x_from, move.y_from);

		if (figure != nullptr)
		{
			figure->make_move(position, move);
		}
		else
		{
			throw Exception();
		}
	}
	else
	{
		throw Exception();
	}
}