#pragma once

#include <iostream>

#include "Movie.h"
#include "Room.h"

class Track
{
public:
	// constructors
	Track(const Room a_room, const Movie a_movie, const std::string a_time, std::string a_day);
	// destructor
	~Track() {}
	// getters
	std::string get_room() const;
	std::string get_movie() const;
	std::string get_time() const;
	// functions
	void print_info();

private:
	const Room room;
	const Movie movie;
	const std::string time;
	const std::string day;
};

