#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <vector>

class Seat
{
public:
	Seat(unsigned int a_seat_number);
	~Seat() {}
	void print_info();
	void print_free_seat();
	void change_to_occupied(unsigned int seat_num);
	void change_to_unoccupied(unsigned int seat_num);
	bool is_occupied();
	bool is_occupied(unsigned int seat_num);

private:
	const unsigned int seat_number;
	std::vector<unsigned int> available_seats;
};

