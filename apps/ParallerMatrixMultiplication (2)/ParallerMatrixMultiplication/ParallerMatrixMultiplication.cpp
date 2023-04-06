/*
Aleksandr Gryzlov
CS 415
Assignment 3
02/07/2023
*/

#include <iostream>
#include <thread>
#include <chrono>
static const int THREAD_NUM = 4; //choose number 4 because i don't know how many cores people have
using namespace std;

int** createMatrix(int size)//easy matrix creator that resive matrix sides SIZE from the main function, uses rand to fill it up
{
    int** Matrix = new int* [size];
    for (int i = 0; i < size; i++) {
        Matrix[i] = new int[size];
        for (int j = 0; j < size; j++) {
            Matrix[i][j] = rand() % 100;
        }
    }
    return Matrix;
}

int** squareMatrix(int** Matrix, int size)//easy matrix mult thatks to Dr.Merit classes
{
    int** result = new int* [size];
    for (int i = 0; i < size; i++) {
        result[i] = new int[size];
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += Matrix[i][k] * Matrix[k][j];
            }
        }
    }
    return result;
}

int** squareArrayThreaded(int** array, int size) //this should work, but I always run into same error, when I used ifdef DEBUG on it it still runs into some problems, probs I didn't pass things right
{
    int** result = new int* [size];
    for (int i = 0; i < size; i++) {
        result[i] = new int[size];
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
        }
    }
    thread threads[THREAD_NUM];
    for (int i = 0; i < THREAD_NUM; i++) {
        #ifdef DEBUG
            threads[i] = thread(squareArrayThreadedHelper, array, result, size, i);
        #endif  
    }
    for (int i = 0; i < THREAD_NUM; i++) {
        threads[i].join();
    }
    return result;
}
void squareArrayThreadedHelper(int** array, int** result, int size, int i)
{
    for (int j = 0; j < size; j++) {
        for (int k = 0; k < size; k++) {
            result[i][j] += array[i][k] * array[k][j];
        }
    }
}

int main() 
{
    int SIZE;
    cout << "\nEnter number of rows in square matrix:";
    cin >> SIZE;
    cout << endl << endl << "\nRandom matrix with " << SIZE << " rows on each side" << endl;
    int** matrix = createMatrix(SIZE);//pass int, returns double pointer, I found there is no way to return single pointer if you trying to make dinamic 2d array
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
    
    cout << "\nMatrix squared using single thread" << endl;
    matrix = squareMatrix(matrix, SIZE);//pass matrix and size of it
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\nMatrix squared using multi thread" << endl;
    delete matrix;

    matrix = createMatrix(SIZE);
    matrix = squareArrayThreaded(matrix, SIZE);//have issues
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    delete matrix;
    return 0;
}