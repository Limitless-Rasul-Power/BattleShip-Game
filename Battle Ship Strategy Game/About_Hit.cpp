#include "About_Hit.h"
void Hit_mock_board_ship(const Player& attacker, char**& mock_defender)
{
	mock_defender[attacker.coordinate.number][attacker.coordinate.letter] = 'H';
}
void Hit_real_board_ship(const Player& attacker, Player& defender)
{
	defender.ship.board[attacker.coordinate.number][attacker.coordinate.letter] = 'H';
}