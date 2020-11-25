#include "About_Horizontal.h"
bool Check_for_board_is_fill_horizontally(Player& player, size_t number)
{
	for (size_t i = player.coordinate.letter; i < player.coordinate.letter + number; i++)
	{
		if (player.ship.board[player.coordinate.number][i] == '.')
			continue;
		else
			return false;
	}
	return true;
}
void Fill_horizontal_orientation(Player& player, char letter, size_t number)
{
	for (size_t i = player.coordinate.letter; i < player.coordinate.letter + number; i++)
	{
		player.ship.board[player.coordinate.number][i] = letter;
	}
}