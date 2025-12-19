#include "BankAccount.hpp"

    // function to get balance, returns double
    double BankAccount::get_balance() {
        return balance;
    }

    // function to get first name, returns string
    std::string BankAccount::get_first_name() {
        return first_name;
    }

    // function to get last name, returns string
    std::string BankAccount::get_last_name() {
        return last_name;
    }

    // function to set first name, takes a new first name as string and returns void
    void BankAccount::set_first_name(std::string new_first) {
        first_name = new_first; // set first name to new first name
    }

    // function to set last name, takes a new last name as string and returns void
    void BankAccount::set_last_name(std::string new_last) {
        last_name = new_last; // set last name to new last name
    }

    // function to deposit amount into account, returns bool indicating success of operation
    bool BankAccount::deposit(double amount) {
        // check to see if deposit amount is valid, should not be zero or negative
        if (amount > 0) {
            balance += amount; // add amount to balance
            return true; 
        } else { // amount is invalid 
            // display message to user about invalid amount
            std::cout << "Invalid amount to deposit. Amount cannot be negative or zero." << std::endl;
            return false; // unsuccessful deposit
        }
    }

    // function to withdraw amount from account, returns bool indicating success of operation
    bool BankAccount::withdraw(double amount) {
        // check if withdrawal amount is valid, should not be zero or negative
        if (amount > 0) {
            // check if user's balance meets conditions for withdrawal
            if (balance >= amount) {
                balance -= amount; // deduct amount from balance
                return true; // withdrawal has been processed
            } else { // balance is too low for withdrawal
                // display message to user about low balance
                std::cout << "Invalid amount to withdraw. Amount cannot be greater than balance." << std::endl;
                return false;
            }
        } else { // handle case where user enters a negative or zero amount
            // display message to user about invalid amount
            std::cout << "Invalid amount to withdraw. Amount cannot be negative or zero." << std::endl;
            return false; // unsuccessful withdraw
        }
    }
