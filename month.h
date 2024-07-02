#ifndef MONTH_H
#define MONTH_H

#include <vector>
#include "day.h"
#include <ctime>
#include <iostream>

using namespace std;

class month
{
    private:
        time_t Month;
        vector<day> days;
        void add_days();
        struct tm *localTime = localtime(&Month);
        int days_in_month(int yr, int mon);

    public:
        month(time_t* _month): Month(*_month) {add_days();}
        void show_monthlySchedule();
        
};

#endif