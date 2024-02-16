#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Customer {
	string firstName, lastName;

public:
	Customer();
	Customer(const string& first, const string& last);


	string getFirstName() const;

	string getLastName() const;


};
#endif
