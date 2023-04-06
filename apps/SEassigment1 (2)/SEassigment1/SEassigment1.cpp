//Aleksandr Gryzlov
//08.22.2022
//Asigment 1

#include <iostream>
#include <fstream>

typedef int AllNumbers[100];

float Average(const AllNumbers, int);

using namespace std;

int main()
{
    int count = 0;
    float average;
    string name;
    cout << "Please enter the file name you want to open: ";
    cin >> name;
    name = name + ".txt";
    ifstream InFile;
    AllNumbers list;
    InFile.open(name);
    while (InFile)
    {
        InFile >> list[count];
        count++;
    }
    average = Average(list, count);
    cout << "Average of all numbers is " << average << endl;
    InFile.close();
    return 0;
}

float Average(const AllNumbers array, int size)
{
    float sum = 0, average;
    int pos = 0;
    while (pos < size - 1)
    {
        sum = sum + array[pos];
        pos++;
    }
    average = sum / pos;
    return(average);
}