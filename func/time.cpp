#include <ctime>
#include <time.h>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main(){
    time_t right_now = time(NULL);
    tm *pTM = localtime(&right_now);
    cout << ctime(&right_now);
    cout << asctime(pTM);
    double time_passed = clock()/static_cast<double>(CLOCKS_PER_SEC);
    cout << "Program has been running for ";
    cout << time_passed << " seconds." << endl;

    long x1 = clock();
    long big_array[10000];
    for (int i = 0; i < 10000; i++)
    {
        big_array[i] = i;
    }
    long x2 = clock();
    cout << "Time passed in microsecs: " << x2 - x1 << endl;

    tm theday;
    theday.tm_mday = 1;
    theday.tm_mon = 0;
    theday.tm_year = 200;
    theday.tm_hour = 12;
    theday.tm_min = 0;
    theday.tm_sec = 0;

    mktime(&theday);

    char date_str[256];
    strftime(date_str, 256, "Day of the week is %A.", &theday);
    cout << date_str << endl;
}