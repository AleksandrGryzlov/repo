#include <iostream>
using namespace std;
int main()
{
	int numTellers;
	int numDays, total, allTotal = 0;
	int teller, year = 0;
	cout << "This program will find the average number of hours a day"
		<< " that a student spent programming over a long weekend\n\n";
	cout << "How many tellers worked at Nation's Bank during each of the last three years?"
		<< endl << endl;
	cin >> numTellers;
	for (teller = 1; teller <= numTellers; teller++)
	{
		total = 0;
		for (year = 1; year <= 3; year++)
		{
			cout << "How many days was teller "
				<< teller << " out sick during year " << year << "." << endl;
			cin >> numDays;
			total = total + numDays;
		}
		allTotal = allTotal + total;
	}
	cout << "The " << numTellers << " tellers were out sick for a total of " 
		<< allTotal << " days during the last 3 years"
		<< endl;
	return 0;
}