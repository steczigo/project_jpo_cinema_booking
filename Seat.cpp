#include "Seat.h"

Seat::Seat(unsigned int a_seat_number) : seat_number(a_seat_number) 
{
	srand(time(NULL));
	available_seats.resize(100, 0);	// simulating free seats
	for (int i = 0; i < available_seats.size(); i++)
	{
		available_seats[i] = rand() % 100;
		if (available_seats[i] < 50)
		{
			available_seats[i] = 0;	// which means the seat is free
		}
		else
		{
			available_seats[i] = 1;	// which means the seat is taken
		}
	}

}

void Seat::print_info()
{
	std::cout << "Seat: " << seat_number << std::endl;
}

void Seat::print_free_seat()
{
	std::cout << "----------- Free seats are: -----------" << std::endl;
	for (int i = 0; i < available_seats.size(); i++)
	{
		

			if (this->is_occupied(i))
			{
				std::cout << i << ", ";
				if (i < 10)
				{
					std::cout << " ";
				}
				if (i == 9 || i == 19 || i == 29 || i == 39 || i == 49 || i == 59 || i == 69 || i == 79 || i == 89 || i == 99)
				{
					std::cout << std::endl;
				}

			}
			else
			{
				std::cout << "--, ";
				if (i == 9 || i == 19 || i == 29 || i == 39 || i == 49 || i == 59 || i == 69 || i == 79 || i == 89 || i == 99)
				{
					std::cout << std::endl;
				}
			}
		
	}
	std::cout << "---------------------------------------" << std::endl;
}

void Seat::change_to_occupied(unsigned int seat_num)
{
	available_seats[seat_num] = 1;
}

void Seat::change_to_unoccupied(unsigned int seat_num)
{
	available_seats[seat_num] = 0;
}

bool Seat::is_occupied()
{
	if (available_seats[seat_number] == 0)
		return true;
	else if (available_seats[seat_number] == 1)
		return false;
}

bool Seat::is_occupied(unsigned int seat_num)
{
	if (available_seats[seat_num] == 0)
		return true;
	else if (available_seats[seat_num] == 1)
		return false;
}