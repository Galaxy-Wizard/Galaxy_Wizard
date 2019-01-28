#pragma once
#include <list>
#include "tree.h"
#include "basic_types.h"
#include "board.h"

class Score
{
public:
	Score();
	~Score();

	WORD Evaluate();

	Board board;
	std::list<Score> childen;
	signed char side_to_move;

	void GenetateAllMoves();
};

