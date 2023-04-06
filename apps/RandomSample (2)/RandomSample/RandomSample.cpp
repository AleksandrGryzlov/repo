#include <iostream>
#include <random>
#include <vector>

using namespace std;

vector<int> RandomInPlace(vector <int>);
vector<int> RandomSample(vector <int>, int, int);

int main()
{
    vector<int> vector;

    int n, m;
    cout << "Enter size of the original int set:";
    cin >> n;
    cout << "Enter size of the subset of original set: ";
    cin >> m;
    while (m > n)
    {
        cout << "Size of subset cannot be higher than size of original set.\nEnter size of the subset of original set: ";
        cin >> m;
    }

    //make set size of n
    for (int i = 0; i < n; i++)
    {
        vector.push_back(i+1);
    }
    //print original set
    for (auto i : vector) {
        cout << i << " ";
    }
    cout << endl;

    //make random sample
    vector = RandomSample(vector, n, m);

    // print after manipulations
    if (vector.empty())
    {
        cout << "Empty set: {0}";
    }
    else
    {
        for (auto i : vector) {
            cout << i << " ";
        }
    }
    return 0;
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

vector<int> RandomSample(vector<int> vector, int n, int m)
{
    if (m==0)
    {
        vector.clear();
    }
    else
    {
        vector = RandomInPlace(vector);
        int dif = n - m;
        for (int i = 0; i < dif; i++)
        {
            vector.pop_back();
        }
    }
    return vector;
}