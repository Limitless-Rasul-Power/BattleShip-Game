#include "About_Vertical.h"
bool Check_for_board_is_fill_vertically(Player& player, size_t number)
{
	for (size_t i = player.coordinate.number; i < player.coordinate.number + number; i++)
	{
		if (player.ship.board[i][player.coordinate.letter] == '.')
			continue;
		else
			return false;
	}
	return true;
}
void Fill_vertical_orientation(Player& player, char letter, size_t number)
{
	for (size_t i = player.coordinate.number; i < player.coordinate.number + number; i++)
	{
		player.ship.board[i][player.coordinate.letter] = letter;
	}
}