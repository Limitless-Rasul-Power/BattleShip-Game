#pragma once
#include "Player_Structure.h"
void Print_ship_sequence(size_t space);
void Enter_number(Player& player);
bool Is_wrong_number(const Player& player);
void Warning_about_wrong_number();
void Align_number_for(size_t& ship_sequence);
void Change_number_for_wrong_attempt(size_t& number);
void Print_score(const Player* player);