#pragma once
#include "Player_Structure.h"
bool Is_miss_opponent(const Player& attacker, const Player& defender);
void Miss_mock_board_ship(const Player& attacker, char**& mock_defender);
void Miss_real_board_ship(const Player& attacker, Player& defender);