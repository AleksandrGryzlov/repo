#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int input = 0, option1 = 0, option2 = 0, option3 = 0;
	string item1W, item2W, item3W, item4W, item5W;
	string item1H, item2H, item3H, item4H, item5H;
	string item1S, item2S, item3S, item4S, item5S;
	cout << endl;
	cout << "Please Choose a store:\n1.Wal-mart\n2.Hometown Market\n3.Sam's Club\n4.Done" << endl << endl;
	cin >> input;
	while (input != 4) {
		while (input < 1) {
			cout << "Wrong option, please try again!" << endl;
			cin >> input;
			if (input > 4) {
				cout << "Wrong option, please try again!" << endl;
				cin >> input;
			}
		}
		while (input > 4) {
			cout << "Wrong option, please try again!" << endl;
			cin >> input;
			if (input < 1) {
				cout << "Wrong option, please try again!" << endl;
				cin >> input;
			}
		}
		switch (input) {
		case 1:
			option1 = 1;
			cout << "Please enter 5 items, use 'Enter' key to confirm each item individually" << endl;
			cin >> item1W;
			cin >> item2W;
			cin >> item3W;
			cin >> item4W;
			cin >> item5W;
			cout << endl;
			cout << "Please Choose a store:\n1.Wal-mart\n2.Hometown Market\n3.Sam's Club\n4.Done" << endl << endl;
			cin >> input;
			break;
		case 2:
			option2 = 1;
			cout << "Please enter 5 items, use 'Enter' key to confirm each item individually" << endl;
			cin >> item1H;
			cin >> item2H;
			cin >> item3H;
			cin >> item4H;
			cin >> item5H;
			cout << endl;
			cout << "Please Choose a store:\n1.Wal-mart\n2.Hometown Market\n3.Sam's Club\n4.Done" << endl << endl;
			cin >> input;
			break;
		case 3:
			option3 = 1;
			cout << "Please enter 5 items, use 'Enter' key to confirm each item individually" << endl;
			cin >> item1S;
			cin >> item2S;
			cin >> item3S;
			cin >> item4S;
			cin >> item5S;
			cout << endl;
			cout << "Please Choose a store:\n1.Wal-mart\n2.Hometown Market\n3.Sam's Club\n4.Done" << endl << endl;
			cin >> input;
			break;
		}
	}
	cout << endl;
	ofstream myfile;
	myfile.open("print.txt");
	if (option1 = 1)
		myfile << "Walmart's item list: " << item1W << ", " << item2W << ", " << item3W << ", " << item4W << ", " << item5W << endl;
	if (option2 = 1)
		myfile << "Hometown's Market item list: " << item1H << ", " << item2H << ", " << item3H << ", " << item4H << ", " << item5H << endl;
	if (option3 = 1)
		myfile << "Sam's Club item list: " << item1S << ", " << item2S << ", " << item3S << ", " << item4S << ", " << item5S << endl;
	myfile.close();
	if (option1 = 1)
		cout << "Walmart's item list: " << item1W << ", " << item2W << ", " << item3W << ", " << item4W << ", " << item5W << endl;
	if (option2 = 1)
		cout << "Hometown's Market item list: " << item1H << ", " << item2H << ", " << item3H << ", " << item4H << ", " << item5H << endl;
	if (option3 = 1)
		cout << "Sam's Club item list: " << item1S << ", " << item2S << ", " << item3S << ", " << item4S << ", " << item5S << endl;
	return 0;
}
