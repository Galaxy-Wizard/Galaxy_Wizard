#pragma once

#include "Board.h"
#include "Matrix.h"

#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"

#include "Score.h"

class Game
{
public:
	Game();
	~Game();

	Board board;
	Score score;
};

