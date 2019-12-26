#pragma once
#include "Order.h"
#include <vector>

class User
{	
public:
	User() {}
	~User() {}
	void place_order();
private:
	std::vector <Order> orders;
};

