#include "event.h"
#include <string>

void event::set_starting_time(string time)
{
    starting_time = time;
}

void event::set_ending_time(string time)
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

void event::set_event_location(string location)
{
    event_location = location;
}

string event::get_starting_time()
{
    return starting_time();
}

string event::get_ending_time()
{
    return ending_time();
}

string event::get_event_name()
{
    return event_name();
}

string event::get_event_description()
{
    return event_description();
}

int event::get_event_id()
{
    return get_event_id();
}
