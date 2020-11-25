#pragma once
#include "Player_Structure.h"
void Hit_mock_board_ship(const Player& attacker, char**& mock_defender);
void Hit_real_board_ship(const Player& attacker, Player& defender);