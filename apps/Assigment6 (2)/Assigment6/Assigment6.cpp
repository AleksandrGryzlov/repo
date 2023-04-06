#include <iostream>
#include <vector>
#include "Tree.h"
#include <chrono>
using namespace std;

template<typename T>
struct Mydata {
    size_t num;
    vector<int> Vect1;
    vector<int>* Vec;
    Tree<T>* x = new Tree<T>();
};

template<typename T>
void fill_vector(vector<T>& Vect1, int num) {
    int i = 0;
    int b = 0;
    while (i < num) {
        Vect1.push_back(rand() % 100 + 1);
        i++;
    }
    return;
}

template<typename T>
void sort_vec(vector<T>& Vect1) {
    T temp;
    for (int i = 0; i < Vect1.size() - 1; i++) {
        for (int j = 0; j < Vect1.size() - i - 1; j++) {
            if (Vect1[j] > Vect1[j + 1]) {
                temp = Vect1[j + 1];
                Vect1[j + 1] = Vect1[j];
                Vect1[j] = temp;
            }
        }
    }
}

template<typename T>
void fill_tree(vector<T>& Vect1, Tree<T>* y) {
    for (int i = 0; i < Vect1.size(); i++) {
        y->insert(Vect1[i]);
    }
}

template<typename T>
bool binary_search(vector<T>& Vect1, T target) {
    int lower_bound = 0;
    int upper_bound = Vect1.size() - 1;
    int midP;
    while (true) {
        if (upper_bound < lower_bound) {
            return false;
        }
        midP = lower_bound + (upper_bound - lower_bound) / 2;

        if (Vect1[midP] == target) {
            return true;
        }
        if (Vect1[midP] < target) {
            lower_bound = midP + 1;
        }
        else {
            upper_bound = midP - 1;
        }
    }
}


template<typename T>
void insert_vec(vector<T>& Vect1, Tree<T>* y) {
    for (int i = 0; i < Vect1.size() - 1; i++) {
        y->insert(Vect1[i]);
    }
}

template<typename T>
void print(vector<T>& Vect1) {
    for (int i = 0; i < Vect1.size() - 1; i++) {
        cout << Vect1[i] << " ";
    }
    cout << endl;
    cout << endl;
    cout << endl;
}


void fill_pointer(Mydata<int>* ptr) {
    int i = 0;
    while (i < ptr->num) {
        ptr->Vec->push_back(rand() % 100 + 1);
        i++;
    }

}

void sort_pointer(Mydata<int>* ptr) {
    int temp;
    for (int i = 0; i < ptr->Vec->size(); i++) {
        for (int j = 0; j < ptr->Vec->size() - i - 1; j++) {
            if (ptr->Vec->at(j) > ptr->Vec->at(j + 1)) {
                temp = ptr->Vec->at(j + 1);
                ptr->Vec->at(j + 1) = ptr->Vec->at(j);
                ptr->Vec->at(j) = temp;
            }
        }
    }
}

void insert_pointer(Mydata<int>* ptr) {
    for (int i = 0; i < ptr->Vec->size(); i++) {
        ptr->x->insert(ptr->Vec->at(i));
    }
}

void print_pointer(Mydata<int>* ptr) {
    for (int i = 0; i < ptr->Vec->size(); i++) {
        cout << ptr->Vec->at(i) << " ";
    }
    cout << endl;
}

template<typename T>
Mydata<T>* makeStruck(size_t size_arry) {
    Mydata<T>* ptr = new Mydata<T>;
    ptr->num = size_arry;
    ptr->Vec = new vector<T>;
    fill_pointer(ptr);
    sort_pointer(ptr);
    insert_pointer(ptr);
    print_pointer(ptr);
    return ptr;
}

template<typename T>
void Time(int Size) {
    int bsearch = 0;
    int bstL = 0;
    T target;
    Mydata<T>* new_thing = new Mydata<T>;
    new_thing->num = Size;
    fill_vector(new_thing->Vect1, new_thing->num);
    insert_vec(new_thing->Vect1, new_thing->x);
    sort_vec(new_thing->Vect1);
    for (int g = 0; g < 100; g++) {
        target = new_thing->Vect1.at(rand() % (new_thing->Vect1.size()));
        bsearch = time(0) - bsearch;
        binary_search(new_thing->Vect1, target);
        bsearch = bsearch + time(0);

        bstL = time(0) - bstL;
        new_thing->x->member(target);
        bstL = bstL + time(0);
    }
    cout << "\nSize of Vector " << Size << endl;
    cout << "Total time for both searches(Binary search, Binary lookup) " << bsearch << " " << bstL << endl;
    cout << "The average time for each search(Binary search, Binary lookup) " << bsearch / 100 << " " << bstL / 100 << endl;
}

int main()
{

    Mydata<int> data;

    fill_vector<int>(data.Vect1, 100);
    sort_vec<int>(data.Vect1);
    bool Breturn = binary_search<int>(data.Vect1, 1000);
    cout << Breturn << endl;
    Breturn = binary_search<int>(data.Vect1, data.Vect1[0]);
    cout << Breturn << endl;
    cout << endl;
    insert_vec(data.Vect1, data.x);
    print(data.Vect1);


    Mydata<int>* point;
    point = makeStruck<int>(16);

    Time<int>(1000);
    Time<int>(10000);
    Time<int>(100000);
}