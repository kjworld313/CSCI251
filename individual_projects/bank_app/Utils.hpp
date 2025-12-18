#include "BankAccount.hpp"
#include "SavingAccount.hpp"
#include "CheckingAccount.hpp"

#include <map>

// function takes no input, prints a message about account status
void display_account_status();

/* function to check if an account is active in a map containing accounts,
takes a string representing an account username and a map, then returns the existence
status of the account */
bool is_account_active(std::string username, std::map<std::string, BankAccount*> accounts); 

/* function that takes a string representing the type of operation, prompts user for an account name,
and returns the account username */ 
std::string get_username(std::string prompt);

// function that takes no input, prints a message about bad input, and returns nothing
void display_bad_input();

// function that takes a prompt as input, prompts user to enter input, and returns the amount after conversion
double get_amount(std::string prompt, bool& is_valid);

// function that takes a string and a pointer to a character as input, converts string to a double, and returns converted amount
double convert_string_double(std::string amount_string,  bool& is_valid);

/* function that takes an address to a string representing first name and an address to a string representing last name,
function alters arguments and returns nothing */
void get_user_information(std::string& first_name, std::string& last_name);

/* function that takes in no input, gets inputs from user to construct account, constructs the account, 
and returns a pointer to a BankAccount */
BankAccount* make_account();