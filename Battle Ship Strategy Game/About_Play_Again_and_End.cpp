#include "About_Play_Again_and_End.h"
int Play_again_question()
{
	const int result = MessageBox(NULL, L"Do You Want To Play More? ", L"BattleShip Strategy Game", MB_YESNO | MB_ICONQUESTION);
	return result;
}
void End_game_report()
{
	std::cout << "See You Soon, Bye-Bye!!!\n";
}
void Warning_about_wrong_choice()
{
	std::cout << "Enter FIRST choice number or SECOND choice number!\n";
	Sleep(1000);
}