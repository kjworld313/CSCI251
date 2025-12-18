#include "SavingAccount.hpp"

    // function to get interest_rate, returns double
    double SavingAccount::get_interest_rate() {
        return interest_rate;
    }

    // function to set interest_rate, takes a new interest rate of type double and returns void
    void SavingAccount::set_interest_rate(double new_interest) {
        interest_rate = new_interest;
    }

    // function that calculates interest bank account receives and adjusts balance, returns void
    void SavingAccount::accrue_interest() {
        // initialize interest to current balance multiplied by interest rate
        double interest = get_balance() * interest_rate;

        // deposit accrued interest to balance
        deposit(interest);
    }

    // function that takes no inputs and returns a string
    std::string SavingAccount::to_string() {
        // return a string representing the Saving Account
        return "Saving Account Balance: $" + std::to_string(get_balance()) + ", Interest Rate: " + std::to_string(interest_rate);
    }