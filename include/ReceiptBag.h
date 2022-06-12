/*
 File:   bag.h
Author: Aleksandr Gryzlov
Purpose:
Implement the Bag receipt using bag.h
*/

#pragma once
#include <iostream>
#include "list.h"

template <typename Thing>
class ReceiptBag {
public:
    bag() {
        bagContents = new List<Thing*>;
        bagContents[0] = nullptr;
    }
    ~bag() {
        delete[] bagContents;
        bagContents = nullptr;
    }
    void insert(Thing aThing) {
        bagContents.push_back(&aThing);
    }
    void delet(Thing aThing) {
        bagContents.delete(&aThing);
    }
    Thing& pop() {
        Thing* ptrToAThing;
        int i = bagContents.size();
        bool thingIsNull = true;
        while (thingIsNull && (i > 0)) {
            if (bagContents[i] != nullptr) {
                ptrToAThing = bagContents[i];
                thingIsNull = false;
            }
        }
    }
    int size() {
        return bagContents.capacity();
    }
    int count() {
        return bagContents.size();
    }
private:
    List<Thing*>* bagContents;
	int receipt = 0;
};
