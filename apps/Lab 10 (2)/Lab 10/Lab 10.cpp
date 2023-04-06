// Lab 10.cpp 
//Aleksandr Gryzlov
//04/15/2022

#include <string>
#include <map>
#include <iostream>
using namespace std;

using FreqTable = map<string, int>;

void buildFreqTable(FreqTable&);
void printTable(FreqTable&);

int main() {
	FreqTable wordFreqTable;
	buildFreqTable(wordFreqTable);
	printTable(wordFreqTable);
	return 0;
}

void buildFreqTable(FreqTable& aFreqTable) {
    string aWord = "";
    while (cin >> aWord) {
        if (aWord == "End-of-File") {
            break;
        }
        auto keyiter = aFreqTable.find(aWord);
        if (keyiter != aFreqTable.end()) {
            aFreqTable[aWord]++;
        }
        else {
            aFreqTable[aWord] = 1;
        }
    }
}

void printTable(FreqTable& aFreqTable) {
    cout << "Word frequency table:" << endl;
    for (const auto& pair : aFreqTable) {
        cout << pair.first << " : " << pair.second << endl;
    }
}