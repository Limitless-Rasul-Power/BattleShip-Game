#include "About_Spot.h"
bool Is_spot_full(const Player & attacker, char**& mock_board)
{
	if (mock_board[attacker.coordinate.number][attacker.coordinate.letter] == '*'
		|| mock_board[attacker.coordinate.number][attacker.coordinate.letter] == 'H')
		return true;

	return false;
}
void Warning_about_full_spot()
{
	std::cout << "You Hit Here Before!\n";
	Sleep(200);
}