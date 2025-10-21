#include "IntVector.hpp"

#include <iostream>
#include <stdlib.h>

int main() {
    // create empty IntVector
    IntVector defaultVector;

    bool isInputValid = true;

    // loop to ask user for integers to add to a vector
    while (isInputValid) {
        // declare userInput to hold user input
        char userInput[800]; // going to set to a random large number just in case
        
        // ask users for integer to add to the IntVector
        std::cout << "Enter integer to add to the IntVector: ";
        std::cin >> userInput;

        // set a character pointer to address of userInput for use in strtol()
        char* charPointer = userInput;
        char* charTracker; // used to track characters in char array
        // convert user input to integer (referenced cplusplus.com and documentation of strtol here)
        int integer = strtol(charPointer, &charTracker, 0); 

        /* check if user entered something other than an int

        cplusplus.com states charTracker is a nullpointer if not used (does not find a character after a numerical value)
        can check also to see if charTracker found a character and set to false because a number with a character in it is not a
        real integer
        
        also want to allow user to add 0 since 0 is an integer so compare charPointer's value to '0' */
        bool isIntegerZero = *charPointer == '0'; 
        if (!integer && !isIntegerZero) { // end while loop
            isInputValid = false;
        } 
        // hardware ASCII -> strings end with null so charTracker will be a nullptr, check if not '\0'
        else if (!isIntegerZero && *charTracker != '\0') { 
            isInputValid = false;
        }
        else { // append to empty IntVector, integer is valid
            defaultVector.append(integer);
        }
    } // end while loop

    // add all values in the default IntVector together and print them to user
    int defaultIVSum = 0; // default IntVector sum
    std::cout << "\nPrinting and summing values of defaultVector..." << std::endl;
    for (int i = 0; i < defaultVector.getSize(); i++) {
        int currentValue = defaultVector.getValue(i); // grab current value
        std::cout << currentValue << std::endl;
        defaultIVSum += currentValue; // add currentValue to the sum
    }
    std::cout << "Sum of defaultVector is " << defaultIVSum << "\n" << std::endl;

    // create an IntVector with multi-input constructor
    int sourceVector[5] = {1,2,3,4,5};
    IntVector nonDefaultVector(5,sourceVector);

    // sum the vector's values and print them
    int nonDefaultIVSum = 0;
    std::cout << "Printing and summing values of nonDefaultVector..." << std::endl;
    for (int i = 0; i < nonDefaultVector.getSize(); i++) {
        int currentValue = nonDefaultVector.getValue(i); // grab current value
        std::cout << currentValue << std::endl;
        nonDefaultIVSum += currentValue;
    }
    std::cout << "Sum of nonDefaultVector is " << nonDefaultIVSum << std::endl;

    return 0;
}