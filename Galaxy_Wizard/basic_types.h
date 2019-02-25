#pragma once

#include <string>
#include <list>

using DWORD = signed __int64;

const DWORD Pawn_Value = 200;
const DWORD King_Value = 500 * Pawn_Value;
const DWORD Queen_Value = 11 * Pawn_Value;
const DWORD Rook_Value = 6 * Pawn_Value;
const DWORD Bishop_Value = DWORD(4.5 * Pawn_Value);
const DWORD Knight_Value = 4 * Pawn_Value;

const DWORD MoveScoreBonus = Pawn_Value / 50;

template <class T>
T sign(T v)
{
	if (v > T(0))
	{
		return T(1);
	}
	else
	{
		if (v < T(0))
		{
			return T(-1);
		}
		else
		{
			return T(0);
		}
	}
}

enum MoveTypeEnum : int
{
	Capture = 1,
	Attack = 2,
	Avoidance = 4,
	QuiteMove = 8,
	None = 0,
};

class MachineStudingMoveTypeData
{
public:
	MachineStudingMoveTypeData() : MoveType(None), Weight(0.0), Generation(0.0) {}
	~MachineStudingMoveTypeData() {}

	MoveTypeEnum MoveType;
	double Weight;
	double Generation;
};

class Puzzle
{
public:
	Puzzle(std::string f, std::string s): Fen(f), Solution(s) {}
	~Puzzle() {}

	std::string Fen;
	std::string Solution;
};

class Puzzles
{
public:
	Puzzles() {}
	~Puzzles() {}

	std::list<Puzzle> PuzzleList;
};