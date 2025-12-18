#include "IntVector.hpp"

#include <iostream>
    /* private copy function, takes two int pointers and returns void */
    void IntVector::copy(int* oldArray, int* newArray) {
        // loop through oldArray items and copy them into newArray
        for (int i = 0; i < size; i++) {
            *(newArray + i) = *(oldArray + i);
        }
    }

    // default constructor
    IntVector::IntVector() {
        capacity = 1;
        size = 0;
        values = new int[1]; // dynamic array of ints (size 1)
    }

    // constructor with startingCapacity
    IntVector::IntVector(int startingCapacity) {
        capacity = startingCapacity;
        size = 0;
        values = new int[startingCapacity]; // dynamic array of ints
    }

    // constructor with many inputs
    IntVector::IntVector(int startingCapacity, int* initValues) {
        capacity = startingCapacity; // set capacity to the starting capacity
        size = capacity; // initValues has a size of startingCapacity
        values = new int[size]; // dynamic array of ints

        // copy values from initValues to values array
        copy(initValues, values);
    }

    // destructor
    IntVector::~IntVector() {
        delete[] values; // free up dynamic memory

        std::cout << "An IntVector has been destructed." << std::endl;
    }

    // function to get capacity
    int IntVector::getCapacity() {
        return capacity;
    }

    // function to get size
    int IntVector::getSize() {
        return size;
    }

    // function to help append to values
    void IntVector::appendHelper(int value) {
        // place value at back of the values array
        *(values + size) = value;
        ++size; // increment size
    }

    /* append function, takes a newValue int, adjusts 
    capacity if necessary, and returns void */
    void IntVector::append(int newValue) {
        // check if IntVector has room for a new value
        if ((size == 0) && (size != capacity) || size != capacity) { // check if IntVector empty or size greater than 0
            // place newValue at back of the values array (spot size)
            appendHelper(newValue);
        } 
        else { // IntVector is at capacity
            // create a new array with twice capacity of current array
            int newCapacity = 2*capacity;
            int* newValues = new int[newCapacity];
            // copy old array's values into newValues
            copy(values,newValues);

            delete[] values; // free memory of values array
            values = newValues; // set values to point to newValues array
            capacity = newCapacity; // set capacity to new capacity

            // append new value to values array
            appendHelper(newValue);
        }
    }

    /* get value function, takes an index and returns 
        an integer located at that index in the intvector */
    int IntVector::getValue(int index) {
        if (index >= 0 && index < size) {
            return values[index]; // found item
        } else {
            // display message to user that index is out of bounds
            std::cout << "Index is not within the size of the array." << std::endl;
            return -1;
        }
    }

