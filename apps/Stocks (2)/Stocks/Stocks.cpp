#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inFile;
    ofstream outFile;
    double number=0;
    string bar="*", fullBar="";
    int barNumber = 0, count;
    inFile.open("StockMarket.txt");
    outFile.open("StockResult.txt");
    outFile << "Average Closing Price of the stock market" << endl << endl;
    if (inFile)
        inFile >> number;
    for (int year = 2015; year < 2022; year++)
    {
        barNumber = number / 3000;
        count = 0;
        while (count < barNumber) {
            count++;
            fullBar = fullBar + bar;
        }
        outFile << "Year " << year << ": " << fullBar << endl;
        inFile >> number;
        fullBar = "";
    }
    inFile.close();
    outFile.close();
    return 0;
}