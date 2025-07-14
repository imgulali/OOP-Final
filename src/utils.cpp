#include "utils.h"
#include<iostream>
#include <sstream>
#include <iomanip>
#include<conio.h>

using namespace std;

void clearScreen(){
    system("cls");
}

int choiceInput(const int& min, const int& max){
    while (true){
        int choice;
        cout<<"Choice: ";
        cin>>choice;
        if(choice > max || choice < min) showAlert("Error: Invalid choice");
        return choice;
   }
}

void showAlert(const string& message){
    cout<< message << "\n";
    cout << "Press any key to continue...\n";
    getch();
}

string generateID(const string& prefix, int number) {
    string numStr = to_string(number);
    while (numStr.length() < 5) {
        numStr = "0" + numStr;
    }
    return prefix + numStr;
}