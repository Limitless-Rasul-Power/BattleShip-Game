#pragma once
#include "Coordinate_Structure.h"
#include "About_Define.h"
Coordinate* Create_target_collector();
void Delete_target_collector(Coordinate*& target_collector);
void Swapping(size_t& first_index, size_t& second_index);
void Equal_computer_number_to_successful_target_number(Coordinate& computer, const Coordinate& success_target);
void Equal_computer_letter_to_successful_target_letter(Coordinate& computer, const Coordinate& success_target);