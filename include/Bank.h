#ifndef BANK_H
#define BANK_H

#include <vector>
#include <string>
#include "AccountRequest.h"

using namespace std;

class Customer;
class Manager;
class Teller;

class Bank {
private:
    vector<Customer> customers;
    vector<Teller> tellers;
    vector<Manager> managers;
    vector<AccountRequest> accountRequests;

public:
    vector<Customer>& getCustomers();
    vector<Teller>& getTellers();
    vector<Manager>& getManagers();
    vector<AccountRequest>& getAccountRequests();

    void createAccountRequest(const AccountRequest& req);
    bool approveAccountRequest(const string& requestID);
    bool rejectAccountRequest(const string& requestID);
};

#endif