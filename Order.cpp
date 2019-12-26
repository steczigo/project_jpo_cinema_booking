#include "Order.h"

Order::Order(unsigned int a_seat, Track a_track) : seat(a_seat), track(a_track) {}

void Order::print_order() 
{
	std::cout << "YOUR ORDER IS ----->" << std::endl;
	seat.print_info();
	track.print_info();
}