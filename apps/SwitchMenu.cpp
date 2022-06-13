/*
Assignment 3.1
Aleksandr Gryzlov
6/13/2022 
*/

#include <iostream>
#include "Array.h"
#include "vector.h"
#include "Queue.h"
using namespace std;

int main()
{
	int choice = 0; //declaire variable to use in switch later

	while (choice != -99) //while loop to keep thing running until you don't need it
	{
		cout << "1.Display all items\n 2.Display selected items\n 3.Mark Task as done\n 4.Exit\n"
		cin >> choice;
		switch (choice) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		default:
			cout << "Wrong option! Try again!\n";
			break;
		}
	}
	return 0;
}