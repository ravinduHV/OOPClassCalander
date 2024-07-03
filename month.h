#ifndef MONTH_H
#define MONTH_H

#include <vector>
#include "day.h"
#include <iostream>
#include <ctime>

using namespace std;

class month
{
    private:
        time_t month_=0;
        tm month_tm;

        vector<day> days;
    public:
        month(time_t _month);
        void add_days(time_t day_dt, bool off);
        void show_monthlySchedule();
        
};

#endif