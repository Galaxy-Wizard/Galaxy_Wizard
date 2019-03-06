#pragma once

#include "Board.h"
#include "Score.h"

class Game
{
public:
	Game();
	~Game();

	Board board;
	Score score;
};

