#include "day.h"
#include <string>
#include <iostream>

using namespace std;

day::day(time_t _date, bool is_offDay_)
{
    is_offDay = is_offDay_;
    next_id = 0;
    date = _date;
    date_tm = *localtime(&date);
}

void day::show_events(bool showIndex)
{
    if (events.size() != 0)
    {
        char buffer[80];
        int tracker = 0;
        strftime(buffer, 20, "%d %b (%a)", &date_tm);
        cout << buffer << endl;
        for (auto i = events.begin(); i != events.end(); i++)
        {
            tracker++;
            if (showIndex)
                cout <<"\t"<< tracker <<". ";
            else
                cout <<"\t";
            i->show_meeting_info();
        }
    }
}

void day::show_events_details()
{
    if (events.size() != 0)
    {
        char buffer[80];
        int tracker = 0;
        strftime(buffer, 20, "%d %b (%a)", &date_tm);
        cout << buffer << endl;
        for (auto i = events.begin(); i != events.end(); i++)
        {
            tracker++;
            cout <<"\t"<< tracker<<". ";
            i->show_meeting_detailed_info();
        }
    }
}

void day::add_event(event _event)
{
    _event.set_event_ID(next_id); 
    events.push_back(_event);  
    next_id++;
    sort_events();
}

void day::remove_event(int id)
{
    for (auto i = events.begin(); i != events.end(); i++)
    {
        if (i->get_event_id() == id)
        {
            events.erase(i);
            break;
        }
    }
}

void day::edit_event(int id, string newDescription="", string newName = "")
{
    for (auto i = events.begin(); i != events.end(); i++)
    {
        if (i->get_event_id() == id)
        {
            if (newDescription != "")
                i->set_event_description(newDescription);
            if (newName != "")
                i->set_event_name(newName);
            break;
        }
    }
}

void day::shift_event(int id, time_t starting_time, time_t ending_time)
{   
    for (auto i = events.begin(); i != events.end(); i++)
    {
        if (i->get_event_id() == id)
        {
            i->set_starting_time(starting_time);
            i->set_ending_time(ending_time);
            break;
        }
    }
}

bool day::is_free(time_t starting_time, time_t ending_time)
{
    for (auto i = events.begin(); i != events.end(); i++)
    {
        if (starting_time >= *i->get_starting_time() && starting_time < *i->get_ending_time())
            return false;
        if (ending_time > *i->get_starting_time() && ending_time <= *i->get_ending_time())
            return false;
        if (starting_time <= *i->get_starting_time() && ending_time >= *i->get_ending_time())
            return false;
    }
    return true;
}

bool day::is_free(time_t starting_time, time_t ending_time, int ignore_event_ID)
{
    for (auto i = events.begin(); i != events.end(); i++)
    {
        if (i->get_event_id() != ignore_event_ID){
            if (starting_time >= *i->get_starting_time() && starting_time < *i->get_ending_time())
                return false;
            if (ending_time > *i->get_starting_time() && ending_time <= *i->get_ending_time())
                return false;
            if (starting_time <= *i->get_starting_time() && ending_time >= *i->get_ending_time())
                return false;
        }
    }
    return true;
}

bool day::is_off_day()
{
    return is_offDay;
}

bool day::is_weekEnd()
{
    if(date_tm.tm_wday == 0 || date_tm.tm_wday == 6)
        return true;
    return false;
}

void day::set_offDay()
{
    is_offDay = true;
    events.clear();
    events.shrink_to_fit();
    next_id = 0;
}

int day::no_ofEvents()
{
    return events.size();
}

time_t* day::get_date()
{
    return &date;
}

void day::sort_events()
{
    for (auto i = events.begin(); i != events.end(); i++)
    {
        for (auto j = i; j != events.end(); j++)
        {
            if (*i->get_starting_time() > *j->get_starting_time())
            {
                event temp = *i;
                *i = *j;
                *j = temp;
            }
        }
    }
}

event* day::at_this_time(time_t time)
{
    for (auto i = events.begin(); i != events.end(); i++)
    {
        if (time >= *i->get_starting_time() && time < *i->get_ending_time())
        {
            return &(*i);
        }
    }
    return nullptr;
}

event* day::get_event(int index){
    return &events[index];
}
