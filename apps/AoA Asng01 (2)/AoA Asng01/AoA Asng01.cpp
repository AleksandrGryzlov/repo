/*
Aleksandr Gryzlov
Assignment 1
Question 2
01/23/2022
*/

#include <iostream>

using namespace std;

int main()
{
	int count = 0, size1 = 0, size0 = 0;
	int poss1 = 0, poss0 = 0;
	int check = 0;
	int stack[7][4] =  {{0,0,1,0},
						{0,0,0,0},
						{0,1,1,0},
						{0,0,1,1},
						{0,1,0,0},
						{0,1,0,1},
						{0,0,0,1}};
	int array1[7][4];
	int array0[7][4];

	cout << "BEFORE:\n";
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << stack[i][j];
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 4; i > 0; i--)
	{
		for (int j = 7; j > 0; j--)
		{
			check = stack[j-1][i-1];
			if (check==1)
			{
				for (int k = 0; k < 4; k++)
				{
					array1[poss1][k] = stack[j-1][k];
				}
				size1++;
				poss1++;
			}
			else
			{
				for (int k = 0; k < 4; k++)
				{
					array0[poss0][k] = stack[j-1][k];
				}
				size0++;
				poss0++;
			}
			check = 0;
		}

		for (int j = size1; j > 0; j--)
		{
			for (int k = 0; k < 4; k++)
			{
				stack[count][k] = array1[j-1][k];
			}
			count++;
		}

		for (int j = size0; j > 0; j--)
		{
			for (int k = 0; k < 4; k++)
			{
				stack[count][k] = array0[j-1][k];
			}
			count++;
		}
		size1 = size0 = count = poss1 = poss0 = 0;
	}

	cout << "AFTER:\n";
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << stack[i][j];
		}
		cout << endl;
	}
	cout << endl;
    return 0;
}