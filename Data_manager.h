#pragma once
#include "Movie.h"
#include "Order.h"
#include "Room.h"
#include "Seat.h"
#include "Track.h"
#include "Track_modify.h"
#include "User.h"


#include <iostream>
#include <iterator>
#include <functional>
#include <fstream>
#include <string>
#include <vector>


#include "string/classification.hpp"
#include "string/find_iterator.hpp"
#include "string/split.hpp"
#include "cinema_booking.h"

using namespace std;
using namespace boost;

class Data_manager
{
public:
	Data_manager() {}
	~Data_manager() {}
	bool fill_data(std::vector<Room>& room_names, std::vector<Movie>& movie_titles, std::vector<Track>& tracks, std::vector<Seat>& seats, const std::string& filename);
	void choose_title(std::vector<Movie>& movie_titles, Movie& chosen_movie);
	unsigned int choose_time(std::vector<Track>& tracks, Movie& chosen_movie, Track_modify& chosen_track, unsigned int & number);

private:

};

