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
    char start[30], end[30];
    // plz refer : https://www.w3schools.com/cpp/ref_ctime_strftime.asp
    strftime(start, 30, "%H%M", &starting_time_tm);
    strftime(end, 30, " - %H%MH ", &ending_time_tm);
    cout << start << end << event_name << endl;
}

void event::show_meeting_detailed_info()
{
    char start[30], end[30];
    // plz refer : https://www.w3schools.com/cpp/ref_ctime_strftime.asp
    strftime(start, 30, "%H%M", &starting_time_tm);
    strftime(end, 30, " - %H%MH ", &ending_time_tm);
    cout << start << end << event_name << " -> "<< event_description << " -> ";
    switch(repeat_option){
        case 1:
            cout << "Repeating(Daily)\n";
            break;
        case 2:
            cout << "Repeating(Weekly)\n";
            break;
        case 3:
            cout << "Non-repeating\n";
            break;
    }
}
