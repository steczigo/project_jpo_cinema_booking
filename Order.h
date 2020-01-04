#pragma once

#include <iostream>
#include <vector>
#include "Seat.h"
#include "Track_modify.h"

class Order
{
public:
	Order(std::vector<unsigned int> a_seat, Track_modify a_track);
	~Order() {}
	void print_order();
	

private:
	std::vector<unsigned int> seats;
	std::vector <Track_modify> track;
};

