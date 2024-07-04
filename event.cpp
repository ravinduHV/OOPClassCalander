#include "event.h"
#include <string>
#include <iostream>

using namespace std;

event::event(time_t _starting_time, time_t _ending_time, string _event_name, string _event_description, int _event_id, int _repeat_option, int _repeat_count)
{
    starting_time = _starting_time;
    ending_time = _ending_time;
    event_name = _event_name;
    event_description = _event_description;
    event_id = _event_id;
    repeat_option = _repeat_option;
    repeat_count = _repeat_count;

    starting_time_tm = *localtime(&starting_time);
    ending_time_tm = *localtime(&ending_time);
}


void event::set_starting_time(time_t time)
{
    starting_time = time;
    starting_time_tm = *localtime(&starting_time);
}

void event::set_ending_time(time_t time)
{
    ending_time = time;
    ending_time_tm = *localtime(&ending_time);
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


time_t* event::get_starting_time()
{
    return &starting_time;
}

time_t* event::get_ending_time()
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
    cout << "Starting Time: " << asctime(&starting_time_tm);
    cout << "Ending Time: " << asctime(&ending_time_tm);
}
