#include "month.h"
#include <ctime>

void month::add_days(time_t day_dt, bool off)
{
    day temp(day_dt, off);
    days.push_back(temp);
}

month::month(time_t _month)
{
    month_ = _month;
    month_tm = *localtime(&month_);
    cout << "Month created: " << asctime(&month_tm);
}

void month::show_monthlySchedule()
{
    char title[50];
    strftime(title, 50, "Schedule for month of %B %Y", &month_tm);
    cout << title << endl;

    for (auto i = days.begin(); i != days.end(); ++i)
    {
        i->show_events();
    }
}




