#pragma once
/*
File:   Array.h
Author: Aleksandr Gryzlov
Purpose:
A simplifed version of the C++ STL vector class
*/

#pragma once
#include <iostream>

template <typename T>
class vector {
public:
	vector() {
		arr = new T[1];
		vCapacity = 1;
		length = 0;
	}
	~vector() {
		delete[] arr;
		arr = nullptr;
	}

	void put(T data, int index) {
		if (index == vCapacity) {
			push_back(T data);
		}
		else {
			arr[index] = data;
		}
	}

	void push_back(T data) {
		/* if number of elements is equal to capacity
		than we need to reallocate and deep copy */
		if (length == vCapacity) {
			expand(2 * vCapacity);
		}
		arr[length] = data;
		length++;
	}

	T& at(int index) {
		if (index < 0 || index > length) {
			cerr << "Vector: index out of bounds on access" << endl;
			exit(1);
		}
		else {
			return arr[index];
		}
	}

	int size() {
		return length;
	}

	int capacity() {
		return vCapacity;
	}

	int size_t() {
		return size_t;
	}

	void traverse() {
		for (int i = 0; i < length; i++) {
			cout << arr[i] << endl;
		}
		cout << endl;
	}

	bool operator==(Vector& other) const {
		if (other.size() != length) {
			return false;
		}
		else {
			for (int i = 0; i < length; i++) {
				if (arr[i] != other.get(i)) {
					return false;
				}
			}
		}
		return true;
	};

	T& operator[](int i) {
		if ((i < 0) || (i >= length)) {
			cerr << endl << "Vector index out of bounds" << endl;
		}
		return at(i);
	}

	vector& operator=(const Vector& source) {
		// Do a self check.
		if (this == &source)
		{
			return *this;
		}
		// Reset self
		delete[] arr;
		arr = new T[1];
		vCapacity = 1;
		length = 1;
		for (int i = 0; i < source.size(); i++) {
			push_back(source.at(i));
		}
		return *this;
	}
private:
	T* arr = new T[1];
	int vCapacity = 1;
	int length = 1;
	int size_t = 1;

	void setSize() {
		if (size_t > vCapacity) {
			T* temp = new T[size_t];
			for (int i = 0; i < length; i++) {
				temp[i] = arr[i];
			}
			delete[] arr;
			vCapacity = size_t;
			arr = temp;
		}
		else {
			std::cerr << "size of array can't less than 1\n";
		}
	}
}