#pragma once

#include <iostream>
#include <string>

class Movie
{
public:
	//constructors
	Movie(std::string title, unsigned int len, std::string type);
	//destructor
	~Movie() {}
	// operators
	Movie& operator=(const Movie& a_movie);

	//getters
	std::string get_title() const { return title; }
	unsigned int get_length() const { return length; }
	std::string get_type() const { return type; }

	//functions
	void show_info();

private:
	std::string title;	// just a title
	unsigned int length;	// in minutes
	std::string type;		// horror etc
};

