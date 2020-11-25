#include "About_Number_and_Sequence.h"
void Print_ship_sequence(size_t space)
{
	if (space == 5)
		std::cout << "AIRCRAFT  SHIP(5 spaces)\n";
	else if (space == 4)
		std::cout << "BATTLE SHIP(4 spaces)\n";
	else if (space == 3)
		std::cout << "CRUSIER SHIP(3 spaces)\n";
	else if (space == 2)
		std::cout << "SUBMARINE SHIP(3 spaces)\n";
	else
		std::cout << "DESTROYER SHIP(2 spaces)\n";
}
void Enter_number(Player& player)
{
	std::cout << "Player " << player.name << " Enter Number To Place: ";
	std::cin >> player.coordinate.number;
}
bool Is_wrong_number(const Player& player)
{
	if (player.coordinate.number >= 0 &&
		player.coordinate.number < 10)
		return false;
	return true;
}
void Warning_about_wrong_number()
{
	std::cout << "Please enter a number between 0 and 9,\
 including 0 and 9\n";
	Sleep(1000);
}
void Align_number_for(size_t& ship_sequence)
{
	if (ship_sequence == 2)
		ship_sequence = SUBMARINE;
	else if (ship_sequence == 1)
		ship_sequence = DESTROYER;
}
void Change_number_for_wrong_attempt(size_t& number)
{
	std::cout << "There's a SHIP here or Too Much Space Required!!\n";
	number += 1;
}
void Print_score(const Player* player)
{
	std::cout << "\t  Player " << player[FIRST].name << " Score: " << player[FIRST].score << "\t\t\t\t\t\t\t" << "Player "
		<< player[SECOND].name << " Score: " << player[SECOND].score << "\n\n";
}