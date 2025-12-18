#include "Utils.hpp"

// function takes no input, prints a message about account status
void display_account_status() {
    std::cout << "An account under that username does not exist." << std::endl;
}

/* function to check if an account is active in a map containing accounts,
takes a string representing an account username and a map, then returns the existence
status of the account */
bool is_account_active(std::string username, std::map<std::string, BankAccount*> accounts) {
    // declare a boolean to store account status
    bool is_active; 

    // declare and initialize an iterator to find account in map
    auto find_account = accounts.find(username);

    // check to see if the account exists in the system, assign result to is_active boolean
    is_active = (find_account != accounts.end());

    // return the status of the account (exists or does not exist in system)
    return is_active;
}

/* function that takes a string representing the type of operation, prompts user for an account name,
and returns the account username */ 
std::string get_username(std::string prompt) {
    // create a variable to store the account name
    std::string username;

    // ask user prompt
    std::cout << prompt;
    std::cin >> username; // store user input in username 

    // return username
    return username;
}


// function that takes no input, prints an error message about bad input, and returns nothing
void display_bad_input() {
    // display message to user about invalid input
    std::cerr << "Bad input. Exiting current operation." << std::endl;
}


// function that takes a string and an address to a boolean as input, prompts user for an amount, converts it to type double, updates boolean, and returns the amount
double get_amount(std::string prompt, bool& is_valid) {
    // prompt user for amount 
    std::cout << prompt;

    // get amount from user in form of string
    std::string amount_string;
    std::cin >> amount_string;

    // convert amount string to double
    double amount = convert_string_double(amount_string, is_valid);

    return amount; // return the amount
}

// function that takes a string and an address to a boolean as input, converts string to a double and updates boolean, and returns converted amount
double convert_string_double(std::string amount_string, bool& is_valid) {
    char* end_of_string; // create a pointer to a char to track end of string

    // convert amount_string to type double
    double amount = strtod(amount_string.c_str(), &end_of_string); // convert string
    is_valid = *end_of_string == '\0'; // update is_valid boolean, if true, amount is valid

    return amount; // return the converted amount
}

/* function that takes an address to a string representing first name and an address to a string representing last name,
function alters arguments and returns nothing */
void get_user_information(std::string& first_name, std::string& last_name) {
    // prompt user for a first name for the bank account
    std::cout << "Enter a first name for your BankAccount: ";

    // store user information about first name
    std::cin >> first_name;

    // prompt user for a last name for the bank account
    std::cout << "Enter a last name for your BankAccount: ";

    // store user information about last name
    std::cin >> last_name;
}

/* function that takes in no input, gets inputs from user to construct account, constructs the account, 
and returns a pointer to a BankAccount */
BankAccount* make_account() {
    // declare BankAccount pointer and initialize to nullptr
    BankAccount* account_ptr = nullptr;

    // initialize first_name and last_name for account personal information fields
    std::string first_name;
    std::string last_name;
    
    // prompt user for information and store to first_name and last_name
    get_user_information(first_name, last_name);

    // prompt user to determine whether to create a saving or checking account
    std::cout << "Would you like to create a Saving Account (Enter 1) or a Checking Account? (Enter 2): ";

    // store user option
    std::string option;
    std::cin >> option;

    // handle cases
    // check if user wants to make a saving account
    if (option == "1") { // create a saving account

        // declare is_valid boolean to determine if amount is valid
        bool is_valid;
        double interest_rate = get_amount("Enter the interest rate of the account (Accepted Range: 0-1): ", is_valid); // get interest rate for account from user
        
        // check if user entered a valid input and interest rate is between 0 and 1
        if (is_valid && (interest_rate >= 0 && interest_rate <= 1)) { // create a new saving account
            SavingAccount* saving_account = new SavingAccount(first_name, last_name, 0.00, interest_rate); // default balance of 0
            account_ptr = saving_account; // set BankAccount pointer to the created saving account
        } else { // user input is invalid
            display_bad_input(); // display error message
        }

        return account_ptr; // return pointer to saving account (if user input was valid)
    }
    // check if user wants to make a checking account
    else if (option == "2") { // create a checking account
        // create a new checking account with first name and last name
        CheckingAccount* checking_account = new CheckingAccount(first_name, last_name);
        account_ptr = checking_account; // set BankAccount pointer to the created checking account

        return account_ptr; // return pointer to checking account 
    } else { // user input is invalid
        display_bad_input(); // display error message
        return account_ptr; // return a nullptr
    }
}