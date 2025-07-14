#ifndef ACCOUNTREQUEST_H
#define ACCOUNTREQUEST_H

#include<string>
using namespace std;

struct AccountRequest {
    string requestID;
    string name;
    string password;
    string accountType;
    bool approved = false;
    bool processed = false;
};
#endif