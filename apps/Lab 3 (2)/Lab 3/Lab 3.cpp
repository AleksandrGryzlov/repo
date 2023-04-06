//Aleksandr Gryzlov
//Lab 3
//01.28.2022

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;
const string DATAFILE = "datafile.txt";
struct ReadingRow {
    int sensorNumber;
    string timestamp;
    int sensorReading;
};

vector<ReadingRow> sensorReadings;
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
        if (choice == 0)
        {
            keepGoing = false;
        }
        else
        {
            displayDataForSensor(choice-1);
        }
    } while (keepGoing);
    return 0;
}

void readData() {
    ifstream dfile;
    ReadingRow tempReading;
    int sumOfTemps = 0;
    dfile.open(DATAFILE);
    if (dfile.is_open())
    {
        dfile >> tempReading.sensorNumber
            >> tempReading.timestamp
            >> tempReading.sensorReading;
        while (!dfile.eof())
        {
            sensorReadings.push_back(tempReading);
                dfile >> tempReading.sensorNumber
                >> tempReading.timestamp
                >> tempReading.sensorReading;
        }
        numReadings = sensorReadings.size();
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
    while ((choice <= -1) || (choice > numReadings)) {
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
    cout << "Temperature : " << sensorReadings[sensorID].sensorReading << endl;
}