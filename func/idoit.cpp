#include <iostream>
#include <string>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;
using std::string;

string input_str;

int get_month_num(string str);

int main(){
    int a_year = 0, a_month = 0, a_day = 1;
    do{
        cout << "Enter a year from 1900 onward: ";
        cin >> a_year;

        cout << "Enter the name of a month: ";
        cin >> input_str;
        a_month = get_month_num(input_str);

        cout << "Enter a day of the month, from 1 to 31: ";
        cin >> a_day;

        tm theday;
        theday.tm_mday = a_day;
        theday.tm_mon = a_month - 1;
        theday.tm_year = a_year - 1900;
        theday.tm_hour = 12;
        theday.tm_min = 0;
        theday.tm_sec = 0;
        time_t this_time = mktime(&theday);
        if (this_time != -1){
            char date_str[256];
            char format_str[] = "The day is %A, %d %B, %Y.";
            strftime(date_str, 256, format_str, &theday);
            cout << date_str << endl;
        }else {
            cout << "Sorry. Invalid date." << endl;
        }

        cout << "I'm an excellent driver... ";
        cout << "Do again? (Enter Y or N.)";
        cin >> input_str; 

        if(input_str[0] != 'Y' && input_str[0] != 'y'){
            break;
        }
    }while(true);
    return 0;
}

int get_month_num(string s) {
     if (s == "January")
          return 1;
     if (s == "Feburary")
          return 2;
     if (s == "March")
          return 3;
     if (s == "April")
          return 4;
     if (s == "May")
          return 5;
     if (s == "June")
          return 6;
     if (s == "July")
          return 7;
     if (s == "August")
          return 8;
     if (s == "September")
          return 9;
     if (s == "October")
          return 10;
     if (s == "November")
          return 11;
     if (s == "December")
          return 12;
     
     return 0; // Default to out of range value.
               // (Will be converted to -1.)
}