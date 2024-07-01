#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <ctime>

using namespace std;

class event
{
    private:
        time_t starting_time;
        time_t ending_time;
        string event_name;
        string event_description; 
        int event_id;

    public:
        void set_starting_time(time_t* time);
        void set_ending_time(time_t* time);
        void set_event_name(string name);
        void set_event_description(string description);
        void set_event_ID(int id);
        time_t* get_starting_time();
        time_t* get_ending_time();
        string get_event_name();
        string get_event_description();
        int get_event_id();
        void show_meeting_info();  
};

#endif