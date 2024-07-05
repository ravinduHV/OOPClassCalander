#ifndef DAY_H
#define DAY_H

#include <vector>
#include "event.h"
#include <ctime>
#include <iostream>

using namespace std;

class day
{
private:
    time_t date;
    tm date_tm;

    vector<event> events;
    bool is_offDay;
    int next_id;

public:
    day(time_t _date, bool is_offDay_);  
    void show_events();
    void add_event(event _event);
    void remove_event(int id);
    void edit_event(int id);
    void shift_event(int id, time_t starting_time, time_t ending_time); 
    bool is_free(time_t starting_time, time_t ending_time);
    bool is_off_day();
    bool is_weekEnd();
    void set_offDay();
    int no_ofEvents();
    time_t* get_date();
    event* at_this_time(time_t time);
};

#endif