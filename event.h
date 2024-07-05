#ifndef EVENT_H
#define EVENT_H

#include <string>

using namespace std;


class event
{
    private:
        time_t starting_time = 0;
        time_t ending_time = 0;
        tm starting_time_tm;
        tm ending_time_tm;

        string event_name;
        string event_description; 
        int event_id;
        int repeat_option; // 0-non-repeating, 1 for daily, 2 for weekly
        int repeat_count;

    public:
        event(time_t _starting_time, time_t _ending_time, string _event_name, string _event_description, int _event_id, int _repeat_option, int _repeat_count);
        void set_starting_time(time_t time);
        void set_ending_time(time_t time);
        void set_event_name(string name);
        void set_event_description(string description);
        void set_event_ID(int id);
        time_t* get_starting_time();
        time_t* get_ending_time();
        string get_event_name();
        string get_event_description();
        int get_event_id();
        void show_meeting_info();  
        void show_meeting_detailed_info();
};

#endif