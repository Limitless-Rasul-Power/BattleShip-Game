#include "About_Orientation.h"
void Enter_ship_orientation(Player& player)
{
	std::cout << "Player " << player.name << " Enter Ship Orientation Horizontal(H,h) or Vertical(V,v): ";
	std::cin >> player.ship.place;
}
bool Is_wrong_orientation(const Player& player)
{
	if (player.ship.place == 'h' || player.ship.place == 'H' ||
		player.ship.place == 'v' || player.ship.place == 'V')
	{
		return false;
	}
	return true;
}
void Warning_about_wrong_orientation()
{
	std::cout << "Choose H or h for Horizontal and\
 V or v for Vertical!\n";
	Sleep(1000);
}