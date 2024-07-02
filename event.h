#ifndef EVENT_H
#define EVENT_H

#include <string>
#include "datetime.h"

using namespace std;


class event
{
    private:
        datetime starting_time;
        datetime ending_time;
        string event_name;
        string event_description; 
        int event_id;

    public:
        void set_starting_time(datetime time);
        void set_ending_time(datetime time);
        void set_event_name(string name);
        void set_event_description(string description);
        void set_event_ID(int id);
        datetime* get_starting_time();
        datetime* get_ending_time();
        string get_event_name();
        string get_event_description();
        int get_event_id();
        void show_meeting_info();  
};

#endif