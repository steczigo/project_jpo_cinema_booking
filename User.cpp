#include "User.h"

void User::place_order(Order order)
{
	orders.push_back(order);
}

void User::remove_order(unsigned int order_number)
{
	orders.erase(orders.begin() + order_number - 1);  /*has to be -1 to prevent trying to get access to
													   orders[order_number] above orders.size() 
													   because order numbers are printed as 1,2,3...*/
}

void User::print_order()
{
	int order_number = 1;
	for (auto order : orders)
	{
		std::cout << " Number: -- " << order_number << " --" << std::endl;
		order.print_order();
		order_number++;
	}
}

bool User::order_empty()
{
	if (orders.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int User::order_amount()
{
	return orders.size();
}