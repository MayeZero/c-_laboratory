#include <string>
#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;

#define VERT_LINES 25

bool ask_more();

int main(){
    string fname;
    string input_str;
    int n = 0;
    ifstream file_in;
    while(true){
        cout << "Enter file name: ";
        getline(cin, fname);
        if(fname.length() == 0){
            break;
        }
        file_in.open(fname);
        if(!file_in){
            cout << "Could not open file." << endl;
        }else{
            while(!file_in.eof()){
                getline(file_in, input_str);
                for (int i = 0;i < input_str.length(); i++){
                    input_str[i] = toupper(input_str[i]);
                }
                cout << input_str << endl;
                ++n;
                if(n % (VERT_LINES - 2) == 0){
                    if(!ask_more()){
                        break;
                    }
                }
            }
        }
    }

    cout << "Press ENTER to quit program.";
    cin.ignore();
    return 0;
}

bool ask_more(){
    string input_str;
    cout << endl << "[PRESS ENTER for more, Q to quit]: ";
    getline(cin, input_str);
    if(input_str.size() > 0){
        char c = input_str[0];
        if (c == 'Q' || c == 'q'){
            return false;
        }
    }
    return true;
}