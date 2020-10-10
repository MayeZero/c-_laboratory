#include <iostream>
#include <cstdlib>
#include <stdlib.h>
using std::cout;
using std::endl;

int main(){
    char str[] = "  3.14159265";
    double pi = atof(str);
    cout << pi << endl;

    char str1[] = " -2001";
    int num = atoi(str1);
    cout << num << endl;

    char str2[] = "25.37    3.141596";
    char *p;
    double x = strtod(str2, &p);
    double y = strtod(p, NULL);
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    char str3[] = "7    -50";
    long i = strtod(str3, &p);
    long j = strtod(p, NULL);
    cout << "i = " << i << endl;
    cout << "j = " << j << endl;
}