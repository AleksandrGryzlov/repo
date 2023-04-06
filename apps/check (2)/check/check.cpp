#include <iostream>
using namespace std;

int main()
{
    int sum, number = 0, inNumber, countNumber;
    cout << "Please enter positive even number" << endl;
    cin >> inNumber;
    while (inNumber < 0) {
        cout << "Number can't be negative, try again!" << endl;
        cin >> inNumber;
    }
    sum = inNumber/2;
    sum = sum * 2;
    countNumber = sum;
    do {
        sum = sum + number;
        number = number + 2;
    } while (number < countNumber);
    cout << "Sum of all even positive numbers from 0 to " << inNumber << " is " << sum << endl;
    return 0;
}