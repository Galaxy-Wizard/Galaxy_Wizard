#pragma once
#include <list>
#include <string>
#include "basic_types.h"
#include "board.h"

class Score
{
public:
	Score();
	~Score();

	DWORD Evaluate();

	Score *parent;
	Board board;
	std::list<Score> childen;
	signed char side_to_move;

	std::string move;
	DWORD evaluation;

	void GenetateAllMoves();
};

