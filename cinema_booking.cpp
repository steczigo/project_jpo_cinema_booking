// cinema_booking.cpp 

#include "Data_manager.h"

int main()
{
    // here all Room, Movie and Track objects will be constructed ==========

    vector<Room> room_names;
    vector<Movie> movie_titles;
    vector<Track> tracks;
    vector<Seat> seats;
    unsigned int number = 0;        // value is 0 just to make sure functions work when using number as a parameter

    Data_manager data_manager;   
    data_manager.fill_data(room_names, movie_titles, tracks, seats, "data.txt");

    //====================================================================//
    // MENU STARTS HERE //
    while (1)
    {
        cout << "<............................................>" << endl;
        cout << "Welcome to the cinema booking system!" << endl;
        cout << "Choose from the options below (type 1,2 etc):" << endl;
        cout << "0 - exit" << endl;
        cout << "1 - list all movies to be displayed" << endl;
        cout << "2 - order (choose seats and movie)" << endl;
        cout << "<............................................>" << endl;
        string choice;
        cin >> choice;
  
        if (stoi(choice) == 0)
            break;
        switch (stoi(choice))
        {
            case 1:
            {
                cout << "The current movies are: " << endl << "============================================" << endl;
            
                for (int i = 0; i < tracks.size(); i++)
                {
                    tracks[i].print_info();
                    cout << "============================================" << endl;
                } 
                break;
            }
            case 2:
            {
                // creating objects helpful in maintaining Order and User objects
                
                Movie chosen_movie("title", 0, "type");     // a movie that user will choose
                data_manager.choose_title(movie_titles, chosen_movie);  // user chooses title here
                
                Track_modify chosen_track(Room("room_name"), chosen_movie, "time", "day");      // track which will be used to choose time
                data_manager.choose_time(tracks, chosen_movie, chosen_track, number);                   // user chooses time here

                vector<unsigned int> chosen_seats;    // a seat numbers that user will choose
               
                while (1)
                {
                    cout << "<............................................>" << endl;
                    cout << "Choose from menu below:" << endl;
                    cout << "0. exit" << endl;
                    cout << "1. Book a seat or another seat" << endl;
                    cout << "2. Check your booked seats" << endl;
                    cout << "3. Remove booked seat" << endl;
                    cout << "<............................................>" << endl;
                    string switcher;
                    cin >> switcher;
                    if (stoi(switcher) == 0)
                    {
                        break;
                    }
                    switch (stoi(switcher))
                    {   
                    case 1:
                        {
                            cout << "Please choose a suitable seat from:" << endl;
                            seats[number].print_free_seat();
                            cout << "Enter the seat number:" << endl;
                            unsigned int seat_choice;
                            cin >> seat_choice;
                            if (seats[number].is_occupied(seat_choice))
                            {
                                cout << "You have chosen seat number: " << seat_choice << endl;
                                chosen_seats.push_back(seat_choice);
                                seats[number].change_to_occupied(seat_choice);
                            }
                            else
                            {
                                cout << "===This seat is already occupied, please choose another one===" << endl;
                                break;
                            }
                        }
                    case 2:
                        {
                        cout << "============================================" << endl;
                            cout << "Your booked seats are: " << endl;
                            if (chosen_seats.empty())
                            {
                                cout << "no seats are booked yet..." << endl;
                                cout << "============================================" << endl;
                            }
                            else
                            {
                                const int chosen_seats_size = chosen_seats.size();
                                for (auto seats : chosen_seats)
                                {
                                    cout << seats << ", ";
                                }
                                cout << endl;
                                cout << "============================================" << endl;
                            }
                        }
                    case 3:
                        {
                            cout << "============================================" << endl;
                            cout << "Your booked seats are: " << endl;
                            if (chosen_seats.empty())
                            {
                                cout << "CAN'T REMOVE, no seats are booked yet..." << endl;
                                cout << "============================================" << endl;
                                break;
                            }
                            else
                            {
                                for (auto seats : chosen_seats)
                                {
                                   cout << seats << ", ";
                                }
                                cout << endl;
                                cout << "============================================" << endl;
                            }
                            unsigned int seat_to_remove;
                            cout << "Please enter number of the seat you would like to remove: " << endl;
                            cin >> seat_to_remove;
                            const int chosen_seats_size = chosen_seats.size();
                            for (auto i = 0; i < chosen_seats_size; i++)
                            {
                                if (seat_to_remove == chosen_seats[i])
                                {   
                                    auto seat_iterator = chosen_seats.begin();
                                    chosen_seats.erase(seat_iterator + i);
                                    seats[number].change_to_unoccupied(i);
                                    cout << "Your seat number " << seat_to_remove << " has been removed" << endl;
                                    break;
                                }
                                else if (i < chosen_seats_size)
                                {
                                    break;
                                }
                                else if (seat_to_remove != chosen_seats[i])
                                {
                                    cout << "===You didnt book this seat, please type suitable number===" << endl;
                                    break;
                                }

                            }
                        }
                    }
                    if (stoi(switcher) == 0)
                    {
                        break;
                    }
                }







                break;          // case break
            }
            default:
            {
                cout << "===please choose an appropriate number===" << endl;
                break;
            }
        }
    }

    return 0;
}