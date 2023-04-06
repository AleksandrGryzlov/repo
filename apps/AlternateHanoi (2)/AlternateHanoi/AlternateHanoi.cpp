/*
Aleksandr Gryzlov
Analysis of Algorithms
01/31/2023
Assignment 2 Question 1
*/

#include <iostream>
#include <vector>

using namespace std;

vector<string> generateGray(int n)
{
	// Base case
	if (n <= 0)
		return { "0" };
	if (n == 1)
	{
		return { "0","1" };
	}
	//Recursive case
	vector<string> recAns =
		generateGray(n - 1);
	vector<string> mainAns;
	// Append 0 to the first half
	for (int i = 0; i < recAns.size(); i++)
	{
		string s = recAns[i];
		mainAns.push_back("0" + s);
	}
	// Append 1 to the second half
	for (int i = recAns.size() - 1; i >= 0; i--)
	{
		string s = recAns[i];
		mainAns.push_back("1" + s);
	}
	return mainAns;
}

//print calls gray code generator function checks number of disk and prints right solution occording to it
void Print(int n)
{
	vector<string> PrintVector;
	PrintVector = generateGray(n);
	for (int i = 0; i < PrintVector.size(); i++) 
	{
		cout << PrintVector[i] << endl;
	}
}

// Enter number of disk and call print function
int main()
{
	cout << "Please enter number of disks:";
	int input = 0;
	cin >> input;
	if (input % 2 == 0)//check if it's even
	{
		cout << "\nOrder for disks: from Starting peg to Remaining peg to Final peg" << endl;
		cout << "Solution is:" << endl;
		Print(input);
	}
	else
	{
		cout << "\nOrder for disks: from Starting peg to Final peg to Remaining Peg" << endl;
		cout << "Solution is:" << endl;
		Print(input);
	}
	return 0;
}

/*
#include <iostream>
#include <vector>
using namespace std;

void hanoi(int n, int from, int to, int via, vector<vector<int> > &moves) {
  if (n == 0) return;
  hanoi(n - 1, from, via, to, moves);
  moves.push_back({from, to});
  hanoi(n - 1, via, to, from, moves);
}

int main() {
  int n;
  cin >> n;
  vector<vector<int> > moves;
  hanoi(n, 0, 1, 2, moves);
  for (auto &move : moves) {
	cout << move[0] << " " << move[1] << endl;
  }
  return 0;
}
*/ 