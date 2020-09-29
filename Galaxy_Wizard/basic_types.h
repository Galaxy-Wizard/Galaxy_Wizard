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

	const double Pin = 0.4;
	const double Defense = 0.3;	
	const double Hang = 0.3;
	const double Sacrifice = 0.2;
	const double Clearance = 0.2;
	const double Decoy = 0.2;
	const double Deflection = 0.2;
	const double Trap = 0.1;

	const double DefenceDestruction = Weight_Capture + Weight_Attack;
	const double ClearanceSacrifice = Weight_Capture + Sacrifice + Clearance;
	const double ExchangeSacrifice = Weight_Capture + Sacrifice;
	const double QueenSacrifice = Weight_Capture + Sacrifice;
	const double DiscoveredAttack = Weight_Attack + Clearance;
	const double TrappedPiece = Weight_Attack + Trap;
	const double Fork = Weight_Attack;
	const double DoubleAttack = Weight_Attack + Weight_Attack;
	const double DoubleCheck = Weight_Check + Weight_Check + Weight_Attack + Weight_Attack;
	const double XRayAttack = Weight_Attack;
	const double Interference = Clearance + Clearance;
	const double Overloading = Hang;
	const double HangingPiece = Hang;

	const double Promotion = Weight_Capture;
	const double Underpromotion = Weight_Capture + Sacrifice;
	const double EnPassant = Weight_Capture;

	const double PerpetualCheck = Weight_Check;

	/*/
	const double Stalemate;				
	const double AlekhinesGun;			
	const double Skewer;
	const double Zugzwang;
	const double Desperado;		
	const double EndgameTactics;	
	const double SmotheredMate;
	const double MatingNet;	
	const double Zwischenzug;
	const double Windmill;
	/*/
}

namespace Strategy
{
	const double Weight_EnemyKingSafety = 0.4;
	const double Weight_KingSafety = 0.3;
	const double Weight_Development = 0.2;
	const double Weight_CenterOccupation = 0.1;
	const double Weight_None = 1.0;

	const double VulnerableKing = 0.2;
	const double KnightOutpost = 0.16;
	const double BishopPair = 0.16;
	const double DoubledRook = 0.16;
	const double PassedPawns = 0.12;
	const double Battery = 0.1;
	const double Fianchetto = 0.1;
	const double Simplification = 0.1;
	const double BackRank = 0.1;
	const double RooksOnSeventh = 0.1;
	const double OppositeColoredBishops = 0.1;
}

namespace Mastery
{
	const double QueenCheckMate = 0.1;
	const double RookCheckMate = 0.1;
	const double TwoRooksCheckMate = 0.1;
	const double TwoBishopsCheckMate = 0.1;
	const double BishopsAndKnightCheckMate = 0.1;
	const double BasicCheckMates = QueenCheckMate + RookCheckMate + TwoRooksCheckMate + TwoBishopsCheckMate + BishopsAndKnightCheckMate;

	const double MateIn2 = 0.1;
	const double MateIn3 = 0.1;
	const double MateIn4 = 0.1;
	const double AttackingCastledKing = 0.1;
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
		EnemyKingSafety = 1,
		KingSafety = 2,
		Development = 3,
		CenterOccupation = 4,
		SpaceCapture = 8,
		MobilityImprovement = 16,
		SafetyImprovement = 32,
		Attack = 64,
		PieceImprovement = Development + MobilityImprovement + Attack,
		PawnImprovement = CenterOccupation + SpaceCapture + Attack,
		KingImprovement = SafetyImprovement + Attack + EnemyKingSafety + KingSafety,
		None = 0,
	};
}

const double MoveWeightAllowedValue = 0.0;// 1.0;

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
