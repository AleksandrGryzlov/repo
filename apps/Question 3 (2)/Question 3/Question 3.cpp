//Aleksandr Gryzlov
//03.09.2022
//Question 3

#include <iostream>
#include <string>
using namespace std;

class Work {
private:
	string lastName;
	string firstName;
	int id;
	string department;
	string position;
	int salary;
public:
	Work() {
		lastName = " ";
		firstName = " ";
		id = 0;
		department = " ";
		position = " ";
		salary = 0;
	}
	Work(string last, string first, int number, string place, string pos, int money) {
		lastName = last;
		firstName = first;
		id = number;
		department = place;
		position = pos;
		salary = money;
	}
	string getLast() {
		return lastName;
	}
	string getFirst() {
		return firstName;
	}
	int getID() {
		return id;
	}
	string getDep() {
		return department;
	}
	string getPosition() {
		return position;
	}
	int getSalary() {
		return salary;
	}
};
int main()
{
	Work print1("Susan", "Meyers", 478999, "Accounting", "Vice President", 100250);
	Work print2("Norman", "Bates", 39119, "IT", "Programmer", 80000);
	Work print3("Millard", "Fillmore", 00013, "C - Suite", "President", 999999);
	cout << print1.getLast() << " " << print1.getFirst() << ", " << print1.getID() << ", " << print1.getDep() << ", " << print1.getPosition() << ", " << print1.getSalary() << endl;
	cout << print2.getLast() << " " << print2.getFirst() << ", " << print2.getID() << ", " << print2.getDep() << ", " << print2.getPosition() << ", " << print2.getSalary() << endl;
	cout << print3.getLast() << " " << print3.getFirst() << ", " << print3.getID() << ", " << print3.getDep() << ", " << print3.getPosition() << ", " << print3.getSalary() << endl;
	return 0;
}