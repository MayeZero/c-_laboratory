#include <iostream>
#include <string>
#include <math.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main(){
    string input_str;
    cin >> input_str;
    int num = 0;
    int multiple = 0;
    for ( int i = input_str.length()-1; i >= 0; i--){
        if(input_str[i] == '1'){
            num +=  pow(2,multiple);
        }
        multiple++;
    }
    cout << num;
    return 0;
}