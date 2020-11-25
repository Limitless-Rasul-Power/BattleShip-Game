#include "About_Space.h"
bool Verify_for_empty_ship_space(const Player& player, size_t number)
{
	if (player.ship.place == 'V' || player.ship.place == 'v')
		return true;
	else 
		if (player.coordinate.letter >= 0 && player.coordinate.letter + number <= 10)
			return true;
		else
	return false;
}
void Warning_about_space()
{
	std::cout << "Can't Place Here!\n";
	Sleep(1000);
}