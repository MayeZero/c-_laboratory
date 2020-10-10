#include <cstdlib>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int icomp(const void* p1, const void* p2);

int arr[] = {-5, -1, 10, 35, 78, 79, 82, 99, 101, 103 };
int arr1[] = {99, -107, 103, -5, 10, -1, 35, 78, 366, 82};
int key = 0;
int icomp(const void* p1, const void* p2){
    int i1 = *(reinterpret_cast<const int*>(p1));
    int i2 = *(reinterpret_cast<const int*>(p2));
    if (i1 < i2){
        return -1;
    }else if(i1 == i2){
        return 0;
    }else{
        return 1;
    }
}

void my_exit_function(){
    cout << "Program terminating! Bye!" << endl;
}

int main(){
    cout << "Enter value to search for: ";
    cin >> key;
    void *p;
    p = bsearch(&key, arr, 10, sizeof(int), icomp);
    if(p){
        cout << key << " was found." << endl;
    }else{
        cout << key << " was not found." << endl;
    }
    
    qsort(arr1, 10, sizeof(int), icomp);
    for (int i = 0; i < 10; i++){
        cout << arr1[i] << "    ";
    }
    cout << endl;

    div_t divdata;
    divdata = div(53, 10);
    cout << divdata.quot << endl;
    cout << divdata.rem << endl;

    cout << "PATH = " << getenv("PATH") << endl;

    atexit(my_exit_function);
    exit(0);
}