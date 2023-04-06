#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
    float i1, i2, i3, E=40, R=15, e= 2.71828, RC=0.555;
    float t1, t2, t3;
    cout << "First test.  Please enter umber of seconds that the circuit will run: ";
    cin >> t1;
    i1 = (E / R) * (pow(e, -t1 / RC));
    cout << "Second test. Please enter umber of seconds that the circuit will run: ";
    cin >> t2;
    i2 = (E / R) * (pow(e, -t2 / RC));
    cout << "Third test.  Please enter umber of seconds that the circuit will run: ";
    cin >> t3;
    i3 = (E / R) * (pow(e, -t3 / RC));
    cout << fixed;
    cout << endl << endl << endl;
    cout << "Voltage V   " << "Resistance R       " << "  RC    " << "         Time t   " << "       Current i" << endl;
    cout << " (Volts)" << "       (0hms)" << "      (Time Constant)" << "     (Seconds)" << "         (Amps)" << endl;
    cout << setprecision(0) <<"   " << E << "            " << R << "             " << setprecision(3) << RC << "           " << t1 << "             " << i1 << endl;
    cout << setprecision(0) <<"   " << E << "            " << R << "             " << setprecision(3) << RC << "           " << t2 << "             " << i2 << endl;
    cout << setprecision(0) <<"   " << E << "            " << R << "             " << setprecision(3) << RC << "           " << t3 << "             " << i3 << endl;
    return 0;
}