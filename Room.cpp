#include "Room.h"

Room::Room(std::string r_name) : room_name(r_name) {}

void Room::show_info()
{
	std::cout << "Room name: " << get_room_name() << std::endl;
	std::cout << "Amount of seats: 99" << std::endl;
}

Room& Room::operator=(const Room& a_room)
{
	room_name = a_room.room_name;
	return *this;
}