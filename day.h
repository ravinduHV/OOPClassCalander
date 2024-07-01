#include <vector>

class day
{
private:
    int day_;
    vector<event> events;
    bool is_offDay;
    bool is_weekEnd;

public:
    day(int _day, bool is_offDay_, bool is_weekEnd_): day_(_day) ,is_offDay(is_offDay_) , is_weekEnd(is_weekEnd_)  {}
    void show_events();
    void add_event(event _event);
    void remove_event(int id);
    void edit_event(int id);
    void shift_event(int id, string starting_time, string ending_time);
    void show_meetings();    
};

