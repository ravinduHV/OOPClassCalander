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
int maxDays(int month, int year);

month * currentMonth;
tm temp_tm;

int main()
{
    
    tm time_1;
    time_t time1;
    time_1 = {0, 0, 0, 1, 7-1, 2024 - 1900};
    time1 = mktime(&time_1);
    month JULY(time1);
    currentMonth = &JULY;
    
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
}

int menu_1() {
    int choice;
    cout << "1. View Schedule\n2. Add New Event/Meeting\n3. Show Details of Scheduled Meetings\n4. Add Day Offs\n5. Meeting Controls\n6. Exit\n\tEnter your choice: ";
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
    cout << "View the Scheduled Events\n1. Daily Schedule\n2. Weekly Schedule\n3. Monthly Schedule\n\tEnter your choice: ";
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
            cout << "Enter the week number (1/2/3/4/5/6): ";
            cin >> data;
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
    
    char tmp[15];
    strftime(tmp, 15, "(%Y %B ?) :", &temp_tm);
     
    day * currentDay; 
	int repeatChoice, repeatCount=1, date, Starting_Time_h, Starting_Time_m, Ending_Time_h, Ending_Time_m;
	
    string Title, Description;

    cout<<"Add new Event/Meeting\nTitle:";
    cin.ignore();   
    getline(cin, Title);

    cout<<"Date "<<tmp;
    cin>>date;
    while (true)
    {
        if(date<now_tm.tm_mday || date > maxDays(temp_tm.tm_mon+1, temp_tm.tm_year+1900))
        {
		    cout<<"Entered date is invalid,please try again :";
            cin>>date;
        }
        else
            break;
    }
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
            cout<<"Invalid time slot, please try again\n";
        else{
            if(currentDay->is_free(s_, e_))
                break;
            else
                cout<<"The time slot is already booked, please try again\n";
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
            int mx = maxDays(temp_tm.tm_mon+1, temp_tm.tm_year+1900);
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
        event newEvent(s_, e_, Title, Description, 0 , repeatChoice, repeatCount-1);
        currentDay->add_event(newEvent);
        
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
	int date;
    cout<<"Enter the date of the Scheduled Event/Meeting: ";
    while(true){
    	cin>>date;
		if(date>=1 && date<=31){
			cout<<"The details of the Event Scheduled on "<<date<<"/07/2024 are:";							
		}else{
			cout<<"Entered date is invalid,please try again";
		}
	}	
	return date;
}

int menu_5() {
	int date;
    cout<<"Add Dayoffs\n Enter the required date:\n";
    while(true) {
    	cin>>date;
        if(date>=1 && date<=31){
			cout<<date<<"/07/2024";							
		}else{
			cout<<"Entered date is invalid,please try again";
		}
    }
    return date;
}

int menu_6() {
	int choice;
    cout<<"Meeting Controls\n1.Shift a event/meeting\n2.Edit a scheduled event/meeting\n3.Delete a scheduled event/meeting\n";
    cout<<"Enter your prefered setting:";
    cin >> choice;
	while(true) {
        cin >> choice;
        if (choice < 1 || choice > 3) 
            cout << "Invalid choice, please try again: ";
        else
            break;
    }
    return choice;
}

int maxDays(int month, int year) {
    //month 1-12 
    if(month % 2==0 && month!=8 && month!=2)
        return 30;
    if(month==2){
        if(year % 4 == 0)
            return 29;
        else 
            return 28;
        }
    return 31;
}