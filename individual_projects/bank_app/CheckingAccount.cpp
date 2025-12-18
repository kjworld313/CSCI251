#include "CheckingAccount.hpp"

    // function to get check_log, takes no arguments and returns a list of doubles
    std::list<double> CheckingAccount::get_check_log() {
        return check_log;
    }

    /* function that takes in a reference to a bank account (target_account), a double, amount, and attempts to deposit amount in 
    bank account, attempts to withdraw amount from account writing check, and deposit in account taken as input and
    returns a boolean indicating success of operation */
    bool CheckingAccount::write_check(BankAccount& target_account, double amount) {
        if (withdraw(amount)) { // check if this account has funds to withdraw and withdraw if so
            target_account.deposit(amount); // deposit amount in target account
            check_log.push_back(amount); // add amount to bank of check_log

            // write check operation successful
            return true;
        } else { // operation not successful
            return false;
        }
    }

    // function that takes no inputs and returns a string
    std::string CheckingAccount::to_string() {
        // return a string representing the Checking Account
        return "Checking Account Balance: $" + std::to_string(get_balance()) + ", Checks Written: " + std::to_string(check_log.size());
    }