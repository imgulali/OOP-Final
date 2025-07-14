#include "Customer.h"
#include "Bank.h"
#include "utils.h"
#include <iostream>

Customer* Customer::login(vector<Customer>& customers) {
    clearScreen();
    string id, password;
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Password: ";
    cin >> password;

    for (auto& customer : customers) {
        if (customer.getID() == id && customer.checkPassword(password)) {
            showAlert("Customer login successful.");
            return &customer;
        }
    }

    showAlert("Error: Invalid credentials.");
    return nullptr;
}

void Customer::requestAccount(Bank& bank) {
    clearScreen();
    string name, accountType, password;

    cout << "=== Request New Account ===\n";
    cout << "Enter Name: ";
    cin >> name;

    cout << "Select Account Type:\n";
    cout << "1. Savings\n2. Current\n";
    int choice = choiceInput(1, 2);
    accountType = (choice == 1) ? "Savings" : "Current";

    cout << "Create Password: ";
    cin >> password;

    static int tempCounter = 1000;
    string requestID = generateID("REQ", tempCounter++);

    AccountRequest req = {
        requestID,
        name,
        password,
        accountType,
        false,
        false,
    };

    bank.createAccountRequest(req);
}

void Customer::withdraw() {
    double amount;
    cout << "Enter amount to withdraw: ";
    cin >> amount;
    if (amount <= 0) {
        showAlert("Invalid amount.");
        return;
    }
    if (deductBalance(amount)) {
        showAlert("Withdrawal successful.");
    } else {
        showAlert("Insufficient balance.");
    }
}

void Customer::deposit() {
    double amount;
    cout << "Enter amount to deposit: ";
    cin >> amount;
    if (amount <= 0) {
        showAlert("Invalid amount.");
        return;
    }
    addBalance(amount);
    showAlert("Deposit successful.");
}

void Customer::transfer(Bank& bank) {
    string receiverID;
    double amount;

    cout << "Enter recipient's Customer ID: ";
    cin >> receiverID;

    cout << "Enter amount to transfer: ";
    cin >> amount;

    if (amount <= 0) {
        showAlert("Invalid amount.");
        return;
    }

    Customer* recipient = nullptr;
    for (Customer& c : bank.getCustomers()) {
        if (c.getID() == receiverID) {
            recipient = &c;
            break;
        }
    }

    if (!recipient) {
        showAlert("Recipient not found.");
        return;
    }

    if (!deductBalance(amount)) {
        showAlert("Insufficient balance.");
        return;
    }

    recipient->addBalance(amount);
    showAlert("Transfer successful.");
}


void Customer::displayMenu(Bank& bank) {
    int choice;
    do {
        clearScreen();
        displayHeader();
        cout<<"Balance: " << balance << endl;
        cout << "1. Withdraw\n";
        cout << "2. Deposit\n";
        cout << "3. Transfer\n";
        cout << "4. Change Password\n";
        cout << "5. Logout\n";
        choice = choiceInput(1, 5);

        if (choice == 1) withdraw();
        else if (choice == 2) deposit();
        else if (choice == 3) transfer(bank);
        else if (choice == 4) changePassword();

    } while (choice != 5);
}