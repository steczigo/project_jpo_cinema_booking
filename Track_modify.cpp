#include <iostream>

#include "Track_modify.h"

Track_modify::Track_modify(const Room a_room, const Movie a_movie, const std::string a_time, std::string a_day)
	: room{ a_room }, movie{ a_movie }, time{ a_time }, day{ a_day }
{}

void Track_modify::print_info()
{
	std::cout << "Title: " << movie.get_title() << std::endl;
	std::cout << "Length: " << movie.get_length() << std::endl;
	std::cout << "Type: " << movie.get_type() << std::endl;
	std::cout << "Room info: " << room.get_room_name() << std::endl;
	std::cout << "Date: " << day << ", " << time << std::endl;
}

std::string Track_modify::get_room() const
{
	return room.get_room_name();
}
std::string Track_modify::get_movie_title() const
{
	return movie.get_title();
}
std::string Track_modify::get_time() const
{
	return time;
}
std::string Track_modify::get_day() const
{
	return day;
}


void Track_modify::set_room(std::string new_room)
{
	room = Room(new_room);
}
void Track_modify::set_time(std::string new_time)
{
	time = new_time;
}
void Track_modify::set_day(std::string new_day)
{
	day = new_day;
}



Track_modify& Track_modify::operator=(const Track_modify& a_track)
{
	room = a_track.room;
	movie = a_track.movie;
	time = a_track.time;
	day = a_track.day;
	return *this;
}

Track_modify& Track_modify::operator=(const Track& a_track)
{
	room = a_track.get_room();
	movie = a_track.get_movie();
	time = a_track.get_time();
	day = a_track.get_day();
	return *this;
}