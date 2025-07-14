#include <iostream>
#include "Bank.h"
#include "Customer.h"
#include "Manager.h"
#include "Teller.h"

using namespace std;

void customer(Bank& bank){
    clearScreen();
    cout << "=== Customer Portal ===\n";
    cout << "1. Login\n";
    cout << "2. Request New Account\n";

    int choice = choiceInput(1, 2);
    if (choice == 1) {
        Customer* c = Customer::login(bank.getCustomers());
        if (c) c->displayMenu(bank);
    } else Customer().requestAccount(bank);
}

void menu(Bank& bank) {
    int choice;
    do {
        clearScreen();
        cout << "=== Welcome to the Bank System ===\n";
        cout << "1. Customer\n";
        cout << "2. Manager\n";
        cout << "3. Teller\n";
        cout << "4. Exit\n";

        choice = choiceInput(1, 4);

        if (choice == 1) {
            customer(bank);
        } else if (choice == 2) {
            Manager* m = Manager::login(bank.getManagers());
            if (m) m->displayMenu(bank);
        } else if (choice == 3) {
            Teller* t = Teller::login(bank.getTellers());
            if (t) t->displayMenu(bank);
        }

    } while (choice != 4);

    cout << "Goodbye!\n";
}


int main() {
    Bank bank;

    Manager M1("MGR001", "Ali");
    M1.setPassword("admin");
    bank.getManagers().push_back(M1);

    Teller T1("TEL001", "Ahmed");
    T1.setPassword("teller");
    bank.getTellers().push_back(T1);

    Customer C1("CUS00001", "Anas", "Savings", 100.0, false);
    C1.setPassword("pass");
    bank.getCustomers().push_back(C1);

    Customer C2("CUS00002", "Iqbal", "Current", 1000.0, false);
    C2.setPassword("pass");
    bank.getCustomers().push_back(C2);

    menu(bank);

    return 0;
}
