// Aleksandr Gryzlov
// 06.24.2022

#include <iostream>
using namespace std;
void RecursiveTower(int, char, char, char);
int main()
{
	int DiskNum, choice = 0;

	cout << "How many disks do you have?\n#";
	cin >> DiskNum;
	cout << "Choose what solution you want to use\n1.Recursive\n2.Iterative\n3.Exit Program\n#";
	cin >> choice;

	while (choice != -99)
	{
		switch (choice) 
		{
		case 1:
			RecursiveTower(DiskNum, 'A', 'B', 'C');
			cout << endl << endl;
			break;
		case 2:
			break;
		case 3:
			return 1;
		default:
			cout << "Wrong option! Try again.\n";
			break;
		}

		cout << "Choose what solution you want to use\n1.Recursive\n2.Iterative\n3.Exit Program\n#";
		cin >> choice;
	}
	return 0;
}

void RecursiveTower(int diskNUM, char A, char B, char C)
{
	if (diskNUM == 1)
	{
		cout << "Move Disk " << diskNUM << " from " << A << " to " << C << endl;
		return;
	}

	RecursiveTower(diskNUM - 1, A, C, B);
	cout << "Move Disk " << diskNUM << " from " << A << " to " << C << endl;
	RecursiveTower(diskNUM - 1, B, A, C);
}