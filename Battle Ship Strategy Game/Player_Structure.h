#pragma once
#include "Ship_Structure.h"
#include "Coordinate_Structure.h"
#include <iostream>
#include <string.h>

struct Player
{
	char* name;
	short point;
	unsigned short score{ 0 };
	bool is_not_computer{ true };
	Ship ship;
	Coordinate coordinate;
};
