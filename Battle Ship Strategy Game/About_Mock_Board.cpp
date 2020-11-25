#include "About_Mock_Board.h"
char*** Create_mock_board()
{
	char*** player_mock_board = new char** [player_number];

	for (size_t i = 0; i < player_number; i++)
	{
		player_mock_board[i] = new char* [row];
		for (size_t j = 0; j < row; j++)
		{
			player_mock_board[i][j] = new char[column];
		}
	}
	return player_mock_board;
}
void Fill_mock_board_with_dot(char**& mock_board)
{
	for (size_t i = 0; i < row; i++)
		for (size_t j = 0; j < column; j++)
			mock_board[i][j] = '.';
}
void Print_mock_board(char**& mock_board)
{
	for (size_t i = 0; i < row; i++)
	{
		std::cout << "\t\t\t\t\t" << i << " ";
		for (size_t j = 0; j < column; j++)
		{
			std::cout << mock_board[i][j] << " ";
		}
		std::cout << '\n';
	}
	std::cout << "\n\n\n\n";
}
void Delete_mock_board(char***& mock_board)
{
	for (size_t i = 0; i < player_number; i++)
	{
		for (size_t j = 0; j < row; j++)
		{
			delete[] mock_board[i][j];
		}
		delete[] mock_board[i];
	}
	delete[] mock_board;
}