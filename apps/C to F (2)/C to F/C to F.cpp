#include <iostream>
using namespace std;

int main()
{
    int C, F;
    cout<<"Please enter the number of Celcius : ";
    cin >> C;
    F = (9 / 5) * C + 32;
    cout << C << " of Celcius is equal to " << F << " of Fahrenheit" << endl;
    return 0;
}