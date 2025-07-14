#include "Manager.h"
#include "utils.h"
#include "Bank.h"
#include "Teller.h"

Manager* Manager::login(vector<Manager>& managers) {
    clearScreen();
    string id, password;
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Password: ";
    cin >> password;

    for (auto& manager : managers) {
        if (manager.getID() == id && manager.checkPassword(password)) {
            showAlert("Manager login successful.");
            return &manager;
        }
    }

    showAlert("Error: Invalid credentials.");
    return nullptr;
}

void Manager::manageAccountRequests(Bank& bank) {
    vector<AccountRequest>& requests = bank.getAccountRequests();

    while (true) {
        clearScreen();
        displayHeader();

        int count = 0;
        for (int i = 0; i < requests.size(); ++i) {
            if (!requests[i].processed) {
                cout << i + 1 << ". "
                     << "Request ID: " << requests[i].requestID
                     << ", Name: " << requests[i].name
                     << ", Account Type: " << requests[i].accountType << "\n";
                count++;
            }
        }

        if (count == 0) {
            showAlert("No pending account requests.");
            return;
        }

        cout << "\nEnter the request number to manage (0 to return): ";
        int choice;
        cin >> choice;

        if (choice == 0) break;

        if (choice < 1 || choice > requests.size() || requests[choice - 1].processed) {
            showAlert("Invalid or already processed request.");
            continue;
        }

        AccountRequest& req = requests[choice - 1];

        cout << "\nRequest Details:\n";
        cout << "Request ID: " << req.requestID << "\n";
        cout << "Name: " << req.name << "\n";
        cout << "Account Type: " << req.accountType << "\n";

        cout << "\n1. Approve\n2. Reject\n3. Cancel\nChoose action: ";
        int action;
        cin >> action;

        if (action == 1) {
            if (bank.approveAccountRequest(req.requestID)) {
                showAlert("Request approved and customer account created.");
            } else {
                showAlert("Failed to approve request.");
            }
        } else if (action == 2) {
            if (bank.rejectAccountRequest(req.requestID)) {
                showAlert("Request rejected.");
            } else {
                showAlert("Failed to reject request.");
            }
        } else if (action == 3) {
            continue;
        } else {
            showAlert("Invalid action.");
        }
    }
}

void Manager::viewAllUsers(Bank& bank) {
    clearScreen();
    displayHeader();

    cout << "\n=== Customers ===\n";
    for (const auto& c : bank.getCustomers()) {
        cout << "ID: " << c.getID() << ", Name: " << c.getName()
             << ", Account Type: " << c.getAccountType()
             << ", Balance: " << c.getBalance() << "\n";
    }

    cout << "\n=== Tellers ===\n";
    for (const auto& t : bank.getTellers()) {
        cout << "ID: " << t.getID() << ", Name: " << t.getName() << "\n";
    }

    cout << "\n=== Managers ===\n";
    for (const auto& m : bank.getManagers()) {
        cout << "ID: " << m.getID() << ", Name: " << m.getName() << "\n";
    }

    getch();
}


void Manager::displayMenu(Bank& bank) {
    int choice;
    do {
        clearScreen();
        displayHeader();
        cout << "1. Manage Account Requests\n";
        cout << "2. Search Customer by ID\n";
        cout << "3. View All Users\n";
        cout << "4. Change Password\n";
        cout << "5. Logout\n";

        choice = choiceInput(1, 5);

        if (choice == 1) {
            manageAccountRequests(bank);
        } else if (choice == 2) {
            searchCustomerByID(bank);
        } else if (choice == 3) {
            viewAllUsers(bank);
        } else if (choice == 4) {
            changePassword();
        }

    } while (choice != 5);
}

