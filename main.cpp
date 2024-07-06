#include <iostream>
#include <vector>
#include "month.h"
#include "day.h"
#include "event.h"
#include <ctime>
#include <string>

using namespace std;

// menu prototypes
int menu_1();
int menu_2();
int menu_3();
int menu_4();
int menu_5();
int menu_6();
int choose_date(bool previousDays);
int choose_event(day * currentDay);

month * currentMonth;
tm temp_tm;
#define MONTH  7
#define YEAR 2024

int main()//shcbhcbe
{
    time_t time1;
    tm time_1 = {0, 0, 0, 1, MONTH-1, YEAR - 1900};
    time1 = mktime(&time_1);
    month cursor(time1);
    currentMonth = &cursor;
    
    while(true) {
        switch(menu_1()) {
            case 1: { menu_2(); break;} // View Schedule
            case 2: { menu_3(); break;} // Add New Event/Meeting
            case 3: { menu_4(); break;} // Show Details of Scheduled Meetings
            case 4: { menu_5(); break;} // Add Day Offs
            case 5: { menu_6(); break;} // Meeting Controls
            case 6: { cout << "Exiting the program..." << endl; return 0;} // Exit
        }
    }
    return 0;
}

int menu_1() {
    int choice;
    cout << "\n1. View Schedule\n2. Add New Event/Meeting\n3. Show Details of Scheduled Meetings\n4. Add Day Offs\n5. Meeting Settings\n6. Exit\n\tEnter your choice: ";
    while(true) {
        cin >> choice;
        if (choice < 1 || choice > 6) {
            cout << "Invalid choice, please try again: ";
        } else {
            return choice;
        }
    }
}

int menu_2() {
    int choice;
    cout << "\nView the Scheduled Events\n1. Daily Schedule\n2. Weekly Schedule\n3. Monthly Schedule\n\tEnter your choice: ";
    while(true) {
        cin >> choice;
        if (choice < 1 || choice > 3) {
            cout << "Invalid choice, please try again: ";
        } else {
            break;
        }
    }
    int data;
    time_t mon = currentMonth->get_month();
    temp_tm = *localtime(&mon);

    switch (choice){
        case 1:{
            char tmp[50];
            strftime(tmp, 50, "Enter the date (%Y %B ?) :", &temp_tm);
            cout <<tmp;
            cin >> data;
            currentMonth->show_dailySchedule(data);
            break;
        
        }
        case 2:{
            while (true)
            {
                cout << "Enter the week number (1/2/3/4/5 ?): ";
                cin >> data;
                if (data < 1 || data > 5)
                    cout << "\nInvalid choice, please try again.\n";
                else
                    break;
            }
            
            
            currentMonth->show_weeklySchedule(data);
            break;
        }
        case 3:{
            currentMonth->show_monthlySchedule();
            break;
        }
    }
    return 0;
}

int menu_3() {
    tm newDy, s, e, now_tm, nextDy;
    time_t s_, e_, now, nextDy_;
    
    time(&now);
    now_tm = *localtime(&now);
    vector<int> repeatMultiple = {1, 7, 1};

    time_t mon = currentMonth->get_month();
    temp_tm = *localtime(&mon);
    
    char quote[25];
    
    day * currentDay; 
	int repeatChoice, repeatCount=1, date, Starting_Time_h, Starting_Time_m, Ending_Time_h, Ending_Time_m;
	
    string Title, Description;

    cout<<"\nAdd new Event/Meeting\nTitle:";
    cin.ignore();   
    getline(cin, Title);

    date = choose_date(false);

    newDy = {0, 0, 0, date, temp_tm.tm_mon, temp_tm.tm_year};
    time_t new_day = mktime(&newDy);
    currentDay = currentMonth->get_day(new_day);

    if (currentDay == nullptr)
    {
        currentMonth->add_days(new_day, false);
        currentDay = currentMonth->get_day(new_day);
    }

    while(true){
        cout<<"Starting Time (HH MM) :";
        cin>>Starting_Time_h>>Starting_Time_m;
        s = {0, Starting_Time_m, Starting_Time_h, date, temp_tm.tm_mon, temp_tm.tm_year};
        s_ = mktime(&s);

        cout<<"Ending Time (HH MM) :";
        cin>>Ending_Time_h>>Ending_Time_m;
        e = {0, Ending_Time_m, Ending_Time_h, date, temp_tm.tm_mon, temp_tm.tm_year};
        e_ = mktime(&e);
        if (e_ < s_ || s_ < now || e_ <  now || Starting_Time_m % 30 != 0|| Ending_Time_m % 30 != 0)
            cout<<"Invalid time slot, please try again\n\n";
        else{
            if(currentDay->is_free(s_, e_))
                break;
            else
                cout<<"The time slot is already booked, please try again\n\n";
        }
    }

    cout<<"Description:";
    cin.ignore();
    getline(cin, Description);
    
    cout<<"Repeating Options\n1.Repeat Daily\n2.Repeat weekly\n3.Non-Repeating\n\tEnter your choice: ";
    cin>>repeatChoice;
    while(true) {
        if (repeatChoice < 1 || repeatChoice > 3) {
            cout << "Invalid choice, please try again :";
            cin >> repeatChoice;
        } else 
            break;
    }
    if(repeatChoice != 3){  //develop this to get untile date not repeat count, in future.
        cout<<"Enter Repeat Count : ";
        cin>>repeatCount;
        while(true) {
            int mx = currentMonth->maxDays();
            if (repeatCount <= 1 || (repeatChoice == 2 && repeatCount > ((mx-date)/repeatMultiple[1] + 1)) || (repeatChoice == 1 && repeatCount > (mx - date + repeatMultiple[0]))) {
                cout << "Invalid choice, please try again :";
                cin >> repeatCount;
            } else 
                break;
        }
    }
    for (int i = 0; i < repeatCount; i++)
    {
        if (currentDay == nullptr)
        {
            currentMonth->add_days(nextDy_, false);
            currentDay = currentMonth->get_day(nextDy_);
        }

        event newEvent(s_, e_, Title, Description, 0 , repeatChoice, repeatCount-i);
        if (currentDay->is_free(s_, e_) && !currentDay->is_off_day() && !currentDay->is_weekEnd())
        {
            currentDay->add_event(newEvent);
        }
        else if (currentDay->is_free(s_, e_) && (currentDay->is_off_day() || currentDay->is_weekEnd()))
        {
            strftime(quote, 25, "(%Y %B %d - %a)", localtime((i == 0) ? &new_day:&nextDy_));
            char q;
            cout << "The day " << quote << " is off/weekend, Are you sure? (Y/N):\n";
            cin >> q;
            if (q == 'Y' || q == 'y')
            {
                currentDay->add_event(newEvent);
                cout << "Event added successfully\n";
            }
        }
        else
        {
            strftime(quote, 25, "(%Y %B %d - %a)", localtime((i == 0) ? &new_day:&nextDy_));
            cout << "The time slot is already booked " << quote << " , No meeting were added\n";
        }

        
        s = {0, Starting_Time_m, Starting_Time_h, date + repeatMultiple[repeatChoice-1]*(i+1), temp_tm.tm_mon, temp_tm.tm_year};
        s_ = mktime(&s);
        //cout << s_<<endl;

        e = {0, Ending_Time_m, Ending_Time_h, date + repeatMultiple[repeatChoice-1]*(i+1), temp_tm.tm_mon, temp_tm.tm_year};
        e_ = mktime(&e);
        //cout << e_<<endl;

        nextDy = {0, 0, 0, date + repeatMultiple[repeatChoice-1]*(i+1), temp_tm.tm_mon, temp_tm.tm_year};
        nextDy_ = mktime(&nextDy);
        //cout << nextDy_<<endl;

        currentDay = currentMonth->get_day(nextDy_);
    }
    
    return 0;
}

int menu_4() {
    time_t ref_mon_t = currentMonth->get_month();
    tm ref_mon = *localtime(&ref_mon_t);

    int date = choose_date(false);

    tm now_tm = {0, 0, 0, date, ref_mon.tm_mon, ref_mon.tm_year};
    time_t now = mktime(&now_tm);

    day * currentDay = currentMonth->get_day(now);
    if (currentDay == nullptr || currentDay->no_ofEvents() == 0){
        cout << "No events/meetings scheduled for the day\n";
        return 1;
    }

    int meetingChoice;
    currentDay->show_events(true);
    cout << "\n\tEnter the ID(1,2,..) to select the event/meeting: ";
    while (true)
    {
        cin >> meetingChoice;
        if (meetingChoice < 1 || meetingChoice > currentDay->no_ofEvents())
            cout << "\tInvalid choice, please try again: ";
        else
            break;
    }

    event * currentEvent = currentDay->get_event(meetingChoice-1);
    cout << "\t";
    currentEvent->show_meeting_detailed_info();
	return 0;
}

int menu_5() {
	int date;
    time_t ref_mon_t = currentMonth->get_month(), now;
    tm ref_mon = *localtime(&ref_mon_t), now_tm;
    time(&now);
    now_tm = *localtime(&now);

    char quote[60];
    strftime(quote, 60, "Add Dayoffs\nEnter the required date (%Y %B ?) :", &ref_mon);
    cout<<quote;
    while(true) {
    	cin >> date;
        if(date<now_tm.tm_mday && date > currentMonth->maxDays())
            cout<<"Entered date is invalid,please try again : ";
        else
            break;
    }
    now_tm = {0, 0, 0, date, ref_mon.tm_mon, ref_mon.tm_year};
    now = mktime(&now_tm);
    if (currentMonth->get_day(now) == nullptr)
        currentMonth->add_days(now, true);
    else
        currentMonth->get_day(now)->set_offDay();
    return date;
}

int menu_6() {
	int settingChoice, date, meetingChoice;
    event * currentEvent;
    cout<<"Meeting Setting\n1. Shift a event/meeting\n2. Edit a scheduled event/meeting\n3. Delete a scheduled event/meeting\n";
    cout<<"\n\tEnter your prefered setting:";
	while(true) {
        cin >> settingChoice;
        if (settingChoice < 1 || settingChoice > 3) 
            cout << "\tInvalid choice, please try again: ";
        else
            break;
    }
    tm now_tm;
    time_t now;
    time(&now);
    now_tm = *localtime(&now);

    time_t mon = currentMonth->get_month();
    temp_tm = *localtime(&mon);
    
    date = choose_date(false);

    now_tm = {0, 0, 0, date, temp_tm.tm_mon, temp_tm.tm_year};
    now = mktime(&now_tm);

    day * currentDay = currentMonth->get_day(now);
    if (currentDay == nullptr || currentDay->no_ofEvents() == 0){
        cout << "No events/meetings scheduled for the day\n";
        return 1;
    }
    
    meetingChoice = choose_event(currentDay);

    currentEvent = currentDay->get_event(meetingChoice-1); // by gettting whole object we can access all the details of the event and pop up the event in the vector.
    switch (settingChoice){
        case 1:{ //shift event
            int Starting_Time_h, Starting_Time_m, Ending_Time_h, Ending_Time_m;
            tm s_, e_;
            time_t s,e;

            char time_[25];
            temp_tm = *localtime(currentEvent->get_starting_time());
            strftime(time_, 25, "(%H %M) :", &temp_tm);
            
            cout << "shift starting time " << time_;
            cin >> Starting_Time_h >> Starting_Time_m;
            
            temp_tm = *localtime(currentEvent->get_ending_time());
            strftime(time_, 25, "(%H %M) :", &temp_tm);
            
            cout << "shift ending time " << time_;
            cin >> Ending_Time_h >> Ending_Time_m;
            
            s_ = {0, Starting_Time_m, Starting_Time_h, date, temp_tm.tm_mon, temp_tm.tm_year};
            e_ = {0, Ending_Time_m, Ending_Time_h, date, temp_tm.tm_mon, temp_tm.tm_year};
            s = mktime(&s_);
            e = mktime(&e_);
            time(&now);
            if(e < s || s < now || e < now || Starting_Time_m % 30 != 0 || Ending_Time_m % 30 != 0)
                cout << "Invalid time slot, please try again\n";
            if (currentDay->is_free(s, e, currentEvent->get_event_id())){
                currentDay->shift_event(currentEvent->get_event_id(), s, e);
            }
            else
                cout << "The time slot is already booked, please try again\n";

            break;
        }
        case 2:{ // edit event description
            string Description, name;
            cout << "The current name is: " << currentEvent->get_event_name() << endl;
            cout << "If you want to change the name, enter the new name: ";
            cin.ignore();
            getline(cin, name);
            cout << "The current description is: " << currentEvent->get_event_description() << endl;
            cout << "If you want to change the description, enter the new description: ";
            cin.ignore();
            getline(cin, Description);
            currentDay->edit_event(currentEvent->get_event_id(), Description, name);
            break;
        }
        case 3:{ // delete event
            currentDay->remove_event(currentEvent->get_event_id());
            cout << "Event deleted successfully\n";
            break;
        }
    }

    return 0;
}

int choose_event(day * currentDay){
    int meetingChoice;
    currentDay->show_events(true);
    cout << "\n\tEnter the ID(1,2,..) to select the event/meeting: ";
    while (true)
    {
        cin >> meetingChoice;
        if (meetingChoice < 1 || meetingChoice > currentDay->no_ofEvents())
            cout << "\tInvalid choice, please try again: ";
        else
            break;
    }
    return meetingChoice;
}

int choose_date(bool previousDays = true){
    int date;
    time_t ref_mon_t = currentMonth->get_month(), now;
    tm ref_mon = *localtime(&ref_mon_t), now_tm;
    
    time(&now);
    now_tm = *localtime(&now);
    
    char quote[40];
    strftime(quote, 40, "Date (%Y %B ?) :", &ref_mon);
    cout<<quote;
    
    while(true) {
        cin >> date;
        if((previousDays && date < 1 && date > currentMonth->maxDays()) || (!previousDays && date < now_tm.tm_mday && date > currentMonth->maxDays()))
            cout<<"Entered date is invalid,please try again : ";
        else
            break;
    }
    return date;
}