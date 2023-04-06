#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	float Estimate, Exact, Pounds;
	cout << "Please enter ponds: ";
	cin >> Pounds;
	Estimate = (Pounds / 2) - ((Pounds / 2) * 0.1);
	Exact = Pounds / 2.2046;
	cout << fixed;
	cout << Pounds << " pounds=" << setprecision(2) << Estimate << " estimate " << setprecision(2) << Exact << " exact";
	return 0;
}
