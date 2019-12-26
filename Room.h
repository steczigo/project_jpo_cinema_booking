#pragma once

#include <iostream>
#include <string>

class Room
{
public:
	// constructors
	Room(std::string r_name);
	// destructor
	~Room() {}
	
	// getters
	std::string get_room_name() const { return room_name; }

	//functions
	void show_info();

	// operators
	Room& operator=(const Room& a_room);

private:
	std::string room_name;					// there is constant amount of rooms to choose from
	const unsigned int seat_amount = 99;	// amount of seats (10 in a row beggining with 0), so row's 0 seats are 0 - 9 etc
};

