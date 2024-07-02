#include "month.h"


void month::add_days()
{
    int yr = localTime->tm_year, mon = localTime->tm_mon;
    cout << "adding days :" <<localTime->tm_mon << " " << localTime->tm_year+1900 << endl;
    int noofDays = days_in_month(yr, mon);
    cout << "adding days :" <<localTime->tm_mon << " " << localTime->tm_year+1900 << endl;

    for (int i = 1; i <= noofDays; i++){
        tm time_in = { 0, 0, 0, i, localTime->tm_mon, localTime->tm_year};
        time_t time_temp = mktime(&time_in);
        day temp(&time_temp, false);
        days.push_back(temp);
    }
}


void month::show_monthlySchedule()
{
    char mon[20];
    strftime(mon, 20, "%B %Y", localTime);
    cout << "Schedule for month of "<<mon << ":\n";

    for (auto i = days.begin(); i != days.end(); ++i)
    { 
        struct tm *_localTime = localtime(i->get_date());
        char buffer[20];
        strftime(buffer, 20, "%d %B (%a)", _localTime);
        cout << buffer << endl;
    }
}

int month::days_in_month(int yr, int mon) {
    if (mon == 12) {
        mon = 0;  // Move to January of the next year
        yr++;
    }
    
    // tm structure for the first day of the next month
    struct tm in = { 0, 0, 0, 1, mon, yr };
    time_t time_temp = mktime(&in);
    // Subtract one day
    time_temp -= 24 * 60 * 60;
    // Convert back to tm structure
    struct tm *out = localtime(&time_temp);
    return out->tm_mday;
}


