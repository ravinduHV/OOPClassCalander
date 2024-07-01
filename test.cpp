#include <iostream>
#include <ctime>
using namespace std;

int main() {
    //get time now
    time_t timestamp = time(NULL);
    //convert to local time
    struct tm *localTime = localtime(&timestamp);
    //print the local time
    cout << localTime->tm_hour << ":" << localTime->tm_min << ":" << localTime->tm_sec << endl;
    //print the local day    
    cout << localTime->tm_mday << endl;
    cout << localTime->tm_mon + 1 << endl;
    cout << localTime->tm_year + 1900 << endl;

    cout << localTime->tm_wday <<endl<< localTime->tm_yday << endl;
    cout << localTime->tm_mon << endl;
  return 0;
}
