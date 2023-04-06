#include <iostream>
using namespace std;

typedef char FreeBirdM[7][8];
typedef char FreeBirdN[7][8];
typedef char BethoovenM[7][8];
typedef char BethoovenN[7][8];

void User(FreeBirdM&, FreeBirdN&, BethoovenM&, BethoovenN&);
void Admin(const FreeBirdM, const FreeBirdN, const BethoovenM, const BethoovenN, float, float, char&);
void TicketCount(int, int, int, int, int&, int&, int&, int&);

const float AdultDay = 6.00;
const float AdultNight = 8.00;
const float KidsDay = 4.00;
const float KidsNight = 6.00;
int adultT=0, kidT=0, adultNT=0, kidNT=0;

int main()
{
    FreeBirdM FBM;
    FreeBirdN FBN;
    BethoovenM BM;
    BethoovenN BN;
    char quit = 'N';
    int row = 7, colom = 8;
    float total = 0, totalTicket = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colom; j++)
        {
            FBM[i][j] = '*';
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colom; j++)
        {
            FBN[i][j] = '*';
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colom; j++)
        {
            BM[i][j] = '*';
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colom; j++)
        {
            BN[i][j] = '*';
        }
    }
    cout << "Movies today\nFree Bird at 3:30PM: ($4 Kids Ticket | $6 Adults Ticket)" << endl;
    cout << "Free Bird at 6:00PM: ($6 Kids Ticket | $8 Adult Ticket)" << endl;
    cout << "Bethooven at 5:30PM: ($4 Kids Ticket | $6 Adults Ticket)" << endl;
    cout << "Bethooven at 7:30PM: ($6 Kids Ticket | $8 Adults Ticket)" << endl;
    while (quit == 'N')
    {
        User(FBM, FBN, BM, BN);
        Admin(FBM, FBN, BM, BN, total, totalTicket, quit);
    }
    cout << "\nHave a good day!\n";
    return 0;
}

void User(FreeBirdM& FBM, FreeBirdN& FBN, BethoovenM& BM, BethoovenN& BN)
{
    int choice, seatsN, seatRow, seatColom; 
    int adult, kid;
    int adultN, kidN;
    float total;
    int row = 7, colom = 8;
    cout << "Choose movie" << endl;
    cout << "1.Free Bird(Morning)\n2.Free Bird(Night)\n3.Bethooven(Morning)\n4.Bethooven(Night)" << endl;
    cin >> choice;
    while (choice != -99)
    {
        adult = 0;
        kid = 0;
        adultN = 0;
        kidN = 0;
        switch (choice)
        {
        case 1:
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < colom; j++)
                {
                    cout << FBM[i][j];
                }
                cout << endl;
            }
            cout << "How many adult tickets do you need: ";
            cin >> adult;
            cout << "How many kids tickets do you need: ";
            cin >> kid;
            seatsN = adult + kid;
            cout << "Please choose row:";
            cin >> seatRow;
            cout << "Please choose colom:";
            cin >> seatColom;
            while (seatsN + seatColom-1 > 8)
            {
                cout << "Sorry, we can't sit all " << seatsN << " guests in this location, try again!" << endl;
                cout << "How many adult tickets do you need: ";
                cin >> adult;
                cout << "How many kids tickets do you need: ";
                cin >> kid;
                seatsN = adult + kid;
                cout << "Please choose row:";
                cin >> seatRow;
                cout << "Please choose colom:";
                cin >> seatColom;              
            }
            while (FBM[seatRow - 1][seatColom - 1] == 'X' || FBM[seatRow - 1][seatColom - 1] == '#')
            {
                cout << "Sorry, this seat you chose already taken or close to another visitor\n";
                cout << "Please choose row:";
                cin >> seatRow;
                cout << "Please choose colom:";
                cin >> seatColom;
            }
            for (int count=0; count < seatsN; count++)
            {
                if (count == 0)
                {
                    if (seatColom - 2 >= 0)
                    {
                        FBM[seatRow - 1][seatColom - 2] = 'X';
                    }
                }
                FBM[seatRow-1][seatColom-1] = '#';
                if (seatRow - 2 >= 0)
                {
                    FBM[seatRow - 2][seatColom - 1] = 'X';
                }
                FBM[seatRow][seatColom - 1] = 'X';
                seatColom++;
            }
            FBM[seatRow - 1][seatColom - 1] = 'X';
            total = adult * AdultDay + kid * KidsDay;
            cout << "Your total is: " << total << "$"<<endl;
            break;
        case 2:
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < colom; j++)
                {
                    cout << FBN[i][j];
                }
                cout << endl;
            }
            cout << "How many adult tickets do you need: ";
            cin >> adultN;
            cout << "How many kids tickets do you need: ";
            cin >> kidN;
            seatsN = adultN + kidN;
            cout << "Please choose row:";
            cin >> seatRow;
            cout << "Please choose colom:";
            cin >> seatColom;
            while (seatsN + seatColom-1 > 8)
            {
                cout << "Sorry, we can't sit all " << seatsN << " guests in this location, try again!" << endl;
                cout << "How many adult tickets do you need: ";
                cin >> adultN;
                cout << "How many kids tickets do you need: ";
                cin >> kidN;
                seatsN = adultN + kidN;
                cout << "Please choose row:";
                cin >> seatRow;
                cout << "Please choose colom:";
                cin >> seatColom;
            }
            while (FBN[seatRow - 1][seatColom - 1] == 'X' || FBN[seatRow - 1][seatColom - 1] == '#')
            {
                cout << "Sorry, this seat you chose already taken or close to another visitor\n";
                cout << "Please choose row:";
                cin >> seatRow;
                cout << "Please choose colom:";
                cin >> seatColom;
            }
            for (int count = 0; count < seatsN; count++)
            {
                if (count == 0)
                {
                    if (seatColom - 2 >= 0)
                    {
                        FBN[seatRow - 1][seatColom - 2] = 'X';
                    }
                }
                FBN[seatRow - 1][seatColom - 1] = '#';
                if (seatRow - 2 >= 0)
                {
                    FBN[seatRow - 2][seatColom - 1] = 'X';
                }
                FBN[seatRow][seatColom - 1] = 'X';
                seatColom++;
            }
            FBN[seatRow - 1][seatColom - 1] = 'X';
            total = adult * AdultNight + kid * KidsNight;
            cout << "Your total is: " << total << "$"<<endl;
            break;
        case 3:
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < colom; j++)
                {
                    cout << BM[i][j];
                }
                cout << endl;
            }
            cout << "How many adult tickets do you need: ";
            cin >> adult;
            cout << "How many kids tickets do you need: ";
            cin >> kid;
            seatsN = adult + kid;
            cout << "Please choose row:";
            cin >> seatRow;
            cout << "Please choose colom:";
            cin >> seatColom;
            while (seatsN + seatColom-1 > 8)
            {
                cout << "Sorry, we can't sit all " << seatsN << " guests in this location, try again!" << endl;
                cout << "How many adult tickets do you need: ";
                cin >> adult;
                cout << "How many kids tickets do you need: ";
                cin >> kid;
                seatsN = adult + kid;
                cout << "Please choose row:";
                cin >> seatRow;
                cout << "Please choose colom:";
                cin >> seatColom;
            }
            while (BM[seatRow - 1][seatColom - 1] == 'X' || BM[seatRow - 1][seatColom - 1] == '#')
            {
                cout << "Sorry, this seat you chose already taken or close to another visitor\n";
                cout << "Please choose row:";
                cin >> seatRow;
                cout << "Please choose colom:";
                cin >> seatColom;
            }
            for (int count = 0; count < seatsN; count++)
            {
                if (count == 0)
                {
                    if (seatColom - 2 >= 0)
                    {
                        BM[seatRow - 1][seatColom - 2] = 'X';
                    }
                }
                BM[seatRow - 1][seatColom - 1] = '#';
                if (seatRow - 2 >= 0)
                {
                    BM[seatRow - 2][seatColom - 1] = 'X';
                }
                BM[seatRow][seatColom - 1] = 'X';
                seatColom++;
            }
            BM[seatRow - 1][seatColom - 1] = 'X';
            total = adult * AdultDay + kid * KidsDay;
            cout << "Your total is: " << total << "$" << endl;
            break;
        case 4:
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < colom; j++)
                {
                    cout << BN[i][j];
                }
                cout << endl;
            }
            cout << "How many adult tickets do you need: ";
            cin >> adultN;
            cout << "How many kids tickets do you need: ";
            cin >> kidN;
            seatsN = adultN + kidN;
            cout << "Please choose row:";
            cin >> seatRow;
            cout << "Please choose colom:";
            cin >> seatColom;
            while (seatsN + seatColom-1 > 8)
            {
                cout << "Sorry, we can't sit all " << seatsN << " guests in this location, try again!" << endl;
                cout << "How many adult tickets do you need: ";
                cin >> adultN;
                cout << "How many kids tickets do you need: ";
                cin >> kidN;
                seatsN = adultN + kidN;
                cout << "Please choose row:";
                cin >> seatRow;
                cout << "Please choose colom:";
                cin >> seatColom;
            }
            while (BN[seatRow - 1][seatColom - 1] == 'X' || BN[seatRow - 1][seatColom - 1] == '#')
            {
                cout << "Sorry, this seat you chose already taken or close to another visitor\n";
                cout << "Please choose row:";
                cin >> seatRow;
                cout << "Please choose colom:";
                cin >> seatColom;
            }
            for (int count = 0; count < seatsN; count++)
            {
                if (count == 0)
                {
                    if (seatColom - 2 >= 0)
                    {
                        BN[seatRow - 1][seatColom - 2] = 'X';
                    }
                }
                BN[seatRow - 1][seatColom - 1] = '#';
                if (seatRow - 2 >= 0)
                {
                    BN[seatRow - 2][seatColom - 1] = 'X';
                }
                BN[seatRow][seatColom - 1] = 'X';
                seatColom++;
            }
            BN[seatRow - 1][seatColom - 1] = 'X';
            total = adult * AdultNight + kid * KidsNight;
            cout << "Your total is: " << total << "$" << endl;
            break;
        default:
            break;
        }
        TicketCount(adult, kid, adultN, kidN, adultT, kidT, adultNT, kidNT);
        cout << "\nChoose movie" << endl;
        cout << "1.Free Bird(Morning)\n2.Free Bird(Night)\n3.Bethooven(Morning)\n4.Bethooven(Night)" << endl;
        cin >> choice;
    }
}

void Admin(const FreeBirdM FBM, const FreeBirdN FBN, const BethoovenM BM, const BethoovenN BN, float totalSale, float totalTickets, char& quit)
{
    int choice;
    int row = 7, colom = 8;
    int adultSale, kidSale, adultNSale, kidNSale;
    adultSale = adultT * AdultDay;
    kidSale = kidT * KidsDay;
    adultNSale = adultNT * AdultNight;
    kidNSale = kidNT * KidsNight;
    totalTickets = adultT + kidT + adultNT + kidNT;
    totalSale = adultSale + kidSale + adultNSale + kidNSale;
    cout << "\nPlease choose:\n1.Free Bird Morning\n2.Free Bird Night\n3.Bethooven Morning\n4.Bethooven Night\n";
    cout << "5.Total sale\n6.Total tickets" << endl;
    cin >> choice;
    while (choice !=-99)
    {
        switch (choice)
        {
        case 1:
            cout << endl;
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < colom; j++)
                {
                    cout << FBM[i][j];
                }
                cout << endl;
            }
            break;
        case 2:
            cout << endl;
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < colom; j++)
                {
                    cout << FBN[i][j];
                }
                cout << endl;
            }
            break;
        case 3:
            cout << endl;
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < colom; j++)
                {
                    cout << BM[i][j];
                }
                cout << endl;
            }
            break;
        case 4:
            cout << endl;
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < colom; j++)
                {
                    cout << BN[i][j];
                }
                cout << endl;
            }
            break;
        case 5:
            cout << "\nTotal adult(day) sale: " << adultSale << "$" << endl;
            cout << "Total adult(night) sale: " << adultNSale << "$" << endl;
            cout << "Total kids(day) sale: " << kidSale << "$" << endl;
            cout << "Total kids(night) sale: " << kidNSale << "$" << endl;
            cout << "Total sale is " << totalSale << "$" << endl;
            break;
        case 6:
            cout << "\nTotal adult(day) tickets: " << adultT << endl;
            cout << "Total adult(night) tickets: " << adultNT << endl;
            cout << "Total kids(day) tickets: " << kidT << endl;
            cout << "Total kids(night) tickets: " << kidNT << endl;
            cout << "Total tickets sold today: " << totalTickets << endl;
            break;
        default:
            break;
        }
        cout << "\nPlease choose:\n1.Free Bird Morning\n2.Free Bird Night\n3.Bethooven Morning\n4.Bethooven Night\n";
        cout << "5.Total sale\n6.Total by tickets" << endl;
        cin >> choice;
    }
    cout << "Would you like to close for today? 'Y' or 'N'" << endl;
    cin >> quit;
    while ((quit != 'N') && (quit != 'Y'))
    {
        if (quit == 'n')
        {
            quit = 'N';
        }
        else if(quit == 'y')
        {
            quit = 'Y';
        }
        else if (quit != 'N')
        {
            cout << "Wrong option, please try again!" << endl;
            cin >> quit;
        }
        else if (quit != 'Y')
        {
            cout << "Wrong option, please try again!" << endl;
            cin >> quit;
        }
    }
}

void TicketCount(int adult, int kid, int adultN, int kidN, int& adultT, int& kidT, int& adultNT, int& kidNT)
{
    adultT = adultT + adult;
    adultNT = adultNT + adultN;
    kidT = kidT + kid;
    kidNT = kidNT = kidN;
}