#include "pch.h"
#include "Pawn.h"


Pawn::Pawn(size_t x, size_t y, double Score)
	:Figure(x, y, Score)
{
}


Pawn::~Pawn()
{
}

std::list<Matrix> Pawn::moves(Matrix, size_t, size_t)
{
	std::list<Matrix> result;

	return result;
}

Figure* Pawn::Clone()
{
	return new Pawn(m, n, Value);
}
