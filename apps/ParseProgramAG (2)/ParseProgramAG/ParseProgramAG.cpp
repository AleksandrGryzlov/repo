/*
Aleksandr Gryzlov
Parse Program
10/05/2022
*/

#include <iostream>
#include<stack>
#include<vector>;
using namespace std;

stack<int> state;
vector<char> input;

int A = 0;

void rule(int,int);


int main()
{
    int count = 0;

    //string in = "I+I*I";
    //vector<char>input(in.begin(), in.end());

    char test[] = { 'I','+','I','*','I', '$' };
    state.push(0);
    while (A == 0)
    {

    }

    return 0;
}

void rule(int x,int y) //x - rule number, y - row
{
    switch (x)
    {
    case 1:
        state.pop();
        state.pop();
        state.pop();
        if (y == 0)
            state.push(1);
        else
            state.push(8);
        break;
    case 2:
        state.pop();
        if (y == 0)
            state.push(1);
        else
            state.push(8);
        break;
    case 3:
        state.pop();
        state.pop();
        state.pop();
        if (y == 6)
            state.push(9);
        else
            state.push(2);
        break;
    case 4:
        state.pop();
        if (y == 6)
            state.push(9);
        else
            state.push(2);
        break;
    case 5:
        state.pop();
        state.pop();
        state.pop();
        if (y == 7)
            state.push(10);
        else
            state.push(3);
        break;
    case 6:
        state.pop();
        if (y == 7)
            state.push(10);
        else
            state.push(3);
        break;
    default:
        break;
    }
}

int Action[12][6] = {
    //id    +     *    (    )     $
    {   5,NULL,NULL,   4,NULL, NULL},  //0
    {NULL,   6,NULL,NULL,NULL,A = 1},  //1
    {NULL,   2,   7,NULL,   2,    2},  //2
    {NULL,   4,   4,NULL,   4,    4},  //3
    {   5,NULL,NULL,   4,NULL, NULL},  //4
    {NULL,   6,   6,NULL,   6,    6},  //5
    {   5,NULL,NULL,   4,NULL, NULL},  //6
    {   5,NULL,NULL,   4,NULL, NULL},  //7
    {NULL,   6,NULL,NULL,  11, NULL},  //8
    {NULL,   1,   7,NULL,   1,    1},  //9
    {NULL,   3,   3,NULL,   3,    3}, //10
    {NULL,   5,   5,NULL,   5,    5}  //11
};

int Goto[12][3] = {
    //  E    T    F
    {   1,   2,   3}, //0
    {NULL,NULL,NULL}, //1
    {NULL,NULL,NULL}, //2
    {NULL,NULL,NULL}, //3
    {   8,   2,   3}, //4
    {NULL,NULL,NULL}, //5
    {NULL,   9,   3}, //6
    {NULL,NULL,  10}, //7
    {NULL,NULL,NULL}, //8
    {NULL,NULL,NULL}, //9
    {NULL,NULL,NULL},//10
    {NULL,NULL,NULL} //11
};