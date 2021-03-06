#pragma once

#include "Move.h"

class Figure;

class Matrix
{
public:
	std::vector<std::vector<Figure*>> matrix;
	size_t matrix_n;
	size_t matrix_m;

	Move move;
	signed char side_to_move;

	bool white_left_rook_not_moved;
	bool white_right_rook_not_moved;
	bool white_king_not_moved;

	bool black_left_rook_not_moved;
	bool black_right_rook_not_moved;
	bool black_king_not_moved;

	explicit Matrix();
	Matrix(size_t m, size_t n);
	~Matrix();
	Matrix(const Matrix &m);
	Matrix& operator=(const Matrix& m) throw(Exception);

	Matrix& put(size_t x, size_t y, Figure* value) throw(Exception);
	Figure* get(size_t x, size_t y) throw(Exception);
	size_t get_matrix_n() const;
	size_t get_matrix_m() const;
};

