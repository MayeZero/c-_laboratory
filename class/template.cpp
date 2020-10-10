#include <iostream>
using std::endl;
using std::cout;
using std::cin;

// 模板类 内联函数 外定义
template<typename T>
class Vec2D{
    private: 
        T x, y;
    public:
        Vec2D();
        Vec2D(T newx, T newy) : x(newx),y(newy){}
        void set(T newx, T newy){
            x = newx;
            y = newy;
        }
        T get_x(){
            return x;
        }
        T get_y();
};

template<typename T>
Vec2D<T>::Vec2D(){

}

template<typename T>
T Vec2D<T>::get_y(){
    return y;
}

// 模板函数
template<typename T>
T t_min(T a,T b){
    cout << "Using generic version: ";
    if(a < b)
        return a;
    return b;
}
// 模板专门化
template<>
bool t_min(bool a, bool b){
    cout << "Using specialized version: ";
    return a && b;
}

// 终端版本: 当有一个参数时调用
template<typename T>
void printv(T val){
    cout << val << endl;
}
// 可变参数版本： 当有多个参数时调用
template<typename T,typename... TArgs>
void printv(T val, TArgs... args){
    cout << val << endl;
    printv(args...);
}

void printvf(const char* s){
    cout << s;
}

template<typename T, typename... TArgs>
void printvf(const char* s, T val, TArgs... argList){
    while(*s){
        if(*s == '%' && *(++s) != '%'){
            cout << val;
            printvf(s, argList...);
            return;
        }
        cout << *s++;
    }
}

int main(){
    cout << "t_min(10, 15) = " << t_min(10, 15) << endl;
    cout << "t_min(true, true) = " << t_min(true, true) << endl;
    int i = 2;
    double p = 3.3;
    printv(i);
    printv(i, p);
    int x = 100;
    int y = 200;
    printvf("x = %, y = %.", x, y);
    cin.ignore();
    return 0;

}