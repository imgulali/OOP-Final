#ifndef UTILS_H
#define UTILS_H

#include <string>
using namespace std;


void clearScreen();
int choiceInput(const int& min, const int& max);
void showAlert(const string& message);
string generateID(const string& prefix, int number);


#endif