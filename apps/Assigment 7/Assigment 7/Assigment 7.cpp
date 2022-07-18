#include <iostream>
#include <list>
#include "Tree.h"

using namespace std;


template<typename T>
list<T>* Ascending(Tree<T>& xtree) {
    list<T>* mylist = new list<T>;

    list<T>* rlist = new list<T>;
    if (xtree.isEmpty())
        return new list<T>();
    T currNode = xtree.root();
    Tree<T> l, r;
    l = xtree.left();
    r = xtree.right();
    mylist = Ascending<T>(l);
    mylist->push_back(currNode);
    rlist = Ascending<T>(r);
    while (rlist->size() != 0) {
        mylist->push_back(rlist->front());
        rlist->pop_front();
    }
    return mylist;
}

template<typename T>
list<T>* Descending(Tree<T>& xtree) {
    list<T>* descend = new list<int>();
    list<T>* mylist = Ascending(xtree);
    while (mylist->size() != 0) {
        descend->push_front(mylist->front());
        mylist->pop_front();
    }
    return descend;
}

void print(list<int>* x) {
    while (x->size() != 0) {
        cout << x->front() << " ";
        x->pop_front();
    }
    cout << endl;
}

int main()
{
    Tree<int> X;

    for (int i = 0; i < 14; i++) {
        X = X.insert(rand() % 100 + 1);
    }
    list<int>* ascList = Ascending<int>(X);
    cout << " Ascending order " << endl;
    print(ascList);
    cout << endl;

    list<int>* descList = Descending<int>(X);
    cout << " Descending order " << endl;
    print(descList);

    return 0;
}