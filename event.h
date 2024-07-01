#include <string>

class event
{
    private:
        string starting_time;
        string ending_time;
        string event_name;
        string event_description; 
        int event_id;

    public:
        event(int ID): event_id(ID) {}
        void set_starting_time(string time);
        void set_ending_time(string time);
        void set_event_name(string name);
        void set_event_description(string description);
        string get_starting_time();
        string get_ending_time();
        string get_event_name();
        string get_event_description();
        int get_event_id();  
}