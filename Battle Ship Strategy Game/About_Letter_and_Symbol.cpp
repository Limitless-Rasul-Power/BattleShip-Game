#include "About_Letter_and_Symbol.h"
char Enter_letter(const Player& player)
{
	char letter{};
	std::cout << "Player " << player.name << " Enter Letter: ";
	std::cin >> letter;
	return letter;
}
bool Is_wrong_letter(char letter, Player& player)
{
	for (size_t i = 0; i < letter_number; i++)
		if (letter == char(65 + i) || letter == char(65 + 32 + i))
			return false;

	return true;
}
void Warning_about_wrong_letter()
{
	std::cout << "Choose A, B, C, D, E, F, G, H, I, J !\
 (it doesn't matter uppercase or lowercase)\n";
	Sleep(1000);
}
void Place_letter_to_player_coordinate(char letter, Player& player)
{
	for (short i = 0; i < letter_number; i++)
		if (letter == char(65 + i) || letter == char(65 + 32 + i))
			player.coordinate.letter = i;
}
void Put_ship_symbol(char& ship_symbol, size_t number)
{
	if (number == AIRCRAFT)
		ship_symbol = 'A';
	else if (number == BATTLE_SHIP)
		ship_symbol = 'B';
	else if (number == CRUISER)
		ship_symbol = 'C';
	else if (number == SUBMARINE)
		ship_symbol = 'S';
	else
		ship_symbol = 'D';
}
void Print_letters()
{
	std::cout << "\t\t\t\t\t  ";

	for (size_t i = 0; i < 10; i++)
	{
		std::cout << char(65 + i) << " ";
	}
	std::cout << '\n';
}