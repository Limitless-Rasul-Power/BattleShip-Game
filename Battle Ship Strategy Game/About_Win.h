#pragma once
#include "Player_Structure.h"
bool Attacker_win(const Player& defender);
void Win_Congratulations(const Player& player);
void Earn_score(Player& player);
void Total_game_winner(Player* player);
void Delete_player(Player*& player);