#pragma once
#include "Figure.h"
class King :
	public Figure
{
public:
	King(DWORD Score);
	~King();

	virtual void make_move(Matrix& matrix, Move move);
	virtual Figure* Clone();
	virtual std::list<Matrix> moves(Matrix, size_t, size_t);
	virtual bool is_atacking(size_t x, size_t y);
	virtual bool is_atacked_castling_path(Matrix &m, size_t x, size_t y) throw (Exception);	//	size_t x, size_t y - Rook position
	virtual bool is_atacked(Matrix& m) throw (Exception);
};

