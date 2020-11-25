#pragma once
#include "About_Define.h"
#include <windows.h>
void Set_console_font();
void Hide_console_cursor();
void Set_console_color(const short color);
void Change_window_size(int window_width, int window_height);
void Disable_maximize_button();
void Disable_window_resize();
void Set_console_coordinate(short x, short y);
