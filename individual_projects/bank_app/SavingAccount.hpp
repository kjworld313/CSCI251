#ifndef SAVINGACCOUNT_HPP
#define SAVINGACCOUNT_HPP

#include "BankAccount.hpp"

class SavingAccount : public BankAccount {
    private:
        double interest_rate;
    public:
        // constructor taking in values to set each member variable
        SavingAccount(std::string first, std::string last, double starting_balance, double interest) : BankAccount(first, last, starting_balance),
        interest_rate(interest) {}

        // constructor taking in values for first and last name only, interest rate and balance are default
        SavingAccount(std::string first, std::string last) : BankAccount(first, last), interest_rate(0.00) {}
        // public virtual destructor
        virtual ~SavingAccount() {}

        // function to get interest_rate, returns double
        double get_interest_rate();

        // function to set interest_rate, takes a new interest rate of type double and returns void
        void set_interest_rate(double new_interest);

        // function that calculates interest bank account receives and adjusts balance, returns void
        void accrue_interest();

        // function that takes no inputs and returns a string
        std::string to_string();

};

#endif