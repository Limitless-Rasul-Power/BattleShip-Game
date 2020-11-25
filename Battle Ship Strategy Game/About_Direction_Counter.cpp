#include "About_Direction_Counter.h"
void Change_direction_counter_if_target_less_zero_or_bigger_nine
(unsigned short& counter_for_directions, const Coordinate& target_collector)
{
	if (counter_for_directions == UP && target_collector.number - 1 < 0)
		counter_for_directions++;
	if (counter_for_directions == DOWN && target_collector.number + 1 > 9)
		counter_for_directions++;
	if (counter_for_directions == RIGHT && target_collector.letter + 1 > 9)
		counter_for_directions++;
	if (counter_for_directions == LEFT && target_collector.letter - 1 < 0)
		counter_for_directions++;
}
void Return_direction_counter_value(unsigned short& counter_for_directions, const Coordinate& target_collector)
{
	if (counter_for_directions == UP && target_collector.number > 9)
		counter_for_directions++;
	if (counter_for_directions == DOWN && target_collector.number - 1 < 0)
		counter_for_directions++;
	if (counter_for_directions == RIGHT && target_collector.letter - 1 < 0)
		counter_for_directions++;
	if (counter_for_directions == LEFT && target_collector.letter + 1 > 9)
		counter_for_directions++;
}