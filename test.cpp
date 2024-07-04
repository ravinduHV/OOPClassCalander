#include<iostream>
using namespace std;

int menu_1();
int menu_2();
int menu_3();
int menu_4();
int menu_5();
int menu_6();

int main() {
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
            break;
        }
    }
    return choice;
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
}

int menu_3() {
	int choice_2,date,Starting_Time,Ending_Time;
	string Title;
	string Description;
    cout<<"Add new Event/Meeting\nTitle:";
    cin>>Title;
    cout<<"Date:";
    cin>>date;
    if(date<1 ||date>31){
		cout<<"Entered date is invalid,please try again\n";							
	}else{
    	cout<<date<<"/07/2024\n";
	}
    cout<<"Starting Time:";
    cin>>Starting_Time;
    cout<<"Ending Time:";
    cin>>Ending_Time;
    cout<<"Description:";
    cin>>Description;
    cout<<"Repeating Options\n1.Repeat Daily\n2.Repeat weekly\n3.Non-Repeating\n\tEnter your choice: ";
    cin>>choice_2;
    while(true) {
        cin >> choice_2;
        if (choice_2 < 1 || choice_2 > 3) {
            cout << "Invalid choice, please try again";
        } else {
            return choice_2;
        }
    }
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