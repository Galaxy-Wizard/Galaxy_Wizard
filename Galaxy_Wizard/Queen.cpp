#include "pch.h"
#include "Queen.h"


Queen::Queen(size_t x, size_t y, double Score)
	:Figure(x, y, Score)
{
}


Queen::~Queen()
{
}

std::list<Matrix> Queen::moves(Matrix, size_t, size_t)
{
	std::list<Matrix> result;

	return result;
}

Figure* Queen::Clone()
{
	return new Queen(m, n, Value);
}
