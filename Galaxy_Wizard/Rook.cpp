#include "pch.h"
#include "Rook.h"


Rook::Rook(DWORD Score)
	:Figure(Score)
{
}


Rook::~Rook()
{
}

std::list<Matrix> Rook::moves(Matrix m, size_t x, size_t y)
{
	std::list<Matrix> result;

	Figure* figure = m.get(x, y);

	{
		auto current_x = x;
		auto current_y = y;

		for (;;)
		{
			current_x;
			current_y++;

			if (current_x >= m.get_matrix_m() || current_y >= m.get_matrix_n())
			{
				break;
			}
			else
			{
				if (m.get(current_x, current_y) == nullptr)
				{
					Matrix new_move(m);

					new_move.put(current_x, current_y, figure);
					new_move.put(x, y, nullptr);

					new_move.move.x_from = x;
					new_move.move.y_from = y;
					new_move.move.x_to = current_x;
					new_move.move.y_to = current_y;
					new_move.move.from_figure = new_move.move.to_figure = figure->Value;
					result.push_back(new_move);
				}
				else
				{
					if (m.get(current_x, current_y)->Value * figure->Value > 0)
					{
						break;
					}
					else
					{
						Matrix new_move(m);

						new_move.put(current_x, current_y, figure);
						new_move.put(x, y, nullptr);

						new_move.move.x_from = x;
						new_move.move.y_from = y;
						new_move.move.x_to = current_x;
						new_move.move.y_to = current_y;
						new_move.move.from_figure = new_move.move.to_figure = figure->Value;
						result.push_back(new_move);
					}
				}
			}
		}
	}

	{
		auto current_x = x;
		auto current_y = y;

		for (;;)
		{
			current_x;
			current_y--;

			if (current_x >= m.get_matrix_m() || current_y >= m.get_matrix_n())
			{
				break;
			}
			else
			{
				if (m.get(current_x, current_y) == nullptr)
				{
					Matrix new_move(m);

					new_move.put(current_x, current_y, figure);
					new_move.put(x, y, nullptr);

					new_move.move.x_from = x;
					new_move.move.y_from = y;
					new_move.move.x_to = current_x;
					new_move.move.y_to = current_y;
					new_move.move.from_figure = new_move.move.to_figure = figure->Value;
					result.push_back(new_move);
				}
				else
				{
					if (m.get(current_x, current_y)->Value * figure->Value > 0)
					{
						break;
					}
					else
					{
						Matrix new_move(m);

						new_move.put(current_x, current_y, figure);
						new_move.put(x, y, nullptr);

						new_move.move.x_from = x;
						new_move.move.y_from = y;
						new_move.move.x_to = current_x;
						new_move.move.y_to = current_y;
						new_move.move.from_figure = new_move.move.to_figure = figure->Value;
						result.push_back(new_move);
					}
				}
			}
		}
	}

	{
		auto current_x = x;
		auto current_y = y;

		for (;;)
		{
			current_x--;
			current_y;

			if (current_x >= m.get_matrix_m() || current_y >= m.get_matrix_n())
			{
				break;
			}
			else
			{
				if (m.get(current_x, current_y) == nullptr)
				{
					Matrix new_move(m);

					new_move.put(current_x, current_y, figure);
					new_move.put(x, y, nullptr);

					new_move.move.x_from = x;
					new_move.move.y_from = y;
					new_move.move.x_to = current_x;
					new_move.move.y_to = current_y;
					new_move.move.from_figure = new_move.move.to_figure = figure->Value;
					result.push_back(new_move);
				}
				else
				{
					if (m.get(current_x, current_y)->Value * figure->Value > 0)
					{
						break;
					}
					else
					{
						Matrix new_move(m);

						new_move.put(current_x, current_y, figure);
						new_move.put(x, y, nullptr);

						new_move.move.x_from = x;
						new_move.move.y_from = y;
						new_move.move.x_to = current_x;
						new_move.move.y_to = current_y;
						new_move.move.from_figure = new_move.move.to_figure = figure->Value;
						result.push_back(new_move);
					}
				}
			}
		}
	}

	{
		auto current_x = x;
		auto current_y = y;

		for (;;)
		{
			current_x++;
			current_y;

			if (current_x >= m.get_matrix_m() || current_y >= m.get_matrix_n())
			{
				break;
			}
			else
			{
				if (m.get(current_x, current_y) == nullptr)
				{
					Matrix new_move(m);

					new_move.put(current_x, current_y, figure);
					new_move.put(x, y, nullptr);

					new_move.move.x_from = x;
					new_move.move.y_from = y;
					new_move.move.x_to = current_x;
					new_move.move.y_to = current_y;
					new_move.move.from_figure = new_move.move.to_figure = figure->Value;
					result.push_back(new_move);
				}
				else
				{
					if (m.get(current_x, current_y)->Value * figure->Value > 0)
					{
						break;
					}
					else
					{
						Matrix new_move(m);

						new_move.put(current_x, current_y, figure);
						new_move.put(x, y, nullptr);

						new_move.move.x_from = x;
						new_move.move.y_from = y;
						new_move.move.x_to = current_x;
						new_move.move.y_to = current_y;
						new_move.move.from_figure = new_move.move.to_figure = figure->Value;
						result.push_back(new_move);
					}
				}
			}
		}
	}

	return result;
}

Figure* Rook::Clone()
{
	return new Rook(Value);
}

void Rook::make_move(Matrix& matrix, Move move)
{
	matrix.move = move;

	size_t x_from = move.x_from;
	size_t y_from = move.y_from;
	size_t x_to = move.x_to;
	size_t y_to = move.y_to;

	if (
		x_from >= matrix.get_matrix_m()
		||
		y_from >= matrix.get_matrix_n()
		||
		x_to >= matrix.get_matrix_m()
		|| 
		y_to >= matrix.get_matrix_n()
		)
	{
		throw Exception();
	}

	signed char left_rook = 0;

	if ((y_from == 0 && matrix.side_to_move > 0) || (y_from == matrix.get_matrix_n() - 1 && matrix.side_to_move < 0))
	{
		for (size_t x_from_counter = 0; x_from_counter < matrix.get_matrix_m(); x_from_counter++)
		{
			auto Figure = matrix.get(x_from_counter, y_from);

			if (Figure != nullptr)
			{
				if (Figure->Value * matrix.side_to_move == Rook_Value)
				{
					if (x_from_counter == x_from)
					{
						left_rook = -1;
						break;
					}
					else
					{
						left_rook = +1;
						break;
					}
				}
			}
		}
	}

	auto Figure = matrix.get(x_from, y_from);
	auto CapturedFigure = matrix.get(x_to, y_to);
	matrix.put(x_to, y_to, Figure);
	matrix.put(x_from, y_from, nullptr);
	if (CapturedFigure != nullptr)
	{
		//delete CapturedFigure;
	}

	if (matrix.side_to_move > 0)
	{
		if (left_rook < 0)
		{
			matrix.white_left_rook_not_moved = false;
		}
		if (left_rook > 0)
		{
			matrix.white_right_rook_not_moved = false;
		}
	}
	else
	{
		if (matrix.side_to_move < 0)
		{
			if (left_rook < 0)
			{
				matrix.black_left_rook_not_moved = false;
			}
			if (left_rook > 0)
			{
				matrix.black_right_rook_not_moved = false;
			}
		}
	}
}

bool Rook::is_atacking(size_t x, size_t y)
{
	return false;
}