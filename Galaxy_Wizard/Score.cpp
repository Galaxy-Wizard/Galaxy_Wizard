#include "pch.h"

#include <iostream>
#include <algorithm>
#include "Score.h"
#include "Board.h"
#include "Figure.h"

Score::Score()
	:side_to_move(1), evaluation(0), parent(nullptr)
{
}


Score::~Score()
{
}

DWORD Score::Evaluate()
{
#ifdef _DEBUG
	return 0;
#endif

	Board board;
	prepare_board(board);

	DWORD result = 0;
	for (size_t x = 0; x < board.position.get_matrix_m(); x++)
	{
		for (size_t y = 0; y < board.position.get_matrix_n(); y++)
		{
			Figure *figure = board.position.get(x, y);

			if (figure != nullptr)
			{
				result += figure->Value;
			}
		}
	}

	if (parent != nullptr)
	{
		result += parent->childen.size() * MoveScoreBonus * (-side_to_move);
	}

	return result;
}

double Score::GetMoveWeight(const Move m, const Board *board)
{
	double result = 0.0;

	double result_tactics = m.get_tactics_move_type();
	double result_strategy = m.get_strategy_move_type();

	result = result_tactics + result_strategy;

	return result;
}

bool Score::IsMoveWeightAllowed(const Move m, const Board *board)
{
	if (GetMoveWeight(m, board) >= MoveWeightAllowedValue)
	{
		return true;
	}
	else
	{
		return false;
	}

	return true;
}

void Score::genetate_all_moves(Score *parent)
{
	Board board;
	prepare_board(board);

	for (size_t x = 0; x < board.position.get_matrix_m(); x++)
	{
		for (size_t y = 0; y < board.position.get_matrix_n(); y++)
		{
			Figure *figure = board.position.get(x, y);

			if (figure != nullptr)
			{
				if (figure->Value * side_to_move > 0)
				{
					auto current_figure_moves = figure->moves(board.position, x, y);

					for (auto current_figure_moves_iterator = current_figure_moves.begin(); current_figure_moves_iterator != current_figure_moves.end(); current_figure_moves_iterator++)
					{
						Board board(*current_figure_moves_iterator);
						Move current_move = board.position.move;

						if (IsMoveWeightAllowed(current_move, &board))
						{
							Score* current_score = new Score();
							current_score->parent = this;
							current_score->move = current_move;

							std::string current_move_string;
							current_move.format_move(current_move_string);
							current_score->move_string = current_move_string;

							current_score->side_to_move = -side_to_move;

							childen.push_back(*current_score);
						}
					}
				}
			}
		}
	}
}

DWORD Score::search(const Matrix &position, size_t &nodes_calculated, size_t depth, Score *parent)
{
	DWORD search_result = 0;
	DWORD game_end_result = 0;
	DWORD enemy_plan_result = 0;
	DWORD my_plan_result = 0;

	size_t currently_nodes_calculated = 0;
	size_t currently_nodes_calculated_1 = 0;
	size_t currently_nodes_calculated_2 = 0;
	size_t currently_nodes_calculated_3 = 0;
	size_t currently_nodes_calculated_7 = 0;
	size_t currently_nodes_calculated_8 = 0;

	//	1.
	if (game_ended(position, game_end_result))
	{
		currently_nodes_calculated_1++;
		nodes_calculated = currently_nodes_calculated_1;
		return game_end_result;
	}

	//	2.
	enemy_plan(position, enemy_plan_result, currently_nodes_calculated_2);

	//	3.
	my_plan(position, my_plan_result, currently_nodes_calculated_3);

	//	4.
	if (abs(my_plan_result - enemy_plan_result) <= Pawn_Value / 3)
	{
		nodes_calculated = currently_nodes_calculated_2 + currently_nodes_calculated_3;
#ifndef _DEBUG
#ifdef PLAN
		return enemy_plan_result + (my_plan_result + enemy_plan_result) / 2;
#endif
#endif
	}

	//	5.
	if (depth == 0)
	{
		genetate_all_moves(parent);
	}

	//	6.
    const auto ca = childen.begin();
	const auto cz = childen.end();
    std::stable_sort(ca, cz, sort_tactics_procedure);

	//	7.
	for (auto child = childen.begin(); child != childen.end(); child++)
	{
		currently_nodes_calculated_7++;
		child->Evaluate();
	}

	{
		Score *this_current_score = this;

		if (this_current_score != nullptr)
		{
			std::string variant;

			Score *current_score = this_current_score;
			for (; current_score != nullptr; current_score = current_score->parent)
			{
				std::string current_move;

				current_score->move.format_move(current_move);

				variant = current_move + std::string(" ") + variant;
			}

			if (this_current_score != nullptr)
			{
				std::cout << "Depth " << depth << " ";
				std::cout << "Current variant " << variant << " ";
				std::cout << "Current variant evaluation " << this_current_score->evaluation << std::endl;
			}
		}
	}

	currently_nodes_calculated += currently_nodes_calculated_2 + currently_nodes_calculated_3 + currently_nodes_calculated_7;

	if (depth == 0)
	{
		return evaluation;
	}

	//	8.
	for (auto child = childen.begin(); child != childen.end(); child++)
	{
		if (time_manager->think_time_expired())
		{
			return evaluation;
		}

		Board b1;
		child->prepare_board(b1);
		child->search(b1.position, currently_nodes_calculated_8, depth-1, this);
		currently_nodes_calculated += currently_nodes_calculated_8;
	}

	//	9.
	search_result = evaluation;

	for (auto child = childen.begin(); child != childen.end(); child++)
	{
		if (
			((search_result > child->evaluation) && (side_to_move > 0))
			||
			((search_result < child->evaluation) && (side_to_move < 0))
			)
		{
			search_result = child->evaluation;
		}
	}

	evaluation = search_result;

	return search_result;
}

void Score::prepare_board(Board &board)
{
	Score *last_score = this;
	Score *start_score = nullptr;

	std::list<Score*> path_score;

	Score *current_score = last_score;

	for (; current_score != nullptr;)
	{
		if (current_score->parent != nullptr)
		{
			path_score.push_back(current_score);
			start_score = current_score->parent;
		}
		else
		{
			//	Initial board should be prepared here
			board.set_root_position();
			//board.set_test_position();

			break;
		}
		current_score = current_score->parent;
	}

	for (auto s = path_score.rbegin(); s != path_score.rend(); s++)
	{
		board.make_move((*s)->move);
	}
}

void Score::delete_not_principal_variant_nodes(Score *principal_variant)
{
	if (principal_variant != nullptr)
	{
		if (principal_variant->parent != nullptr)
		{
			Score *current_score = principal_variant->parent;

			auto child = current_score->childen.begin();
			for (; child != current_score->childen.end(); child++)
			{
				if (principal_variant != &(*child))
				{
					current_score->childen.erase(child);

					child = current_score->childen.begin();
				}
			}

			delete_not_principal_variant_nodes(current_score);
		}
	}
}

bool Score::game_ended(const Matrix &position, DWORD &result)
{
	return false;

	result = 0;
	return true;
}

bool Score::enemy_plan(const Matrix &position, DWORD &result, size_t &nodes_calculated)
{
	return false;

	result = 0;
	return true;
}

bool Score::my_plan(const Matrix &position, DWORD &result, size_t &nodes_calculated)
{
	return false;

	result = 0;
	return true;
}

extern MachineStuding::MachineStudingTacticsMoveTypeDataList MachineStudingTacticsMoveTypeDataListSortData;
extern MachineStuding::MachineStudingStrategyMoveTypeDataList MachineStudingStrategyMoveTypeDataListSortData;

bool sort_tactics_procedure(const Score &s1, const Score &s2)
{
	auto s1_tactics_move_type = s1.move.get_tactics_move_type();
	auto s2_tactics_move_type = s2.move.get_tactics_move_type();

	double s1_tactics_move_weight = 0.0;
	double s2_tactics_move_weight = 0.0;

	auto mi = MachineStudingTacticsMoveTypeDataListSortData.MachineStudingData.back();

	for (auto av = mi.AtomVector.begin(); av != mi.AtomVector.end(); av++)
	{
		if (bool(s1_tactics_move_type & av->MoveType))
		{
			s1_tactics_move_weight += av->Weight;
		}

		if (bool(s2_tactics_move_type & av->MoveType))
		{
			s2_tactics_move_weight += av->Weight;
		}
	}

	return s1_tactics_move_weight < s2_tactics_move_weight;
}

