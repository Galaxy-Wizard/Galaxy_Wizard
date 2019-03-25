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

void Score::genetate_all_moves()
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

						Score *current_score = new Score();
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

DWORD Score::search(const Matrix &position)
{
	DWORD search_result = 0;
	DWORD game_end_result = 0;
	DWORD enemy_plan_result = 0;
	DWORD my_plan_result = 0;
	
	//	1.
	if (game_ended(position, game_end_result))
	{
		return game_end_result;
	}

	//	2.
	enemy_plan(position, enemy_plan_result);

	//	3.
	my_plan(position, my_plan_result);

	//	4.
	if (abs(my_plan_result - enemy_plan_result) <= Pawn_Value / 3)
	{
		return enemy_plan_result + (my_plan_result - enemy_plan_result) / 2;
	}

	//	5.
	genetate_all_moves();

	//	6.
	auto ca = childen.begin();
	auto cz = childen.end();
	std::stable_sort(ca, cz, sort_procedure);

	//	7.
	for (auto child = childen.begin(); child != childen.end(); child++)
	{
		child->Evaluate();
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
		child->search(b1.position);
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

bool Score::enemy_plan(const Matrix &position, DWORD &result)
{
	return false;

	result = 0;
	return true;
}

bool Score::my_plan(const Matrix &position, DWORD &result)
{
	return false;

	result = 0;
	return true;
}

extern MachineStuding::MachineStudingMoveTypeDataList MachineStudingMoveTypeDataListSortData;

bool sort_procedure(const Score &s1, const Score &s2)
{
	auto s1_move_type = s1.move.get_move_type();
	auto s2_move_type = s2.move.get_move_type();

	double s1_move_weight = 0.0;
	double s2_move_weight = 0.0;

	for (auto mi = MachineStudingMoveTypeDataListSortData.MachineStudingData.begin(); mi != MachineStudingMoveTypeDataListSortData.MachineStudingData.end(); mi++)
	{
		if (bool(s1_move_type & mi->MoveType))
		{
			s1_move_weight += mi->Weight;
		}

		if (bool(s2_move_type & mi->MoveType))
		{
			s2_move_weight += mi->Weight;
		}
	}

	return s1_move_weight >= s2_move_weight;
}