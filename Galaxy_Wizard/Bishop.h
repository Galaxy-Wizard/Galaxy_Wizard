#pragma once
#include "Figure.h"
class Bishop :
	public Figure
{
public:
	Bishop();
	~Bishop();

	static double Value;
};


double Bishop::Value = 4.5;
