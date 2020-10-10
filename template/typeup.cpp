#include <iostream>
#include <string>
#include <tuple>
using std::cout;
using std::cin;
using std::endl;
using std::get;
using std::string;
using std::tuple;
using std::tuple_size;

template<typename T1, typename T2>
string return_type(T1 a, T2 b){
    if(typeid(a + b) == typeid(int))
        return "int";
    if(typeid(a + b) == typeid(unsigned))
        return "unsigned";
    if(typeid(a + b) == typeid(float))
        return "float";
    if(typeid(a + b) == typeid(double))
        return "double";
    if(typeid(a + b) == typeid(char))
        return "char";
    return "other";
}

int main(){
    // tuple元组
    tuple<int, string, double> my_tup(1, "hello", 3.14);
    auto my_tup2 = make_tuple(2, string("goodbye"), 2.5);
    cout << "Here is 4th tuple element: ";
    cout << get<2>(my_tup) << endl;
    cout << "Num. of elements of my_tup2 is: ";
    cout << tuple_size<decltype(my_tup2)>::value << endl;

    // 类型提升
    char ch = 'a';
    int si = 0;
    unsigned ui = 0;
    double x = 0.0;
    float flt = 0.0F;
    cout << "ch + si => " << return_type(ch, si) << endl;
    cout << "si + si => " << return_type(si, si) << endl;
    cout << "si + ui => " << return_type(si, ui) << endl;
    cout << "si + x => " << return_type(si, x) << endl;
    cout << "x + flt => " << return_type(x, flt) << endl;
}