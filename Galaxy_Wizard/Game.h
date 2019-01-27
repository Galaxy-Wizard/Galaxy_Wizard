#pragma once

#include "Board.h"
#include "Matrix.h"

#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"

class Game
{
protected:
	Board board;
public:
	Game();
	~Game();
};

