#ifndef DATETIME_H
#define DATETIME_H

#include <string>
#include <iostream>
#include <ctime>

using namespace std;


class datetime{
    public:
        int year, month, day, hour, minute;
        datetime(int year_, int month_, int day_, int hour_, int minute_): year(year_), month(month_), day(day_), hour(hour_), minute(minute_) {}
        datetime(const datetime& other);
        string show_date(); 
        int days_in_month();    
};

#endif