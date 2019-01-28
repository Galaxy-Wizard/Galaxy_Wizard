#include "pch.h"

#include <iostream>
#include "Score.h"
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

	return result;
}

void Score::GenetateAllMoves()
{
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

						Score current_score;
						current_score.parent = this;
						current_score.board = board;

						std::string current_move;
						current_figure_moves_iterator->format_move(current_move);
						current_score.move = current_move;

						current_score.side_to_move = -side_to_move;

						childen.push_back(current_score);
					}
				}
			}
		}
	}
}

void Score::iterative_search(size_t tree_task_depth_level, size_t tree_depth_level, size_t &nodes_calculated, Score *evaluation_best_score)
{
	Evaluate();
	nodes_calculated++;

	if (evaluation_best_score == nullptr)
	{
		evaluation_best_score = this;
	}

	Score *this_current_score = this;

	if (false)
	if (this_current_score != nullptr)
	{
		std::string variant;

		Score *current_score = this_current_score;
		for (; current_score != nullptr; current_score = current_score->parent)
		{
			std::string current_move;

			current_score->board.position.format_move(current_move);

			variant = current_move + std::string(" ") + variant;
		}

		if (evaluation_best_score != nullptr)
		{
			std::cout << "Variant " << variant << " ";
			std::cout << "Variant evaluation " << this_current_score->evaluation << std::endl;
		}
	}

	if (tree_depth_level == 0)
	{
		return;
	}

	GenetateAllMoves();

	if (false)
	{
		std::cout << "Tree depth level = " << tree_task_depth_level - tree_depth_level << std::endl;
		std::cout << "Moves generated = " << childen.size() << std::endl;
	}

	for (auto child = childen.begin(); child != childen.end(); child++)
	{
		Score *evaluation_child_best_score = evaluation_best_score;

		child->iterative_search(tree_task_depth_level, tree_depth_level-1, nodes_calculated, evaluation_child_best_score);

		if (side_to_move > 0)
		{
			if (evaluation_child_best_score->evaluation < evaluation_best_score->evaluation)
			{
				evaluation_best_score = evaluation_child_best_score;
				std::cout << "Tree depth level = " << tree_task_depth_level - tree_depth_level << std::endl;

				if (evaluation_best_score != nullptr)
				{
					std::string variant;

					Score *current_score = evaluation_best_score;
					for (; current_score != nullptr; current_score = current_score->parent)
					{
						std::string current_move;

						current_score->board.position.format_move(current_move);

						variant = current_move + std::string(" ") + variant;
					}

					if (evaluation_best_score != nullptr)
					{
						std::cout << "Best variant " << variant << " ";
						std::cout << "Best variant evaluation " << evaluation_best_score->evaluation << std::endl;
					}
				}
			}
		}
		else
		{
			if (side_to_move < 0)
			{
				if (evaluation_child_best_score->evaluation > evaluation_best_score->evaluation)
				{
					evaluation_best_score = evaluation_child_best_score;
					std::cout << "Tree depth level = " << tree_task_depth_level - tree_depth_level << std::endl;

					if (evaluation_best_score != nullptr)
					{
						std::string variant;

						Score *current_score = evaluation_best_score;
						for (; current_score != nullptr; current_score = current_score->parent)
						{
							std::string current_move;

							current_score->board.position.format_move(current_move);

							variant = current_move + std::string(" ") + variant;
						}

						if (evaluation_best_score != nullptr)
						{
							std::cout << "Best variant " << variant << " ";
							std::cout << "Best variant evaluation " << evaluation_best_score->evaluation << std::endl;
						}
					}
				}
			}
		}
	}
}