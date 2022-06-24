// Aleksandr Gryzlov
// 06.24.2022

#include <iostream>
using namespace std;
void RecursiveTower(int, char, char, char); //recursive solution

struct Stack //iterative solution
{
	unsigned capacity;
	int top;
	int* array;
};
struct Stack* createStack(unsigned capacity)
{
	struct Stack* stack =
		(struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array =
		(int*)malloc(stack->capacity * sizeof(int));
	return stack;
}

int isFull(struct Stack* stack)
{
    return (stack->top == stack->capacity - 1);
}

int isEmpty(struct Stack* stack)
{
    return (stack->top == -1);
}

void push(struct Stack* stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

void moveDisk(char fromPeg, char toPeg, int disk)
{
    cout << "Move the disk " << disk << " from " << fromPeg << " to " << toPeg << endl;
}

void moveDisksBetweenTwoPoles(struct Stack* src,
    struct Stack* dest, char s, char d)
{
    int pole1TopDisk = pop(src);
    int pole2TopDisk = pop(dest);

    if (pole1TopDisk == INT_MIN)
    {
        push(src, pole2TopDisk);
        moveDisk(d, s, pole2TopDisk);
    }

    else if (pole2TopDisk == INT_MIN)
    {
        push(dest, pole1TopDisk);
        moveDisk(s, d, pole1TopDisk);
    }

    else if (pole1TopDisk > pole2TopDisk)
    {
        push(src, pole1TopDisk);
        push(src, pole2TopDisk);
        moveDisk(d, s, pole2TopDisk);
    }

    else
    {
        push(dest, pole2TopDisk);
        push(dest, pole1TopDisk);
        moveDisk(s, d, pole1TopDisk);
    }
}

void IterativeTower(int num_of_disks, struct Stack* src, struct Stack* aux, struct Stack* dest)
{
    int i, total_num_of_moves;
    char s = 'S', d = 'D', a = 'A';

    if (num_of_disks % 2 == 0)
    {
        char temp = d;
        d = a;
        a = temp;
    }
    total_num_of_moves = pow(2, num_of_disks) - 1;

    for (i = num_of_disks; i >= 1; i--)
        push(src, i);

    for (i = 1; i <= total_num_of_moves; i++)
    {
        if (i % 3 == 1)
            moveDisksBetweenTwoPoles(src, dest, s, d);

        else if (i % 3 == 2)
            moveDisksBetweenTwoPoles(src, aux, s, a);

        else if (i % 3 == 0)
            moveDisksBetweenTwoPoles(aux, dest, a, d);
    }
}

int main()
{
    struct Stack* A, * C, * B;
	int DiskNum, choice = 0;

	
	cout << "Choose what solution you want to use\n1.Recursive\n2.Iterative\n3.Exit Program\n#";
	cin >> choice;

	while (choice != -99)
	{
		switch (choice) 
		{
		case 1:
            cout << "How many disks do you have?\n#";
            cin >> DiskNum;
			RecursiveTower(DiskNum, 'A', 'B', 'C'); //recursive solution
			cout << endl << endl;
			break;
		case 2:
            cout << "How many disks do you have?\n#";
            cin >> DiskNum;
            A = createStack(DiskNum);
            B = createStack(DiskNum);
            C = createStack(DiskNum);
            IterativeTower(DiskNum, A, B, C); //Iterative solution
            cout << endl << endl;
			break;
		case 3:
            cout << "\n\n\nGoodbye!\n\n\n";
			return 1;
		default:
			cout << "Wrong option! Try again.\n";
			break;
		}

		cout << "Choose what solution you want to use\n1.Recursive\n2.Iterative\n3.Exit Program\n#";
		cin >> choice;
	}
	return 0;
}

void RecursiveTower(int diskNUM, char A, char B, char C) //recursive solution
{
	if (diskNUM == 1)
	{
		cout << "Move Disk " << diskNUM << " from " << A << " to " << C << endl;
		return;
	}

	RecursiveTower(diskNUM - 1, A, C, B);
	cout << "Move Disk " << diskNUM << " from " << A << " to " << C << endl;
	RecursiveTower(diskNUM - 1, B, A, C);
}