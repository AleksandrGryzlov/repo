#include <iostream>
#include <time.h>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    int input, credit=0, bet, Pnum1, Pnum2, Dnum1, Dnum2, Psum, Dsum, cont, quit;
    int Pnum3=0, Dnum3=0, victory=0;
    int randomNum;
    string Dvictory, line;
    cout << "\nBLACKJACK GAME MENU\n\nPlease select options\n\n(1) Play BlackJack\n(2) View Game History\n(3) Quit Game\n" << endl;
    ifstream inFile;
    ofstream outFile;
    outFile.open("GryzlovHistory.txt");
    cin >> input;
    while (input != 3) {
        while (input < 1) {
            cout << "\nWrong option, please try again!" << endl;
            cin >> input;
            while (input > 3) {
                cout << "\nWrong option, please try again!" << endl;
                cin >> input;
            }
        }
        while (input > 3) {
            cout << "\nWrong option, please try again!" << endl;
            cin >> input;
            while (input < 1) {
                cout << "\nWrong option, please try again!" << endl;
                cin >> input;
            }
        }
        switch (input) {
        case 1:
            inFile.open("GryzlovHistory.txt");
            cout << "\nHow many credits do you have?" << endl;
            quit = 1;
            cin >> credit;
            while (credit < 1) {
                cout << "\nCredits amount can't be 0 or lower, try again!" << endl;
                cin >> credit;
            }
            while (quit == 1) {
                if (credit <= 0) {
                    cout << "\nEnter more credits" << endl;
                    cin >> credit;
                    while (credit < 1) {
                        cout << "\nCredits amount can't be 0 or lower, try again!" << endl;
                        cin >> credit;
                    }
                }
                cout << "\nPlace your bet between 10 and 150" << endl;
                cin >> bet;
                while ((bet < 10) || (bet > 150)) {
                    cout << "\nWrong number, try again!" << endl;
                    cin >> bet;
                }
                srand(time(NULL));
                randomNum = rand() % 13 + 1;
                Pnum1 = randomNum;               
                randomNum = rand() % 13 + 1;
                Pnum2 = randomNum;
                randomNum = rand() % 13 + 1;
                Dnum1 = randomNum;
                randomNum = rand() % 13 + 1;
                Dnum2 = randomNum;
                if (Pnum1 < 9)
                    Pnum1++;
                if (Pnum2 < 9)
                    Pnum2++;
                if (Dnum1 < 9)
                    Dnum2++;
                if (Dnum2 < 9)
                    Dnum2++;    
                if (Pnum1 > 8)
                    Pnum1=10;
                if (Pnum2 > 8)
                    Pnum2 = 10;
                if (Dnum1 > 8)
                    Dnum1 = 10;
                if (Dnum2 > 8)
                    Dnum2 = 10;
                if (Pnum1 == 13)
                    Pnum1 = 11;
                if (Pnum2 == 13)
                    Pnum2 = 11;
                if (Dnum1 == 13)
                    Dnum1 = 11;
                if (Dnum2 == 13)
                    Dnum2 = 11;
                Psum = Pnum1 + Pnum2;
                Dsum = Dnum1 + Dnum2;
                if (Psum == 21) {
                    credit = credit + bet;                   
                    victory = 1;
                }
                else if (Dsum == 21) {
                    credit = credit - bet;                    
                }
                else if (Dsum == Psum == 21) {
                    credit = credit;
                    victory = 2;
                }
                else {
                    cout << "\nPlayer " << Pnum1 << " " << Pnum2 << endl;
                    cout << "Dealer " << "XX" << " " << Dnum2 << endl;
                    cout << "Would you like to take another card? 1)Yes 2)No" << endl;
                    cin >> cont;
                    if (cont == 1) {
                        randomNum = rand() % 13 + 1;
                        Pnum3 = randomNum;
                        if (Pnum3 < 9)
                            Pnum3++;  
                        if (Pnum3 > 8)
                            Pnum3 = 10;
                        if (Pnum3 == 13)
                            Pnum3 = 11;
                        Psum = Pnum1 + Pnum2 + Pnum3;
                        if (Dsum < 17) {
                            randomNum = rand() % 13 + 1;
                            Dnum3 = randomNum;
                            if (Dnum3 < 9)
                                Dnum3++;
                            if (Dnum3 > 8)
                                Dnum3 = 10;
                            if (Dnum3 == 13)
                                Dnum3 = 11;
                            Dsum = Dnum1 + Dnum2 + Dnum3;
                        }
                        if (Psum > 21)
                            credit = credit - bet;
                        else if (Dsum > 21) {
                            credit = credit + bet;
                            victory = 1;
                        }
                        else if (Psum < Dsum)
                            credit = credit - bet;
                        else if (Psum > Dsum) {
                            credit = credit + bet;
                            victory = 1;
                        }
                        else {
                            credit = credit;                           
                            victory = 2;
                        }
                    }
                    else {
                        if (Dsum < 17) {
                            srand(time(NULL));
                            randomNum = rand() % 13 + 1;
                            Dnum3 = randomNum;
                            if (Dnum3 < 9)
                                Dnum3++;
                            if (Dnum3 > 8)
                                Dnum3 = 10;
                            if (Dnum3 == 13)
                                Dnum3 = 11;
                            Dsum = Dnum1 + Dnum2 + Dnum3;
                        }
                        if (Psum > 21)
                            credit = credit - bet;
                        else if (Dsum > 21) {
                            credit = credit + bet;
                            victory = 1;
                        }
                        else if (Psum < Dsum)
                            credit = credit - bet;
                        else if (Psum > Dsum) {
                            credit = credit + bet;
                            victory = 1;
                        }
                        else {
                            credit = credit;                          
                            victory = 2;
                        }
                    }
                   
                }
                cout << "\nPlayer hand is: " << Psum << endl;
                cout << "Dealer hand is: " << Dsum << endl;
                cout << "remain credit is " << credit << endl;
                cout << "\nWould you like to continue? 1)Y  2)N " << endl;
                cin >> quit;
                if (victory == 0)
                    Dvictory = "L";
                else if (victory == 1)
                    Dvictory = "W";
                else Dvictory = "D";
                outFile << "\nGame History" << endl;
                outFile << "Hand" << setw(10) << "Card 1" << setw(10) << "Card 2" << setw(10) << "Card 3" << setw(10) << "Bet" << setw(10) << "Dealer" << setw(10) << "W/L" << setw(10) << "Balance" << endl;
                outFile << "**********************************************************************************************************************" << endl;
                outFile << Psum << setw(10) << Pnum1 << setw(10) << Pnum2 << setw(10) << Pnum3 << setw(12) << bet << setw(8) << bet << setw(11) << Dvictory << setw(8) << credit << endl;
              }
            break;
        case 2:
            if (inFile.is_open()) {
                while (getline(inFile, line))
                {
                    cout << line << '\n';
                }
                inFile.close();
            }
            else cout << "\nGame History is missing!" << endl;
            break;
        }
        cout << "\nBLACKJACK GAME MENU\n\nPlease select options\n\n(1) Play BlackJack\n(2) View Game History\n(3) Quit Game\n" << endl;
        cin >> input;
    }
    cout << "\nThank you!\nYour remain balance is: " << credit << endl;
    inFile.close();
    outFile.close();
    return 0;
}