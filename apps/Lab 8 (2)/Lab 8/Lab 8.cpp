// Lab 8.cpp 
//Aleksandr Gryzlov
#include <iostream>
#include <fstream>
#include <list>
using namespace std;

struct Employee {
    int empId;
    int hours;
    int rate;
    int pay;
};

list<Employee*> employeeList;
void getEmployee(Employee*);
void displayAndDump();

int main() {
    int numEmps = 0;
    Employee* empPtr = nullptr;
    cout << "How many employees? ";
    cin >> numEmps;
    for (int count = 0; count < numEmps; ++count) {
        empPtr = new Employee();
        getEmployee(empPtr);
        employeeList.push_back(empPtr);
    }
    displayAndDump();
    return 0;
}

void getEmployee(Employee* emp) {
    cout << "Enter employee number: ";
    cin >> emp->empId;
    cout << "How many hours did they work? ";
    cin >> emp->hours;
    cout << "What is their hourly rate? ";
    cin >> emp->rate;
    emp->pay = emp->hours * emp->rate;
}

void displayAndDump() {
    fstream dStream("empdata.csv", ios::out);
    if (dStream.is_open()) {
        for (auto empPtr : employeeList) {
            dStream << empPtr->empId << ",";
            dStream << empPtr->hours << ",";
            dStream << empPtr->rate << ",";
            dStream << empPtr->pay << endl;
            cout << empPtr->empId << ",";
            cout << empPtr->hours << ",";
            cout << empPtr->rate << ",";
            cout << empPtr->pay << endl;
        }
        dStream.close();
    }
}