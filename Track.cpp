#include <iostream>

#include "Track.h"

Track::Track(const Room a_room, const Movie a_movie, const std::string a_time, std::string a_day)
	: room{ a_room }, movie{ a_movie }, time{ a_time }, day{ a_day }
	{}

void Track::print_info()
{
	std::cout << "Title: " << movie.get_title() << std::endl;
	std::cout << "Length: " << movie.get_length() << std::endl;
	std::cout << "Type: " << movie.get_type() << std::endl;
	std::cout << "Room info: " << room.get_room_name() << std::endl;
	std::cout << "Date: " << day << ", " << time << std::endl;
}

std::string Track::get_room() const
{
	return room.get_room_name();
}
std::string Track::get_movie() const
{
	return movie.get_title();
}
std::string Track::get_time() const
{
	return time;
}
std::string Track::get_day() const
{
	return day;
}