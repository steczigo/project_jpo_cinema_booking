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

    User user;

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
        cout << "3 - Display order" << endl;                            // DOROBIC CASE 3 !!!!!!!!!!!!!!!!!!!!!!
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
                data_manager.choose_seat(seats, number, chosen_seats);




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