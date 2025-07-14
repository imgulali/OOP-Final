#ifndef TELLER_H
#define TELLER_H

#include"Employee.h"
#include"utils.h"
#include"Bank.h"

class Teller : public Employee {
public:
    Teller() = default;
    Teller(const string& id, const string& name) : Employee(id, name) {}

    static Teller* login(vector<Teller> &tellers);

    void performWithdraw(Bank& bank);
    void performDeposit(Bank& bank);
    void performTransfer(Bank& bank);

    void displayMenu(Bank &bank) override;
};
#endif
