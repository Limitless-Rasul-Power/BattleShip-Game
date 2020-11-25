#pragma once
#include "About_Define.h"
#include <iostream>
#include <windows.h>
#include <string.h>
char** Create_menu();
void Fill_main_menu(char** main_menu);
void Fill_mode_menu(char** mode_menu);
void Print_menu(char* menu);
void Delete_menu(char**& menu);
void Load_modes();
void Print_mode_word();
unsigned short Is_mode(const short& mode);