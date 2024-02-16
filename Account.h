#include <string>
#include "Customer.h"
#ifndef ACCOUNT_H
#define ACCOUNT_H
class Account {
protected:
    string accountNumber;
    double Balance;
    Customer accountHolder;


public:
    Account();
    Account(const std::string& accNumber, const std::string& fName, const std::string& lName, double initialBalance);
    void Deposit(double amount);
    void Withdraw(double amount);
    virtual void displayAccountInfo() const;
    const std::string& getAccountNumber() const;
    bool operator==(const std::string& accNumber) const;
    double getBalance() const;
    Customer getCustomer() const;
    static Account* createAccount();
    void setBalance(double newBalance);
    void setAccountNumber(const std::string& accNumber);
    void setAccountHolder(const Customer& customer);

};


class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(const std::string& accNumber, const Customer& cust, const std::string& fName, const std::string& lName, double interestRate);
    void displayAccountInfo() const override;
    void addInterest();
};
class CheckingAccount : public Account {
private:
    double transactionFee;

public:
    CheckingAccount(const std::string& accNumber, const Customer& cust, const std::string& fName, const std::string& lName, double transactionFee);
    void displayAccountInfo() const override;
    void deductTransactionFee();
};

#endif