#include "Game_Header_Files_Part_One.h"
#include "Game_Header_Files_Part_Two.h"
#include "Game_Header_Files_Part_Three.h"
#include <conio.h>
using namespace std;

int main()
{
	Player* player = new Player[player_number]{};
	bool play = true;
	char letter{};

	srand(unsigned int(time(NULL)));
	Change_window_size(WINDOW_WIDTH, WINDOW_HEIGHT);
	Disable_maximize_button();
	Disable_window_resize();

	Set_console_font();
	Hide_console_cursor();
	Set_console_color(WHITE);

	char** main_menu = Create_menu();
	Fill_main_menu(main_menu);
	short keyboard_input{ 0 };
	Sleep(100);

	COORD coordinate = { CENTER_COORDINATE_X, MARGIN_TOP };
	char* battleship_game_rules = Rules();
	while(true)
	{
		Set_console_coordinate(ZERO, ZERO);
		Set_console_color(WHITE);
		Game_name();

		for (short i = 0; i < CHOICE_COUNTER; i++)
		{
			if (i == keyboard_input)
				Set_console_color(FOREGROUND_RED);
			else
				Set_console_color(WHITE);
			coordinate.Y++;
			Set_console_coordinate(coordinate.X, coordinate.Y);
			Print_menu(main_menu[i]);
		}
		coordinate.Y -= CHOICE_COUNTER;
		Set_console_coordinate(coordinate.X, coordinate.Y);

		if (GetAsyncKeyState(VK_UP) != 0 || GetAsyncKeyState(0x57) != 0)
			Press_button_up(keyboard_input);
		else if (GetAsyncKeyState(VK_DOWN) != 0 || GetAsyncKeyState(0x53) != 0)
			Press_button_down(keyboard_input);
		else if (GetAsyncKeyState(VK_RETURN) & IS_PRESSED_NOW)
		{
			system("CLS");
			if (keyboard_input == PLAY_THE_BATTLESHIP)
				break;
			else if (keyboard_input == BATTLESHIP_RULES)
			{
				Sleep(100);
				Print_rules(battleship_game_rules);
				Select_rules_then_press_enter_button(keyboard_input);
			}
			else if (keyboard_input == EXIT)
			{
				Set_console_color(AQUA);
				Set_console_coordinate(CENTER_COORDINATE_X, MARGIN_TOP);
				End_game_report();
				return 0;
			}
		}	
		Sleep(150);
	}		
	Delete_rules(battleship_game_rules);
	Delete_menu(main_menu);
	
	for (short i = 0; i < CHOICE_COUNTER - 1; i++)
	{
		Set_console_coordinate(CENTER_COORDINATE_X, MARGIN_TOP);
		Load_modes();
		if (i != CHOICE_COUNTER - 2)
			system("CLS");
	}
	cout << '\n';
	system("pause");
	system("CLS");
	Sleep(100);

	char** mode_menu = Create_menu();
	Fill_mode_menu(mode_menu);
	coordinate = { CENTER_COORDINATE_X - 5, MARGIN_TOP };
	while (true)
	{
		Set_console_coordinate(ZERO, ZERO);
		Set_console_color(WHITE);
		Game_name();
		Set_console_coordinate(CENTER_COORDINATE_X + 6, MARGIN_TOP);
		Print_mode_word();
		for (short i = 0; i < CHOICE_COUNTER; i++)
		{
			if (i == keyboard_input)
				Set_console_color(FOREGROUND_RED);
			else
				Set_console_color(WHITE);
			coordinate.Y++;
			Set_console_coordinate(coordinate.X, coordinate.Y);
			Print_menu(mode_menu[i]);
		}
		coordinate.Y -= CHOICE_COUNTER;
		Set_console_coordinate(coordinate.X, coordinate.Y);

		if (GetAsyncKeyState(VK_UP) != 0 || GetAsyncKeyState(0x57) != 0)
			Press_button_up(keyboard_input);
		else if (GetAsyncKeyState(VK_DOWN) != 0 || GetAsyncKeyState(0x53) != 0)
			Press_button_down(keyboard_input);
		else if (GetAsyncKeyState(VK_RETURN) & IS_PRESSED_NOW)
		{
			Modify_button_to_mode(keyboard_input);
			break;
		}
	
		Sleep(150);
	}
	Delete_menu(mode_menu);
	
	bool is_hard_mode = false;
	Ship parity;
	if (Is_mode(keyboard_input) != Player_VS_Player)
	{
		Connect_player_to_computer(player[SECOND]);
		Systemize_computer_name(player[SECOND]);
		if (Is_mode(keyboard_input) == Player_VS_Hard_Computer)
		{
			Fill_board_like_checker_orientation_for_hard_mode(parity);
			is_hard_mode = true;
		}
	}
		
	system("CLS");
	Set_console_color(WHITE);
	Set_console_coordinate(CENTER_COORDINATE_X + 10, MARGIN_TOP);
	Ready_game_information();

	Game_name();
	for (size_t i = 0; i < player_number && player[i].is_not_computer; i++)
		Enter_name(player, i);

	while (play)
	{
		Coordinate* target_collector = new Coordinate[player_number]{};
		if (Is_mode(keyboard_input) == Player_VS_Hard_Computer)
		{
			delete[] target_collector;
			target_collector = Create_target_collector();
		}

		for (size_t i = 0; i < player_number; i++)
			Fill_board_with_dot(player[i]);

		for (size_t i = 0; i < player_number; i++)
		{
			for (size_t j = ship_number; j > 0; j--)
			{
				size_t ship_sequence = j;
				Align_number_for(ship_sequence);
				system("CLS");

				if (player[i].is_not_computer)
				{
					Set_console_color(AQUA);
					Game_name();
					Set_console_color(GOLD);
					Print_score(player);
					Print_letters();
					Print_board(player[i]);
					Set_console_color(WHITE);
					Print_ship_sequence(j);
					Enter_ship_orientation(player[i]);

					while (Is_wrong_orientation(player[i]))
					{
						Warning_about_wrong_orientation();
						Enter_ship_orientation(player[i]);
					}

					Enter_number(player[i]);

					while (Is_wrong_number(player[i]))
					{
						Warning_about_wrong_number();
						Enter_number(player[i]);
					}

					letter = Enter_letter(player[i]);

					while (Is_wrong_letter(letter, player[i]))
					{
						Warning_about_wrong_letter();
						letter = Enter_letter(player[i]);
					}

					Place_letter_to_player_coordinate(letter, player[i]);
				}
				else
				{
					Systemize_computer_place(player[i]);
					Systemize_computer_number(player[i]);
					Systemize_computer_letter(player[i]);
				}
				
				char ship_symbol{};

				if (player[i].ship.place == 'h' || player[i].ship.place == 'H')
				{
					if (Check_for_board_is_fill_horizontally(player[i], ship_sequence) &&
						Verify_for_empty_ship_space(player[i], ship_sequence))
					{
						Put_ship_symbol(ship_symbol, j);
						Fill_horizontal_orientation(player[i], ship_symbol, ship_sequence);
					}
					else
						Change_number_for_wrong_attempt(j);
				}
				else
				{
					if (Check_for_board_is_fill_vertically(player[i], ship_sequence))
					{
						Put_ship_symbol(ship_symbol, j);
						Fill_vertical_orientation(player[i], ship_symbol, ship_sequence);
					}
					else
						Change_number_for_wrong_attempt(j);
				}

			}
		}
		
		char*** player_mock_board = Create_mock_board();
		for (size_t i = 0; i < player_number; i++)
			Fill_mock_board_with_dot(player_mock_board[i]);

		Decide_by_lot(player);
		size_t attacker = 0;
		size_t defender = 0;

		if (Starting_player(player))
		{
			Change_hitting_player(attacker);
			Change_defending_player(defender);
		}
		else
		{
			Change_hitting_player(defender);
			Change_defending_player(attacker);
		}

		unsigned short counter_for_directions = 0;
		unsigned short target_coordinate_counter = 0;
		unsigned short enemy_target = 0;
		while (play)
		{
			system("CLS");

			Set_console_color(AQUA);
			Game_name();
			Print_score(player);
			Set_console_color(RED);


			bool is_attacker_computer = false;
			if (!player[attacker].is_not_computer)
			{
				Swapping(attacker, defender);				
				is_attacker_computer = true;
			}

			Print_letters();
			Print_mock_board(player_mock_board[defender]);
			Set_console_color(GREEN);
			Print_letters();
			Print_board(player[attacker]);

			if (is_attacker_computer)
				Swapping(defender, attacker);

			Set_console_color(GRAY);

			if (player[attacker].is_not_computer)
			{												
				Enter_number(player[attacker]);
				while (Is_wrong_number(player[attacker]))
				{
					Warning_about_wrong_number();
					Enter_number(player[attacker]);
				}
				
				letter = Enter_letter(player[attacker]);
				while (Is_wrong_letter(letter, player[attacker]))
				{
					Warning_about_wrong_letter();
					letter = Enter_letter(player[attacker]);
				}
				
				Place_letter_to_player_coordinate(letter, player[attacker]);
			}
			else
			{
				if (target_collector[enemy_target].number > NEGATIVE && is_hard_mode)
				{
					Change_direction_counter_if_target_less_zero_or_bigger_nine
					(counter_for_directions, target_collector[enemy_target]);
					
					if (counter_for_directions == UP)
						Decrease_success_coordinate(target_collector[enemy_target].number);
					else if (counter_for_directions == DOWN)
						Increase_success_coordinate(target_collector[enemy_target].number);
					else if (counter_for_directions == RIGHT)
						Increase_success_coordinate(target_collector[enemy_target].letter);
					else if (counter_for_directions == LEFT)
						Decrease_success_coordinate(target_collector[enemy_target].letter);

					Equal_computer_number_to_successful_target_number(player[attacker].coordinate, target_collector[enemy_target]);
					Equal_computer_letter_to_successful_target_letter(player[attacker].coordinate, target_collector[enemy_target]);

					Return_direction_counter_value(counter_for_directions, target_collector[enemy_target]);

					if (counter_for_directions == UP)
						Increase_success_coordinate(target_collector[enemy_target].number);
					else if (counter_for_directions == DOWN)
						Decrease_success_coordinate(target_collector[enemy_target].number);
					else if (counter_for_directions == RIGHT)
						Decrease_success_coordinate(target_collector[enemy_target].letter);
					else if (counter_for_directions == LEFT)
						Increase_success_coordinate(target_collector[enemy_target].letter);

				}
				else
				{					
					Systemize_computer_number(player[attacker]);
					Systemize_computer_letter(player[attacker]);
					
					while (Is_computer_not_hitting_target_with_parity(player[attacker], parity) && (is_hard_mode))
					{
						Systemize_computer_number(player[attacker]);
						Systemize_computer_letter(player[attacker]);
					}
				}
			}

			if (Is_spot_full(player[attacker], player_mock_board[defender]))
			{
				if ((!player[attacker].is_not_computer) && is_hard_mode &&
					(target_collector[enemy_target].number > NEGATIVE) && (counter_for_directions <= LEFT))
					counter_for_directions++;

				Warning_about_full_spot();
			}
			else if (Is_miss_opponent(player[attacker], player[defender]))
			{
				Miss_mock_board_ship(player[attacker], player_mock_board[defender]);
				Miss_real_board_ship(player[attacker], player[defender]);

				if ((!player[attacker].is_not_computer) && is_hard_mode &&
					target_collector[enemy_target].number > NEGATIVE && counter_for_directions <= LEFT)
					counter_for_directions++;

				if (attacker == FIRST)
				{
					Change_hitting_player(defender);
					Change_defending_player(attacker);
				}
				else
				{
					Change_hitting_player(attacker);
					Change_defending_player(defender);
				}
			}
			else
			{
				if (is_hard_mode && (!player[attacker].is_not_computer))
				{
					Get_success_coordinate_number_from_computer(target_collector[target_coordinate_counter], player[attacker].coordinate);
					Get_success_coordinate_letter_from_computer(target_collector[target_coordinate_counter], player[attacker].coordinate);
					target_coordinate_counter++;
				}

				Hit_mock_board_ship(player[attacker], player_mock_board[defender]);
				Hit_real_board_ship(player[attacker], player[defender]);

				if ((!player[attacker].is_not_computer) && is_hard_mode)
					counter_for_directions++;

				if (Attacker_win(player[defender]))
				{
					Set_console_color(AQUA);
					Win_Congratulations(player[attacker]);
					Earn_score(player[attacker]);
					break;
				}
			}
		

			if (counter_for_directions == MAX_DIRECTION_NUMBER && is_hard_mode)
			{
				if (target_collector[enemy_target + 1].number > NEGATIVE)
					counter_for_directions = UP;
				else
					counter_for_directions = ZERO;

				enemy_target++;
			}
		}

		Delete_mock_board(player_mock_board);
		Delete_target_collector(target_collector);

		const int result = Play_again_question();
		if (result == IDNO)
		{
			End_game_report();
			break;
		}
	}

	system("CLS");
	Set_console_coordinate(CENTER_COORDINATE_X + 3, MARGIN_TOP);
	Total_game_winner(player);
	Delete_player(player);

	system("pause");
	return 0;
}