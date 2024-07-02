#include <iostream>
#include <vector>
#include "month.h"
#include "day.h"
#include "event.h"
#include <ctime>
#include "datetime.h"

using namespace std;

int menu_1();

int main()
{
    menu_1();
    
}


int menu_1(){
    int choice;
    cout << "View Schedule\nAdd New meeting\nShow details of individual meetings\nAdd day offs\nMeeting Controls\n";
    
    while(true)
    {
        cin >> choice;
        if (choice < 1 || choice > 5)
        {
            cout << "Invalid choice, please try again :";
        }
        else
        {
            return choice;
        }
    }

}