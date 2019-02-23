#pragma once

#include "basic_types.h"

class Move
{
public:
	Move();
	~Move();

	Move(const Move &m);

	Move& operator=(const Move &m);

	size_t x_from, y_from;
	size_t x_to, y_to;
	size_t enpassant;

	DWORD from_figure;
	DWORD to_figure;

	size_t rook_x_from, rook_y_from;
	size_t rook_x_to, rook_y_to;

	void format_move(std::string &current_move);
};

