#include "Data_manager.h"

// basically a function used to fill vectors with all movie data from text file
bool Data_manager::fill_data(std::vector<Room>& room_names, std::vector<Movie>& movie_titles, std::vector<Track>& tracks, std::vector<Seat>& seats, const std::string& filename)
{
    fstream data_file;
    data_file.open(filename, std::fstream::in | std::fstream::out | std::fstream::app);
    if (data_file.is_open())
    {
        string string_to_be_inserted;
        vector<string> raw_file_data;
        while (getline(data_file, string_to_be_inserted))
        {
            /* I insert all movie data into one string vector
            to be then divided by boost::split */
            raw_file_data.push_back(string_to_be_inserted);            
        }
        const int data_size = raw_file_data.size();     // amount of rows in data_file
        vector<string> after_split_data_container;      /*  ----> after_split_data_container has a few assumptions:
                                                        1. first value is room name
                                                        2. second is title
                                                        3. is length
                                                        4. is type
                                                        5. is hour
                                                        6. is day */

        for (int i = 0; i < data_size; i++)
        {
            // here I will use boost::split to help construct all needed objects
            split(after_split_data_container, raw_file_data[i], is_any_of("<--->"), token_compress_on);
            if (after_split_data_container.size() != 6)     // the reason for 6 is right in the above comments, usually to prevent white marks from crashing the file read
            {
                continue;
            }

            Room room_to_be_inserted(after_split_data_container[0]);
            room_names.push_back(room_to_be_inserted);

            Movie movie_to_be_inserted(after_split_data_container[1], stoi(after_split_data_container[2]), after_split_data_container[3]);
            movie_titles.push_back(movie_to_be_inserted);

            Track track_to_be_inserted(room_to_be_inserted, movie_to_be_inserted, after_split_data_container[4], after_split_data_container[5]);
            tracks.push_back(track_to_be_inserted);
        }
       
        /* BLOCK FOR ARTIFICIAL Seat FILLING */
        for (int i = 0; i < data_size; i++)
        {
            seats.push_back(Seat(0));
        }
        /* ================================= */
    }
    else
    {
        cout << "ERROR - cannot open data filled file..." << endl;
        return false;
    }
    
    data_file.close();
    return true;
}


/*=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=*/


void Data_manager::choose_title(std::vector<Movie>& movie_titles, Movie& chosen_movie)  // lets user choose title
{
    while (1)
    {
        cout << "Please choose a movie from list below by writing its title:" << endl;
        for (auto movie : movie_titles)
        {
            cout << movie.get_title() << endl;

        }
        // cin_title with movie_titles title comparison
        std::string cin_title;
        cin >> cin_title;
        for (int i = 0; i < movie_titles.size(); i++)
        {
            if (movie_titles[i].get_title() == cin_title)
            {
                chosen_movie = movie_titles[i];
                break;
            }
        }
        if (chosen_movie.get_title() == "title")
        {
            cout << "None of the titles match the one you entered: \"" << cin_title << "\", try again ------" << endl;
            break;
        }
        break;      // breaks the whole while loop if user typed database-matching title
    }
}


/*=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=*/


// number ---> tracks are contained in vector, so every Seat set is assigned to corresponding tracks[number]
//              so returns number in order to further use it to choose vector Seat[number] corresponding to vector Track[number] 
unsigned int Data_manager::choose_time(std::vector<Track>& tracks, Movie& chosen_movie, Track_modify& chosen_track, unsigned int & number)
{
   
        while (1)
        {
            // first i check which title in track matches the one user entered previously and print info
            cout << "The upcoming projections will take place in:" << endl;
            cout << "============================================" << endl;
            for (auto title : tracks)
            {
                if (title.get_movie_title() == chosen_movie.get_title())
                {
                    title.print_info();
                    cout << "============================================" << endl;
                }
            }
            cout << "Please choose time from list above by writing it:" << endl;
            std::string cin_time;
            std::cin >> cin_time;
            // chosen_movie title comparison and cin_time with tracks time comparison
            number = 0; // first field of vector has to be 0
            const int tracks_size = tracks.size();
            int i = 0;              // will be used for maintaining while loop conditions
            for (auto title : tracks)
            {
                i++;
                if (title.get_movie_title() == chosen_movie.get_title())  // firstly i check which titles match
                {
                    if (cin_time == title.get_time())               // secondly i check if cin_time matches any time in track
                    {
                        chosen_track.set_room(title.get_room());    // chosen room name being assigned
                        chosen_track.set_time(title.get_time());    // chosen time being assigned
                        break;
                    }
                    else if (i >= tracks_size - 1)
                    {
                        cout << "None of the hours match the one you entered: \"" << cin_time << "\", try again ------" << endl;
                        break;
                    }
                    else if (cin_time != title.get_time())
                    {
                        continue;
                    }
                }
                number++;
            }
            if (chosen_track.get_time() != "time")      // if time has been set, then we leave the while loop
            {
                break;  // breaks the whole while loop if user typed database-matching time
            }
        }
        return number;
}


/*=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=*/


// number ---> tracks are contained in vector, so every Seat set is assigned to corresponding tracks[number]
// number is returned from Data_manager::choose_time, so in order to use choose_seat you should first use choose_time
// no comments needed in function --- couts are self explanatory
void Data_manager::choose_seat(std::vector<Seat>& seats, unsigned int number, std::vector<unsigned int>& chosen_seats)
{
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
                break;
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
                break;
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
                break;
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

                unsigned int seat_to_remove;
                cout << "Please enter number of the seat you would like to remove: " << endl;
                cin >> seat_to_remove;
                const int chosen_seats_size = chosen_seats.size();
                auto seat_iterator = chosen_seats.begin();      // declared here to prevent using begin() over and over in 'for' loop
                for (auto i = 0; i < chosen_seats_size; i++)
                {
                    if (seat_to_remove == chosen_seats[i])
                    {
                        chosen_seats.erase(seat_iterator + i);
                        seats[number].change_to_unoccupied(seat_to_remove);
                        cout << "Your seat number " << seat_to_remove << " has been removed" << endl;
                        break;
                    }
                    /*else if (i < chosen_seats_size)
                    {
                        break;
                    }*/
                    else if (seat_to_remove != chosen_seats[i])
                    {
                        cout << "===You didnt book this seat, please type suitable number===" << endl;
                        break;
                    }
                }
                break;
            }
        default:
        {
            cout << "something went wrong..." << endl;
            break;
        }
        }
        if (stoi(switcher) == 0)
        {
            break;
        }
        }
    }
}


/*=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=*/


void Data_manager::manage_order(User& user)
{
    while (1)
    {
        if (user.order_empty())
        {
            cout << "============================================" << endl;
            cout << "No orders yet" << endl;
            cout << "============================================" << endl;
            break;
        }
        else
        {
            user.print_order();
            cout << "<............................................>" << endl;
            cout << "If you would like to exit, choose '0'" << endl;    // can use 0 here because order numbers are printed as 1,2,3...
            cout << "If you would like to remove an order, enter a corresponding order number:" << endl;
            cout << "<............................................>" << endl;
            string switcher;
            cin >> switcher;
            if (stoi(switcher) == 0)
            {
                break; // case break
            }
            int int_switcher = stoi(switcher);
            int order_amount = user.order_amount();
            for (int i = 0; i < order_amount; i++)
            {
                if ((int_switcher - 1) == i)      // has to be -1 because user types order_number (as switcher) as 1 above actual position in vector
                {
                    user.print_order();
                    user.remove_order(int_switcher);
                    user.print_order();
                    break;
                }
                else if (i < order_amount)
                {
                    continue;
                }
                else
                {
                    cout << "=== CAN'T ERASE ===" << endl;
                    cout << "=== choose appropriate order number ===" << endl;
                    break;
                }
            }
            break;  // while break
        }
    }
}


/*=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=*/


void Data_manager::print_track(std::vector<Track>& tracks)
{
    cout << "The current movies are: " << endl << "============================================" << endl;

    for (int i = 0; i < tracks.size(); i++)
    {
        tracks[i].print_info();
        cout << "============================================" << endl;
    }
}