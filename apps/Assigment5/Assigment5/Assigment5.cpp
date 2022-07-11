//Assigment 5
//Aleksandr Gryzlov
//07.11.2022

#include <iostream>
#include <list>
#include<chrono>

using namespace std;

int anyEqual(int n, int A[][])
{
	int i, j, k, m;

	for (i = 1; i <= n; i++) 
	{
		for (j = 1; j <= n; j++)
		{
			for (k = 1; k <= n; k++)
			{
				for (m = 1; m <= n; m++)
				{
					if (A[i][j] == A[k][m] && !(i == k && j == m))
						return 1;	
				}
			}
		}
	}
	return 0;
}

int main()
{
	list<int> sizes = { 10,20,30,40,50,100,500,1000 };
	int average = 0;
	auto start = chrono::steady_clock::now();
	for (auto size : sizes)
	{
		int sum = 0;
		for (int i = 0; i <= 20; i++)
		{
			anyEqual(size, A[][]);
			average = sum / 20;
		}
	}
	auto end = chrono::steady_clock::now();
	chrono::duration<double>elapsed_seconds = end - start;
	cout << "\nelapsed time: " << elapsed_seconds.count() << "s\n";
	return 2;
}