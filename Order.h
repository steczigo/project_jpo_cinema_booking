#pragma once

#include <iostream>
#include <vector>
#include "Seat.h"
#include "Track.h"

class Order
{
public:
	Order(unsigned int a_seat, Track a_track);
	~Order() {}
	void print_order();
	

private:
	Seat seat;
	Track track;
};

