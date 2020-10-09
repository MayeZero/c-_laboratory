// 调用库
#include <iostream>
#include <math.h>
#include <string>
#include <cmath>
// 引用命名空间下的函数
using std::cout;
using std::endl;
using std::string;

// 类声明 函数声明
class Point;
class Map;
class Car;
class Mammal;
class Dog;
class Cat;
void print_point(Point p);
Point create_point();
// 类
class Point{
    // 修饰符 成员变量
    private:
    double x,y;
    // 修饰符 成员函数
    public:
    double err_num = -1;
    double arr[100];
    const int year;

    void set_x(double x){
        this->x = x;
    };
    void set_y(double y){
        this->y = y;
    };
    double get_x(){
        return x;
    };
    double get_y(){
        return y;
    };

    //构造函数 重载 初始化列表
    Point() : year(2020) {};
    Point(double newx) : x(newx), y(0), year(2020){};
    Point(double newx,double newy) : x(newx), y(newy), year(2020) {};
    // 复制构造函数
    Point(const Point &p) : year(2020) {
        x = p.x + 1;
        y = p.y + 1;
    }

    // 运算符函数作为成员
    Point operator - (){
        Point new_point;
        new_point.x = -x;
        new_point.y = -y;
        return new_point;
    }

    Point operator + (const Point &rp){
        Point new_point;
        new_point.x = x + rp.x;
        new_point.y = y + rp.y;
        return new_point;
    }
    // 友元
    // friend Point operator + (const Point &left, const Point &right);

    // 函数调用运算符
    bool operator() () {
        return x == y;
    }

    // 赋值运算法
    Point& operator = (const Point &cp){
        x = cp.x + 10;
        y = cp.y + 10;
        return *this;
    }

    double& operator[] (const int i){
        if ( i < 0 || i > 99){
            return err_num;
        }else {
            return arr[i];
        }
    }
    // 前缀
    Point& operator++ (){
        ++x, ++y;
        return *this;
    }
    // 后缀
    Point operator++ (int){
        Point temp_pt = *this;
        ++x, ++y;
        return temp_pt;
    }
    // 转出函数
    operator double(){
        return sqrt(x * x + y * y);
    }

    // 析构函数
    ~Point(){
        // cout << "Point out " << endl;
    }
}my_array;

// Point operator + (const Point &left, const Point &right){
//     Point new_point;
//     new_point.x = (left.x + right.x);
//     new_point.y = (left.y + right.y);
//     return new_point;
// }

class Map{
    public:
    Point p;  
};

class Car{
    public:
        string name;
        class Brand{
            public:
            string name;
            string description;
        };
};

class Mammal{
    public:
        virtual void sound();
};

class Dog : public Mammal{
    public:
        void sound();
};

class Cat : public Mammal{
    public:
        void sound();
};

void Mammal::sound(){

}

void Dog::sound(){
    cout << "Ruff! " << endl;
}

void Cat::sound(){
    cout << "Meow... " << endl;
}

enum card_suit {clubs, diamonds, hearts, spades };

class CardClass{
    public:
        card_suit suit : 2;
        unsigned rank : 4;
        unsigned marked : 1;
        unsigned copied : 6;
} a_card;

union Var_data{
    int n;
    double x;
    char *name[20];
};

int main(){
    // 类中类
    Map m;
    m.p.set_x(6.0);
    // set get
    Point pt1,pt2;
    pt1.set_x(3.0);
    pt1.set_y(4.0);
    pt2.set_x(12.0);
    pt2.set_y(5.0);
    cout << m.p.get_x() << endl;
    // 对象作为函数参数被调用
    print_point(pt1);
    Point pt3 = create_point();
    print_point(pt3);
    // 运算符函数
    Point pt4(-pt1);
    print_point(pt4);
    Point pt5(pt1+pt2);
    print_point(pt5);
    Point pt6(pt1+pt2);
    print_point(pt6);
    Point pt7;
    pt7.set_x(3.0);
    pt7.set_y(3.0);
    cout << pt7() << endl;
    Point pt8 = pt7;
    pt7 = pt8;
    print_point(pt7);
    Point pt9(pt1++);
    print_point(pt9);
    Point pt10(++pt1);
    print_point(pt10);
    print_point(pt1);
    // 转入转出函数
    Point pt11,pt12;
    pt11 = 7.5; // 隐式
    pt12 = Point(100.0); // 显式
    double x = pt11;
    cout << 1.5 + pt12 << endl; // 隐式
    cout << double(pt11) << endl; // 显式
    my_array[-1] = 3;
    // 继承 多态
    Mammal *ptr_to_mammal;
    Mammal m_obj;
    Dog d_obj;
    Cat c_obj;
    ptr_to_mammal = &d_obj;
    ptr_to_mammal->sound();
    ptr_to_mammal = &c_obj;
    ptr_to_mammal->sound();
    // 位字段
    a_card.suit = hearts;
    a_card.rank = 10;
    a_card.marked = false;
    a_card.copied = 1;
    // 联合类
    Var_data v1;
    v1.n = 5;
    cout << v1.n << endl;
    v1.x = 3.141592;
    cout << v1.x << endl;
    // 内部类
    Car my_car;
    Car::Brand ae86;
    my_car.name = "ear_worm";
    ae86.name = "AE86";
    ae86.description = "A japan automobile";
    cout << my_car.name << endl;
    cout << ae86.name + ": " + ae86.description << endl;
}


// 类的对象作为参数调用时 拷贝构造函数
void print_point(Point p){
    cout << "x: " ;
    cout << p.get_x() << " ";
    cout << "y: ";
    cout << p.get_y() << " ";
    cout << "year: ";
    cout << p.year << endl;
}

// 不同的编译器 函数返回值为对象时不一定调用 拷贝构造函数 例如此处
Point create_point(){
    Point p(7,8);
    return p;
}
