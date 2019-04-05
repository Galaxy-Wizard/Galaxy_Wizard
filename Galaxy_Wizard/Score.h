#pragma once
#include <list>
#include <string>
#include "basic_types.h"
#include "Move.h"
#include "Board.h"
#include "TimeManager.h"

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

	DWORD search(const Matrix &position, size_t &nodes_calculated);

	static TimeManager *time_manager;

	bool game_ended(const Matrix &position, DWORD &result);
	bool enemy_plan(const Matrix &position, DWORD &result, size_t &nodes_calculated);
	bool my_plan(const Matrix &position, DWORD &result, size_t &nodes_calculated);

	void genetate_all_moves();

	void delete_not_principal_variant_nodes(Score *principal_variant);

	void prepare_board(Board &board);
};

bool sort_procedure(const Score &s1, const Score &s2);

