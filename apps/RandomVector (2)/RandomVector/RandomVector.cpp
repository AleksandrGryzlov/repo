#include <iostream>
#include <random>
#include <vector>

using namespace std;

vector<int> RandomInPlace(vector <int>);

int main()
{
    vector<int> vector = { 1,2,3,4,5,6,7,8,9,10 };

    // print before swaps
    for (auto i : vector) {
        cout << i << " ";
    }
    cout << endl;

    vector = RandomInPlace(vector);

    // print swaped vector
    for (auto i : vector) {
        cout << i << " ";
    }
}

vector<int> RandomInPlace(vector<int> vector) 
{
    random_device RANDOM;
    uniform_int_distribution <int> distribution(0, vector.size());
    for (int i = 0; i < vector.size(); i++)
    {
        int n = distribution(RANDOM);
        swap(vector[i], vector[n]);
        n = 0;
    }

    return vector;
}