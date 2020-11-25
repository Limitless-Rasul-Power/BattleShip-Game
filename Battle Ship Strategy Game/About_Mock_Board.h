#pragma once
#include <iostream>
#include "About_Define.h"
char*** Create_mock_board();
void Fill_mock_board_with_dot(char**& mock_board);
void Print_mock_board(char**& mock_board);
void Delete_mock_board(char***& mock_board);