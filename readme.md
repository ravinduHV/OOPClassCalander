# Calendar Management System

## Contributors
1. A.M.A.P. Atapattu (EE) [@APA337](https://github.com/APA337)
2. N.L. Sirimanne (EE) 
3. P.M.T. Kehara (EE) [@Kehara2002](https://github.com/Kehara2002)
4. H.M.R.V.Herath(CO) [@ravinduHV](https://github.com/ravinduHV)
5. P. Nithurjithan (EE) 

## Overview

This Calendar Management System is a console-based application written in C++. It allows users to manage their schedules by adding, viewing, and managing events and meetings. The application supports viewing schedules on a daily, weekly, and monthly basis, adding new events or meetings, showing details of scheduled meetings, adding day-offs, and managing meeting settings.

## Features

- **View Schedule**: Users can view their schedule in three different modes: daily, weekly, and monthly.
- **Add New Event/Meeting**: Allows users to add new events or meetings by specifying the title, date, start and end times, description, and repetition options.
- **Show Details of Scheduled Meetings**: Users can view detailed information about any scheduled meeting by selecting it from a list.
- **Add Day Offs**: This feature enables users to mark certain days as off-days, during which no meetings can be scheduled.
- **Meeting Controls**: Provides additional settings for managing meetings.

## How to Use

1. **Start the Application**: Run the application. The main menu will be displayed with the following options:
    - View Schedule
    - Add New Event/Meeting
    - Show Details of Scheduled Meetings
    - Add Day Offs
    - Meeting Settings
    - Exit

2. **Navigate the Menu**: Use the numeric keys (1-6) to navigate through the menu options. Each option leads to a submenu or a functionality described below.

### Viewing the Schedule

- Choose "View Schedule" from the main menu.
- Select the desired schedule view: Daily, Weekly, or Monthly.
- Follow the prompts to specify the date or week number.

### Adding a New Event/Meeting

- Select "Add New Event/Meeting" from the main menu.
- Enter the event/meeting title, date, start and end times, and description.
- Choose the repetition option (daily, weekly, or non-repeating) and specify the repeat count if applicable.

### Showing Details of Scheduled Meetings

- Choose "Show Details of Scheduled Meetings" from the main menu.
- Enter the date for which you want to view the meetings.
- Select a meeting from the list to view its detailed information.

### Adding Day Offs

- Select "Add Day Offs" from the main menu.
- Enter the date you wish to mark as an off-day.

### Meeting Controls

- This feature allows for additional meeting management settings, accessible through the main menu.

## Exiting the Program

- To exit the application, choose the "Exit" option from the main menu.

## Dependencies

- C++ Standard Library
- Time manipulation functions (`<ctime>`)

## Compilation and Execution

To compile and run the application, use a C++ compiler that supports C++11 or later. For example, using g++:

```bash
g++ main.cpp event.cpp event.h day.cpp day.h month.h month.cpp  -o CalendarManagementSystem
./CalendarManagementSystem
```
![UML diagram](https://github.com/ravinduHV/OOPClassCalendar/assets/75525974/5265f99e-b039-4e91-b3f2-841cc04ce797)

