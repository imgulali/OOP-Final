#ifndef MANAGER_H
#define MANAGER_H
#include"Employee.h"
#include"utils.h"
#include"Bank.h"
#include"AccountRequest.h"

class Manager : public Employee {
public:
    Manager() = default;
    Manager(const string& id, const string& name) : Employee(id, name) {}
    static Manager* login(vector<Manager> &managers);
    void displayMenu(Bank &bank) override;
    void manageAccountRequests(Bank &bank);
    void viewAllUsers(Bank &bank);
    
};

#endif