#include <iostream>
#include <fstream>
using namespace std;

void Choice(string&);
void Close();
void Count(int, double&, string);
void Sum(int, double&, double&, string);
void Average(int, double&, double&, double&, string);
void Min(int, double&, double&, string);
void Max(int, double&, double&, string);

ifstream inFile;

int main()
{
	int count = 0;
	double sum = 0, average = 0, number = 0, max = 0, min = 1;
	string name;
	Choice(name);
	Count(count, number, name);
	Close();
	Sum(count, number, sum, name);
	Close();
	Average(count, number, sum, average, name);
	Close();
	Min(count, number, min, name);
	Close();
	Max(count, number, max, name);
	Close();
	return 0;
}

void Choice(string& name)
{
	cout << "Please enter name of the file below (Ex. Numbers.txt)" << endl;
	cin >> name;
	name = name + ".txt";
}

void Close()
{
	inFile.close();
}

void Count(int count, double& number, string name)
{
	inFile.open(name);
	if (inFile)
		inFile >> number;
	while (inFile) {
		count++;
		inFile >> number;	
	}
	cout << "Amount of numbers in file is: " << count << endl;
}

void Sum(int count, double& number, double& sum, string name)
{
	inFile.open(name);
	while (inFile && count < 15) {
		sum = sum + number;
		count++;
		inFile >> number;
	}
	cout << "Sum of first 15 numbers in file is: " << sum << endl;
}

void Average(int count, double& number, double& sum, double& average, string name)
{
	inFile.open(name);
	while (inFile && count < 22) {
		sum = sum + number;
		count++;
		inFile >> number;

	}
	average = sum / 22;
	cout << "Average of first 22 numbers in the file is: " << average << endl;
}

void Min(int count, double& number, double& min, string name)
{
	inFile.open(name);
	while (inFile)
	{
		count++;
		inFile >> number;
		if (count == 1)
			min = number;
		else if (min > number)
			min = number;
		else{}
	}
	cout << "Min number in file is: " << min << endl;
}

void Max(int count, double& number, double& max, string name)
{
	inFile.open(name);
	while (inFile)
	{
		count++;
		inFile >> number;
		if (max < number)
			max = number;
		else{}
	}
	cout << "Max number in file is: " << max << endl;
}