#include <set>
#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>

using std::set;
using std::string;
using std::ifstream;
using std::cout;
using std::cin;
using std::endl;
using std::uppercase;
using std::vector;

set<string> word_set;
vector<string> word_vec;

string select_nth_word(int n);
void purge_word(string &s);
void play_the_game(const string &target);
int comp_str(string s1, string s2);

int main(){
    string fname;
    string a_word;
    cout << "Input name of a file to pick a word from: ";
    getline(cin, fname);
    ifstream file_in(fname);
    if(!file_in){
        cout << "Could not open file." << endl;
        system("PAUSE");
        return 1;
    }
        
    while(file_in >> a_word){
        word_set.insert(a_word);
    }

    word_vec.assign(word_set.begin(),word_set.end());

    while(true){
        srand(static_cast<unsigned>(time(NULL)));
        int n = rand() % word_set.size();
        a_word = word_vec[n];
        // a_word = select_nth_word(n);
        purge_word(a_word);
        play_the_game(a_word);

        string input;
        cout << "Play the game again? (y/n): ";
        getline(cin,input);
        if(input != "y" && input != "Y"){
            break;
        }
    }
    cout << endl;
    cin.ignore();
    return 0;
}

string select_nth_word(int n){
    set<string>::iterator it;
    it = word_set.begin();
    while(n-- > 0){
        ++it;
    }
    return *it;
}

void purge_word(string &s){
    for(unsigned i = 0; i < s.size(); ++i){
        if(!isalpha(s[i])){
            s.erase(i);
        }
        if(s.size() == 0){
            s = "unknown";
        }
    }
}

void play_the_game(const string &target){
    string my_guess;
    while(true){
        cout << "Enter your guess or press ENTER to exit: ";
        getline(cin, my_guess);
        if(my_guess.size() == 0){
            cout << "the answer is: " << target << endl;
            return;
        }
        int n = comp_str(my_guess,target);

        if(n < 0){
            cout << "Secret word is later in alpha order.";
        }else if(n > 0){
            cout << "Secret word is earlier in alpha order.";
        }else{
            cout << "That's exactly! YOU WIN!" << endl;
            return;
        }
        cout << "Guess again. " << endl;
    }
}

int comp_str(string s1, string s2) {
     string temp1;
     string temp2;
     for (int i = 0; i < s1.size(); ++i) {
          temp1 += toupper(s1[i]);
     }
     for (int i = 0; i < s2.size(); ++i) {
          temp2 += toupper(s2[i]);
     }
     if (temp1 < temp2) return -1;
     if (temp1 > temp2) return 1;
     return 0;
}
