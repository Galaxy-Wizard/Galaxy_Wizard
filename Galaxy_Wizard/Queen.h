#pragma once
#include "Figure.h"
class Queen :
	public Figure
{
public:
	Queen();
	~Queen();

	static double Value;
};

double Queen::Value = 11;