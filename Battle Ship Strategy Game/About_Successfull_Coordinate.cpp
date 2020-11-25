#include "About_Successfull_Coordinate.h"
void Get_success_coordinate_number_from_computer(Coordinate& success_target, const Coordinate& computer)
{
	success_target.number = computer.number;
}
void Get_success_coordinate_letter_from_computer(Coordinate& success_target, const Coordinate& computer)
{
	success_target.letter = computer.letter;
}
void Decrease_success_coordinate(short& coordinate)
{
	coordinate = coordinate - 1;
}
void Increase_success_coordinate(short& coordinate)
{
	coordinate = coordinate + 1;
}