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

namespace Tactics
{
	const double Weight_Check = 0.8;
	const double Weight_Capture = 0.7;
	const double Weight_Attack = 0.6;
	const double Weight_Avoidance = 0.5;
	const double Weight_Defence = 0.4;
	const double Weight_QuiteMove = 0.3;
	const double Weight_None = 1.0;
}

namespace Strategy
{
	const double Weight_Development = 0.2;
	const double Weight_CenterOccupation = 0.1;
	const double Weight_None = 1.0;
}

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

namespace Tactics
{
	enum TacticsMoveTypeEnum : int
	{
		Check = 1,
		Capture = 2,
		Attack = 4,
		Avoidance = 8,
		Defence = 16,
		QuiteMove = 32,
		None = 0,
	};
}

namespace Strategy
{
	enum StrategyMoveTypeEnum : int
	{
		Development = 1,
		CenterOccupation = 2,
		None = 0,
	};
}

const double MoveWeightAllowedValue = 0.0;// 0.5;

namespace MachineStuding
{
	class MachineStudingTacticsMoveTypeDataAtom
	{
	public:
		MachineStudingTacticsMoveTypeDataAtom() : MoveType(Tactics::TacticsMoveTypeEnum::None), Weight(Tactics::Weight_None), Generation(0.0) {}
		~MachineStudingTacticsMoveTypeDataAtom() {}

		Tactics::TacticsMoveTypeEnum MoveType;
		double Weight;
		double Generation;
	};

	class MachineStudingTacticsMoveTypeData
	{
	public:
		std::vector<MachineStudingTacticsMoveTypeDataAtom> AtomVector;
	};

	class MachineStudingTacticsMoveTypeDataList
	{
	public:
		MachineStudingTacticsMoveTypeDataList() {}
		~MachineStudingTacticsMoveTypeDataList() {}

		std::list<MachineStudingTacticsMoveTypeData> MachineStudingData;
	};


	class MachineStudingStrategyMoveTypeDataAtom
	{
	public:
		MachineStudingStrategyMoveTypeDataAtom() : MoveType(Strategy::StrategyMoveTypeEnum::None), Weight(Strategy::Weight_None), Generation(0.0) {}
		~MachineStudingStrategyMoveTypeDataAtom() {}

		Strategy::StrategyMoveTypeEnum MoveType;
		double Weight;
		double Generation;
	};

	class MachineStudingStrategyMoveTypeData
	{
	public:
		std::vector<MachineStudingStrategyMoveTypeDataAtom> AtomVector;
	};

	class MachineStudingStrategyMoveTypeDataList
	{
	public:
		MachineStudingStrategyMoveTypeDataList() {}
		~MachineStudingStrategyMoveTypeDataList() {}

		std::list<MachineStudingStrategyMoveTypeData> MachineStudingData;
	};

	const auto Required_Generation_Count = 100;

	const auto DELTA = 0.01;
}

namespace PuzzleSpace
{
	class Puzzle
	{
	public:
		Puzzle(std::string f, std::string s, Tactics::TacticsMoveTypeEnum mt = Tactics::TacticsMoveTypeEnum::None) : Fen(f), Solution(s), MoveType(mt) {}
		~Puzzle() {}

		bool operator!=(const Puzzle &p) const { return Fen != p.Fen || Solution != p.Solution || MoveType != p.MoveType; }

		std::string Fen;
		std::string Solution;
		Tactics::TacticsMoveTypeEnum MoveType;
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
