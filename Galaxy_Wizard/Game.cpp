#include "pch.h"
#include "Game.h"


Game::Game()
{
	Board b;

	b.set_root_position();

	board = b;
}


Game::~Game()
{
}
