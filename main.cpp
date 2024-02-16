#include "Account.h"
#include "Bank.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void saveAccountsToFile(const Account& account, const std::string& filename) {
    std::ofstream outputFile(filename);
    if (outputFile.is_open()) {
        const Customer& accountHolder = account.getCustomer();
        outputFile << account.getAccountNumber() << ","
            << accountHolder.getFirstName() << ","
            << accountHolder.getLastName() << ","
            << account.getBalance() << std::endl;

        outputFile.close();
        std::cout << "Account saved to file: " << filename << std::endl;
    }
    else {
        std::cout << "Unable to open file: " << filename << std::endl;
    }
}

void loadAccountFromFile(Account& account, const std::string& filename) {
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            std::istringstream iss(line);
            std::string number, firstName, lastName;
            double balance;

            if (getline(iss, number, ',')) {
                account.setAccountNumber(number);
                getline(iss, firstName, ',');
                getline(iss, lastName, ',');
                iss >> balance;
                iss.ignore();

                Customer accountHolder(firstName, lastName);
                account.setAccountHolder(accountHolder);
                account.setBalance(balance);

                std::cout << "Account Number: " << number << std::endl;
                std::cout << "First Name: " << firstName << std::endl;
                std::cout << "Last Name: " << lastName << std::endl;
                std::cout << "Balance: " << balance << std::endl;
                std::cout << std::endl;
                break;
            }
        }
        file.close();
    }
    else {
        std::cerr << "Error: Unable to open the file." << std::endl;
    }
}

int main() {
    // Menu loop
    Bank bank("My Bank");
    int choice;
    Account currentAccount;
    bool exitProgram = false;


    do {
        std::cout << "********** Bank System Menu **********" << std::endl;
        std::cout << "1. Create an account" << std::endl;
        std::cout << "2. Deposit" << std::endl;
        std::cout << "3. Withdraw" << std::endl;
        std::cout << "4. Display account information" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "**************************************" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            // Create a new account
            Account* newAccount = Account::createAccount();
            if (newAccount != nullptr) {
                std::cout << "Account created successfully." << std::endl;
                saveAccountsToFile(*newAccount, "account.txt");
                newAccount->displayAccountInfo();
            }
            break;
        }
        case 2: {
            // Deposit money into an account
            std::string accountNumber;
            double amount;
            std::cout << "Enter account number: ";
            std::cin >> accountNumber;
            std::cout << "Enter deposit amount: ";
            std::cin >> amount;

            currentAccount.setAccountNumber(accountNumber);
            loadAccountFromFile(currentAccount, "account.txt");

            currentAccount.Deposit(amount);
            std::cout << "Deposit successful!" << std::endl;
            saveAccountsToFile(currentAccount, "account.txt");

            break;
        }
        case 3: {
            // Withdraw money from an account
            std::string accountNumber;
            double amount;
            std::cout << "Enter account number: ";
            std::cin >> accountNumber;
            std::cout << "Enter withdrawal amount: ";
            std::cin >> amount;

            currentAccount.setAccountNumber(accountNumber);
            loadAccountFromFile(currentAccount, "account.txt");

            currentAccount.Withdraw(amount);
            std::cout << "Withdrawal successful!" << std::endl;
            saveAccountsToFile(currentAccount, "account.txt");

            break;
        }
        case 4: {
            // Display account information
            std::string accountNumber;
            std::cout << "Enter account number: ";
            std::cin >> accountNumber;
            currentAccount.setAccountNumber(accountNumber);
            loadAccountFromFile(currentAccount, "account.txt");
            break;
        }
        case 5:
            // Exit the program
            std::cout << "Exiting..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
        std::cout << std::endl;

        if (!exitProgram) {
            char option;
            std::cout << "Do you want to return to the menu? (Y/N): ";
            std::cin >> option;
            if (option == 'N' || option == 'n') {
                exitProgram = true;
            }
        }

        std::cout << std::endl;

    } while (!exitProgram);

        std::cout << std::endl;



return 0;
}