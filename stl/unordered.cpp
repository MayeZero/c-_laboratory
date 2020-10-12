#include <string>
#include <iostream>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
using std::hash;

class BookID{
    public:
        string author, title;
        BookID(string _author, string _title) : author(_author), title(_title){}
};

class BookHashf{
    public:
        size_t operator () (const BookID& arg){
            return hash<string>() (arg.author) + hash<string>() (arg.title);
        }
};

class BookEqf{
    public:
        bool operator() (const BookID& lhs, const BookID& rhs){
            return lhs.author == rhs.author && lhs.title == rhs.title;
        }
};

int main(){
    unordered_map<BookID, int, BookHashf, BookEqf> books;
    books[BookID("Homer", "Odyssey")] = 180;
    books[BookID("Homer", "Iliad")] = 185;
    books[BookID("Tolkien", "The Hobbit")] = 300;
    books[BookID("Tolkien", "LOTR")] = 1500;
    books[BookID("Austen", "Emma")] = 240;
    books[BookID("Austen", "Pride and Prejudice")] = 250;

    for(auto x: books){
        cout << x.first.author << "\t";
        cout << x.first.title << "\t";
        cout << x.second << endl;
    }
}