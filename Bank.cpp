#include "Bank.h"
#include "Account.h"
#include <iostream>

Bank::Bank(const std::string& name)
    : bankName(name) {
}

void Bank::addAccount(Account* account) {
    try {
        accounts.push_back(account);
    }
    catch (const std::exception& e) {
        throw std::runtime_error("Exception occurred while adding an account: " + std::string(e.what()));
    }
}


bool Bank::removeAccount(const std::string& accountNumber) {
    try {
        for (auto it = accounts.begin(); it != accounts.end(); ++it) {
            if ((*it)->getAccountNumber() == accountNumber) {
                delete* it;
                accounts.erase(it);
                return true; // Account successfully removed
            }
        }
    }
    catch (const std::exception& e) {
        throw std::runtime_error("Exception occurred while removing an account: " + std::string(e.what()));
    }
    return false; // Account not found
}

Account* Bank::findAccount(const std::string& accNumber) const {
    try {
        for (const Account* account : accounts) {
            if (*account == accNumber) {
                return const_cast<Account*>(account);
            }
        }
        throw "Account not found.";
    }
    catch (const char* errorMessage) {
        std::cout << "Error: " << errorMessage << std::endl;
        return nullptr;
    }
}
void Bank::displayAllAccounts() const {
    try {
        std::cout << "Bank Accounts:" << std::endl;
        for (Account* account : accounts) {
            account->displayAccountInfo();
            std::cout << "-----------------------" << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cout << "Exception occurred while displaying all accounts: " << e.what() << std::endl;
    }
}

void Bank::displayBankInfo() const {
    try {
        std::cout << "Bank Name: " << bankName << std::endl;
        std::cout << "Number of Accounts: " << accounts.size() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception occurred while displaying bank info: " << e.what() << std::endl;
    }
}
int Bank::getNumberOfCustomers() const {
    try {
        return accounts.size();
    }
    catch (const std::exception& e) {
        std::cout << "Exception occurred while getting the number of customers: " << e.what() << std::endl;
        return -1;
    }
}

Bank::~Bank() {
    try {
        for (Account* account : accounts) {
            delete account;
        }
        accounts.clear();
    }
    catch (const std::exception& e) {
        std::cout << "Exception occurred while destructing the bank: " << e.what() << std::endl;
    }
}



















