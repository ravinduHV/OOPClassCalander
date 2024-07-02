#ifndef MONTH_H
#define MONTH_H

#include <vector>
#include "day.h"
#include <iostream>
#include "datetime.h"

using namespace std;

class month
{
    private:
        datetime month_;
        vector<day> days;
        void add_days();

    public:
        month(datetime _month): month_(_month) {add_days();}
        void show_monthlySchedule();
        
};

#endif