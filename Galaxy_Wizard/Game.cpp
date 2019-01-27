#include "pch.h"
#include "Game.h"


Game::Game()
{
	Matrix position(8, 8);

	for (size_t i = 0; i < 8; i++)
	{
		position.put(i, 1, +Pawn::Value);
		position.put(i, 6, -Pawn::Value);
	}

	position.put(0, 0, +Rook::Value);
	position.put(7, 0, +Rook::Value);
	position.put(0, 7, -Rook::Value);
	position.put(7, 7, -Rook::Value);

	position.put(1, 0, +Knight::Value);
	position.put(6, 0, +Knight::Value);
	position.put(1, 7, -Knight::Value);
	position.put(6, 7, -Knight::Value);

	position.put(2, 0, +Bishop::Value);
	position.put(5, 0, +Bishop::Value);
	position.put(2, 7, -Bishop::Value);
	position.put(5, 7, -Bishop::Value);

	position.put(3, 0, +Queen::Value);
	position.put(4, 0, +King::Value);
	position.put(3, 7, -Queen::Value);
	position.put(4, 7, -King::Value);


	Board b(position);

	board = b;
}


Game::~Game()
{
}
