// Galaxy_Wizard.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <time.h>

#include "basic_types.h"

#include "Game.h"
#include "Board.h"
#include "Score.h"
#include "Figure.h"
#include "TimeManager.h"

#include <algorithm>

const size_t const_maximum_depth = 4;

TimeManager* Score::time_manager;

MachineStuding::MachineStudingMoveTypeDataList MachineStudingMoveTypeDataListSortData;

int main()
{
	std::cout << "Galaxy_Wizard 2.0" << std::endl;

	std::cout << "Size of Game = " << sizeof(Game) + 40 * sizeof(void*) + 8 * 8 * sizeof(void*) + sizeof(Figure) * 32 << std::endl;
	std::cout << "Size of Board = " << sizeof(Board) + 8 * 8 * sizeof(void*) + sizeof(Figure) * 32 << std::endl;
	std::cout << "Size of Matrix = " << sizeof(Matrix) + 8 * 8 * sizeof(void*) + sizeof(Figure) * 32 << std::endl;
	std::cout << "Size of Figure = " << sizeof(Figure) << std::endl;
	std::cout << "Size of Score = " << sizeof(Score) + 40 * sizeof(void*) << std::endl;
	std::cout << "Size of Node = " << sizeof(Score) + 40 * sizeof(void*) << std::endl;

	std::cout << "Studying started" << std::endl;
	PuzzleSpace::StudyStrongPuzzles();
	std::cout << "Studying ended" << std::endl;

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
			TimeManager* time_manager = new TimeManager();

			if (time_manager != nullptr)
			{
				try
				{
					Score* evaluation_best_score = nullptr;

					size_t total_nodes_calculated = 0;

					__time64_t calculation_start_time;
					_time64(&calculation_start_time);
					__time64_t calculation_end_time;

					__time64_t total_calculation_time = 0;

					game->score.time_manager = time_manager;
					game->score.evaluation = game->score.Evaluate();
					total_nodes_calculated++;

					Score* evaluation_best_score_start = &game->score;

					_time64(&calculation_end_time);

					total_calculation_time += calculation_end_time - calculation_start_time;


					_time64(&calculation_start_time);

					size_t nodes_calculated = 0;

					for (size_t depth = 0; depth < const_maximum_depth; depth++)
					{
						DWORD best_evaluation = evaluation_best_score_start->search(game->board.position, nodes_calculated, depth, NULL);

						if (abs(best_evaluation) < 4 * King_Value)
						{
							Score* this_current_score = evaluation_best_score;

							if (this_current_score != nullptr)
							{
								std::string variant;

								Score* current_score = this_current_score;
								for (; current_score != nullptr; current_score = current_score->parent)
								{
									std::string current_move;

									current_score->move.format_move(current_move);

									variant = current_move + std::string(" ") + variant;
								}

								if (this_current_score != nullptr)
								{
									std::cout << "Depth " << depth << " ";
									std::cout << "Best variant " << variant << " ";
									std::cout << "Best variant evaluation " << this_current_score->evaluation << std::endl;
								}
							}
						}

						_time64(&calculation_end_time);

						auto calculation_time = calculation_end_time - calculation_start_time;

						std::cout << "Calculating time " << calculation_time << " seconds" << std::endl;

						std::cout << "Nodes calculated " << nodes_calculated << std::endl;
						std::cout << "Total nodes calculated " << total_nodes_calculated << std::endl;

						if (calculation_time != 0)
						{
							std::cout << "Nodes per second " << nodes_calculated / calculation_time << std::endl;
						}
						else
						{
							std::cout << "Nodes per second " << nodes_calculated / 1 << std::endl;
						}

						total_calculation_time += calculation_time;

						if (total_calculation_time != 0)
						{
							std::cout << "Total nodes per second " << total_nodes_calculated / total_calculation_time << std::endl;
						}
						else
						{
							std::cout << "Total nodes per second " << total_nodes_calculated / 1 << std::endl;
						}
					}
				}
				catch (Exception& e)
				{
					std::cout << std::endl << "Exception occured" << std::endl;
				}
				catch (std::bad_alloc& e)
				{
					std::cout << std::endl << e.what() << std::endl;
				}
				catch (...)
				{
					std::cout << std::endl << "Unknown exception occured" << std::endl;
				}

				delete time_manager;
			}

			delete game;

			game = nullptr;
		}
	}
	catch (std::bad_alloc& e)
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
