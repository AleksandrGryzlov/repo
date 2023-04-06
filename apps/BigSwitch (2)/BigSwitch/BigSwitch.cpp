#include <iostream>
using namespace std;

int main()
{
	double Ben=0, Blake=0, Mason=0;
	double Ben1=0, Ben2=0, Blake1=0, Blake2=0, Mason1=0, Mason2=0;
	int event, bar, name, run=0;
	int BenP=0, BlakeP=0, MasonP=0;
	string DisplayEvent;
	label: 
	cout << "Please choose event\n";
	cout << " 1. Axle Clean and Press\n 2. Farmers Frame Medley\n 3. Axle Deadlift\n";
	cout << " 4. Yoke Carry Keg Medley\n 5. Stone over\n 6. Display Results" << endl;
	cin >> event;
		switch (event)
		{
		case 1:
			cout << " 1. High Bar\n 2. Low Bar" << endl;
			cin >> bar;
				switch (bar)
				{
				case 1:
					DisplayEvent = "Axle Clean and Press";
					cout << "Pick the name" << endl;
					cout << "1. Ben\n2. Blake\n3. Mason\n";
					cin >> name;
						switch (name)
						{
						case 1:
							cout << "Enter Ben's First attempt\n";
							cin >> Ben1;
							cout << "Enter Ben's second attempt\n";
							cin >> Ben2;
							if (Ben1 > Ben2)
								Ben = Ben1;
							else
								Ben = Ben2;
							goto label;
							break;
						case 2:
							cout << "Enter Blake's First attempt\n";
							cin >> Blake1;
							cout << "Enter Blake's second attempt\n";
							cin >> Blake2;
							if (Blake1 > Blake2)
								Blake = Blake1;
							else
								Blake = Blake2;
							goto label;
							break;
						case 3:
							cout << "Enter Mason's First attempt\n";
							cin >> Mason1;
							cout << "Enter Mason's second attempt\n";
							cin >> Mason2;
							if (Mason1 > Mason2)
								Mason = Mason1;
							else
								Mason = Mason2;
							goto label;
							break;
						default:
							cout << "Wrong option, end of programm!";
							return 0;
						}
				case 2:
					DisplayEvent = "Axle Clean and Press";
					cout << "Pick the name" << endl;
					cout << "1. Ben\n2. Blake\n3. Mason\n";
					cin >> name;
						switch (name)
						{
						case 1:
							cout << "Enter Ben's First attempt\n";
							cin >> Ben1;
							cout << "Enter Ben's second attempt\n";
							cin >> Ben2;
							if (Ben1 > Ben2)
								Ben = Ben1;
							else
								Ben = Ben2;
							goto label;
							break;
						case 2:
							cout << "Enter Blake's First attempt\n";
							cin >> Blake1;
							cout << "Enter Blake's second attempt\n";
							cin >> Blake2;
							if (Blake1 > Blake2)
								Blake = Blake1;
							else
								Blake = Blake2;
							goto label;
							break;
						case 3:
							cout << "Enter Mason's First attempt\n";
							cin >> Mason1;
							cout << "Enter Mason's second attempt\n";
							cin >> Mason2;
							if (Mason1 > Mason2)
								Mason = Mason1;
							else
								Mason = Mason2;
							goto label;
							break;
						default:
							cout << "Wrong option, end of programm!";
							return 0;
						}
				}
		case 2:
			DisplayEvent = "Farmers Frame Medley";
			cout << "Pick the name" << endl;
			cout << "1. Ben\n2. Blake\n3. Mason\n";
			run = 1;
			cin >> name;
				switch (name)
				{
				case 1:
					cout << "Enter Ben's First attempt\n";
					cin >> Ben1;
					cout << "Enter Ben's second attempt\n";
					cin >> Ben2;
					if (Ben1 > Ben2)
						Ben = Ben1;
					else
						Ben = Ben2;
					goto label;
					break;
				case 2:
					cout << "Enter Blake's First attempt\n";
					cin >> Blake1;
					cout << "Enter Blake's second attempt\n";
					cin >> Blake2;
					if (Blake1 > Blake2)
						Blake = Blake1;
					else
						Blake = Blake2;
					goto label;
					break;
				case 3:
					cout << "Enter Mason's First attempt\n";
					cin >> Mason1;
					cout << "Enter Mason's second attempt\n";
					cin >> Mason2;
					if (Mason1 > Mason2)
						Mason = Mason1;
					else
						Mason = Mason2;	
					goto label;
					break;
				default:
					cout << "Wrong option, end of programm!";
					return 0;
				}
		case 3:
			DisplayEvent = "Axle Deadlift";
			cout << "Pick the name" << endl;
			cout << "1. Ben\n2. Blake\n3. Mason\n";
			cin >> name;
				switch (name)
				{
				case 1:
					cout << "Enter Ben's First attempt\n";
					cin >> Ben1;
					cout << "Enter Ben's second attempt\n";
					cin >> Ben2;
					if (Ben1 > Ben2)
						Ben = Ben1;
					else
						Ben = Ben2;
					goto label;
					break;
				case 2:
					cout << "Enter Blake's First attempt\n";
					cin >> Blake1;
					cout << "Enter Blake's second attempt\n";
					cin >> Blake2;
					if (Blake1 > Blake2)
						Blake = Blake1;
					else
						Blake = Blake2;
					goto label;
					break;
				case 3:
					cout << "Enter Mason's First attempt\n";
					cin >> Mason1;
					cout << "Enter Mason's second attempt\n";
					cin >> Mason2;
					if (Mason1 > Mason2)
						Mason = Mason1;
					else
						Mason = Mason2;
					goto label;
					break;
				default:
					cout << "Wrong option, end of programm!";
					return 0;
				}
		case 4:
			DisplayEvent = "Yoke Carry Keg Medley";
			cout << "Pick the name" << endl;
			cout << "1. Ben\n2. Blake\n3. Mason\n";
			run = 1;
			cin >> name;
				switch (name)
				{
				case 1:
					cout << "Enter Ben's First attempt\n";
					cin >> Ben1;
					cout << "Enter Ben's second attempt\n";
					cin >> Ben2;
					if (Ben1 > Ben2)
						Ben = Ben1;
					else
						Ben = Ben2;
					goto label;
					break;
				case 2:
					cout << "Enter Blake's First attempt\n";
					cin >> Blake1;
					cout << "Enter Blake's second attempt\n";
					cin >> Blake2;
					if (Blake1 > Blake2)
						Blake = Blake1;
					else
						Blake = Blake2;
					goto label;
					break;
				case 3:
					cout << "Enter Mason's First attempt\n";
					cin >> Mason1;
					cout << "Enter Mason's second attempt\n";
					cin >> Mason2;
					if (Mason1 > Mason2)
						Mason = Mason1;
					else
						Mason = Mason2;
					goto label;
					break;
				default:
					cout << "Wrong option, end of programm!";
					return 0;
				}
		case 5:
			DisplayEvent = "Stone over";
			cout << "Pick the name" << endl;
			cout << "1. Ben\n2. Blake\n3. Mason\n";
			cin >> name;
				switch (name)
				{
				case 1:
					cout << "Enter Ben's First attempt\n";
					cin >> Ben1;
					cout << "Enter Ben's second attempt\n";
					cin >> Ben2;
					if (Ben1 > Ben2)
						Ben = Ben1;
					else
						Ben = Ben2;
					goto label;
					break;
				case 2:
					cout << "Enter Blake's First attempt\n";
					cin >> Blake1;
					cout << "Enter Blake's second attempt\n";
					cin >> Blake2;
					if (Blake1 > Blake2)
						Blake = Blake1;
					else
						Blake = Blake2;
					goto label;
					break;
				case 3:
					cout << "Enter Mason's First attempt\n";
					cin >> Mason1;
					cout << "Enter Mason's second attempt\n";
					cin >> Mason2;
					if (Mason1 > Mason2)
						Mason = Mason1;
					else
						Mason = Mason2;
					goto label;
					break;
				default:
					cout << "Wrong option, end of programm!";
					return 0;
				}
		case 6:
			if (run == 0) {
				if (Ben > Blake && Ben > Mason && Blake > Mason) {
					BenP = 3; BlakeP = 2; MasonP = 1;
				}
				else if (Ben > Blake && Ben > Mason && Mason > Blake) {
					BenP = 3; MasonP = 2; BlakeP = 1;
				}
				else if (Blake > Ben && Blake > Mason && Ben > Mason) {
					BlakeP = 3; BenP = 2; MasonP = 1;
				}
				else if (Blake > Ben && Blake > Mason && Mason > Ben) {
					BlakeP = 3; MasonP = 2; BenP = 1;
				}
				else if (Mason > Ben && Mason > Blake && Ben > Blake) {
					MasonP = 3; BenP = 2; BlakeP = 1;
				}
				else if (Mason > Ben && Mason > Blake && Blake > Ben) {
					MasonP = 3; BlakeP = 2; BenP = 1;
				}
				else if (Ben == Blake && Blake == Mason) {
					BenP = 3; BlakeP = 3; MasonP = 3;
				}
				else if (Ben > Blake && Blake == Mason) {
					BenP = 3; BlakeP = 2; MasonP = 2;
				}
				else if (Blake > Ben && Ben == Mason) {
					BlakeP = 3; BenP = 2; MasonP = 2;
				}
				else if (Mason > Ben && Ben == Blake) {
					MasonP = 3; BenP = 2; BlakeP = 2;
				}
			}
			else if (run == 1) {
				if (Ben > Blake && Ben > Mason && Blake > Mason) {
					BenP = 1; BlakeP = 2; MasonP = 3;
				}
				else if (Ben > Blake && Ben > Mason && Mason > Blake) {
					BenP = 1; MasonP = 2; BlakeP = 3;
				}
				else if (Blake > Ben && Blake > Mason && Ben > Mason) {
					BlakeP = 1; BenP = 2; MasonP = 3;
				}
				else if (Blake > Ben && Blake > Mason && Mason > Ben) {
					BlakeP = 1; MasonP = 2; BenP = 3;
				}
				else if (Mason > Ben && Mason > Blake && Ben > Blake) {
					MasonP = 1; BenP = 2; BlakeP = 3;
				}
				else if (Mason > Ben && Mason > Blake && Blake > Ben) {
					MasonP = 1; BlakeP = 2; BenP = 3;
				}
			}
			cout << "          " << DisplayEvent << endl;
			cout << "                 1st     2nd     Pts\n";
			cout << "Competitors" << endl;
			cout << "   Ben " << "           " << Ben1   << "       " << Ben2   << "       " << BenP   << endl;
			cout << "  Blake" << "           " << Blake1 << "       " << Blake2 << "       " << BlakeP << endl;
			cout << "  Mason" << "           " << Mason1 << "       " << Mason2 << "       " << MasonP << endl;
			return 0;
		default:
			cout << "Wrong option, end of programm!";
			return 0;
		}
return 0;
}