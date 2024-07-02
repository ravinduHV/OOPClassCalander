#include "datetime.h"
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

datetime::datetime(const datetime& other) 
    : year(other.year), month(other.month), day(other.day), hour(other.hour), minute(other.minute) {}

string datetime::show_date()
{
    char buffer[80];    
    snprintf(buffer, sizeof(buffer), "%i-%i-%i %i:%i", year, month, day, hour, minute);
    return buffer;
}

int datetime::days_in_month()
{
    return 31;
}
