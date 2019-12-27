#pragma once
#include "Order.h"
#include <vector>

class User
{	
public:
	User() {}
	~User() {}
	void place_order(Order order);
	void remove_order(unsigned int order_number);
	void print_order();
	bool order_empty();
	int order_amount();
private:
	std::vector <Order> orders;
};

