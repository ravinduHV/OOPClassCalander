#include <iostream>
#include <vector>
#include "month.h"
#include "day.h"
#include "event.h"
#include <ctime>


using namespace std;

int menu_1();

int main()
{
    
    tm time_1;
    time_t time1;
    time_1 = {0, 0, 0, 1, 7-1, 2024 - 1900};
    time1 = mktime(&time_1);
    month month1(time1);
    month1.add_days(time1, false);
    month1.show_monthlySchedule();
}


int menu_1(){
    int choice;
    cout << "View Schedule\nAdd New meeting\nShow details of individual meetings\nAdd day offs\nMeeting Controls\n";
    
    while(true)
    {
        cin >> choice;
        if (choice < 1 || choice > 5)
            cout << "Invalid choice, please try again :";
        else
            return choice;
    }
}