#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

int main()
{
    float Item1 = 9.50, Item2 = 2.00, tax = 0.0948, Order, Table, Total, TaxMoney,GrandTotal, Tip15,Tip18,Tip20;
    float LowT = 0.15, MidT = 0.18, HighT = 0.2;
    string Date="7/4/2013  7:28 PM", Item1Name="44 Ginger Lover", Add="[Pork][2**]", Item2Name="Brown Rice";
    Order = rand() % 100 + 1;
    cout << "Please enter Table number: ";
    cin >> Table;
    Total = Item1 + Item2;
    TaxMoney = Total * tax;
    GrandTotal = Total + TaxMoney;
    Tip15 = GrandTotal * LowT;
    Tip18 = GrandTotal * MidT;
    Tip20 = GrandTotal * HighT;
    cout<<endl<<"               Ying Thai Kitchen"<<endl;
    cout << "             2220 Queen Anne AVE N" << endl;
    cout << "                Seatle WA 98 109" << endl;
    cout << "      Tel. (206) 285-8424 FAX. (206) 285-8427"<<endl;
    cout << "            www.yingthaikitchen.com" << endl;
    cout << "      Welcome to Ying Thai Kitchen Restaurant." << endl;
    cout <<endl<<endl<< "Order#: " << Order << "                                        Table  " << Table << endl;
    cout << "Date: " << Date << endl;
    cout << "Server: Jack                                         (T.4)" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << fixed;
    cout << Item1Name << "                                      $" << setprecision(2)<< Item1<< endl;
    cout << Add << endl;
    cout << Item2Name << "                                           $" << Item2<< endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "Total 2 items(s)                                    $" << Total << setprecision(2)<< endl;
    cout << "Sales Tax                                            $" << TaxMoney << endl;
    cout << "==========================================================" << setprecision(2) <<endl;
    cout << "Grand Total                                         $" << GrandTotal << endl << endl << endl;
    cout << "Tip Guide" << endl;
    cout << "15%=$" << setprecision(2)<< Tip15 << ",   18%=$" << setprecision(2)<< Tip18 << ",   20%=$" << setprecision(2)<< Tip20 << endl;
    cout << "                Thank you very much." << endl;
    cout << "                  Come back again"<<endl;
    return 0;

}
