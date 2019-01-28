// Galaxy_Wizard.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include "Game.h"
#include "Board.h"
#include "Score.h"

int main()
{
    std::cout << "Hello World!\n";

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
			WORD evaluation_minimum = 0;
			WORD evaluation_maximum = 0;

			game->score.evaluation = game->score.Evaluate();

			Score *score_level_1 = &game->score;

			score_level_1->GenetateAllMoves();

			for (auto child = score_level_1->childen.begin(); child != score_level_1->childen.end(); child++)
			{
				child->GenetateAllMoves();

				Score *score_level_2 = &*child;

				score_level_2->GenetateAllMoves();

				score_level_2->evaluation = score_level_2->Evaluate();

				for (auto child = score_level_2->childen.begin(); child != score_level_2->childen.end(); child++)
				{
					child->GenetateAllMoves();

					Score *score_level_3 = &*child;

					score_level_3->GenetateAllMoves();

					score_level_3->evaluation = score_level_3->Evaluate();

					for (auto child = score_level_3->childen.begin(); child != score_level_3->childen.end(); child++)
					{
						child->GenetateAllMoves();

						Score *score_level_4 = &*child;

						score_level_4->GenetateAllMoves();

						score_level_4->evaluation = score_level_4->Evaluate();

						for (auto child = score_level_4->childen.begin(); child != score_level_4->childen.end(); child++)
						{
							child->GenetateAllMoves();

							Score *score_level_5 = &*child;

							//score_level_5->GenetateAllMoves();

							score_level_5->evaluation = score_level_5->Evaluate();

							if (evaluation_minimum > score_level_5->evaluation)
							{
								evaluation_minimum = score_level_5->evaluation;
							}
							if (evaluation_maximum < score_level_5->evaluation)
							{
								evaluation_maximum = score_level_5->evaluation;
							}
						}
					}
				}
			}

			std::cout << "Minimum score = " << evaluation_minimum << std::endl;

			std::cout << "Maximum score = " << evaluation_maximum << std::endl;

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
