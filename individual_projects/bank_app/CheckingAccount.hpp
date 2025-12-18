#ifndef CHECKINGACCOUNT_HPP
#define CHECKINGACCOUNT_HPP

#include "BankAccount.hpp"
#include <list>

class CheckingAccount : public BankAccount {
    private:
        std::list<double> check_log;
    public:
        // constructor taking in values to set all member variables and default check_log to empty list
        CheckingAccount(std::string first, std::string last, double starting_balance) : BankAccount(first, last, starting_balance), 
        check_log({}) {}

        // constructor taking in values for first and last name, where check_log is an empty list
        CheckingAccount(std::string first, std::string last) : BankAccount(first, last), 
        check_log({}) {}

        // public virtual destructor
        virtual ~CheckingAccount() {}

        // function to get check_log, takes no arguments and returns a list of doubles
        std::list<double> get_check_log();

        /* function that takes in a reference to a bank account (target_account), a double, amount, and attempts to deposit amount in 
        bank account, attempts to withdraw amount from account writing check, and deposit in account taken as input and
        returns a boolean indicating success of operation */
        bool write_check(BankAccount& target_account, double amount);
        
        // function that takes no inputs and returns a string
        std::string to_string();
};

#endif