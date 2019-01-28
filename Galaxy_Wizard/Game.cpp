#include "pch.h"
#include "Game.h"


Game::Game()
{
	Matrix position(8, 8);

	for (size_t i = 0; i < 8; i++)
	{
		position.put(1, i, new Pawn(1, i, +Pawn_Value));
		position.put(6, i, new Pawn(6, i, -Pawn_Value));
	}

	position.put(0, 0, new Rook(0, 0, +Rook_Value));
	position.put(0, 7, new Rook(0, 7, +Rook_Value));
	position.put(7, 0, new Rook(7, 0, -Rook_Value));
	position.put(7, 7, new Rook(7, 7, -Rook_Value));

	position.put(0, 1, new Knight(0, 1, +Knight_Value));
	position.put(0, 6, new Knight(0, 6, +Knight_Value));
	position.put(7, 1, new Knight(7, 1, -Knight_Value));
	position.put(7, 6, new Knight(7, 6, -Knight_Value));

	position.put(0, 2, new Bishop(0, 2, +Bishop_Value));
	position.put(0, 5, new Bishop(0, 5, +Bishop_Value));
	position.put(7, 2, new Bishop(7, 2, -Bishop_Value));
	position.put(7, 5, new Bishop(7, 5, -Bishop_Value));

	position.put(0, 3, new Queen(0, 3, +Queen_Value));
	position.put(0, 4, new King(0, 4, +King_Value));
	position.put(7, 3, new Queen(7, 3, -Queen_Value));
	position.put(7, 4, new King(4, 4, -King_Value));


	Board b(position);

	board = b;

	score.board = b;
}


Game::~Game()
{
}
