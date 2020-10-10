#include <cstring>
#include <string.h>
#include <iostream>
#include <cctype>
#include <ctype.h>

using std::cin;
using std::cout;
using std::endl;

#define MAX_CHARS 10
#define SCREENWIDTH 80
#define SCRN_WIDTH 80

int main(){
    char a_name[MAX_CHARS+1] = "KittyKat";
    char input_line[SCREENWIDTH +1];
    strncat(a_name, "Kar", MAX_CHARS - strlen(a_name));
    cin.getline(input_line, SCREENWIDTH);
    cout << a_name << endl;
    cout << input_line;

    char lic[] = "KAR123";
    char digit_str[] = "0123456789";
    int n = strcspn(lic, digit_str);
    cout << "Position of first digit is: " << n << endl;

    char name[] = "White Rabbit";
    char *substr = strpbrk(name, " ,\t");
    if(substr){
        cout << "Last name is " << substr << endl;
    }
    
    char* token, input_ln[SCRN_WIDTH + 1];
    cout << "Enter line of input: ";
    cin.getline(input_ln, SCRN_WIDTH);
    token = strtok(input_ln, ",");
    while(token){
        cout << token << endl;
        token = strtok(NULL, " ,");
    }
}