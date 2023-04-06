// Aleksandr Gryzlov

#include <iostream>
#include <fstream>

typedef int AllNumbers[100];

float Highest(const AllNumbers, int);
float Lowest(const AllNumbers, int);
float Total(const AllNumbers, int);
float Average(const AllNumbers, int);

using namespace std;

int main()
{
    int count = 0;
    float low, high, sum, average;
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
    sum = Total(list, count);
    high = Highest(list, count);
    low = Lowest(list, count);
    average = Average(list, count);
    cout << "Highest numbers is " << high << endl;
    cout << "Lowest number is " << low << endl;
    cout << "Sum of all numbers is " << sum << endl;
    cout << "Average of all numbers is " << average << endl;
    InFile.close();
    return 0;
}

float Highest(const AllNumbers array, int size)
{
    float high;
    int pos = 0;
    high = array[pos];
    pos++;
    while (pos < size-1)
    {
        if (high < array[pos])
        {
            high = array[pos];
        }
        pos++;
    }
    return (high);
}

float Lowest(const AllNumbers array, int size)
{
    float low;
    int pos = 0;
    low = array[pos];
    pos++;
    while (pos < size-1)
    {
        if (low > array[pos])
        {
            low = array[pos];
        }
        pos++;
    }
    return (low);
}

float Total(const AllNumbers array, int size)
{
    float sum = 0;
    int pos = 0;
    while (pos < size-1)
    {
        sum = sum + array[pos];
        pos++;
    }
    return (sum);
}

float Average(const AllNumbers array, int size)
{
    float sum = 0, average;
    int pos = 0;
    while (pos < size-1)
    {
        sum = sum + array[pos];
        pos++;
    }
    average = sum / pos;
    return(average);
}