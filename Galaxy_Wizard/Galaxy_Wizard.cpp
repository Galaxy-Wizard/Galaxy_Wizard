﻿// Galaxy_Wizard.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include "Board.h"
#include "Matrix.h"

#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"

int main()
{
    std::cout << "Hello World!\n"; 

	Matrix position(8, 8);

	for (size_t i = 0; i < 8; i++)
	{
		position.put(i, 1, +Pawn::Value);
		position.put(i, 6, -Pawn::Value);
	}

	position.put(0, 0, +Rook::Value);
	position.put(7, 0, +Rook::Value);
	position.put(0, 7, -Rook::Value);
	position.put(7, 7, -Rook::Value);

	position.put(1, 0, +Knight::Value);
	position.put(6, 0, +Knight::Value);
	position.put(1, 7, -Knight::Value);
	position.put(6, 7, -Knight::Value);

	position.put(2, 0, +Bishop::Value);
	position.put(5, 0, +Bishop::Value);
	position.put(2, 7, -Bishop::Value);
	position.put(5, 7, -Bishop::Value);

	position.put(3, 0, +Queen::Value);
	position.put(4, 0, +King::Value);
	position.put(3, 7, -Queen::Value);
	position.put(4, 7, -King::Value);


	Board board(position);
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
