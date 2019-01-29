#include "pch.h"
#include "Game.h"


Game::Game()
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


	Board b(position);

	board = b;

	score.board = b;
}


Game::~Game()
{
}
