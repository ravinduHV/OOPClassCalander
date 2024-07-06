#include<iostream>
#include <ctime>
#include "event.h"

using namespace std;

int main() {
    tm t1 = {0, 30, 10, 1,7-1,2024-1900};
    tm t2 = {0, 30, 12, 1,7-1,2024-1900};
    cout << t1.tm_min<<endl;
    time_t t1_ = mktime(&t1);
    time_t t2_ = mktime(&t2);
    cout << t1_<<endl;
    cout << t2_<<endl;

    time_t now;
    time(&now);
    tm now_tm = *localtime(&now);

    cout << now_tm.tm_wday <<endl;

}
