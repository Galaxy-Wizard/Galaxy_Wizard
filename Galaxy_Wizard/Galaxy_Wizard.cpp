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
			DWORD evaluation_minimum = +4 * King_Value;
			DWORD evaluation_maximum = -4 * King_Value;
			Score *evaluation_minimum_score = nullptr;
			Score *evaluation_maximum_score = nullptr;

			
			size_t nodes_calculated = 0;

			__time64_t calculation_start_time;
			_time64(&calculation_start_time);
			__time64_t calculation_end_time;
			
			game->score.evaluation = game->score.Evaluate();

			Score *score_level_1 = &game->score;

			score_level_1->GenetateAllMoves();

			if (false)
			{
				std::cout << "Tree depth level = " << 1 << std::endl;
				std::cout << "Moves generated = " << score_level_1->childen.size() << std::endl;
			}

			score_level_1->evaluation = score_level_1->Evaluate();

			nodes_calculated += score_level_1->childen.size();

			if (evaluation_minimum > score_level_1->evaluation)
			{
				evaluation_minimum = score_level_1->evaluation;
				evaluation_minimum_score = score_level_1;
			}
			if (evaluation_maximum < score_level_1->evaluation)
			{
				evaluation_maximum = score_level_1->evaluation;
				evaluation_maximum_score = score_level_1;
			}

			for (auto child = score_level_1->childen.begin(); child != score_level_1->childen.end(); child++)
			{
				Score *score_level_2 = &*child;

				score_level_2->GenetateAllMoves();

				if (false)
				{
					std::cout << "Tree depth level = " << 2 << std::endl;
					std::cout << "Moves generated = " << score_level_2->childen.size() << std::endl;
				}

				score_level_2->evaluation = score_level_2->Evaluate();

				nodes_calculated += score_level_2->childen.size();

				if (evaluation_minimum > score_level_2->evaluation)
				{
					evaluation_minimum = score_level_2->evaluation;
					evaluation_minimum_score = score_level_2;
				}
				if (evaluation_maximum < score_level_2->evaluation)
				{
					evaluation_maximum = score_level_2->evaluation;
					evaluation_maximum_score = score_level_2;
				}

				for (auto child = score_level_2->childen.begin(); child != score_level_2->childen.end(); child++)
				{
					Score *score_level_3 = &*child;

					score_level_3->GenetateAllMoves();

					if (false)
					{
						std::cout << "Tree depth level = " << 3 << std::endl;
						std::cout << "Moves generated = " << score_level_3->childen.size() << std::endl;
					}

					score_level_3->evaluation = score_level_3->Evaluate();

					nodes_calculated += score_level_3->childen.size();

					if (evaluation_minimum > score_level_3->evaluation)
					{
						evaluation_minimum = score_level_3->evaluation;
						evaluation_minimum_score = score_level_3;
					}
					if (evaluation_maximum < score_level_3->evaluation)
					{
						evaluation_maximum = score_level_3->evaluation;
						evaluation_maximum_score = score_level_3;
					}

					for (auto child = score_level_3->childen.begin(); child != score_level_3->childen.end(); child++)
					{
						Score *score_level_4 = &*child;

						score_level_4->GenetateAllMoves();

						if (false)
						{
							std::cout << "Tree depth level = " << 4 << std::endl;
							std::cout << "Moves generated = " << score_level_4->childen.size() << std::endl;
						}

						score_level_4->evaluation = score_level_4->Evaluate();

						nodes_calculated += score_level_4->childen.size();

						if (evaluation_minimum > score_level_4->evaluation)
						{
							evaluation_minimum = score_level_4->evaluation;
							evaluation_minimum_score = score_level_4;
						}
						if (evaluation_maximum < score_level_4->evaluation)
						{
							evaluation_maximum = score_level_4->evaluation;
							evaluation_maximum_score = score_level_4;
						}

						for (auto child = score_level_4->childen.begin(); child != score_level_4->childen.end(); child++)
						{
							Score *score_level_5 = &*child;

							if (false)
							{
								//score_level_5->GenetateAllMoves();
							}

							if (false)
							{
								std::cout << "Tree depth level = " << 5 << std::endl;
								std::cout << "Moves generated = " << score_level_5->childen.size() << std::endl;
							}

							score_level_5->evaluation = score_level_5->Evaluate();

							nodes_calculated += score_level_2->childen.size();

							if (evaluation_minimum > score_level_5->evaluation)
							{
								evaluation_minimum = score_level_5->evaluation;
								evaluation_minimum_score = score_level_5;
							}
							if (evaluation_maximum < score_level_5->evaluation)
							{
								evaluation_maximum = score_level_5->evaluation;
								evaluation_maximum_score = score_level_5;
							}
						}
					}
				}
			}

			_time64(&calculation_end_time);

			auto calculation_time = calculation_end_time - calculation_start_time;

			std::cout << "Calculating time " << calculation_time <<"seconds" << std::endl;

			std::cout << "Nodes calculated " << nodes_calculated << std::endl;

			if (calculation_time != 0)
			{
				std::cout << "Nodes per second " << nodes_calculated/ calculation_time << std::endl;
			}
			else
			{
				std::cout << "Nodes per second " << nodes_calculated / 1 << std::endl;
			}

			std::cout << "Minimum score = " << evaluation_minimum << std::endl;

			std::cout << "Maximum score = " << evaluation_maximum << std::endl;

			{
				std::string variant;

				Score *current_score = evaluation_minimum_score;
				for (; current_score != nullptr; current_score = current_score->parent)
				{
					std::string current_move;

					current_score->board.position.format_move(current_move);

					variant = current_move + std::string(" ") + variant;
				}

				std::cout << "Variant minimum " << variant << " ";
				std::cout << "Variant minimum evaluation " << evaluation_minimum_score->evaluation << std::endl;
			}

			{
				std::string variant;

				Score *current_score = evaluation_maximum_score;
				for (; current_score != nullptr; current_score = current_score->parent)
				{
					std::string current_move;

					current_score->board.position.format_move(current_move);

					variant = current_move + std::string(" ") + variant;
				}

				std::cout << "Variant maximum " << variant << " ";
				std::cout << "Variant maximum evaluation " << evaluation_maximum_score->evaluation << std::endl;
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
