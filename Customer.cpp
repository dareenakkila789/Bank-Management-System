#include "Customer.h"
#include <iostream>
#include <fstream>
using namespace std;
Customer::Customer() {};

Customer::Customer(const string& fName, const string& lName)
    : firstName(fName), lastName(lName) {
}

string Customer::getFirstName() const {
    return firstName;
}

string Customer::getLastName() const {
    return lastName;
}

