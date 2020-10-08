#include <iostream>
#include <math.h>
using std::cout;
using std::endl;

class point{
    private:
    double x,y;

    public:
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

    point(){};
    point(double x){
        this->x = x;
    };
    point(double x,double y){
        this->x = x;
        this->y = y;
    };
};

int main(){
    point pt1,pt2;
    pt1.set_x(3.0);
    pt1.set_y(4.0);
    pt2.set_x(12.0);
    pt2.set_y(5.0);
}