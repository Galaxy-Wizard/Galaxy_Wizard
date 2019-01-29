﻿// Galaxy_Wizard.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <time.h>

#include "Game.h"
#include "Board.h"
#include "Score.h"

#include <algorithm>

int main()
{
    std::cout << "Galaxy_Wizard 1.0" << std::endl;

	std::cout << "Size of Game = " << sizeof(Game) + 30 * sizeof(void*) + 2 * (8 * 8 * sizeof(void*) + sizeof(Figure) * 32) << std::endl;
	std::cout << "Size of Board = " << sizeof(Board) + 8 * 8 * sizeof(void*) + sizeof(Figure) * 32 << std::endl;
	std::cout << "Size of Score = " << sizeof(Score) + 30 * sizeof(void*) + 8 * 8 * sizeof(void*) + sizeof(Figure) * 32 << std::endl;
	std::cout << "Size of Matrix = " << sizeof(Matrix) + 8 * 8 * sizeof(void*) + sizeof(Figure) * 32 << std::endl;
	std::cout << "Size of Figure = " << sizeof(Figure) << std::endl;
	std::cout << "Size of Node = " << sizeof(Score) + 30 * sizeof(void*) + 8 * 8 * sizeof(void*) + sizeof(Figure) * 32 << std::endl;

	Game* game = nullptr;

	try
	{
		if (game != nullptr)
		{
			delete game;

			game = nullptr;
		}

		game = new Game();

		if (game != nullptr)
		{
			try
			{
				Score *evaluation_best_score = nullptr;

				size_t nodes_calculated = 0;

				__time64_t calculation_start_time;
				_time64(&calculation_start_time);
				__time64_t calculation_end_time;

				game->score.evaluation = game->score.Evaluate();
				nodes_calculated++;

				DWORD alpha = -4 * King_Value;
				DWORD beta = +4 * King_Value;

				DWORD delta = 20;

				size_t maximum_tree_task_depth_level = 6;
				size_t tree_task_depth_level = 0;

				Score *evaluation_best_score_start = &game->score;

				while (maximum_tree_task_depth_level >= tree_task_depth_level)
				{
					DWORD best_evaluation = game->score.iterative_search(tree_task_depth_level, 0, nodes_calculated, &evaluation_best_score, alpha, beta, true);

					std::cout << "Current tree depth level = " << tree_task_depth_level << std::endl;

					if ((best_evaluation <= alpha || best_evaluation >= beta) && abs(best_evaluation) < 4 * King_Value)
					{
						evaluation_best_score_start = evaluation_best_score;

						Score *this_current_score = evaluation_best_score;

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
								std::cout << "Best variant " << variant << " ";
								std::cout << "Best variant evaluation " << this_current_score->evaluation << std::endl;
							}
						}

						//if (abs(best_evaluation) < 4 * King_Value)
						//{
						//	evaluation_best_score->delete_not_principal_variant_nodes(evaluation_best_score);
						//}
					}

					if (best_evaluation <= alpha)
					{
						beta = (alpha + beta) / 2;
						alpha = std::max(best_evaluation - delta, -4 * King_Value);
					}
					else if (best_evaluation >= beta)
					{
						beta = std::min(best_evaluation + delta, 4 * King_Value);
					}
					else
					{
					}

					delta += delta / 4 + 5;

					tree_task_depth_level++;
				}

				_time64(&calculation_end_time);

				auto calculation_time = calculation_end_time - calculation_start_time;

				std::cout << "Calculating time " << calculation_time << " seconds" << std::endl;

				std::cout << "Nodes calculated " << nodes_calculated << std::endl;

				if (calculation_time != 0)
				{
					std::cout << "Nodes per second " << nodes_calculated / calculation_time << std::endl;
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

						current_score->move.format_move(current_move);

						variant = current_move + std::string(" ") + variant;
					}

					if (evaluation_best_score != nullptr)
					{
						std::cout << "Best variant " << variant << " ";
						std::cout << "Best variant evaluation " << evaluation_best_score->evaluation << std::endl;
					}
				}
			}
			catch (Exception &e)
			{

			}
			catch (std::bad_alloc &e)
			{
				std::cout << std::endl << e.what() << std::endl;
			}
			catch (...)
			{

			}

			delete game;

			game = nullptr;
		}
	}
	catch (std::bad_alloc &e)
	{
		std::cout << std::endl << e.what() << std::endl;
	}
	catch (...)
	{

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
