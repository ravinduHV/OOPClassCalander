#ifndef DAY_H
#define DAY_H

#include <vector>
#include "event.h"
#include <ctime>
#include <iostream>
#include "datetime.h"

using namespace std;

class day
{
private:
    datetime date;
    vector<event> events;
    bool is_offDay;
    int next_id;

public:
    day(datetime _date, bool is_offDay_): date(_date) ,is_offDay(is_offDay_) , next_id(0)  {cout << date.show_date()<<endl;}  
    void show_events();
    void add_event(event _event);
    void remove_event(int id);
    void edit_event(int id);
    void shift_event(int id, int starting_time, int ending_time); 
    bool is_free(string starting_time, string ending_time);
    bool is_off_day();
    bool is_weekEnd();
    void set_offDay();
    int no_ofEvents();
    datetime* get_date();
};

#endif