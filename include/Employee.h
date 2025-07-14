#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "User.h"
#include "Employee.h"
#include "Bank.h"
#include "Customer.h"
#include "utils.h"
#include <conio.h>

class Employee : public User
{
public:
    Employee() = default;
    Employee(const string &id, const string &name) : User(id, name) {}

    void searchCustomerByID(Bank &bank)
    {
        string id;
        cout << "Enter Customer ID: ";
        cin >> id;

        for (Customer &c : bank.getCustomers())
        {
            if (c.getID() == id)
            {
                clearScreen();
                cout << "Customer Found:\n";
                cout << "ID: " << c.getID() << "\n";
                cout << "Name: " << c.getName() << "\n";
                cout << "Account Type: " << c.getAccountType() << "\n";
                cout << "Balance: " << c.getBalance() << "\n";
                getch();
                return;
            }
        }

        showAlert("Customer not found.");
    }
};

#endif
