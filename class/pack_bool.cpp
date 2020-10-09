#include <iostream>
using std::cout;
using std::cin;
using std::endl;
class Pack_bool;

class Pack_bool{
    private:
        int max_n;
        int nbytes;
        unsigned char *ptr;
    public:
        Pack_bool(int max);
        void set_bit(int n);
        void clear_bit(int n);
        bool get_bit(int n);
        void set_all_true(){
            for (int i = 0; i < nbytes; ++i)
            {
                ptr[i] = 0xFF;
            }
        };
        void set_all_false(){
            for (int i = 0; i < nbytes; ++i)
            {
                ptr[i] = 0x00;
            }
        };
};

Pack_bool::Pack_bool(int max){
    max_n = max;
    nbytes = (max_n + 7) / 8;
    ptr = new unsigned char[nbytes];
}

void Pack_bool::set_bit(int n){
    int i = n / 8;
    int j = n % 8;
    ptr[i] = ptr[i] | (0x01 << j);
}

void Pack_bool::clear_bit(int n){
    int i = n / 8;
    int j = n % 8;
    ptr[i] = ptr[i] & ~(0x01 << j);
}

bool Pack_bool::get_bit(int n){
    int i = n / 8;
    int j = n % 8;
    return (ptr[i] & (0x01 << j)) != 0;
}

int main(){
    Pack_bool pb(64);
    pb.set_all_false();
    for (int i = 1; i < 64; i += 2)
    {
        pb.set_bit(i);
    }
    for (int i = 1; i < 64; i += 2)
    {
        cout << pb.get_bit(i) << "\t";
    }
    cout << endl;
    cin.ignore();
    return 0;
}
