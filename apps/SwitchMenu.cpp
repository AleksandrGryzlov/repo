/*
Assignment 3.1
Aleksandr Gryzlov
6/13/2022 
*/

#include <iostream>
#include <fstream>
#include <string>
#include "text.txt"
#include "Array.h"
#include "vector.h"
using namespace std;

int main()
{
	ifstream inFile;
	ofstream ofFile;
	inFile.open("Text.txt");
	ofFile.open("text.txt");
	File.close();

	int choice = 0, count = 0, inNum1 = 0, inNum2 = 0; //declaire variable to use in switch later
	string task, tasklist;
	vector<string>tasks;
	list<string>tasklist;

	while (choice != -99) //while loop to keep thing running until you don't need it
	{
		while (getline(&_str:inFile, &_str : task)) {
			count++;
			task.push_back();
		}
		while (getline(&_str:inFile, &_str : tasklist)) {
			count++;
			tasklist.push_back();
		}
		cout << "1.Display all items\n 2.Display selected items\n 3.Mark Task as done\n 4.Exit\n"
		cin >> choice;
		switch (choice) {
		case 1:
			if (inFile.is_open())
			{
				task.traverse();
				cout << "\n";
			}
			else {
				cout << "File is empty\n";
			}
			break;
		case 2:
			cin >> inNum1;
			cout << task[inNum1];
			break;
		case 3:
			cin >> inNum2;
			cout << task[inNum2];
			break;
		case 4:
			vector<string>finished(tasklist.begin(), tasklist.end());
			while (ofFile)
			{
				ofFile >> finished.traverse;

			}
			exit;
			break;
		default:
			cout << "Wrong option! Try again!\n";
			break;
		}
	}
	inFile.close("text.txt");
	ofFile.close("text.txt");
	return 0;
}