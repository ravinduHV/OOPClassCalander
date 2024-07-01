#include <iostream>
#include <vector>
#include "day.h"
#include "event.h"

using namespace std;

int main()
{
    event e1;
    e1.set_event_name("Meeting with the boss");
    e1.set_event_description("Discussing the new project");
    e1.set_starting_time("10:00");
    e1.set_ending_time("11:00");
    
    event e2;
    e2.set_event_name("Meeting with the team");
    e2.set_event_description("Discussing the new project");
    e2.set_starting_time("11:00");
    e2.set_ending_time("12:00");

    day d1(1, false, false);
    d1.add_event(e1);
    d1.add_event(e2);
    d1.show_events();
}