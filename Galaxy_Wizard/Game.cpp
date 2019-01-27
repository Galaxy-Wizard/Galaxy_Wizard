#include "pch.h"
#include "Game.h"


Game::Game()
{
	Matrix position(8, 8);

	for (size_t i = 0; i < 8; i++)
	{
		position.put(1, i, new Pawn(i, 1, +Pawn_Value));
		position.put(6, i, new Pawn(i, 6, -Pawn_Value));
	}

	position.put(0, 0, new Rook(0, 0, +Rook_Value));
	position.put(0, 7, new Rook(7, 0, +Rook_Value));
	position.put(7, 0, new Rook(0, 7, -Rook_Value));
	position.put(7, 7, new Rook(7, 7, -Rook_Value));

	position.put(0, 1, new Knight(1, 0, +Knight_Value));
	position.put(0, 6, new Knight(6, 0, +Knight_Value));
	position.put(7, 1, new Knight(1, 7, -Knight_Value));
	position.put(7, 6, new Knight(6, 7, -Knight_Value));

	position.put(0, 2, new Bishop(2, 0, +Bishop_Value));
	position.put(0, 5, new Bishop(5, 0, +Bishop_Value));
	position.put(7, 2, new Bishop(2, 7, -Bishop_Value));
	position.put(7, 5, new Bishop(5, 7, -Bishop_Value));

	position.put(0, 3, new Queen(3, 0, +Queen_Value));
	position.put(0, 4, new King(4, 0, +King_Value));
	position.put(7, 3, new Queen(3, 7, -Queen_Value));
	position.put(7, 4, new King(4, 7, -King_Value));


	Board b(position);

	board = b;
}


Game::~Game()
{
}
