#include <iostream>
using std::cout;
using std::cin;
using std::endl;
class Pack_bool;
void process_prime(Pack_bool &p, int max_n, int n);

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
        void resize(int n);
        ~Pack_bool(){
            delete[] ptr;
        }
};

Pack_bool::Pack_bool(int max){
    max_n = max;
    nbytes = (max_n + 7) / 8;
    ptr = new unsigned char[nbytes];
}

void Pack_bool::set_bit(int n){
    int i = n / 8;
    int j = n % 8;
    ptr[i] |= (0x01 << j);
}

void Pack_bool::clear_bit(int n){
    int i = n / 8;
    int j = n % 8;
    ptr[i] &= ~(0x01 << j);
}

bool Pack_bool::get_bit(int n){
    int i = n / 8;
    int j = n % 8;
    return (ptr[i] & (0x01 << j)) != 0;
}

void Pack_bool::resize(int n){
    if(n < max_n){
        max_n = n;
    }else{
        int pre_nbytes = nbytes;
        max_n = n;
        nbytes = (max_n + 7)/8;

        unsigned char *temp = new unsigned char[nbytes];
        for(int i = 0; i < pre_nbytes; ++i){
            temp[i] = ptr[i];
        }
        delete [] ptr;
        ptr = temp;
    }
}

void process_prime(Pack_bool &p, int max_n, int n){
    cout << n << "\t";
    for(int i = n + n; i <= max_n; i += n){
        p.clear_bit(i);
    }
}

int main(){
    cout << "Enter the max number: ";
    int max;
    cin >> max;
    Pack_bool pb(max);
    pb.set_all_true();
    for (int i = 2; i <= max; ++i)
    {
        if(pb.get_bit(i)){
            process_prime(pb, max, i);
        }
    }
    cout << endl;
    cin.ignore();
    cin.ignore();
    return 0;
}
