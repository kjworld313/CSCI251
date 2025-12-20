# Software Design Course Portfolio

***

## Directory Information
The directory 'individual_projects' contains two directories: int_vector and bank_app. The int_vector directory contains a self-implemented IntVector class. The bank_app directory includes a banking software with bank account classes and utility functions.

## IntVector Project Information (individual_projects/int_vector)
### Details:
Designed a custom `IntVector` class for integer data. Program allows users to append integers and prints a sum of the selected integers. 
### Language:
C++
### Technical Details:
Implemented Object-Oriented Programming concepts, including Polymorphism (function overloading), Abstraction (header file + implementation file), and Encapsulation (private and public access specifiers in IntVector, accessor and mutator functions). `IntVector` class includes three constructors, a destructor that frees dynamic memory, and several additional functions:
- `copy`: copies values from current array to a new dynamic array
- `append`: adds new items to the array and calls `copy` to expand vector when more capacity is required.

Main prompts user for integers and validates input in a loop. If user input is invalid (ie. input is of non-integer type), the loop is terminated. Program computes and prints total sum of integers stored in the IntVector instance.

## Bank Application Project Information (individual_projects/bank_app)
### Details:
Designed a C++ banking software program that allows users to create accounts, view account details, and perform various account operations including deposits, interest accrual, and withdrawals. I prioritized thorough documentation, object-oriented design, implementation of SOLID principles, and informative user-oriented reports.
### Language:
C++
### Technical Details:
Implemented Object-Oriented Programming concepts, including Polymorphism (function overloading + overriding), Abstraction (header files + implementation files, abstract BankAccount class), Encapsulation (private and public access specifiers for data protection), and Inheritance (BankAccount extends SavingAccount and CheckingAccount). `BankAccount` class is an abstract class that serves as a base for various specialized account types. The class contains initializer list constructors, a virtual destructor, and several additional functions:
- `deposit`: deposits an amount into an account
- `withdraw`: withdraws an amount from an account
- `toString`: a pure virtual function

Derived classes of `BankAccount`:
 - `SavingAccount`: has an interest rate member and `accrueInterest` function
 - `CheckingAccount`: maintains a check log and `writeCheck` function

Utils contains functions for account creation, retrieval/conversion of inputs/data types, and account status to further abstract program. Main prompts menu of options to user, validates user input + informs of and handles bad input, and performs operations on a map containing accounts with usernames as keys. Program frees dynamically allocated BankAccount pointers from map at end of program.
- Focused on incorporating aspects of SOLID principles into program; BankAccount is closed for modification
  but open for extension with specialized children classes to ensure simplicity and lower chance of code
  breakage. 

## Important Notes
These projects require C++11 or higher to compile.

## Program Instructions
In order to compile int_vector program, use the 'g++ IntVector.cpp main.cpp' in the terminal. For bank_app, use 'g++ main.cpp BankAccount.cpp CheckingAccount.cpp SavingAccount.cpp Utils.cpp'

## Author
Author: Katelynn Olson

Thanks to [makeareadme.com](https://www.makeareadme.com/) for this template.
