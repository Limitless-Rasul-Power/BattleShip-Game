#include "About_Entry.h"
char* Entry()
{
	char* entry = _strdup("Group STTA_2920_az \n\t\t\t\t\tBattleShip Game Project\n\t\t\t\t\tPresented by Rasul\n\t\t\t\t\tAQIL Teacher's Student!\n");
	return entry;
}
void Print_entry(const char* entry)
{
	for (size_t i = 0; entry[i] != '\0'; i++)
	{
		std::cout << entry[i];
		Sleep(20);
	}
	std::cout << '\n';
}
void Delete_entry(char*& entry)
{
	delete[] entry;
	system("pause");
	system("CLS");
}

void Ready_game_information()
{
	std::cout << "GAME IS READY!!!\n";
	Sleep(100);
	system("pause");
	system("CLS");
}