#include "About_Computer.h"
void Connect_player_to_computer(Player& player)
{
	player.is_not_computer = false;
}
void Systemize_computer_place(Player& computer)
{
	unsigned short num = rand() % 20;
	if (num % 2 == 0)
		computer.ship.place = 'h';
	else
		computer.ship.place = 'v';
}
void Systemize_computer_number(Player& computer)
{		
	computer.coordinate.number = rand() % 10;	
}
void Systemize_computer_letter(Player& computer)
{	
	computer.coordinate.letter = rand() % 10;	
}
bool Is_computer_not_hitting_target_with_parity(const Player& player, const Ship& parity)
{
	if (parity.board[player.coordinate.number][player.coordinate.letter] == WHITE_GAP)
		return false;

	return true;
}