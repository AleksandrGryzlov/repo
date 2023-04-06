// Lab 9.cpp
//Aleksandr Gryzlov
//04.15.2022

#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

stack<char> characterStack;
void loadFirstFile(string filename);
void saveSecondFile(string filename);

int main() {
	string firstFile = "";
	string secondFile = "";
	cout << "First file: ";
	cin >> firstFile;
	cout << "Second file: ";
	cin >> secondFile;
	loadFirstFile(firstFile);
	saveSecondFile(secondFile);
	return 0;
}

void loadFirstFile(string filename) {
	fstream file1(filename, ios::in);
	char ch;
	file1.get(ch);
	while (!file1.eof()) {
		characterStack.push(ch);
		file1.get(ch);
	}
	file1.close();
}

void saveSecondFile(string filename) {
	fstream file2(filename, ios::out);
	while (!characterStack.empty()) {
		file2.put(characterStack.top());
		characterStack.pop();
	}
	file2.close();
}