#include "event.h"
#include <string>
#include <iostream>

using namespace std;



void event::set_starting_time(datetime time)
{
    starting_time = time;
}

void event::set_ending_time(datetime time)
{
    ending_time = time;
}

void event::set_event_name(string name)
{
    event_name = name;
}

void event::set_event_description(string description)
{
    event_description = description;
}

void event::set_event_ID(int id)
{
    event_id = id;
}


datetime* event::get_starting_time()
{
    return &starting_time;
}

datetime* event::get_ending_time()
{
    return &ending_time;
}

string event::get_event_name()
{
    return event_name;
}

string event::get_event_description()
{
    return event_description;
}

int event::get_event_id()
{
    return get_event_id();
}

void event::show_meeting_info()
{
    cout << "Event ID: " << event_id << endl;
    cout << "Event Name: " << event_name << endl;
    cout << "Event Description: " << event_description << endl;
    cout << "Starting Time: " << starting_time.show_date() << endl;
    cout << "Ending Time: " << ending_time.show_date() << endl;
}
