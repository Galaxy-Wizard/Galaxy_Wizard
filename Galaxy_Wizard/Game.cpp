#include "pch.h"
#include "Game.h"


Game::Game()
{
	Board b;

	b.set_root_position();

	//b.set_test_position();

	board = b;
}


Game::~Game()
{
}
