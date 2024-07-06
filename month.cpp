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
    // plz refer : https://www.w3schools.com/cpp/ref_ctime_strftime.asp
    strftime(title, 50, "\nSchedule for month of %B %Y", &month_tm);
    cout << title << endl;

    for (auto i = days.begin(); i != days.end(); ++i)
    {
        i->show_events(false);
    }
}

void month::show_weeklySchedule(int week_no)
{
    int firstDay_of_firstWeek = 1;
    tm tmp;
    time_t tmp_;
    for (int i = firstDay_of_firstWeek; i <= maxDays(); i++)
    {
        tmp = {0, 0, 0, i, month_tm.tm_mon, month_tm.tm_year};
        tmp_ = mktime(&tmp);
        tmp = *localtime(&tmp_);
        if(tmp.tm_wday == 1) // Monday
        {
            firstDay_of_firstWeek = i;
            break;
        }
    }
    cout << "\nA schedule for week :"<< week_no;
    char buffer[25];
    strftime(buffer, 25,  " of the month :%B\n", &tmp);
    day * currentDay;
    cout << buffer;

    for (int i = (firstDay_of_firstWeek+7*(week_no-1)); i<=maxDays() && i < (firstDay_of_firstWeek+7*week_no); i++)
    {
        tmp = {0, 0, 0, i, month_tm.tm_mon, month_tm.tm_year};
        currentDay = get_day(mktime(&tmp));
        if (currentDay != nullptr)
            currentDay->show_events(false);
        else{
            char buffer[20];
            strftime(buffer, 20, "%d %B (%a)", &tmp);
            cout << buffer << endl;
        }
    }
    cout << endl;
}

void month::show_dailySchedule(int date)
{   
    tm date_tm = {0, 0, 0, date, month_tm.tm_mon, month_tm.tm_year}, upperLimit, lowerLimit;
    time_t temp_t;

    char tmp[50];
    strftime(tmp, 50, "%d  %B %Y", &date_tm);
    day * currentDay = nullptr;
    event * currentEvent = nullptr;

    cout << "\nA schedule for day : " << tmp << endl;
    
    for (auto i = days.begin(); i != days.end(); ++i)
    {
        if (*i->get_date() == mktime(&date_tm))
        {
            currentDay = &(*i);
            break;
        }
    }

    for (int i = 0; i < 24; i++)
    {
        for (int j = 0; j <=30; j = j +30)
        {
            upperLimit = {0, j, i, date, month_tm.tm_mon, month_tm.tm_year};
            lowerLimit = {0, (j==30)? 0:30, (j==0) ? i:(i+1), date, month_tm.tm_mon, month_tm.tm_year};
            char start[5], end[12];
            strftime(start, 5, "%H%M", &upperLimit);
            strftime(end, 12, " - %H%MH ", &lowerLimit);
            cout << start<< end;
            if (currentDay != nullptr)
            {
                temp_t = mktime(&upperLimit);
                currentEvent = currentDay->at_this_time(temp_t);
                if (currentEvent != nullptr)
                {
                    cout << currentEvent->get_event_name();
                }
            }
            cout << endl;
        }
    }
}

time_t month::get_month()
{
    return month_;
}

day *month::get_day(time_t date)
{
    for (auto i = days.begin(); i != days.end(); ++i)
    {
        if (*i->get_date() == date)
        {
            return &(*i);
        }
    }
    return nullptr;
}


int month::maxDays() {
    int _month_ = month_tm.tm_mon + 1; 
    if(_month_ % 2==0 && _month_!=8 && _month_!=2)
        return 30;
    if(_month_==2){
        if((month_tm.tm_year+1900) % 4 == 0)
            return 29;
        else 
            return 28;
        }
    return 31;
}

void month::removeEvents(event *_event)
{
    // remove all repeated events
    
}
