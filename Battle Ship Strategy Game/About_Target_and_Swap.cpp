#include "About_Target_and_Swap.h"
Coordinate* Create_target_collector()
{
	Coordinate* target_collector = new Coordinate[SHIP_TARGET_COUNTER];
	return target_collector;
}
void Delete_target_collector(Coordinate*& target_collector)
{
	delete[] target_collector;
}
void Swapping(size_t& first_index, size_t& second_index)
{
	size_t replace = first_index;
	first_index = second_index;
    second_index  = replace;
}
void Equal_computer_number_to_successful_target_number(Coordinate& computer, const Coordinate& success_target)
{
	computer.number = success_target.number;
}
void Equal_computer_letter_to_successful_target_letter(Coordinate& computer, const Coordinate& success_target)
{
	computer.letter = success_target.letter;
}