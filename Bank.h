#include "Account.h"
#include <vector>

class Bank {
private:
	string bankName;
	vector<Account*> accounts;

public:
	Bank(const string& name);
	void addAccount(Account* account);
	bool removeAccount(const string& accountNumber);
	Account* findAccount(const string& accountNumber) const;
	void displayAllAccounts() const;
	void displayBankInfo() const;
	int getNumberOfCustomers() const;
	//void saveAccountsToFile() const;
	//void loadAccountsFromFile();

	~Bank();
};