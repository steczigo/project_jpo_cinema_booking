#include "Order.h"

Order::Order(std::vector<unsigned int> a_seat, Track a_track) : track(a_track)
{
	for (auto seat : a_seat)
	{
		seats.push_back(seat);
		
	}
}

void Order::print_order() 
{
	std::cout << "============================================" << std::endl;
	std::cout << "YOUR ORDER IS ----->" << std::endl;
	track.print_info();
	std::cout << "Your seats are: ";
	for (auto seat : seats)
	{
		std::cout << seat << ", ";
	}
	std::cout << std::endl;
	std::cout << "============================================" << std::endl;
}