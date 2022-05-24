//
// File:   assignment1.cpp
// Author: <Aleksandr Gryzlov>
// Purpose:
// Illustrate some of the bad thins that can happen with
// pointers
//
#include <iostream>
#include <string>
using namespace std;
void NewF1();
void NewF2();
string NewF3();
void NewF4(string);

int main()
{
	NewF1();
	NewF2();
	NewF4(NewF3());
	return 0;
}


void NewF1()
{
	const int SIZE = 99;
	int* Array1 = new int[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		*(Array1 + i) = i;
	}

	int* Array2 = Array1;

	for (int i = 0; i < 10; i++) {
		cout << Array2[i] << endl;
	}
	delete[] Array1;
	Array1 = nullptr;
}

void NewF2()
{
	int* ptr1, * ptr2;
	const int SIZE = 99;
	int* Array = new int[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		*(Array + i) = i;
	}
	ptr1 = Array;
	ptr2 = Array;

	for (int i = 0; i < 10; i++) {
		cout << (ptr2 + i) << endl;
	}
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << *(ptr2 + i) << endl;
	}
	delete ptr1;
	ptr1 = nullptr;
}

string NewF3()
{
	string* word = new string("abcdefghijkl");
	string* ptr = word;
	return*ptr;
}

void NewF4(string word)
{
	cout << word;
}