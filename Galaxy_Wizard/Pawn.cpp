#include "pch.h"
#include "Pawn.h"

#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"

Pawn::Pawn(size_t x, size_t y, DWORD Score)
	:Figure(x, y, Score)
{
}


Pawn::~Pawn()
{
}

std::list<Matrix> Pawn::moves(Matrix m, size_t x, size_t y)
{
	std::list<Matrix> result;

	Figure* figure = m.get(x, y);

	if ((x == m.get_matrix_n()-2 && figure->Value > 0) || (x == 1 && figure->Value < 0))
	{
		{
			auto current_x = x;
			auto current_y = y;

			for (;;)
			{
				current_y;
				if (figure->Value > 0)
				{
					current_x++;
				}
				else
				{
					current_x--;
				}

				if (current_x >= m.get_matrix_m() || current_y >= m.get_matrix_n())
				{
					break;
				}
				else
				{
					if (m.get(current_x, current_y) == nullptr)
					{
						std::list<Figure*> promoted_figure;
						promoted_figure.push_back(new Queen(current_x, current_y, Queen_Value));
						promoted_figure.push_back(new Rook(current_x, current_y, Rook_Value));
						promoted_figure.push_back(new Bishop(current_x, current_y, Bishop_Value));
						promoted_figure.push_back(new Knight(current_x, current_y, Knight_Value));

						for (auto promoted_figure_iterator = promoted_figure.begin(); promoted_figure_iterator != promoted_figure.end(); promoted_figure_iterator++)
						{
							Matrix new_move(m);

							new_move.put(current_x, current_y, *promoted_figure_iterator);
							new_move.put(x, y, nullptr);
							
							new_move.x_from = x;
							new_move.y_from = y;
							new_move.x_to = current_x;
							new_move.y_to = current_y;
							result.push_back(new_move);
						}
					}
					else
					{
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
				current_y++;
				if (figure->Value > 0)
				{
					current_x++;
				}
				else
				{
					current_x--;
				}

				if (current_x >= m.get_matrix_m() || current_y >= m.get_matrix_n())
				{
					break;
				}
				else
				{
					if (m.get(current_x, current_y) == nullptr)
					{
					}
					else
					{
						if (figure->Value * m.get(current_x, current_y)->Value < 0)
						{
							std::list<Figure*> promoted_figure;
							promoted_figure.push_back(new Queen(current_x, current_y, Queen_Value));
							promoted_figure.push_back(new Rook(current_x, current_y, Rook_Value));
							promoted_figure.push_back(new Bishop(current_x, current_y, Bishop_Value));
							promoted_figure.push_back(new Knight(current_x, current_y, Knight_Value));

							for (auto promoted_figure_iterator = promoted_figure.begin(); promoted_figure_iterator != promoted_figure.end(); promoted_figure_iterator++)
							{
								Matrix new_move(m);

								new_move.put(current_x, current_y, *promoted_figure_iterator);
								new_move.put(x, y, nullptr);

								new_move.x_from = x;
								new_move.y_from = y;
								new_move.x_to = current_x;
								new_move.y_to = current_y;
								result.push_back(new_move);
							}
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
				current_y--;
				if (figure->Value > 0)
				{
					current_x++;
				}
				else
				{
					current_x--;
				}

				if (current_x >= m.get_matrix_m() || current_y >= m.get_matrix_n())
				{
					break;
				}
				else
				{
					if (m.get(current_x, current_y) == nullptr)
					{
					}
					else
					{
						if (figure->Value * m.get(current_x, current_y)->Value < 0)
						{
							std::list<Figure*> promoted_figure;
							promoted_figure.push_back(new Queen(current_x, current_y, Queen_Value));
							promoted_figure.push_back(new Rook(current_x, current_y, Rook_Value));
							promoted_figure.push_back(new Bishop(current_x, current_y, Bishop_Value));
							promoted_figure.push_back(new Knight(current_x, current_y, Knight_Value));

							for (auto promoted_figure_iterator = promoted_figure.begin(); promoted_figure_iterator != promoted_figure.end(); promoted_figure_iterator++)
							{
								Matrix new_move(m);

								new_move.put(current_x, current_y, *promoted_figure_iterator);
								new_move.put(x, y, nullptr);

								new_move.x_from = x;
								new_move.y_from = y;
								new_move.x_to = current_x;
								new_move.y_to = current_y;
								result.push_back(new_move);
							}
						}
					}
				}

				break;
			}
		}
	}
	else
	{
		auto current_x = x;
		auto current_y = y;

		for (;;)
		{
			current_y;
			if (figure->Value > 0)
			{
				current_x++;
			}
			else
			{
				current_x--;
			}

			if (current_x >= m.get_matrix_m() || current_y >= m.get_matrix_n() && current_y > 0)
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
				}
			}

			break;
		}
	}

	if (m.enpassant != size_t(-1))
	{
		if ((x == m.get_matrix_m() - 4 && figure->Value > 0) || (x == 3 && figure->Value < 0))
		{
			auto current_x = x;
			auto current_y = y;

			auto current_x1 = x;

			if (m.enpassant == y - 1 || m.enpassant == y + 1)
			{
				if (m.enpassant == y - 1)
				{
					current_y--;
					if (figure->Value > 0)
					{
						current_x++;
						current_x1 = x;
					}
					else
					{
						current_x--;
						current_x1 = x;
					}

					if (current_y < m.get_matrix_n())
					{
						Figure *pawn = m.get(current_x1, current_y);

						if (pawn->Value == -Value)
						{
							Matrix new_move(m);

							new_move.put(current_x, current_y, figure);
							new_move.put(x, y, nullptr);
							new_move.put(current_x1, current_y, nullptr);

							new_move.x_from = x;
							new_move.y_from = y;
							new_move.x_to = current_x;
							new_move.y_to = current_y;
							result.push_back(new_move);
						}
					}
				}

				if (m.enpassant == y + 1)
				{
					current_y++;
					if (figure->Value > 0)
					{
						current_x++;
						current_x1 = x;
					}
					else
					{
						current_x--;
						current_x1 = x;
					}

					if (current_y < m.get_matrix_n())
					{
						Figure *pawn = m.get(current_x1, current_y);

						if (pawn->Value == -Value)
						{
							Matrix new_move(m);

							new_move.put(current_x, current_y, figure);
							new_move.put(x, y, nullptr);
							new_move.put(current_x1, current_y, nullptr);

							new_move.x_from = x;
							new_move.y_from = y;
							new_move.x_to = current_x;
							new_move.y_to = current_y;
							result.push_back(new_move);
						}
					}
				}
			}
		}
	}

	if ((x == m.get_matrix_m() - 2 && figure->Value < 0) || (x == 1 && figure->Value > 0))
	{
		auto current_x = x;
		auto current_y = y;

		current_y;
		if (figure->Value > 0)
		{
			current_x++;
		}
		else
		{
			current_x--;
		}

		if (m.get(current_x, current_y) == nullptr)
		{
			current_y;
			if (figure->Value > 0)
			{
				current_x++;
			}
			else
			{
				current_x--;
			}

			if (m.get(current_x, current_y) == nullptr)
			{
				Matrix new_move(m);

				new_move.put(current_x, current_y, figure);
				new_move.put(x, y, nullptr);

				new_move.enpassant = y;

				new_move.x_from = x;
				new_move.y_from = y;
				new_move.x_to = current_x;
				new_move.y_to = current_y;
				result.push_back(new_move);
			}
		}
	}

	return result;
}

Figure* Pawn::Clone()
{
	return new Pawn(m, n, Value);
}
