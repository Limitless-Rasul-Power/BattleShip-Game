#include "About_Rules.h"
char* Rules()
{	
	char* battleship_game_rules = _strdup("\t\t\t\tRules for BattleShip (a Milton Bradley Game)\n\n\
 \tGame Objective\n\n\
 \tThe object of Battleship is to try and sink all of the other player's before they sink all of your ships. All of the other player's ships are somewhere on his / her board.You try and hit them by calling out the coordinates of one of the squares on the board.The other player also tries to hit your ships by calling out coordinates.Neither you nor the other player can see the other's board so you must try to guess where they are.  Each board in the physical game has two grids:  the lower (horizontal) section for the player's ships and the upper part(vertical during play) for recording the player's guesses.\n\n\
 \tStarting a New Game\n\n\
 \tEach player places the 5 ships somewhere on their board.The ships can only be placed vertically or horizontally.Diagonal placement is not allowed.No part of a ship may hang off the edge of the board.Ships may not overlap each other.No ships may be placed on another ship.\n\n\
 Once the guessing begins, the players may not move the ships.\n\n\
 The 5 ships are : Aircraft(occupies 5 spaces), Battleship(4), Cruiser(3), Submarine(3), and Destroyer(2).\n\n\
 \tPlaying the Game\n\n\
 \tPlayer's take turns guessing by calling out the coordinates. The opponent responds with \"hit\" or \"miss\" as appropriate.  Both players should mark their board with:  \'H\' for hit, \'*\' for miss. For example, if you call out 6F and your opponent does not have any ship located at 6F, your opponent would respond with \"miss\".  You record the miss 6F by placing a \'*\'  on the lower part of your board at F6.  Your opponent records the miss by placing.\n\n\
 \tAs soon as all of one player's ships have been destroyed, the game ends.");
	return battleship_game_rules;
}
void Print_rules(const char* battleship_game_rules)
{
	std::cout << battleship_game_rules << '\n';
}
void Delete_rules(char*& battleship_game_rules)
{
	delete[] battleship_game_rules;
	system("CLS");
}