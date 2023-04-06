#include <iostream>
#include <random>

using namespace std;

int RANDOM(int, int);

int main()
{
    int a, b;
    cout << "Enter two numbers, they will be a range for the random generated number:\n";
    cin >> a;
    cin >> b;
    cout << "The random number is " << RANDOM(a, b);
    return 0;
}

int RANDOM(int a, int b)
{
    random_device RANDOM;
    uniform_int_distribution<int> distribution(a, b);
    int c = distribution(RANDOM);
    return c;
}