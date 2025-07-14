#ifndef CUSTOMER_H
#define CUSTOMER_H

#include"User.h"
#include"AccountRequest.h"
#include"Bank.h"

class Customer : public User {
private:
    string accountType;
    double balance;
    bool hasActiveLoan;

public:
    Customer() = default;
    Customer(const string &id, const string &name, const string &accountType, double balance=0.0, bool hasLoan=false)
        : User(id, name), accountType(accountType), balance(balance), hasActiveLoan(hasLoan) {}


    string getAccountType() const{ return accountType;}
    double getBalance() const{ return balance; }

    static Customer* login(vector<Customer>& customers);
    void requestAccount(Bank &bank);
    void displayMenu(Bank &bank) override;

    void withdraw();
    void deposit();
    void transfer(Bank& bank);

    void addBalance(double amount) { balance += amount; }
    bool deductBalance(double amount) { if(balance >= amount){ balance -= amount; return true; } return false; }
};
#endif