#pragma once
#include <list>
#include <string>
#include "basic_types.h"
#include "Move.h"
#include "Board.h"

class Score
{
public:
	Score();
	~Score();

	DWORD Evaluate();

	Score *parent;
	std::list<Score> childen;
	signed char side_to_move;
	Move move;

	std::string move_string;

	DWORD evaluation;

	DWORD iterative_search(size_t tree_task_depth_level, size_t tree_depth_level, size_t &nodes_calculated, Score **evaluation_best_score, DWORD alpha, DWORD beta, bool principal_variation);

	void genetate_all_moves();

	void prepare_board(Board &board);
};

