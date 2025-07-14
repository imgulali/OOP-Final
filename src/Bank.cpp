#include "Bank.h"
#include "Customer.h"
#include "Manager.h"
#include "Teller.h"
#include "utils.h"


vector<Customer>& Bank::getCustomers() { return customers; }
vector<Teller>& Bank::getTellers() { return tellers; }
vector<Manager>& Bank::getManagers() { return managers; }
vector<AccountRequest>& Bank::getAccountRequests() { return accountRequests; }

void Bank::createAccountRequest(const AccountRequest &req) {
    accountRequests.push_back(req);
    showAlert("Account request submitted. Awaiting manager approval.");
}
bool Bank::approveAccountRequest(const string &requestID) {
    for (auto &req : accountRequests) {
        if (req.requestID == requestID && !req.processed) {
            string newID = generateID("CUS", customers.size() + 1);
            Customer c(newID, req.name, req.accountType);
            c.setPassword(req.password);
            customers.push_back(c);
            req.approved = true;
            req.processed = true;
            cout<<"Id: "<< newID << endl;
            return true;
        }
    }
    return false;
}

bool Bank::rejectAccountRequest(const string &requestID) {
    for (auto &req : accountRequests) {
        if (req.requestID == requestID && !req.processed) {
            req.approved = false;
            req.processed = true;
            return true;
        }
    }
    return false;
}
