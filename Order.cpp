#include "Order.h"

Order::Order(std::vector<unsigned int> a_seat, Track_modify a_track)
{
	for (auto seat : a_seat)
	{
		seats.push_back(seat);
		
	}
	track.push_back(a_track);
}

void Order::print_order() 
{
	for (auto order : track)
	{
		std::cout << "============================================" << std::endl;
		std::cout << "YOUR ORDER IS ----->" << std::endl;
		order.print_info();
	}
	std::cout << "Your seats are: ";
	for (auto seat : seats)
	{
		std::cout << seat << ", ";
	}
	std::cout << std::endl;
	std::cout << "============================================" << std::endl;
}