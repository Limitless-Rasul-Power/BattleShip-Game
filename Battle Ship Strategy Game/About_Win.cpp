#include "About_Win.h"
bool Attacker_win(const Player& defender)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < column; j++)
		{
			if (defender.ship.board[i][j] == '.' || defender.ship.board[i][j] == '*'
				|| defender.ship.board[i][j] == 'H')
				continue;
			else
				return false;
		}
	}
	return true;
}
void Win_Congratulations(const Player& player)
{
	std::cout << "Player " << player.name << " Congratulations YOU Are The WINNER of BATTLESHIP!!!\n";
}
void Earn_score(Player& player)
{
	player.score += 1;
}
void Total_game_winner(Player* player)
{
	if (player[FIRST].score > player[SECOND].score)
		std::cout << "Player " << player[FIRST].name << " You are BATTLESHIP MASTER!!!\n\n\n";
	else if (player[SECOND].score > player[FIRST].score)
		std::cout << "Player " << player[SECOND].name << " You are BATTLESHIP MASTER!!!\n\n\n";
	else
		std::cout << "Both of You BATTLESHIP MASTERS!!!\n\n\n";
}
void Delete_player(Player*& player)
{
	for (unsigned short i = 0; i < player_number; i++)
		delete[] player[i].name;

	delete[] player;
}