#include <iostream>
using std::cout;
using std::endl;

template<typename T1, typename T2>
void pr_items(const char *s1, const T1 &item1,
const char *s2, const T2 &item2){
    cout << s1 << " is: " << item1 << endl;
    cout << s2 << " is: " << item2 << endl;
}

int main(){
    // cout << __DATE__ << endl;
    // cout << __FILE__ << endl;
    // cout << __LINE__ << endl;
    // cout << __STDC__ << endl;
    // cout << __TIME__ << endl;
    // cout << __cplusplus << endl;
    int a = 1, b = 100;
    double x = 0.0, pi = 3.14159;
    pr_items("a", a, "b", b);
    pr_items("x", x, "pi", pi);
}