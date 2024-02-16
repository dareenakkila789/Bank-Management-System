#include "Account.h"
#include "Customer.h"
#include <iostream>
#include <fstream>
using namespace std;
Account::Account() {};

Account::Account(const std::string& accNumber, const std::string& fName, const std::string& lName, double initialBalance)
    : accountNumber(accNumber), accountHolder(fName, lName), Balance(initialBalance) {
}


// Get the account balance
double Account::getBalance() const {
    return Balance;
}
// Get the account holder information
Customer Account::getCustomer() const {
    return accountHolder;
}
void Account::setBalance(double newBalance) {
    Balance = newBalance;
}
void Account::setAccountNumber(const std::string& accNumber) {
    accountNumber = accNumber;
}
void Account::setAccountHolder(const Customer& customer) {
    accountHolder = customer;
}
// Deposit funds into the account
void Account::Deposit(double amount) {
    Balance += amount;
    cout << "Deposit successful. New balance: " << Balance << endl;
}
// Withdraw funds from the account
void Account::Withdraw(double amount) {
    try {
        if (Balance >= amount) {
            Balance -= amount;
            cout << "Withdrawal successful. New balance: " << Balance << endl;
        }
        else {
            throw "Insufficient funds. Withdrawal canceled.";
        }
    }
    catch (const char* errorMessage) {
        cout << "Error: " << errorMessage << endl;
    }
}
// Display account information
void Account::displayAccountInfo() const {
    cout << "Account Number: " << accountNumber << endl;
    cout << "Account Holder Name: " << accountHolder.getFirstName() << " " << accountHolder.getLastName() << endl;
    cout << "Balance: " << Balance << endl;
}
// Get the account number
const string& Account::getAccountNumber() const {
    return accountNumber;
}
// Compare account number for equality
bool Account::operator==(const std::string& accNumber) const {
    return accountNumber == accNumber;
}
// Create a new account based on user input
Account* Account::createAccount() {
    std::string accNumber;
    std::string fName;
    std::string lName;
    double initialBalance;
    int accountType;

    std::cout << "Enter account number: ";
    std::cin >> accNumber;
    std::cout << "Enter first name: ";
    std::cin >> fName;
    std::cout << "Enter last name: ";
    std::cin >> lName;
    std::cout << "Enter initial balance: ";
    std::cin >> initialBalance;
    std::cout << "Enter account type (1 - Savings, 2 - Checking): ";
    std::cin >> accountType;

    Account* newAccount = nullptr;
    try {
        switch (accountType) {
        case 1: {
            double interestRate = 0.05;
            newAccount = new SavingsAccount(accNumber, Customer(fName, lName), fName, lName, interestRate);
            newAccount->Deposit(initialBalance);  // Deposit the initial balance
            break;
        }
        case 2: {
            double transactionFee = 2.0;
            newAccount = new CheckingAccount(accNumber, Customer(fName, lName), fName, lName, transactionFee);
            newAccount->Deposit(initialBalance);  // Deposit the initial balance
            break;
        }
        default: {
            throw "Invalid account type. Account creation failed.";
        }
        }
    }
    catch (const char* errorMsg) {
        std::cout << "Error: " << errorMsg << std::endl;
        if (newAccount != nullptr) {
            delete newAccount;
            newAccount = nullptr;
        }
    }

    return newAccount;
}
SavingsAccount::SavingsAccount(const std::string& accNumber, const Customer& cust, const std::string& fName, const std::string& lName, double interestRate)
    : Account(accNumber, fName, lName, 0.0), interestRate(interestRate) {
}
void SavingsAccount::addInterest() {
    double interestAmount = Balance * interestRate;
    Balance += interestAmount;
    std::cout << "Interest added. New balance: " << Balance << std::endl;
}

void SavingsAccount::displayAccountInfo() const {
    std::cout << "Savings Account" << std::endl;
    Account::displayAccountInfo();
    std::cout << "Interest Rate: " << interestRate << std::endl;
}


CheckingAccount::CheckingAccount(const std::string& accNumber, const Customer& cust, const std::string& fName, const std::string& lName, double transactionFee)
    : Account(accNumber, fName, lName, 0.0), transactionFee(transactionFee) {
}


void CheckingAccount::deductTransactionFee() {
    double feeAmount = Balance * transactionFee;
    Balance -= feeAmount;
    std::cout << "Transaction fee deducted. New balance: " << Balance << std::endl;
}

void CheckingAccount::displayAccountInfo() const {
    std::cout << "Checking Account" << std::endl;
    Account::displayAccountInfo();
    std::cout << "Transaction Fee: " << transactionFee << std::endl;
}
