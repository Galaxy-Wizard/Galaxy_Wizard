#pragma once
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

	void format_move(std::string &current_move);
};

