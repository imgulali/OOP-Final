#include "Teller.h"
#include "utils.h"
#include "Bank.h"
#include "Customer.h"

Teller* Teller::login(vector<Teller>& tellers) {
    clearScreen();
    string id, password;
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Password: ";
    cin >> password;

    for (auto& teller : tellers) {
        if (teller.getID() == id && teller.checkPassword(password)) {
            showAlert("Teller login successful.");
            return &teller;
        }
    }

    showAlert("Error: Invalid credentials.");
    return nullptr;
}

void Teller::performWithdraw(Bank& bank) {
    string id;
    cout << "Enter Customer ID: ";
    cin >> id;

    Customer* c = nullptr;
    for (Customer& cust : bank.getCustomers()) {
        if (cust.getID() == id) {
            c = &cust;
            break;
        }
    }

    if (!c) {
        showAlert("Customer not found.");
        return;
    }

    c->withdraw();
}

void Teller::performDeposit(Bank& bank) {
    string id;
    cout << "Enter Customer ID: ";
    cin >> id;

    Customer* c = nullptr;
    for (Customer& cust : bank.getCustomers()) {
        if (cust.getID() == id) {
            c = &cust;
            break;
        }
    }

    if (!c) {
        showAlert("Customer not found.");
        return;
    }

    c->deposit();
}

void Teller::performTransfer(Bank& bank) {
    string id;
    cout << "Enter Sender's Customer ID: ";
    cin >> id;

    Customer* sender = nullptr;
    for (Customer& cust : bank.getCustomers()) {
        if (cust.getID() == id) {
            sender = &cust;
            break;
        }
    }

    if (!sender) {
        showAlert("Sender not found.");
        return;
    }

    sender->transfer(bank);
}

void Teller::displayMenu(Bank& bank) {
    int choice;
    do {
        clearScreen();
        displayHeader();
        cout << "1. Withdraw for Customer\n";
        cout << "2. Deposit for Customer\n";
        cout << "3. Transfer between Customers\n";
        cout << "4. Search Customer by ID\n";
        cout << "5. Logout\n";

        choice = choiceInput(1, 5);

        if (choice == 1) performWithdraw(bank);
        else if (choice == 2) performDeposit(bank);
        else if (choice == 3) performTransfer(bank);
        else if (choice == 4) searchCustomerByID(bank);

    } while (choice != 5);
}
