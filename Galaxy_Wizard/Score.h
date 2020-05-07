#pragma once
#include <list>
#include <string>
#include "basic_types.h"
#include "Move.h"
#include "Board.h"
#include "TimeManager.h"

class Score;

bool sort_tactics_procedure(const Score& s1, const Score& s2);

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

	DWORD search(const Matrix &position, size_t &nodes_calculated, size_t depth, Score* parent);

	static TimeManager *time_manager;

	bool game_ended(const Matrix &position, DWORD &result);
	bool enemy_plan(const Matrix &position, DWORD &result, size_t &nodes_calculated);
	bool my_plan(const Matrix &position, DWORD &result, size_t &nodes_calculated);

	bool IsMoveWeightAllowed(const Move m, const Board *board);
	double GetMoveWeight(const Move m, const Board *board);
	void genetate_all_moves(Score *parent);

	void delete_not_principal_variant_nodes(Score *principal_variant);

	void prepare_board(Board &board);
};

