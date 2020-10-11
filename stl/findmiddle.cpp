#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <vector>

using std::string;
using std::stringstream;
using std::list;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

list<double> numList;
vector<double>::iterator it;

double get_nth_item(int n);
void print_middle(const vector<double> &vec);
void print_avg(vector<double> &vec);
void print_max(vector<double> &vec);
void print_min(vector<double> &vec);

int main(){
    string input_str;
    cout << "Enter a series of numbers: ";
    getline(cin, input_str);
    stringstream ss(input_str);
    double x = 0.0;
    double min_num;
    double max_num;  
    double sum = 0;
    while (ss >> x){
        numList.push_back(x);
        sum += x;
        if(numList.size() == 1){
            min_num = max_num = x;
        }else if(x < min_num){
            min_num = x;
        }else if(x > max_num){
            max_num = x;
        }
    }
    if (numList.empty()) {
        cout << "No numbers were entered. Press ENTER to exit." << endl;
        cin.ignore();
        return -1;
    }
    numList.sort();

    vector<double> numVec(numList.begin(), numList.end());
    print_middle(numVec);
    cout << "Average is: " << sum / numVec.size() << endl;
    cout << "max is: " << max_num << endl;
    cout << "min is: " << min_num << endl;
    // print_avg(numVec);
    // print_max(numVec);
    // print_min(numVec);
    cout << "Press ENTER to exit.";
    cin.ignore();
    return 0;
}

void print_avg(vector<double> &vec){
    double sum = 0;
    int n = 0;
    for(it = vec.begin(); it != vec.end(); ++it){
        sum += *it;
        ++n;
    }
    cout << "Average is: " << sum / n << endl;
}

void print_max(vector<double> &vec){
    int max;
    for(it = vec.begin(), max = *it; it != vec.end(); ++it){
        if(*it > max){
            max = *it;
        }
    }
    cout << "max is: " << max << endl;
}

void print_min(vector<double> &vec){
    int min;
    for(it = vec.begin(); it != vec.end(); ++it){
        if(*it < min){
            min = *it;
        }
    }
    cout << "min is: " << min << endl;
}

void print_middle(const vector<double> &vec){
    int n1 = numList.size() / 2;
    int n2 = (numList.size() - 1) / 2;
    cout << "Median value is: ";
    cout << (vec[n1] + vec[n2]) / 2;
    cout << endl;
}

// double get_nth_item(int n){
//     list<double>::iterator it = numList.begin();
//     while(n-- > 0){
//         ++it;
//     }
//     return *it;
// }