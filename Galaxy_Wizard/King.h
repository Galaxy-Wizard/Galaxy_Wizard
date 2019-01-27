#pragma once
#include "Figure.h"
class King :
	public Figure
{
public:
	King();
	~King();

	static double Value;
};

double King::Value = 500;
