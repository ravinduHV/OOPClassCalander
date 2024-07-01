#include "day.h"
#include <string>
#include <iostream>

using namespace std;


void day::show_events()
{
    cout << "Date: " << localTime->tm_mon<<"/" << localTime->tm_mday << endl;
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

void day::shift_event(int id, string starting_time, string ending_time)
{
}

bool day::is_free(string starting_time, string ending_time)
{
    return false;
}

bool day::is_free_day()
{
    return !is_offDay;
}

bool day::is_weekEnd()
{
    if(localTime->tm_wday == 0 || localTime->tm_wday == 6)
        return true;
    return false;
}
