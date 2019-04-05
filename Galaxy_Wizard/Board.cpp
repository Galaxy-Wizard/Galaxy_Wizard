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
				position.side_to_move = -position.side_to_move;
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
	Matrix root_position(8, 8);

	for (size_t i = 0; i < 8; i++)
	{
		root_position.put(i, 1, new Pawn(+Pawn_Value));
		root_position.put(i, 6, new Pawn(-Pawn_Value));
	}

	root_position.put(0, 0, new Rook(+Rook_Value));
	root_position.put(7, 0, new Rook(+Rook_Value));
	root_position.put(0, 7, new Rook(-Rook_Value));
	root_position.put(7, 7, new Rook(-Rook_Value));

	root_position.put(1, 0, new Knight(+Knight_Value));
	root_position.put(6, 0, new Knight(+Knight_Value));
	root_position.put(1, 7, new Knight(-Knight_Value));
	root_position.put(6, 7, new Knight(-Knight_Value));

	root_position.put(2, 0, new Bishop(+Bishop_Value));
	root_position.put(5, 0, new Bishop(+Bishop_Value));
	root_position.put(2, 7, new Bishop(-Bishop_Value));
	root_position.put(5, 7, new Bishop(-Bishop_Value));

	root_position.put(3, 0, new Queen(+Queen_Value));
	root_position.put(4, 0, new King(+King_Value));
	root_position.put(3, 7, new Queen(-Queen_Value));
	root_position.put(4, 7, new King(-King_Value));

	position = root_position;
}