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

DWORD Score::iterative_search(size_t tree_task_depth_level, size_t tree_depth_level, size_t &nodes_calculated, Score **evaluation_best_score, DWORD alpha, DWORD beta, bool principal_variation)
{
	if (evaluation_best_score == nullptr)
	{
		*evaluation_best_score = this;
	}

	if (tree_task_depth_level <= tree_depth_level)
	{
		DWORD best_evaluation = evaluation = Evaluate();
		nodes_calculated++;

		if (best_evaluation > beta)
		{
			return best_evaluation;
		}

		if (principal_variation && best_evaluation > alpha)
			alpha = best_evaluation;

		DWORD prior_pruning_base = best_evaluation + 128;

		if (childen.size() == 0)
		{
			genetate_all_moves();
		}

		for (auto child = childen.begin(); child != childen.end(); child++)
		{
			Score *evaluation_child_best_score = &(*child);

			Board board;

			child->prepare_board(board);

			DWORD prior_pruning = prior_pruning_base + board.position.get(board.position.move.x_to, board.position.move.y_to)->Value;

			if (prior_pruning <= alpha)
			{
				best_evaluation = std::max(best_evaluation, prior_pruning);
				continue;
			}

			evaluation = -child->iterative_search(tree_task_depth_level, tree_depth_level, nodes_calculated, &evaluation_child_best_score, -beta, -alpha, principal_variation);

			if (evaluation > best_evaluation)
			{
				best_evaluation = evaluation;

				if (evaluation > alpha)
				{
					if (principal_variation)
					{
						*evaluation_best_score = evaluation_child_best_score;
					}

					if (principal_variation && evaluation < beta)
						alpha = evaluation;
					else
					{
						break;
					}
				}
			}
		}

		return best_evaluation;
	}

	if (childen.size() == 0)
	{
		genetate_all_moves();
	}

	if (alpha >= beta)
	{
		return alpha;
	}

	DWORD best_evaluation = -4 * King_Value;

	evaluation = best_evaluation;

	for (auto child = childen.begin(); child != childen.end(); child++)
	{
		Score *evaluation_child_best_score = &(*child);

		DWORD child_static_evaluation = child->evaluation = child->Evaluate();
		nodes_calculated++;

		{
			if (tree_task_depth_level - tree_depth_level + 1 >= 3)
			{
				evaluation = -child->iterative_search(tree_task_depth_level, tree_depth_level + 1, nodes_calculated, &evaluation_child_best_score, -alpha - 1, -alpha, false);
			}

			if (evaluation > alpha || !principal_variation)
			{
				evaluation = -child->iterative_search(tree_task_depth_level, tree_depth_level + 1, nodes_calculated, &evaluation_child_best_score, -alpha - 1, -alpha, false);
			}

			if (principal_variation && evaluation > alpha && (tree_depth_level == 0 || evaluation < beta))
			{
				evaluation = -child->iterative_search(tree_task_depth_level, tree_depth_level + 1, nodes_calculated, &evaluation_child_best_score, -beta, -alpha, true);
			}
		}

		if (evaluation > best_evaluation)
		{
			best_evaluation = evaluation;

			if (evaluation > alpha)
			{
				if (principal_variation)
				{
					*evaluation_best_score = evaluation_child_best_score;
				}

				if (principal_variation && evaluation < beta)
				{
					alpha = evaluation;
				}
				else
				{
					break;
				}
			}
		}
	}

	evaluation = best_evaluation;

	return best_evaluation;
}

void Score::prepare_board(Board &board)
{
	Score *last_score = this;
	Score *start_score = nullptr;

	std::list<Score*> path_score;

	Score *current_score = last_score;

	for (; current_score != nullptr;)
	{
		path_score.push_back(current_score);
		if (current_score->parent != nullptr)
		{
			start_score = current_score->parent;
		}
		else
		{
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