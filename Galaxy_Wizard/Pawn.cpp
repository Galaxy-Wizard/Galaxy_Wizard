#include "pch.h"
#include "Pawn.h"

#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"

Pawn::Pawn(size_t x, size_t y, WORD Score)
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

	if ((y == m.get_matrix_n()-1 && figure->Value > 0) || (y == 1 && figure->Value < 0))
	{
		{
			auto current_x = x;
			auto current_y = y;

			for (;;)
			{
				current_x;
				if (figure->Value > 0)
				{
					current_y++;
				}
				else
				{
					current_y--;
				}

				if (current_x > m.get_matrix_m() && current_y > m.get_matrix_n())
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
							
							result.push_back(new_move);
						}
					}
					else
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
				if (figure->Value > 0)
				{
					current_y++;
				}
				else
				{
					current_y--;
				}

				if (current_x > m.get_matrix_m() && current_y > m.get_matrix_n())
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

							result.push_back(new_move);
						}
					}
					else
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
				if (figure->Value > 0)
				{
					current_y++;
				}
				else
				{
					current_y--;
				}

				if (current_x > m.get_matrix_m() && current_y > m.get_matrix_n())
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

							result.push_back(new_move);
						}
					}
					else
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

							result.push_back(new_move);
						}
					}
				}

				break;
			}
		}
	}

	{
		auto current_x = x;
		auto current_y = y;

		for (;;)
		{
			current_x;
			if (figure->Value > 0)
			{
				current_y++;
			}
			else
			{
				current_y--;
			}

			if (current_x > m.get_matrix_m() && current_y > m.get_matrix_n() && current_y > 0)
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

	if (m.enpassant != size_t(-1))
	{
		if ((y == m.get_matrix_n() - 4 && figure->Value > 0) || (y == 4 && figure->Value < 0))
		{
			auto current_x = x;
			auto current_y = y;

			auto current_y1 = y;

			if (m.enpassant == x - 1 || m.enpassant == x + 1)
			{
				if (m.enpassant == x - 1)
				{
					current_x--;
					if (figure->Value > 0)
					{
						current_y++;
						current_y1 = current_y;
						current_y1++;
					}
					else
					{
						current_y--;
						current_y1 = current_y;
						current_y1--;
					}

					if (current_x > m.get_matrix_m())
					{
						Figure *pawn = m.get(current_x, current_y1);

						if (pawn->Value == -Value)
						{
							Matrix new_move(m);

							new_move.put(current_x, current_y, figure);
							new_move.put(x, y, nullptr);
							new_move.put(current_x, current_y1, nullptr);

							result.push_back(new_move);
						}
					}
				}

				if (m.enpassant == x + 1)
				{
					current_x++;
					if (figure->Value > 0)
					{
						current_y++;
						current_y1 = current_y;
						current_y1++;
					}
					else
					{
						current_y--;
						current_y1 = current_y;
						current_y1--;
					}

					if (current_x > m.get_matrix_m())
					{
						Figure *pawn = m.get(current_x, current_y1);

						if (pawn->Value == -Value)
						{
							Matrix new_move(m);

							new_move.put(current_x, current_y, figure);
							new_move.put(x, y, nullptr);
							new_move.put(current_x, current_y1, nullptr);

							result.push_back(new_move);
						}
					}
				}
			}
		}
	}

	if ((y == m.get_matrix_n() - 1 && figure->Value < 0) || (y == 1 && figure->Value > 0))
	{
		auto current_x = x;
		auto current_y = y;

		current_x;
		if (figure->Value > 0)
		{
			current_y++;
		}
		else
		{
			current_y--;
		}

		if (m.get(current_x, current_y) == nullptr)
		{
			current_x;
			if (figure->Value > 0)
			{
				current_y++;
			}
			else
			{
				current_y--;
			}

			if (m.get(current_x, current_y) == nullptr)
			{
				Matrix new_move(m);

				new_move.put(current_x, current_y, figure);
				new_move.put(x, y, nullptr);

				new_move.enpassant = x;

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
