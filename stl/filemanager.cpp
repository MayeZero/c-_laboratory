#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;
using std::vector;

vector<string> str_vec;
vector<string>::iterator it;
void insert_string(string s);
int comp_str(string s1, string s2);

int main(){
    string ifname;
    string ofname;
    string input_str;
    cout << "Enter name of input file: ";
    getline(cin,ifname);
    ifstream file_in(ifname);
    if(!file_in){
        cout << "File could not be opened.";
        system("PAUSE");
        return -1;
    }
    cout << "Enter name of output file: ";
    getline(cin, ofname);
    ofstream file_out(ofname);
    if(!file_out){
        cout << "File could not be opened";
        system("PAUSE");
        return -1;
    }
    while(!file_in.eof()){
        getline(file_in, input_str);
        insert_string(input_str);
    }

    for(it = str_vec.begin(); it != str_vec.end(); ++it){
        file_out << *it << endl;
        cout << ">" << *it << endl;
    }

    cout << "Alphabetizing complete." << endl;
    cout << "Press ENTER to exit.";
    cin.ignore();
    return 0;
}

void insert_string(string s){
    it = str_vec.begin();
    while(it != str_vec.end() && comp_str(s,*it) > 0 ){
        ++it;
    }
    str_vec.insert(it, s);
}

int comp_str(string s1, string s2) {
     string temp1, temp2;
     for (int i = 0; i < s1.length(); ++i) {
          temp1 += toupper(s1[i]);
     }
     for (int i = 0; i < s2.length(); ++i) {
          temp2 += toupper(s2[i]);
     }
     if (temp1 < temp2) return -1;
     else if (temp1 == temp2) return 0;
     else return 1;
}