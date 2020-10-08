#include <iostream>
#include <string>
#include <math.h>
#include <ctime>
#include <cstdarg>
#include <stdarg.h>
#include <vector>
#include <memory>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::unique_ptr;
using std::shared_ptr;
using std::nothrow;

int main(){
    int max_n = 0;
    int min_n = 0;
    int count = 0;

    cout << "Input a lowest number: ";
    cin >> min_n;
    cout << "Calculate primes up tp what number? ";
    cin >> max_n;

    unique_ptr<int[]> p(new (nothrow) int[max_n + 1]);
    if(!p){
        cout << "Insufficient memory." << endl;
    }

    for(int i = 2; i <= max_n; ++i){
        p[i] = 1;
    }

    for(int i = 2;i <= max_n; ++i){
        if(p[i]){
            for(int j = i + i; j <= max_n; j += i){
                p[j] = 0;
            }
            if(i >= min_n && i <= max_n){
                cout << i << "\t";
                count++;
            }
        }
    }
    cout << endl << "The total number of primes is " << count;
    cin.ignore();
    cin.ignore();
    return 0;
}