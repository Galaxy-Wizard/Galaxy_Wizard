#include "pch.h"
#include "King.h"

#include "Rook.h"


King::King(size_t x, size_t y, WORD Score)
	:Figure(x, y, Score), king_not_moved(true)
{
}


King::~King()
{
}

std::list<Matrix> King::moves(Matrix m, size_t x, size_t y)
{
	std::list<Matrix> result;

	Figure* figure = m.get(x, y);

	{
		auto current_x = x;
		auto current_y = y;

		for (;;)
		{
			current_x++;
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
			break;
		}
	}

	{
		auto current_x = x;
		auto current_y = y;

		for (;;)
		{
			current_x--;
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
			break;
		}
	}

	{
		auto current_x = x;
		auto current_y = y;

		for (;;)
		{
			current_x--;
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
			break;
		}
	}

	{
		auto current_x = x;
		auto current_y = y;

		for (;;)
		{
			current_x++;
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
			break;
		}
	}

	if (king_not_moved)
	{
		{
			auto current_x = x;
			auto current_y = y;

			bool castle_right = true;
			bool castle_side = false;

			for (; castle_right;)
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
						continue;
					}
					else
					{
						if (m.get(current_x, current_y)->Value * figure->Value > 0 && abs(m.get(current_x, current_y)->Value) == Rook_Value)
						{
							castle_side = false;
							size_t current_x1 = 0;
							for (; current_x1 < m.get_matrix_m(); current_x1++)
							{
								if (m.get(current_x1, current_y) != nullptr)
								{
									if (abs(m.get(current_x1, current_y)->Value) == Rook_Value)
									{
										if (current_x1 < current_x)
										{
											castle_side = true;

											break;
										}
									}
								}
							}

							Matrix new_move(m);

							Rook* rook = dynamic_cast<Rook*>(m.get(current_x, current_y));

							if (rook->rook_not_moved)
							{
								if (castle_side)
								{
									new_move.put(2, current_y, figure);
									new_move.put(3, current_y, m.get(current_x, current_y));
								}
								else
								{
									new_move.put(6, current_y, figure);
									new_move.put(5, current_y, m.get(current_x, current_y));
								}

								new_move.put(x, y, nullptr);
								new_move.put(current_x, current_y, nullptr);

								result.push_back(new_move);
							}
						}
						else
						{
							if (castle_side)
							{
								castle_right = false;
							}
						}
					}
				}
			}
		}

		{
			auto current_x = x;
			auto current_y = y;

			bool castle_right = true;
			bool castle_side = false;

			for (; castle_right;)
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
						continue;
					}
					else
					{
						if (m.get(current_x, current_y)->Value * figure->Value > 0 && abs(m.get(current_x, current_y)->Value) == Rook_Value)
						{
							castle_side = false;
							size_t current_x1 = 0;
							for (; current_x1 < m.get_matrix_m(); current_x1++)
							{
								if (m.get(current_x1, current_y) != nullptr)
								{
									if (abs(m.get(current_x1, current_y)->Value) == Rook_Value)
									{
										if (current_x1 < current_x)
										{
											castle_side = true;

											break;
										}
									}
								}
							}

							Matrix new_move(m);

							Rook* rook = dynamic_cast<Rook*>(m.get(current_x, current_y));

							if (rook->rook_not_moved)
							{
								if (castle_side)
								{
									new_move.put(2, current_y, figure);
									new_move.put(3, current_y, m.get(current_x, current_y));
								}
								else
								{
									new_move.put(6, current_y, figure);
									new_move.put(5, current_y, m.get(current_x, current_y));
								}

								new_move.put(x, y, nullptr);
								new_move.put(current_x, current_y, nullptr);

								result.push_back(new_move);
							}
						}
						else
						{
							if (castle_side)
							{
								castle_right = false;
							}
						}
					}
				}
			}
		}
	}

	return result;
}

Figure* King::Clone()
{
	return new King(m, n, Value);
}