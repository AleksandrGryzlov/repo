//Aleksandr Gryzlov
//Lab 2
//01.28.2022

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;
const string DATAFILE = "datafile.txt";
const int MAXSAMPLE = 100;
struct ReadingRow {
    int sensorNumber;
    string timestamp;
    int sensorReadings;
};
ReadingRow sensorReadings[MAXSAMPLE];

int numReadings = 0;
int average = 0;

void readData();
void Total();
int displayMenu();
void displayDataForSensor(unsigned int); 

int main()
{
	bool keepGoing = true;
    unsigned int choice = 0;
    readData();
    Total();
    do {
        choice = displayMenu();
        if (choice==0)
        {
            keepGoing = false;
        }
        else
        {
            displayDataForSensor(choice);
        }
    } while (keepGoing);
	return 0;
}

void readData() {
    ifstream dfile;
    string currentTS = "";
    int sNumber = 0;
    int sReading = 0;
    int readingCount = 0;
    int sumOfTemps = 0;
    dfile.open(DATAFILE);
    if (dfile.is_open())
    {
        dfile >> sNumber >> currentTS >> sReading;
        while (!dfile.eof())
        {
            readingCount++;
            sensorReadings[readingCount].sensorNumber = sNumber;
            sensorReadings[readingCount].timestamp = currentTS;
            sensorReadings[readingCount].sensorReadings = sReading;
            sumOfTemps += sReading;
            dfile >> sNumber >> currentTS >> sReading;

        }
        numReadings = readingCount;
        average = sumOfTemps / numReadings;
        dfile.close();
    }
    else
    {
        cerr << "Error: Unable to open data file" << endl;
        exit(1);
    }
}

void Total() {
    cout << "The average temperature was: " << setw(4) << average;
}

int displayMenu() {
	int choice;
		cout << "Enter a sensor number or 0 to exit program: ";
	cin >> choice;
    while ((choice <= -1) || (choice>numReadings) ) {
        if (choice <= -1) {
            cout << "Number can't be negative, try again!\n";
            cin >> choice;
        }
        else {
            cout << "This sensor doesn't exist\n";
            cin >> choice;
        }
    }
	return choice;
}

void displayDataForSensor(unsigned int sensorID)
{
	cout << "Sensor number: " << sensorReadings[sensorID].sensorNumber << endl;
	cout << "Timestamp : " << sensorReadings[sensorID].timestamp << endl;
	cout << "Temperature : " << sensorReadings[sensorID].sensorReadings << endl;
}