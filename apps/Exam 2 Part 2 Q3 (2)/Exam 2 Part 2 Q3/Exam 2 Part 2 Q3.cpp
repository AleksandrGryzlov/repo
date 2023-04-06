#include <iostream>
#include <string>
#include <list>
using namespace std;

class Employee{
private:
    string name = "";
    int number = 0;
    string hire_date = "";
public:
    Employee();
    string getName();
    int getNumber();
    string getDate();
    void setData(string, int, string);
};

string Employee::getName(){
    return name;
}

int Employee::getNumber(){
    return number;
}

string Employee::getDate(){
    return hire_date;
}

void Employee::setData(string nameIN, int numIN,string dateIN){
    name = nameIN;
    number = numIN;
    hire_date = dateIN;
}

class ProductionWorker : public Employee{
private:
    int shift = 0;
    double pay_rate = 0.0;
public:
    int getShift();
    double getPay_Rate();
    void setDataP(int, double);
};

int ProductionWorker::getShift(){
    return shift;
}

double ProductionWorker::getPay_Rate() {
    return pay_rate;
}

void ProductionWorker::setDataP(int shiftIN, double payIN) {
    shift = shiftIN;
    pay_rate = payIN;
}

class List : public ProductionWorker {
public:
    void createList(int);
};

void List::createList(int n) {
    list<int> shift, pay;
    for (int i = 0; i < n; ++i) {
        shift.push_front(getShift());
        pay.push_back(pay_rate);
    }
}

void showlist(list<int> g)
{
    list<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}

int main() {
    List work;
    int numIN, shiftIN, n, choice = 0;
    double payIN;
    string nameIN, dateIN;
    cout<<"How many emplyees ? "<<endl;
    cin >> n;
    
    cout << "1.Emplyess\n2.Production worker" << endl;
    while (choice != 1 && choice != 2)
        cin >> choice;
    if (choice == 1) {
        cin >> nameIN;
        cin >> numIN;
        cin >> dateIN;
        work.setData(nameIN, numIN, dateIN);
    }
    else {
        cin >> shiftIN;
        cin >> payIN;
        work.setDataP(shiftIN, payIN);
        work.createList(n);
    }   
    return 0;
}