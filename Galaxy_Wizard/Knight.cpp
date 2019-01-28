#include "pch.h"
#include "Knight.h"


Knight::Knight(size_t x, size_t y, DWORD Score)
	:Figure(x, y, Score)
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

					new_move.x_from = x;
					new_move.y_from = y;
					new_move.x_to = current_x;
					new_move.y_to = current_y;
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

						new_move.x_from = x;
						new_move.y_from = y;
						new_move.x_to = current_x;
						new_move.y_to = current_y;
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

					new_move.x_from = x;
					new_move.y_from = y;
					new_move.x_to = current_x;
					new_move.y_to = current_y;
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

						new_move.x_from = x;
						new_move.y_from = y;
						new_move.x_to = current_x;
						new_move.y_to = current_y;
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

					new_move.x_from = x;
					new_move.y_from = y;
					new_move.x_to = current_x;
					new_move.y_to = current_y;
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

						new_move.x_from = x;
						new_move.y_from = y;
						new_move.x_to = current_x;
						new_move.y_to = current_y;
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

					new_move.x_from = x;
					new_move.y_from = y;
					new_move.x_to = current_x;
					new_move.y_to = current_y;
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

						new_move.x_from = x;
						new_move.y_from = y;
						new_move.x_to = current_x;
						new_move.y_to = current_y;
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

					new_move.x_from = x;
					new_move.y_from = y;
					new_move.x_to = current_x;
					new_move.y_to = current_y;
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

						new_move.x_from = x;
						new_move.y_from = y;
						new_move.x_to = current_x;
						new_move.y_to = current_y;
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

					new_move.x_from = x;
					new_move.y_from = y;
					new_move.x_to = current_x;
					new_move.y_to = current_y;
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

						new_move.x_from = x;
						new_move.y_from = y;
						new_move.x_to = current_x;
						new_move.y_to = current_y;
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

					new_move.x_from = x;
					new_move.y_from = y;
					new_move.x_to = current_x;
					new_move.y_to = current_y;
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

						new_move.x_from = x;
						new_move.y_from = y;
						new_move.x_to = current_x;
						new_move.y_to = current_y;
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

					new_move.x_from = x;
					new_move.y_from = y;
					new_move.x_to = current_x;
					new_move.y_to = current_y;
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

						new_move.x_from = x;
						new_move.y_from = y;
						new_move.x_to = current_x;
						new_move.y_to = current_y;
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
	return new Knight(m, n, Value);
}