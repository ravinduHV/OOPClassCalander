#include <iostream>
#include <vector>
#include "day.h"
#include "event.h"
#include <ctime>

using namespace std;

int main()
{
    struct tm datetime_1;
    struct tm datetime_2, datetime;
    time_t timestamp, timestamp_1,timestamp_2;
    
    //creating meeting date
    datetime_1.tm_year = 2024 - 1900; // Number of years since 1900
    datetime_2.tm_year = 2024 - 1900; // Number of years since 1900
    datetime_1.tm_mon = 7-1; // 0-11
    datetime_2.tm_mon = 7-1; // 0-11
    datetime_1.tm_mday = 7; // 1-31
    datetime_2.tm_mday = 7; // 1-31
    datetime_1.tm_hour = 10;
    datetime_2.tm_hour = 11;
    datetime_1.tm_min = 0;
    datetime_2.tm_min = 0;
    timestamp_1 = mktime(&datetime_1);
    timestamp_2 = mktime(&datetime_2);

    event e1;
    e1.set_event_name("Meeting with the boss");
    e1.set_event_description("Discussing the new project");
    e1.set_starting_time(&timestamp_1);
    e1.set_ending_time(&timestamp_2);
    


    //creating date
    datetime.tm_year = 2024 - 1900; // Number of years since 1900
    datetime.tm_mon = 7-1; // 0-11
    datetime.tm_mday = 7; // 1-31
    timestamp = mktime(&datetime);

    day d1(&timestamp, false);
    d1.add_event(e1);
    d1.show_events();
}