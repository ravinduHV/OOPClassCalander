#include<iostream>
#include <ctime>
#include "event.h"

using namespace std;

int main() {
    tm t1 = {0, 30, 10, 1,7,2024-1900};
    time_t t1_ = mktime(&t1);
    tm t2 = {0, 0, 12, 1, 7, 2024 - 1900};
    time_t t2_ = mktime(&t2); 

    event e(t1_, t2_, "Meeting A", "Description", 0, 0, 0);
    e.show_meeting_info();
}
