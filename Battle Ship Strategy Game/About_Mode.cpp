#include "About_Mode.h"
char** Create_menu()
{
	char** menu = new char* [CHOICE_COUNTER];
	return menu;
}
void Fill_main_menu(char** main_menu)
{
	main_menu[FIRST_CHOICE] = _strdup("Play the BattleShip");
	main_menu[SECOND_CHOICE] = _strdup("  BattleShip Rules");
	main_menu[THIRD_CHOICE] = _strdup("       Exit");
}
void Fill_mode_menu(char** mode_menu)
{
	mode_menu[FIRST_CHOICE] = _strdup("     Player VS Player");
	mode_menu[SECOND_CHOICE] = _strdup("     Player VS Easy Computer");
	mode_menu[THIRD_CHOICE] = _strdup("     Player VS Hard Computer");
}
void Print_menu(char* menu)
{
	std::cout << menu << '\n';
}
void Delete_menu(char**& menu)
{
	for (short i = 0; i < CHOICE_COUNTER; i++)
		delete[] menu[i];

	delete[] menu;
}
void Load_modes()
{
	std::cout << "MODES ARE LOADING";
	for (short j = 0; j < CHOICE_COUNTER; j++)
	{
		Sleep(500);
		std::cout << ".";
	}
}
void Print_mode_word()
{
	std::cout << "Modes";
}
unsigned short Is_mode(const short& mode)
{
	if (mode == Player_VS_Player)
		return Player_VS_Player;
	else
		if (mode == Player_VS_Easy_Computer)
			return Player_VS_Easy_Computer;
		else
			return Player_VS_Hard_Computer;
}