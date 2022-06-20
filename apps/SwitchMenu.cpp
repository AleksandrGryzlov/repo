/*
Assignment 3.1
Aleksandr Gryzlov
6/13/2022 
*/

#include <iostream>
#include <fstream>
#include "Array.h"
#include "vector.h"
#include "Queue.h"
using namespace std;
void AllItems(class,class,class);
void Selected(class);
void Done();

int main()
{
	int choice = 0; //declaire variable to use in switch later
	
	while (choice != -99) //while loop to keep thing running until you don't need it
	{
		cout << "1.Display all items\n 2.Display selected items\n 3.Mark Task as done\n 4.Exit\n"
		cin >> choice;
		switch (choice) {
		case 1:
			//call function to show all items

			break;
		case 2:
			//call function to display selected item

			break;
		case 3:
			//call function to mark task

			break;
		case 4:
			//exit
			exit;
			break;
		default:
			cout << "Wrong option! Try again!\n";
			break;
		}
	}
	return 0;
}

//choice 1 function
void AllItems() {
	fstream File;
	File.open("Text.txt");
	File.close();
}

//choice 2 function
void Selected() {
	fstream File;
	File.open("Text.txt");
	File.close();
}

//choice 3 function
void Done() {

}