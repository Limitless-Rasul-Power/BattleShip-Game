#include "About_Board.h"
void Fill_board_with_dot(Player& player)
{
	for (size_t i = 0; i < row; i++)
		for (size_t j = 0; j < column; j++)
			player.ship.board[i][j] = '.';
}
void Print_board(const Player& player)
{
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << "\t\t\t\t\t" << i << " ";
		for (size_t j = 0; j < 10; j++)
		{
			std::cout << player.ship.board[i][j] << " ";
		}
		std::cout << '\n';
	}
	std::cout << "\n\n\n";
}
void Fill_board_like_checker_orientation_for_hard_mode(Ship& parity_ship)
{
	for (short i = 0; i < row; i++)
		for (short j = 0; j < column; j++)
			if ((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0))
				parity_ship.board[i][j] = WHITE_GAP;
}