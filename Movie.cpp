#include "Movie.h"

Movie::Movie(std::string title, unsigned int len, std::string type) : title(title), length(len), type(type) {}

void Movie::show_info()		// shows basic info about the movie
{
	std::cout << "Movie title: " << Movie::get_title() << std::endl;
	std::cout << "Length: " << Movie::get_length() << " min" << std::endl;
	std::cout << "Type: " << Movie::get_type() << std::endl;
}

Movie& Movie::operator=(const Movie& a_movie)
{
	title = a_movie.title;
	length = a_movie.length;
	type = a_movie.type;
	return *this;
}