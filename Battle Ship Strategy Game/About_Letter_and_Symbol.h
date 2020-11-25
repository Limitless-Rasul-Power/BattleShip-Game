#pragma once
#include "Player_Structure.h"
char Enter_letter(const Player& player);
bool Is_wrong_letter(char letter, Player& player);
void Warning_about_wrong_letter();
void Place_letter_to_player_coordinate(char letter, Player& player);
void Put_ship_symbol(char& ship_symbol, size_t number);
void Print_letters();