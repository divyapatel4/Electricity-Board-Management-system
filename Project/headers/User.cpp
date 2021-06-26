#include "User.h"

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
