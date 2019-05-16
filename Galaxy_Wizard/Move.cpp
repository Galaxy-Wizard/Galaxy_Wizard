#include "pch.h"
#include "Move.h"


Move::Move()
{
	x_from = y_from = x_to = y_to = size_t(-1);
	enpassant = size_t(-1);
	from_figure = 0;
	to_figure = 0;
	rook_x_from = rook_y_from = rook_x_to = rook_y_to = size_t(-1);
}


Move::~Move()
{
}

Move::Move(const Move &m)
{
	x_from = m.x_from;
	y_from = m.y_from;
	x_to = m.x_to;
	y_to = m.y_to;

	enpassant = m.enpassant;
	from_figure = m.from_figure;
	to_figure = m.to_figure;

	rook_x_from = m.rook_x_from;
	rook_y_from = m.rook_y_from;
	rook_x_to = m.rook_x_to;
	rook_y_to = m.rook_y_to;
}

Move& Move::operator=(const Move &m)
{
	x_from = m.x_from;
	y_from = m.y_from;
	x_to = m.x_to;
	y_to = m.y_to;

	enpassant = m.enpassant;
	from_figure = m.from_figure;
	to_figure = m.to_figure;

	rook_x_from = m.rook_x_from;
	rook_y_from = m.rook_y_from;
	rook_x_to = m.rook_x_to;
	rook_y_to = m.rook_y_to;

	return *this;
}

void Move::format_move(std::string &current_move)
{
	char buffer_x_from[4];
	char buffer_y_from[4];
	char buffer_x_to[4];
	char buffer_y_to[4];

	memset(buffer_x_from, 0, sizeof(char) * 4);
	memset(buffer_y_from, 0, sizeof(char) * 4);
	memset(buffer_x_to, 0, sizeof(char) * 4);
	memset(buffer_y_to, 0, sizeof(char) * 4);

	if (x_from != size_t(-1) && x_to != size_t(-1) && y_from != size_t(-1) && y_to != size_t(-1))
	{
		buffer_x_from[0] = char(x_from) + 'a';
		buffer_x_to[0] += char(x_to) + 'a';
		_itoa_s(int(y_from) + 1, buffer_y_from, 10);
		_itoa_s(int(y_to) + 1, buffer_y_to, 10);

		current_move = std::string(" ") + std::string(buffer_x_from) + std::string(buffer_y_from) +
			std::string(buffer_x_to) + std::string(buffer_y_to);
	}
	else
	{
		current_move = std::string("____");
	}
}

MoveTypeEnum Move::get_move_type() const
{
	return MoveTypeEnum::None;
}