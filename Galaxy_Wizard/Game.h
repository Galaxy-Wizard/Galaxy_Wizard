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
protected:
	Board board;
	Score score;
public:
	Game();
	~Game();
};

