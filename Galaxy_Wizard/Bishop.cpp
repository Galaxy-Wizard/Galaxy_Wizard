#include "pch.h"
#include "Bishop.h"


Bishop::Bishop(size_t x, size_t y, double Score)
	:Figure(x, y, Score)
{
}


Bishop::~Bishop()
{
}

std::list<Matrix> Bishop::moves(Matrix m, size_t x, size_t y)
{
	std::list<Matrix> result;

	Bishop* figure = dynamic_cast<Bishop*>(m.get(x, y));

	{
		auto current_x = x;
		auto current_y = y;

		for (;;)
		{
			current_x++;
			current_y++;

			if (current_x > m.get_matrix_m() && current_y > m.get_matrix_n())
			{
				break;
			}
			else
			{
				if (m.get(current_x, current_y) == nullptr)
				{
					Matrix new_move(m);

					new_move.put(current_x, current_y, figure);
					new_move.put(x, y, 0);

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
			current_y--;

			if (current_x > m.get_matrix_m() && current_y > m.get_matrix_n())
			{
				break;
			}
			else
			{
				if (m.get(current_x, current_y) == nullptr)
				{
					Matrix new_move(m);

					new_move.put(current_x, current_y, figure);
					new_move.put(x, y, 0);

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
						new_move.put(x, y, 0);

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
			current_y++;

			if (current_x > m.get_matrix_m() && current_y > m.get_matrix_n())
			{
				break;
			}
			else
			{
				if (m.get(current_x, current_y) == nullptr)
				{
					Matrix new_move(m);

					new_move.put(current_x, current_y, figure);
					new_move.put(x, y, 0);

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
						new_move.put(x, y, 0);

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
			current_y--;

			if (current_x > m.get_matrix_m() && current_y > m.get_matrix_n())
			{
				break;
			}
			else
			{
				if (m.get(current_x, current_y) == nullptr)
				{
					Matrix new_move(m);

					new_move.put(current_x, current_y, figure);
					new_move.put(x, y, 0);

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
						new_move.put(x, y, 0);

						result.push_back(new_move);
					}
				}
			}
		}
	}

	return result;
}

Figure* Bishop::Clone()
{
	return new Bishop(m, n, Value);
}