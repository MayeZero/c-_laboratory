#include <cstdio>
#include <iostream>
#include <stdio.h>

#define STR_MAX 255
using std::cin;
using std::cout;
using std::endl;

int main(){
    char my_str[STR_MAX + 1];
    int n = 5;
    double x = 3.141592;
    cout << x << endl;
    sprintf(my_str, "This string contains %d and %.3f.", n, x);
    printf("%s\n", my_str);
    puts(my_str);
    cout << my_str << endl;

    // char my_str2[STR_MAX + 1];
    // sscanf(my_str2, "This string contains %d and %.3f.", n, x);
    // printf("%s\n", my_str);
    // puts(my_str);
    // cout << my_str << endl;

    FILE *fp;
    fp = fopen("test.txt", "r");
    if(!fp){
        cout << "failed open file" << endl;
        return -1;
    }
    // char c = fgetc(fp);
    // while(c != '\n'){
    //     cout << c;
    //     c = fgetc(fp);
    // }
    // fputs("Here i am.", fp);

    int a = 0;
    char *q = reinterpret_cast<char*>(&a);
    int bytes_read = fread(q, sizeof(int), 1, fp);
    cout << bytes_read << endl;
    if(bytes_read != sizeof(int)){
        puts("Read error.");
        return -1;
    }
    short b = 127;
    char *p = reinterpret_cast<char*>(&b);
    int bytes_write = fwrite(p, sizeof(short), 1, fp);
    fclose(fp);
}
