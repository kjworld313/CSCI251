#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP

#include <iostream>

class BankAccount {
    private:
        double balance;
    public: 
        std::string first_name;
        std::string last_name;

        // public constructor for first name, last name, and private variable(s)
        BankAccount(std::string first, std::string last, double starting_balance) : first_name(first), last_name(last),
        balance(starting_balance) {};

        // public constructor for public variable(s), set default balance 
        BankAccount(std::string first, std::string last) : first_name(first), last_name(last),
        balance(0.00) {};

        // public virtual destructor
        virtual ~BankAccount() {}

        // function to get balance, returns double
        double get_balance();

        // function to get first name, returns string
        std::string get_first_name();

        // function to get last name, returns string
        std::string get_last_name();

        // function to set first name, takes a new first name as string and returns void
        void set_first_name(std::string new_first);

        // function to set last name, takes a new last name as string and returns void
        void set_last_name(std::string new_last);

        // function to deposit amount into account, returns bool indicating success of operation
        bool deposit(double deposit_amount);

        // function to withdraw amount from account, returns bool indicating success of operation
        bool withdraw(double withdrawal_amount);

        // pure virtual function that takes no arguments and returns a string
        virtual std::string to_string() = 0;

};

#endif