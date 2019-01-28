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

	DWORD iterative_search(size_t tree_task_depth_level, size_t tree_depth_level, size_t &nodes_calculated, Score **evaluation_best_score, DWORD alpha, DWORD beta, bool principal_variation);

	void GenetateAllMoves();
};

