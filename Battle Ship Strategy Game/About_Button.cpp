#include "About_Button.h"
void Press_button_up(short& key)
{
	key -= 1;
	if (key == -1)
		key = 2;
}
void Press_button_down(short& key)
{
	key += 1;
	if (key == 3)
		key = 0;
}
void Select_rules_then_press_enter_button(short& key)
{
	HANDLE console_out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console_out, GOLD);
	std::cout << "<=Back\n";
	while (true)
		if (GetAsyncKeyState(VK_RETURN) & IS_PRESSED_NOW)
		{
			system("CLS");
			key = 1;
			break;
		}
}
void Modify_button_to_mode(short& keyboard_input)
{
	if (keyboard_input == FIRST_CHOICE)
		keyboard_input = Player_VS_Player;
	else if (keyboard_input == SECOND_CHOICE)
		keyboard_input = Player_VS_Easy_Computer;
	else if (keyboard_input == THIRD_CHOICE)
		keyboard_input = Player_VS_Hard_Computer;
}