#include "month.h"
#include "datetime.h"

void month::add_days()
{
    cout << "adding days :" <<month_.year<< " " << month_.month<< endl;
    cout << "adding days :" <<month_.year << " " << month_.month<<" " << month_.day << endl;

    for (int i = 1; i <= month_.days_in_month(); i++){
        datetime dateTemp(month_.year, month_.month, i, 0, 0);
        day temp(dateTemp, false);
        days.push_back(temp);
    }
    for (int i = 0; i < days.size(); i++){
        cout << days[i].get_date()->show_date() << endl;
    }

    cout << "adding days :" <<month_.year << " " << month_.month<<" " << month_.day << endl;
}


void month::show_monthlySchedule()
{
    cout << "Schedule for month of "<<month_.month << " " << month_.year<< ":\n";

    for (auto i = days.begin(); i != days.end(); ++i)
    { 
        cout << month_.day <<" "<< month_.month << " " << month_.year << endl;
        i->show_events();
    }
}




