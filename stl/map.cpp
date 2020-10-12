#include <map>
#include <string>
#include <iostream>

using std::map;
using std::string;
using std::cout;
using std::cin;
using std::endl;

class empRec{
    public:
        string job;
        int salary_level;
        int year_hired;
        empRec(){}
        empRec(string nJob, int nSal, int nYear):job(nJob), salary_level(nSal), year_hired(nYear){}
};

map<string, empRec> empMap;

bool find_rec(string name, empRec& my_rec){
    map<string, empRec>::iterator it;
    it = empMap.find(name);
    if(it != empMap.end()){
        my_rec = it->second;
        return true;
    }
    return false;
}

int main(){
    string strInput, strTitle;
    empRec my_rec;
    empMap["BillG"] = empRec("CEO", 10, 1979);
    empMap["SteveB"] = empRec("Executive VP", 9, 1980);
    empMap["BrianO"] = empRec("Programmer", 3, 1986);
    empMap["SamIAM"] = empRec("Product Mgr.", 5, 1990);
    empMap["Drone"] = empRec("Director of Bureaucraeic Proliferation", 8, 1999);
    while(true){
        cout << "Enter name (or press ENTER to exit): ";
        getline(cin, strInput);
        if(strInput.size() == 0){
            break;
        }
        if(find_rec(strInput, my_rec)){
            cout << "job: ";
            cout << my_rec.job << endl;
            cout << "year hired: ";
            cout << my_rec.year_hired << endl;
            cout << "salary level: ";
            cout << my_rec.salary_level << endl;
        }else{
            cout << "Employee not found." << endl;
        }
    }
    return 0;
}