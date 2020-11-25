#pragma once
#include <iostream>
#include <windows.h>
#include <string.h>
char* Entry();
void Print_entry(const char* entry);
void Delete_entry(char*& entry);
void Set_console_color(const short color);
void Hide_console_cursor();
void Ready_game_information();