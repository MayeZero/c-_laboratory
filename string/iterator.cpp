#include <string>
#include <iostream>
#include <cctype>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(){
    string a_msg = "I'm trying to use the phone!";
    string::iterator it;
    for(it = a_msg.begin(); it != a_msg.end(); ++it){
        cout << static_cast<char>(toupper(*it));
    }

    cout << endl;

    string s = "god live no tips";
    string::reverse_iterator rv_it;
    for (rv_it = s.rbegin(); rv_it != s.rend(); ++rv_it){
        cout << *rv_it;
    }
}