#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include "defs.h"

using namespace std;

template <typename T>
class Array {

	public:
		//constructor
		Array();
				
		//destructor
		~Array();
		
		// Overloaded += operator to add an element.
		Array<T>& operator+=(const T&);
		// Overloaded -= operator to remove an element.
		Array<T>& operator-=(const T&);
		// Overloaded [] operator for non-const access.
		T& operator[](int index);
		// Overloaded [] operator for const access.
		const T& operator[](int index) const;
		int getSize() const;
		bool isFull() const;
		void clear();
	
	private:
		int numElements;
		T* elements;
};

// Constructor
template <typename T>
Array<T>::Array(){
	elements = new T[MAX_ARR];
	numElements = 0;
}

// Destructor
template <typename T>
Array<T>::~Array(){
	delete [] elements;
}

// Overloaded += operator works identically to the original add function.
template <typename T>
Array<T>& Array<T>::operator+=(const T& s){
	if (numElements >= MAX_ARR)
		return *this;
	elements[numElements++] = s;
	return *this;
}

// Overloaded -= operator works identically to the original remove function.
template <typename T>
Array<T>& Array<T>::operator-=(const T& s){
	int index = 0;
	while (index < numElements){
		if (s == elements[index]){
			--numElements;
			break;
		}
		++index;
	}
	while (index < numElements){
		elements[index] = elements[index + 1];
		++index;
	}
	return *this;
}

// Overloaded [] operator for non-const access.
template <typename T>
T& Array<T>::operator[](int index) {
	if (index < 0 || index >= numElements) {
		cerr << "Array index out of bounds" << endl;
		exit(1);
	}
	return elements[index];
}

// Overloaded [] operator for const access.
template <typename T>
const T& Array<T>::operator[](int index) const {
	if (index < 0 || index >= numElements) {
		cerr << "Array index out of bounds" << endl;
		exit(1);
	}
	return elements[index];
}

// Returns the number of elements.
template <typename T>
int Array<T>::getSize() const{
	return numElements;
}

// Checks if the Array is full.
template <typename T>
bool Array<T>::isFull() const {
	return numElements >= MAX_ARR;
}

// Clears all elements by resetting numElements to 0.
template <typename T>
void Array<T>::clear() {
    numElements = 0;
}

#endif