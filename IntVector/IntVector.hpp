#ifndef INTVECTOR_HPP  
#define INTVECTOR_HPP

class IntVector {
    private:
        int capacity;
        int size;
        int* values; // keeps track of items in vector

        /* copy function, takes two int pointers and returns void */
        void copy(int* oldArray, int* newArray);
    public:
        // default constructor
        IntVector();

        // constructor with startingCapacity
        IntVector(int startingCapacity);

        // constructor with many inputs
        IntVector(int startingCapacity, int* initValues);

        // destructor
        ~IntVector();

        // function to get capacity
        int getCapacity();

        // function to get size
        int getSize();

        // function to help append to values
        void appendHelper(int value);

        /* append function, takes a newValue int, adjusts 
        capacity if necessary, and returns void */
        void append(int newValue);

        /* get value function, takes an index and returns 
        an integer located at that index in the intvector */
        int getValue(int index);
};

#endif