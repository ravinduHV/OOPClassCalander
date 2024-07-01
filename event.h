#ifndef EVENT_H
#define EVENT_H

#include <string>
using namespace std;

class event
{
    private:
        string starting_time;
        string ending_time;
        string event_name;
        string event_description; 
        int event_id;

    public:
        void set_starting_time(string time);
        void set_ending_time(string time);
        void set_event_name(string name);
        void set_event_description(string description);
        void set_event_ID(int id);
        string get_starting_time();
        string get_ending_time();
        string get_event_name();
        string get_event_description();
        int get_event_id();
        void show_meeting_info();  
};

#endif