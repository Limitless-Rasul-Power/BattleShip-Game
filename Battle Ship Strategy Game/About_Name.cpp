#include "About_Name.h"
void Game_name()
{
	std::cout << "\n\n\t\t\t\t    BATTLESHIP STRATEGY GAME <>|<>\n\
\t\t\t\t\t\t\t     _____\n\n\n";
}
void Enter_name(Player*& player, size_t number)
{	
	char* need_for_strdup = new char[255];
	std::cout << "\t\t\t\t\t   #" << number + 1 << " Player Name: ";
	std::cin.getline(need_for_strdup, 255);
	player[number].name = _strdup(need_for_strdup);
	delete[] need_for_strdup;
}
void Systemize_computer_name(Player& player)
{
	player.name = _strdup("Computer");
}