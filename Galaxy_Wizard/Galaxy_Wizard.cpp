// Galaxy_Wizard.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <time.h>

#include "Game.h"
#include "Board.h"
#include "Score.h"

int main()
{
    std::cout << "Galaxy_Wizard 1.0" << std::endl;

	std::cout << "Size of Game = " << sizeof(Game) << std::endl;
	std::cout << "Size of Board = " << sizeof(Board) << std::endl;
	std::cout << "Size of Score = " << sizeof(Score) << std::endl;
	std::cout << "Size of Matrix = " << sizeof(Matrix) << std::endl;
	std::cout << "Size of Figure = " << sizeof(Figure) << std::endl;
	std::cout << "Size of Node = " << (sizeof(Figure) * 32 + sizeof(Matrix)) + sizeof(Score) << std::endl;

	Game* game = nullptr;

	{
		if (game != nullptr)
		{
			delete game;

			game = nullptr;
		}

		game = new Game();

		if (game != nullptr)
		{
			Score *evaluation_best_score = nullptr;
			
			size_t nodes_calculated = 0;

			__time64_t calculation_start_time;
			_time64(&calculation_start_time);
			__time64_t calculation_end_time;

			game->score.evaluation = game->score.Evaluate();

			size_t tree_task_depth_level = 4;
			game->score.iterative_search(tree_task_depth_level, tree_task_depth_level, nodes_calculated, evaluation_best_score);

			_time64(&calculation_end_time);

			auto calculation_time = calculation_end_time - calculation_start_time;

			std::cout << "Calculating time " << calculation_time <<" seconds" << std::endl;

			std::cout << "Nodes calculated " << nodes_calculated << std::endl;

			if (calculation_time != 0)
			{
				std::cout << "Nodes per second " << nodes_calculated/ calculation_time << std::endl;
			}
			else
			{
				std::cout << "Nodes per second " << nodes_calculated / 1 << std::endl;
			}

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

			delete game;

			game = nullptr;
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
