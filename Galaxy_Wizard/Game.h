#pragma once

#include "Board.h"
#include "Matrix.h"

#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"

const double King_Value = 500;
const double Queen_Value = 11;
const double Rook_Value = 6;
const double Bishop_Value = 4.5;
const double Knight_Value = 4;
const double Pawn_Value = 1;

class Game
{
protected:
	Board board;
public:
	Game();
	~Game();
};

