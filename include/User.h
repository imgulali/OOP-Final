#ifndef USER_H
#define USER_H
#include<iostream>
#include<string>
#include<conio.h>
#include"utils.h"
using namespace std;

class Bank;

class User {
protected:
    string id;
    string name;
    string password;

public:
    User() = default;
    User(const string& id, const string& name) : id(id), name(name) {}

    virtual void displayMenu(Bank& bank) = 0;

    string getID() const { return id; }
    string getName() const { return name; }
    bool checkPassword(const string& input) const { return password == input; }
    void setPassword(const string& newPass) { password = newPass; }

    void displayHeader(){
        cout<<"Bank Management System\n";
        cout<<"Id: "<<id << "\n";
        cout<<"Name: "<<name << "\n";
    }

    void changePassword(){
        string newPassword, repeatPassword;
        cout<<"Change Password\nNew Password: "; cin>>newPassword;
        cout<<"Repeat Password: "; cin>>repeatPassword;
        if(newPassword.empty() || repeatPassword.empty()){
            showAlert("Error: All inputs are required"); return;
        }
        if(newPassword != repeatPassword){
            showAlert("Error: Passwords don't match"); return;
        }
        password = newPassword;
        showAlert("Password updated successfully");
    }
    virtual ~User() = default;
};
#endif