//Aleksandr Gryzlov

#include <iostream>
using namespace std;

void Input(float&);
void Estimate(float, float&);
void Exact(float, float&);
void Print(float, float, float);

int main()
{
	float input=0, estimate, exact;
	Input(input);
	Estimate(input, estimate);
	Exact(input, exact);
	Print(input, estimate, exact);
	return 0;
}

void Input(float& number)
{
	cout << "Please enter amount of kilos: ";
	cin >> number;
}

void Estimate(float number, float& estimate)
{
	estimate = (number / 2) - ((number / 2) * 0.1);
}

void Exact(float number, float& exact)
{
	exact = number / 2.2046;
}

void Print(float number, float estimate, float exact)
{
	cout << number << " kilogroams = " << estimate << " pounds(estimate) or " << exact << " pounds(exact)";
}