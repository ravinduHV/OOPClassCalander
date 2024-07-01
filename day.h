#ifndef DAY_H
#define DAY_H

#include <vector>
#include "event.h"
#include <ctime>

using namespace std;

class day
{
private:
    time_t date;
    vector<event> events;
    bool is_offDay;
    int next_id;
    struct tm *localTime = localtime(&date);

public:
    day(time_t* _date, bool is_offDay_): date(*_date) ,is_offDay(is_offDay_) , next_id(0)  {}
    void show_events();
    void add_event(event _event);
    void remove_event(int id);
    void edit_event(int id);
    void shift_event(int id, string starting_time, string ending_time); 
    bool is_free(string starting_time, string ending_time);
    bool is_free_day();
    bool is_weekEnd();
};

#endif