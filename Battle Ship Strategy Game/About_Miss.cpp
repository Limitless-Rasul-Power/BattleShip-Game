#include "About_Miss.h"
bool Is_miss_opponent(const Player& attacker, const Player& defender)
{
	if (defender.ship.board[attacker.coordinate.number]
		[attacker.coordinate.letter] == '.')
		return true;

	return false;
}
void Miss_mock_board_ship(const Player& attacker, char**& mock_defender)
{
	mock_defender[attacker.coordinate.number][attacker.coordinate.letter] = '*';
}
void Miss_real_board_ship(const Player& attacker, Player& defender)
{
	defender.ship.board[attacker.coordinate.number][attacker.coordinate.letter] = '*';
}