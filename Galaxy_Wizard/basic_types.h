#pragma once

#include <string>
#include <list>

typedef int64_t DWORD;

const DWORD Pawn_Value = 200;
const DWORD King_Value = 500 * Pawn_Value;
const DWORD Queen_Value = 11 * Pawn_Value;
const DWORD Rook_Value = 6 * Pawn_Value;
const DWORD Bishop_Value = DWORD(4.25 * Pawn_Value);
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
	Check = 1,
	Capture = 2,
	Attack = 4,
	Avoidance = 8,
	Defence = 16,
	QuiteMove = 32,
	None = 0,
};

namespace MachineStuding
{
	class MachineStudingMoveTypeDataAtom
	{
	public:
		MachineStudingMoveTypeDataAtom() : MoveType(None), Weight(1.0), Generation(0.0) {}
		~MachineStudingMoveTypeDataAtom() {}

		MoveTypeEnum MoveType;
		double Weight;
		double Generation;
	};

	class MachineStudingMoveTypeData
	{
	public:
		std::vector<MachineStudingMoveTypeDataAtom> AtomVector;
	};

	class MachineStudingMoveTypeDataList
	{
	public:
		MachineStudingMoveTypeDataList() {}
		~MachineStudingMoveTypeDataList() {}

		std::list<MachineStudingMoveTypeData> MachineStudingData;
	};

	const auto Required_Generation_Count = 100;

	const auto DELTA = 0.1;
}

namespace PuzzleSpace
{
	class Puzzle
	{
	public:
		Puzzle(std::string f, std::string s, MoveTypeEnum mt = None) : Fen(f), Solution(s), MoveType(mt) {}
		~Puzzle() {}

		bool operator!=(const Puzzle &p) const { return Fen != p.Fen || Solution != p.Solution || MoveType != p.MoveType; }

		std::string Fen;
		std::string Solution;
		MoveTypeEnum MoveType;
	};

	class Puzzles
	{
	public:
		Puzzles() {}
		~Puzzles() {}

		std::list<Puzzle> PuzzleList;
	};

	void StudyStrongPuzzles();
}
