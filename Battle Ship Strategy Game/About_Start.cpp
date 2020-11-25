#include "About_Start.h"
void Decide_by_lot(Player* player)
{
	player[FIRST].point = rand() % 10;
	player[SECOND].point = rand() % 10;
}
bool Starting_player(Player* player)
{
	if (player[FIRST].point > player[SECOND].point)
		return true;

	return false;
}