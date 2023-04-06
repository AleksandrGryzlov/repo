//Aleksandr Gryzlov
//03.09.2022
//Question 2

#include <iostream>
#include <vector>
#include <ostream>
using namespace std;

struct BigArray {
	int MyArray;
};
vector<BigArray> Array;

void resize();

int main()
{
	BigArray Fill;
	for (int i = 0; i < 25; i++) {
		Fill.MyArray = i;
		Array.push_back(Fill);
	}
	resize();
	return 0;
}

void resize() {
	BigArray Fill;
	int* pointer = NULL;
	int n = 50;
	pointer = new int[n];

	for (int i = 0; i < 25; i++) {
		pointer[i] = Array[i].MyArray;
	}

	for (int i = 0; i < n; i++) {
		Fill.MyArray = pointer[i];
		Array.push_back(Fill);
	}

	for (int i = 0; i < n; i++) {
		cout << Array[i].MyArray << endl;
	}
}