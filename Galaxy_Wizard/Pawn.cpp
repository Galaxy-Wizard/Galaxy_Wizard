#include "pch.h"
#include "Pawn.h"

#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"

Pawn::Pawn(DWORD Score)
	:Figure(Score)
{
}


Pawn::~Pawn()
{
}

std::list<Matrix> Pawn::moves(Matrix m, size_t x, size_t y)
{
	std::list<Matrix> result;

	Figure* figure = m.get(x, y);

	if ((y == m.get_matrix_n()-2 && figure->Value > 0) || (y == 1 && figure->Value < 0))
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

				if (current_x >= m.get_matrix_m() || current_y >= m.get_matrix_n())
				{
					break;
				}
				else
				{
					if (m.get(current_x, current_y) == nullptr)
					{
						std::list<Figure*> promoted_figure;
						promoted_figure.push_back(new Queen(Queen_Value * sign(figure->Value)));
						promoted_figure.push_back(new Rook(Rook_Value * sign(figure->Value)));
						promoted_figure.push_back(new Bishop(Bishop_Value * sign(figure->Value)));
						promoted_figure.push_back(new Knight(Knight_Value * sign(figure->Value)));

						for (auto promoted_figure_iterator = promoted_figure.begin(); promoted_figure_iterator != promoted_figure.end(); promoted_figure_iterator++)
						{
							Matrix new_move(m);

							new_move.put(current_x, current_y, *promoted_figure_iterator);
							new_move.put(x, y, nullptr);
							
							new_move.move.enpassant = size_t(-1);

							new_move.move.x_from = x;
							new_move.move.y_from = y;
							new_move.move.x_to = current_x;
							new_move.move.y_to = current_y;
							new_move.move.from_figure = figure->Value;
							new_move.move.to_figure = (*promoted_figure_iterator)->Value;
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
				current_x++;
				if (figure->Value > 0)
				{
					current_y++;
				}
				else
				{
					current_y--;
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
							promoted_figure.push_back(new Queen(Queen_Value * sign(figure->Value)));
							promoted_figure.push_back(new Rook(Rook_Value * sign(figure->Value)));
							promoted_figure.push_back(new Bishop(Bishop_Value * sign(figure->Value)));
							promoted_figure.push_back(new Knight(Knight_Value * sign(figure->Value)));

							for (auto promoted_figure_iterator = promoted_figure.begin(); promoted_figure_iterator != promoted_figure.end(); promoted_figure_iterator++)
							{
								Matrix new_move(m);

								new_move.put(current_x, current_y, *promoted_figure_iterator);
								new_move.put(x, y, nullptr);

								new_move.move.enpassant = size_t(-1);

								new_move.move.x_from = x;
								new_move.move.y_from = y;
								new_move.move.x_to = current_x;
								new_move.move.y_to = current_y;
								new_move.move.from_figure = figure->Value;
								new_move.move.to_figure = (*promoted_figure_iterator)->Value;
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
				current_x--;
				if (figure->Value > 0)
				{
					current_y++;
				}
				else
				{
					current_y--;
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
							promoted_figure.push_back(new Queen(Queen_Value * sign(figure->Value)));
							promoted_figure.push_back(new Rook(Rook_Value * sign(figure->Value)));
							promoted_figure.push_back(new Bishop(Bishop_Value * sign(figure->Value)));
							promoted_figure.push_back(new Knight(Knight_Value * sign(figure->Value)));

							for (auto promoted_figure_iterator = promoted_figure.begin(); promoted_figure_iterator != promoted_figure.end(); promoted_figure_iterator++)
							{
								Matrix new_move(m);

								new_move.put(current_x, current_y, *promoted_figure_iterator);
								new_move.put(x, y, nullptr);

								new_move.move.enpassant = size_t(-1);

								new_move.move.x_from = x;
								new_move.move.y_from = y;
								new_move.move.x_to = current_x;
								new_move.move.y_to = current_y;
								new_move.move.from_figure = figure->Value;
								new_move.move.to_figure = (*promoted_figure_iterator)->Value;
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
			current_x;
			if (figure->Value > 0)
			{
				current_y++;
			}
			else
			{
				current_y--;
			}

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

					new_move.move.enpassant = size_t(-1);

					new_move.move.x_from = x;
					new_move.move.y_from = y;
					new_move.move.x_to = current_x;
					new_move.move.y_to = current_y;
					result.push_back(new_move);
					new_move.move.from_figure = new_move.move.to_figure = figure->Value;
				}
				else
				{
				}
			}

			break;
		}
	}

	if (m.move.enpassant != size_t(-1))
	{
		if ((y == m.get_matrix_n() - 4 && figure->Value > 0) || (y == 3 && figure->Value < 0))
		{
			auto current_x = x;
			auto current_y = y;

			auto current_y1 = y;

			if (m.move.enpassant == x - 1 || m.move.enpassant == x + 1)
			{
				if (m.move.enpassant == x - 1)
				{
					current_x--;
					if (figure->Value > 0)
					{
						current_y++;
						current_y1 = y;
					}
					else
					{
						current_y--;
						current_y1 = y;
					}

					if (current_x < m.get_matrix_n())
					{
						Figure *pawn = m.get(current_x, current_y1);

						if (pawn->Value == -Value)
						{
							Matrix new_move(m);

							new_move.put(current_x, current_y, figure);
							new_move.put(x, y, nullptr);
							new_move.put(current_x, current_y1, nullptr);

							new_move.move.enpassant = size_t(-1);

							new_move.move.x_from = x;
							new_move.move.y_from = y;
							new_move.move.x_to = current_x;
							new_move.move.y_to = current_y;
							new_move.move.from_figure = new_move.move.to_figure = figure->Value;
							result.push_back(new_move);
						}
					}
				}

				if (m.move.enpassant == x + 1)
				{
					current_x++;
					if (figure->Value > 0)
					{
						current_y++;
						current_y1 = y;
					}
					else
					{
						current_y--;
						current_y1 = y;
					}

					if (current_y < m.get_matrix_n())
					{
						Figure *pawn = m.get(current_x, current_y1);

						if (pawn->Value == -Value)
						{
							Matrix new_move(m);

							new_move.put(current_x, current_y, figure);
							new_move.put(x, y, nullptr);
							new_move.put(current_x, current_y1, nullptr);

							new_move.move.enpassant = size_t(-1);

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
	}

	if ((y == m.get_matrix_n() - 2 && figure->Value < 0) || (y == 1 && figure->Value > 0))
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

				new_move.move.enpassant = size_t(-1);

				if (current_x > 0)
				{
					Figure *pawn = m.get(current_x-1, current_y);
					if (pawn != nullptr)
					{
						if (pawn->Value == -Value)
						{
							new_move.move.enpassant = x;
						}
					}
				}
				if (current_x < m.get_matrix_m() - 1)
				{
					Figure *pawn = m.get(current_x + 1, current_y);

					if (pawn != nullptr)
					{
						if (pawn->Value == -Value)
						{
							new_move.move.enpassant = x;
						}
					}
				}

				new_move.move.x_from = x;
				new_move.move.y_from = y;
				new_move.move.x_to = current_x;
				new_move.move.y_to = current_y;
				new_move.move.from_figure = new_move.move.to_figure = figure->Value;
				result.push_back(new_move);
			}
		}
	}

	return result;
}

Figure* Pawn::Clone()
{
	return new Pawn(Value);
}

void Pawn::make_move(Matrix& matrix, Move move)
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

	auto from_figure = move.from_figure;
	auto to_figure = move.to_figure;
	if (from_figure != to_figure)	//	Promotion
	{
		delete Figure;

		switch (abs(to_figure))
		{
		case Queen_Value: Figure = new Queen(to_figure);
			break;
		case Rook_Value: Figure = new Rook(to_figure);
			break;
		case Bishop_Value: Figure = new Bishop(to_figure);
			break;
		case Knight_Value: Figure = new Knight(to_figure);
			break;
		default:
			throw Exception();
			break;
		}
	}

	auto CapturedFigure = matrix.get(x_to, y_to);
	matrix.put(x_to, y_to, Figure);
	matrix.put(x_from, y_from, nullptr);
	if (CapturedFigure != nullptr)
	{
		//delete CapturedFigure;
	}

	size_t enpassant = move.enpassant;

	if (enpassant != size_t(-1))
	{
		auto Pawn = matrix.get(enpassant, y_from);

		if (Pawn == nullptr)
		{
			throw Exception();
		}

		delete Pawn;
	}
}
