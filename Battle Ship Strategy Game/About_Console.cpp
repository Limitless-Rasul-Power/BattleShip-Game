#include "About_Console.h"
void Set_console_font()
{
	HANDLE console_out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX font_info{};
	font_info.cbSize = sizeof font_info;
	font_info.dwFontSize.X = 10;
	font_info.dwFontSize.Y = 20;
	font_info.FontFamily = FF_DONTCARE;
	font_info.FontWeight = FW_REGULAR;
	SetCurrentConsoleFontEx(console_out, FALSE, &font_info);
}

void Set_console_color(const short color)
{
	HANDLE console_output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console_output, color);
}

void Hide_console_cursor()
{
	HANDLE console_output = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor_info;
	GetConsoleCursorInfo(console_output, &cursor_info);
	cursor_info.bVisible = false;
	SetConsoleCursorInfo(console_output, &cursor_info);
}

void Change_window_size(int window_width, int window_height)
{
	HWND window = GetConsoleWindow();
	RECT window_direction{};
	GetWindowRect(window, &window_direction);
	window_direction.left = MARGIN_LEFT;
	window_direction.right = MARGIN_TOP;
	MoveWindow(window, window_direction.left, window_direction.right, window_width, window_height, TRUE);
}

void Disable_maximize_button()
{
	HWND hwnd = GetConsoleWindow();
	DWORD style = GetWindowLong(hwnd, GWL_STYLE);
	style &= ~WS_MAXIMIZEBOX;
	SetWindowLong(hwnd, GWL_STYLE, style);
}

void Disable_window_resize()
{
	HWND hwnd = GetConsoleWindow();
	DWORD style = GetWindowLong(hwnd, GWL_STYLE);
	style &= ~WS_SIZEBOX;
	SetWindowLong(hwnd, GWL_STYLE, style);
}

void Set_console_coordinate(short x, short y)
{
	HANDLE console_out = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordinate{ x, y };
	SetConsoleCursorPosition(console_out, coordinate);
}
