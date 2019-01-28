#include "pch.h"
#include "Score.h"
#include "Figure.h"

Score::Score()
	:side_to_move(1)
{
}


Score::~Score()
{
}

WORD Score::Evaluate()
{
	WORD result = 0;
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
						current_score.board = board;

						current_score.side_to_move = -side_to_move;

						childen.push_back(current_score);
					}
				}
			}
		}
	}
}
