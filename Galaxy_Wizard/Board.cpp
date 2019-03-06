#include "pch.h"
#include "Board.h"
#include "Figure.h"

#include "Matrix.h"

#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"


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
			if (legal_move(move))
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
	else
	{
		throw Exception();
	}
}

bool Board::legal_move(Move move)
{
	return true;
}

void Board::set_root_position()
{
	Matrix position(8, 8);

	for (size_t i = 0; i < 8; i++)
	{
		position.put(1, i, new Pawn(+Pawn_Value));
		position.put(6, i, new Pawn(-Pawn_Value));
	}

	position.put(0, 0, new Rook(+Rook_Value));
	position.put(0, 7, new Rook(+Rook_Value));
	position.put(7, 0, new Rook(-Rook_Value));
	position.put(7, 7, new Rook(-Rook_Value));

	position.put(0, 1, new Knight(+Knight_Value));
	position.put(0, 6, new Knight(+Knight_Value));
	position.put(7, 1, new Knight(-Knight_Value));
	position.put(7, 6, new Knight(-Knight_Value));

	position.put(0, 2, new Bishop(+Bishop_Value));
	position.put(0, 5, new Bishop(+Bishop_Value));
	position.put(7, 2, new Bishop(-Bishop_Value));
	position.put(7, 5, new Bishop(-Bishop_Value));

	position.put(0, 3, new Queen(+Queen_Value));
	position.put(0, 4, new King(+King_Value));
	position.put(7, 3, new Queen(-Queen_Value));
	position.put(7, 4, new King(-King_Value));
}