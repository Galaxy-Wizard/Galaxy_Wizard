#include "pch.h"
#include "Knight.h"


Knight::Knight(DWORD Score)
	:Figure(Score)
{
}


Knight::~Knight()
{
}

std::list<Matrix> Knight::moves(Matrix m, size_t x, size_t y)
{
	std::list<Matrix> result;

	Figure* figure = m.get(x, y);

	{
		auto current_x = x;
		auto current_y = y;

		for (;;)
		{
			current_x++;
			current_y += 2;

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

			break;
		}
	}

	{
		auto current_x = x;
		auto current_y = y;

		for (;;)
		{
			current_x--;
			current_y += 2;

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

			break;
		}
	}

	{
		auto current_x = x;
		auto current_y = y;

		for (;;)
		{
			current_x++;
			current_y -= 2;

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

			break;
		}
	}

	{
		auto current_x = x;
		auto current_y = y;

		for (;;)
		{
			current_x--;
			current_y -= 2;

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

			break;
		}
	}

	{
		auto current_x = x;
		auto current_y = y;

		for (;;)
		{
			current_x += 2;
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

			break;
		}
	}

	{
		auto current_x = x;
		auto current_y = y;

		for (;;)
		{
			current_x += 2;
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

			break;
		}
	}

	{
		auto current_x = x;
		auto current_y = y;

		for (;;)
		{
			current_x -= 2;
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

			break;
		}
	}

	{
		auto current_x = x;
		auto current_y = y;

		for (;;)
		{
			current_x -= 2;
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

			break;
		}
	}

	return result;
}

Figure* Knight::Clone()
{
	return new Knight(Value);
}

void Knight::make_move(Matrix& matrix, Move move)
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

	auto Figure = matrix.get(x_from, y_from);
	auto CapturedFigure = matrix.get(x_to, y_to);
	matrix.put(x_to, y_to, Figure);
	matrix.put(x_from, y_from, nullptr);
	if (CapturedFigure != nullptr)
	{
		//delete CapturedFigure;
	}
}

bool Knight::is_atacking(size_t x, size_t y)
{
	return false;
}