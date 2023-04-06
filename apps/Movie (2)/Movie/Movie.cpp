#include <iostream>
#include <string>
using namespace std;

int main()
{
	string MovieName;
	int AdultTickets, ChildTickets;
	float AdultPrice = 9.00, ChildPrice = 6.00, AdultTotal, ChildTotal, Gross, Net, PaidTo;
	cout << "Please enter Movie Name: ";
	cin >> MovieName;
	cout << "Please enter the amount of adult tickets: ";
	cin >> AdultTickets;
	cout << "Please enter the amount of kids tickets: ";
	cin >> ChildTickets;
	AdultTotal = AdultTickets * AdultPrice;
	ChildTotal = ChildTickets * ChildPrice;
	Gross = AdultTotal + ChildTotal;
	Net = Gross / 5;
	PaidTo = Gross - Net;
	cout << endl;
	cout << endl;
	cout << "Movie Name:                  " << MovieName << endl;
	cout << "Adult tickets Sold:          " << AdultTickets << endl;
	cout << "Child tickets Sold:          " << ChildTickets << endl;
	cout << "Gross Box Office Profit:    $" << Gross << endl;
	cout << "Net Box Office Profit:      $" << Net << endl;
	cout << "Amount Paid to Distributor: $" << PaidTo << endl;
	return 0;
}

