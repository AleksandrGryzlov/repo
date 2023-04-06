#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	const int MAXSIZE = 1000;
	int sensorNumber[MAXSIZE];
	string timestamp[MAXSIZE];
	int sensorReadings[MAXSIZE];
	int sum = 0, found = 0;
	int average, choice;
	string name;
	int count = 0;
	fstream inFile;
	cout << "Enter file name to read: ";
	cin >> name;
	name = name + ".txt";
	inFile.open(name);
	if (inFile)
	{
		while (inFile)
		{
			inFile >> sensorNumber[count];
			inFile >> timestamp[count];
			inFile >> sensorReadings[count];
			count++;
		}
	}
	else { cout << "No File to read!!!\n"; return 1; }
	for (int i = 0; i < count-1; i++)
	{
		sum = sum + sensorReadings[i];
	}
	average = sum / (count - 1);
	cout << "Overall average temperature is " << average << endl;
	cout << "Please choose which sensor reading to display: ";
	cin >> choice;
	for (int i = 0; i < count - 1; i++)
	{
		if (choice == sensorNumber[i])
		{
			cout << sensorNumber[i] << " " << timestamp[i] << " " << sensorReadings[i] << endl;
			found = 1;
		}
	}
	if (found == 0)
		cout << "Sensor with this number not found!";
	return 0;
}