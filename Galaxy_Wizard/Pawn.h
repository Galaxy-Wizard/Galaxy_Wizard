#pragma once
#include "Figure.h"
class Pawn :
	public Figure
{
public:
	Pawn();
	~Pawn();

	static double Value;
};

double Pawn::Value = 1;