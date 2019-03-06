#include "pch.h"
#include "King.h"

#include "Rook.h"


King::King( DWORD Score)
	:Figure(Score)
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

	if (m.king_not_moved)
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

							bool rook_not_moved = (castle_side && m.left_rook_not_moved) || (!castle_side && m.right_rook_not_moved);

							if (rook_not_moved)
							{
								if (castle_side)
								{
									new_move.put(2, current_y, figure);
									new_move.put(3, current_y, m.get(current_x, current_y));
									new_move.move.x_to = 2;
									new_move.move.y_to = current_y;
									new_move.move.rook_x_from = current_x;
									new_move.move.rook_y_from = current_y;
									new_move.move.rook_x_to = 3;
									new_move.move.rook_y_to = current_y;
								}
								else
								{
									new_move.put(6, current_y, figure);
									new_move.put(5, current_y, m.get(current_x, current_y));
									new_move.move.x_to = 6;
									new_move.move.y_to = current_y;
									new_move.move.rook_x_from = current_x;
									new_move.move.rook_y_from = current_y;
									new_move.move.rook_x_to = 5;
									new_move.move.rook_y_to = current_y;
								}

								new_move.put(x, y, nullptr);
								new_move.put(current_x, current_y, nullptr);

								new_move.move.x_from = x;
								new_move.move.y_from = y;
								new_move.move.from_figure = new_move.move.to_figure = figure->Value;
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

							bool rook_not_moved = (castle_side && m.left_rook_not_moved) || (!castle_side && m.right_rook_not_moved);

							if (rook_not_moved)
							{
								if (castle_side)
								{
									new_move.put(2, current_y, figure);
									new_move.put(3, current_y, m.get(current_x, current_y));
									new_move.move.x_to = 2;
									new_move.move.y_to = current_y;
									new_move.move.rook_x_from = current_x;
									new_move.move.rook_y_from = current_y;
									new_move.move.rook_x_to = 3;
									new_move.move.rook_y_to = current_y;
								}
								else
								{
									new_move.put(6, current_y, figure);
									new_move.put(5, current_y, m.get(current_x, current_y));
									new_move.move.x_to = 6;
									new_move.move.y_to = current_y;
									new_move.move.rook_x_from = current_x;
									new_move.move.rook_y_from = current_y;
									new_move.move.rook_x_to = 5;
									new_move.move.rook_y_to = current_y;
								}

								new_move.put(x, y, nullptr);
								new_move.put(current_x, current_y, nullptr);

								new_move.move.x_from = x;
								new_move.move.y_from = y;
								new_move.move.from_figure = new_move.move.to_figure = figure->Value;
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
	return new King(Value);
}

void King::make_move(Matrix& matrix, Move move)
{
	matrix.move = move;

	size_t x_from = move.x_from;
	size_t y_from = move.x_from;
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
		delete CapturedFigure;
	}
	else
	{
		size_t rook_x_from = move.rook_x_from;
		size_t rook_y_from = move.rook_y_from;
		size_t rook_x_to = move.rook_x_to;
		size_t rook_y_to = move.rook_y_to;

		if (
			rook_x_from != size_t(-1) && rook_y_from != size_t(-1)
			&&
			rook_x_to != size_t(-1) && rook_y_to != size_t(-1)
			)
		{
			if (
				rook_x_from >= matrix.get_matrix_m()
				||
				rook_y_from >= matrix.get_matrix_n()
				||
				rook_x_to >= matrix.get_matrix_m()
				||
				rook_y_to >= matrix.get_matrix_n()
				)
			{
				throw Exception();
			}

			auto Rook = matrix.get(rook_x_from, rook_y_from);
			auto CapturedFigure = matrix.get(x_to, y_to);
			matrix.put(rook_x_to, rook_y_to, Rook);
			matrix.put(rook_x_from, rook_y_from, nullptr);

			if (CapturedFigure != nullptr)
			{
				throw Exception();
			}
		}
	}
}
