#include "pch.h"
#include "Knight.h"


Knight::Knight(size_t x, size_t y, WORD Score)
	:Figure(x, y, Score)
{
}


Knight::~Knight()
{
}

std::list<Matrix> Knight::moves(Matrix, size_t, size_t)
{
	std::list<Matrix> result;

	return result;
}

Figure* Knight::Clone()
{
	return new Knight(m, n, Value);
}