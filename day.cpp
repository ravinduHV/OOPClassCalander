#include "day.h"
#include <string>
#include <iostream>

using namespace std;


void day::show_events()
{
    cout << "Date: " << date.year <<" "<< date.month << " "<< date.day << endl;
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
        }
    }
}

void day::edit_event(int id)
{

}

void day::shift_event(int id, int starting_time, int ending_time)
{   datetime new_start_time(0,0,0,starting_time,0);
    datetime new_ending_time(0,0,0,ending_time,0);

	for (int i = 0; i < events.size(); i++)
    {
        if (events[i].get_event_id() == id)
        {
            events[i].set_starting_time(new_start_time); 
            events[i].set_ending_time(new_ending_time);
        }
    }
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
    struct tm * timeinfo;
    struct tm  timeinfo2;
    time_t rawtime;

    timeinfo2.tm_year = date.year - 1900;
    timeinfo2.tm_mon = date.month - 1;
    timeinfo2.tm_mday = date.day;
    timeinfo2.tm_hour = 0;
    timeinfo2.tm_min = 0;
    timeinfo2.tm_sec = 0;
    rawtime = mktime(&timeinfo2);
    timeinfo = localtime(&rawtime); 
    if(timeinfo->tm_wday == 0 || timeinfo->tm_wday == 6)
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

datetime* day::get_date()
{
    return &date;
}
