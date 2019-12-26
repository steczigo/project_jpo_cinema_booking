#pragma once

#include <iostream>

#include "Movie.h"
#include "Room.h"

class Track_modify
{
public:
	// constructors
	Track_modify(const Room a_room, const Movie a_movie, const std::string a_time, std::string a_day);
	// destructor
	~Track_modify() {}
	// getters
	std::string get_room() const;
	std::string get_movie() const;
	std::string get_time() const;
	// setters
	void set_room(std::string new_room);
	void set_time(std::string new_time);
	// functions
	void print_info();
	// operators
	Track_modify& operator=(const Track_modify& a_track);

private:
	Room room;
	Movie movie;
	std::string time;
	std::string day;
};
