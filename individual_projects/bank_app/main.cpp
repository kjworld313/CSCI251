#include "BankAccount.hpp"
#include "CheckingAccount.hpp"
#include "SavingAccount.hpp"
#include "Utils.hpp"
#include <map>
#include <iostream>

int main() {
    // declare and initialize a map to track BankAccounts and a condition variable
    std::map<std::string, BankAccount*> accounts; // map from a string to a BankAccount pointer
    bool finished = false; // boolean for entering and exiting while loop

    // display welcome message to user
    std::cout << "Welcome to the banking software!" << std::endl;
    // display menu of options to user and handle input cases
    while(!finished){
        std::cout << "Options" << std::endl;
        std::cout << "0) Exit" << std::endl;
        std::cout << "1) Make account" << std::endl;
        std::cout << "2) Deposit to existing account" << std::endl;
        std::cout << "3) Withdraw from existing account" << std::endl;
        std::cout << "4) Display existing account balance" << std::endl;
        std::cout << "5) Accrue Interest" << std::endl;
        std::cout << "6) Write a check" << std::endl;
        std::cout << "What would you like to do (Input single number):" << std::endl;

        // store user input to input_string
        std::string input_string;
        std::cin >> input_string;

        // handle user selected options
        // check if user entered "0" to exit software
        if (input_string == "0") {
            // update finished boolean and display message to user that software has been exited
            finished = true; // set finished boolean to true to exit loop block
            std::cout << "Goodbye! Thank you for supporting our banking software." << std::endl;
        }
        // check if user entered "1" to make an account
        else if (input_string == "1") {
            // prompt user for username, get user input and assign to username
            std::string username = get_username("Enter a username: ");

            // check if an account with that username is active
            if (is_account_active(username, accounts)) { // active, alert user
                std::cout << "Username is taken." << std::endl;
            } else {  // create a bank account
                BankAccount* bank_account = make_account();

                // check if an account was created successfully and add to accounts map if so
                if (bank_account != nullptr) {
                    // pair username as key and account as value
                    std::pair<std::string, BankAccount*> account(username, bank_account);

                    // insert account into accounts
                    accounts.insert(account);
                }
            }
        }
        // check if user entered "2" to deposit to an account
        else if (input_string == "2") {
            // prompt user for username, get user input and assign to username
            std::string username = get_username("Enter the username of account for deposit: ");

            // check if an account with that username is active, if so get information from user for deposit
            if (is_account_active(username, accounts)) {
                // boolean to store validity of conversion
                bool is_valid;
                
                // prompt user for amount to deposit and get amount
                double amount = get_amount("Enter an amount to deposit: ", is_valid); 

                // attempt to deposit amount if conversion was successful
                if (is_valid)
                    accounts[username]->deposit(amount); // deposit
                else { // inform user of bad input
                    display_bad_input();
                }
            } else { // username doesn't exist
                display_account_status(); // inform user
            }
        }
        // check if user entered "3" to withdraw from an account
        else if (input_string == "3") {
            // prompt user for username, get user input and assign to username
            std::string username = get_username("Enter the username of account for deposit: ");

            // check if an account with that username is active, if so get information from user for deposit
            if (is_account_active(username, accounts)) {
                // boolean to store validity of conversion
                bool is_valid;
                
                // prompt user for amount to withdraw and get amount
                double amount = get_amount("Enter an amount to withdraw: ", is_valid); 

                // attempt to withdraw amount if conversion was successful
                if (is_valid) {
                    accounts[username]->withdraw(amount); // withdraw
                } else { // inform user of bad input
                    display_bad_input();
                }
            } else { // username doesn't exist
                display_account_status(); // inform user
            }
        }
        // check if user entered "4" to display an account
        else if (input_string == "4") {
            // prompt user for username, get user input and assign to username
            std::string username = get_username("Enter the username of account to view: ");

            // check if an account with that username is active, if so print account information
            if (is_account_active(username, accounts)) {
                std::cout << accounts[username]->to_string() << std::endl; // display information
            } else { // username doesn't exist
                display_account_status(); // inform user
            }
        }

        // check if user entered "5" to accrue interest on an account
        else if (input_string == "5") {
            // iterate through accounts and accrue interest on savings accounts
            for (auto iterator = accounts.begin(); iterator != accounts.end(); iterator++) {
                // cast BankAccount pointer to a SavingAccount pointer using dynamic cast
                SavingAccount* saving_account = dynamic_cast<SavingAccount*>(iterator->second); // second is BankAccount* (value)

                // check if cast was successful and accrue interest if so
                if (saving_account != nullptr) {
                    saving_account->accrue_interest(); // accrue interest
                }
            }
        }
        // check if user entered "6" to write a check from an account
        else if (input_string == "6") {
            // prompt user for username, get user input and assign to username
            std::string username = get_username("Enter the username of account to write check from: ");

            // check if an account with that username is active, if so get information from user for deposit
            if (is_account_active(username, accounts)) {
                // cast BankAccount pointer associated with username to a CheckingAccount pointer
                CheckingAccount* checking_account = dynamic_cast<CheckingAccount*>(accounts[username]);

                // check if cast was successful and initiate writing check process
                if (checking_account != nullptr) {
                    // prompt user for an account to transfer funds to, get user input and assign to username
                    std::string target_username = get_username("Enter the username of the account to write a check to: ");

                    // check if the account under that username exists
                    if (is_account_active(target_username, accounts)) {
                        // boolean to store validity of conversion
                        bool is_valid;

                        // prompt user for amount of check and get amount
                        double amount = get_amount("Enter the amount of the check: ", is_valid); 

                        // check if amount is a valid double and write check if so
                        if (is_valid) {
                            checking_account->write_check(*accounts[target_username], amount);
                        } else { // inform user of bad input
                            display_bad_input();
                        }
                    } else {
                        display_account_status(); // inform user account is not active
                    }
                }
            } else { // user does not exist
                display_account_status();
            }
        } else { // user entered an invalid option
            // inform user to enter a valid option
            std::cout << "Please enter a valid option from the menu." << std::endl;
        }
    }

    // iterate through accounts and free each bank account from memory
    for (auto iterator = accounts.begin(); iterator != accounts.end(); iterator++) {
        delete iterator->second; // free bank account
    }
    
    return 0;
}
