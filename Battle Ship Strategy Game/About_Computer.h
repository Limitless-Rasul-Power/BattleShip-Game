#pragma once
#include "Player_Structure.h"
void Connect_player_to_computer(Player& player);
void Systemize_computer_place(Player& computer);
void Systemize_computer_number(Player& computer);
void Systemize_computer_letter(Player& computer);
bool Is_computer_not_hitting_target_with_parity(const Player& player, const Ship& parity);