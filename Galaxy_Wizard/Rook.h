#pragma once
#include "Figure.h"
class Rook :
	public Figure
{
public:
	Rook();
	~Rook();

	static double Value;
};

double Rook::Value = 6;