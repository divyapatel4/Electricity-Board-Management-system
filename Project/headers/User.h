#include<bits/stdc++.h>
#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

using namespace std;

class user              // class for storing all user data
{
public:
    user();
    string user_id, user_name, contact_No, address;
    user *next;
    long int bill;
    long int credit;
    double power_usage;
};
user ::user()          // class constructor; when new user is added this will be the default value of class data variables
{
    user_id = "";
    user_name = "";
    contact_No = "";
    address = "";
    next = nullptr;
    bill = 0;
    credit = 0;
    power_usage = 0;
}

#endif // USER_H_INCLUDED
