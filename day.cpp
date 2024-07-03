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

void day::show_events()
{
    char tmp[30];
    strftime(tmp, 30, "%d %B (%a)", &date_tm);
    cout << "Date: "<< tmp << endl;
    cout << "Is off day: " << is_offDay << endl;
    cout << "Is weekend: " << is_weekEnd() << endl<< endl;
    cout << "Events: " << endl;
    for (int i = 0; i < events.size(); i++)
    {
        events[i].show_meeting_info();
        cout << endl;
    }
}

void day::add_event(event _event)
{ 
    _event.set_event_ID(next_id); 
    events.push_back(_event);  
    next_id++;
}

void day::remove_event(int id)
{
    for (int i = 0; i < events.size(); i++)
    {
        if (events[i].get_event_id() == id)
        {
            events.erase(events.begin() + i);
            events.shrink_to_fit();
            break;
        }
    }
}

void day::edit_event(int id)
{

}

void day::shift_event(int id, time_t starting_time, time_t ending_time)
{   
    /*time_t new_start_time = {0,0,0,0,starting_time,0};
    time_t new_ending_time(0,0,0,ending_time,0);

	for (int i = 0; i < events.size(); i++)
    {
        if (events[i].get_event_id() == id)
        {
            events[i].set_starting_time(new_start_time); 
            events[i].set_ending_time(new_ending_time);
        }
    }*/
}

bool day::is_free(string starting_time, string ending_time)
{
    return false;
}

bool day::is_off_day()
{
    return !is_offDay;
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
