#ifndef ELECTRICITY_BOARD_H_INCLUDED
#define ELECTRICITY_BOARD_H_INCLUDED
#include<bits/stdc++.h>
#include "conversion.h"
#include "Stack.h"
#include "User.h"

using namespace std;

typedef class electricity_board         //class electricity_board which will maintain all data of different users and requests
{
    user *head = nullptr;
public:
    Queue request_Q;
    Stack request_stack;
    void control_panel();
    void add_new_user();
    void view_user();
    void check_user();
    void update_user();
    void remove_user();
    void add_bill();
    void pay_bill();
    void add_request();
    void Adminstration();
    void view_request();
    void check_request_status();
    void resolve_request();
    void close_program();
    friend void electricityboardrecord();
} EB;

void EB ::control_panel()           //displays main menu of the program ( control panel )
{

    system("cls");
    SetConsoleTextAttribute(console, 10);
    cout << "\n\n\t\t\t\t\t\t\t\t\t  CONTROL PANEL";
    cout << "\n\t\t\t\t\t\t\t\t__________________________________";
    SetConsoleTextAttribute(console, 15);
    cout << "\n\n\t\t\t\t\t\t\t\t 1. ADD USER";
    cout << "\n\t\t\t\t\t\t\t\t 2. DISPLAY ALL USER";
    cout << "\n\t\t\t\t\t\t\t\t 3. CHECK PARTICULAR USER";
    cout << "\n\t\t\t\t\t\t\t\t 4. UPDATE USER";
    cout << "\n\t\t\t\t\t\t\t\t 5. DELETE USER";
    cout << "\n\t\t\t\t\t\t\t\t 6. ADD BILL";
    cout << "\n\t\t\t\t\t\t\t\t 7. PAY BILL";
    cout << "\n\t\t\t\t\t\t\t\t 8. ADD REQUEST";
    cout << "\n\t\t\t\t\t\t\t\t 9. VIEW REQUEST";
    cout << "\n\t\t\t\t\t\t\t\t10. CHECK REQUEST STATUS";
    cout << "\n\t\t\t\t\t\t\t\t11. SOLVE REQUEST";
    SetConsoleTextAttribute(console, 12);
    cout << "\n\t\t\t\t\t\t\t\t12. CLOSE PROGRAM & SAVE THE DATA";
    SetConsoleTextAttribute(console, 10);
    cout << "\n\t\t\t\t\t\t\t\t__________________________________";
    SetConsoleTextAttribute(console, 15);
}
void EB ::add_new_user()            //function to add new user to electricity board
{
    string ID;
    user *p = head;
    int base;
    if (head == NULL)
    {
        base = 202100;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        ID = p->user_id;        //Finding USER ID of last user and adding 1 for next user
        base = stoi(ID) + 1;
    }

    system("cls");
    string name, id, contact, addr, request;
    getchar();
    SetConsoleTextAttribute(console, 10);
    cout << "\n\n\t\t\t\t\t\t\t\t\t  ADD NEW USER";
    SetConsoleTextAttribute(console, 15);
    cout << "\n\t\t\t\t\t\t\t\t__________________________________" << endl;
    cout << "\n\t\t\t\t\t\t\t\tUser Name : ";
    getline(cin, name);
    cout << "\n\t\t\t\t\t\t\t\tUser Contact Number : ";
    getline(cin, contact);
    cout << "\n\t\t\t\t\t\t\t\tUser Adrdress : ";
    getline(cin, addr);
    cout << "\n\t\t\t\t\t\t\t\t__________________________________";

    user *newnode = new user;
    user *temp = head;
    newnode->user_id = itos(base);
    newnode->user_name = name;
    newnode->contact_No = contact;
    newnode->address = addr;
    newnode->next = nullptr;

    if (head == nullptr)
    {
        head = newnode;
    }
    else
    {
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    SetConsoleTextAttribute(console, 10); //green text
    cout << endl
         << endl
         << "\t\t\t\t\t\t\t\t    User successfully added!!\n";
    SetConsoleTextAttribute(console, 15); //reset to white text

    cout << "\t\t\t\t\t\t\t\t\t User ID:" << newnode->user_id << endl
         << endl
         << endl
         << "\t\t\t\t\t\t\t\t ";
    system("pause");
}

void EB ::view_user()   //function to display all active users in list form view
{
    system("cls");
    string user_name, user_id, contact_No, address, request;

    if (head == nullptr)
    {
        SetConsoleTextAttribute(console, 12); // red text
        cout << "\n\n\t\t\t\t\t\t\t\tUser file has no data";
        cout << endl
             << endl;
        SetConsoleTextAttribute(console, 15); // reset to white text
        system("pause");
    }
    else
    {
        user *temp = head;
        SetConsoleTextAttribute(console, 11); //blue text
        cout << "\n\n\n User ID\t\tUser"
             << "\t\t\t\t\tContact No\t\tAddress";
        SetConsoleTextAttribute(console, 15); // reset to white text
        while (temp != nullptr)
        {
            cout << endl;
            cout << "  " << temp->user_id;
            cout << "\t\t" << temp->user_name;
            for (int i = 0; i < 24 - temp->user_name.size(); i++) //24 is the width of username column
            {
                cout << " ";
            }
            cout << "\t\t" << temp->contact_No;
            for (int i = 0; i < 18 - temp->contact_No.size(); i++) //18 is the width of contact number column
            {
                cout << " ";
            }
            cout << "\t" << temp->address;
            cout << "\n\n";

            temp = temp->next;
        }
        cout << endl
             << endl;
        system("pause");
    }
}

void EB ::check_user()  //function to search for a paarticular user using his user ID
{
    system("cls");
    int count = 0;
    string user_name, user_id, contact_No, address, request;
    string temp, line;
    SetConsoleTextAttribute(console, 10); //green text
    cout << "\n\n\t\t\t\t\t\t\t\t\tCHECK SPECIFIC USER";
    SetConsoleTextAttribute(console, 15); // reset to white text
    cout << "\n\t\t\t\t\t\t\t\t__________________________________";
    user *tempd = head;

    if (head == nullptr)
    {
        SetConsoleTextAttribute(console, 12); //red text
        cout << "\n\n\t\t\t\t\t\t\t\tUser file has no data\n\n\n\t\t\t\t\t\t\t\t";
        cout << endl
             << endl;
        SetConsoleTextAttribute(console, 15); //reset to white text
        system("pause");
        return;
    }
    else
    {
        getchar();
        cout << "\n\n\t\t\t\t\t\t\t\tUser ID : ";
        getline(cin, temp);

        while (tempd != nullptr)
        {
            if (temp == tempd->user_id)
            {
                system("cls");
                cout << "\n\n\t\t\t\t\t\t\t\t      "
                     << "User data of id ";
                SetConsoleTextAttribute(console, 10); //green text
                cout << temp;
                SetConsoleTextAttribute(console, 15); //reset to white text
                cout << "\n\t\t\t\t\t\t\t\t__________________________________";
                cout << "\n\n\t\t\t\t\t\t\t\tUser ID : " << tempd->user_id;
                cout << "\n\t\t\t\t\t\t\t\tUser name : " << tempd->user_name;
                cout << "\n\t\t\t\t\t\t\t\tContact : " << tempd->contact_No;
                cout << "\n\t\t\t\t\t\t\t\tAddress : " << tempd->address;
                cout << "\n\t\t\t\t\t\t\t\t__________________________________\n\n\t\t\t\t\t\t\t\t";
                count++;
            }
            tempd = tempd->next;
        }

        if (count == 0)
        {
            SetConsoleTextAttribute(console, 12);
            cout << "\n\n\t\t\t\t\t\t\t\tUser Not Found\n\n\n\t\t\t\t\t\t\t\t";

            SetConsoleTextAttribute(console, 15);
        }
        system("pause");
    }
}

void EB ::update_user()                         // Function to find node with given id and update it's data
{
    system("cls");
    fstream file, file1;
    int count = 0;
    string user_name, id, contact_No, address, request;
    string USER_NAME, USER_ID, CONTACT_NO, ADDRESS;
    string line;
    user *temp = head;
    SetConsoleTextAttribute(console, 10);
    cout << "\n\n\t\t\t\t\t\t\t\t\tUpdate User Record";
    SetConsoleTextAttribute(console, 15);
    cout << "\n\t\t\t\t\t\t\t\t__________________________________";

    if (head == nullptr)                       // If linked list is empty
    {
        SetConsoleTextAttribute(console, 12);
        cout << "\n\n\t\t\t\t\t\t\t\tUser file has no data\n\n\n\t\t\t\t\t\t\t\t";
        cout << endl
             << endl;
        SetConsoleTextAttribute(console, 15);
        system("pause");
        return;
    }
    else                                       // If linked list is not empty
    {
        getchar();
        cout << "\n\n\t\t\t\t\t\t\t\tUser ID : ";
        getline(cin, id);

        while (temp != nullptr)                // Traversal of linked list
        {
            if (id == temp->user_id)
            {

                system("cls");

                cout << "\n\n\t\t\t\t\t\t\t\t\t"
                     << "Update User Record";
                cout << "\n\t\t\t\t\t\t\t\t__________________________________";
                cout << "\n\n\t\t\t\t\t\t\t\tUser Name : ";
                getline(cin, USER_NAME);

                cout << "\n\t\t\t\t\t\t\t\tContact Number : ";
                getline(cin, CONTACT_NO);
                cout << "\n\t\t\t\t\t\t\t\tAddress : ";
                getline(cin, ADDRESS);
                cout << "\n\t\t\t\t\t\t\t\t__________________________________\n\n\t\t\t\t\t\t\t\t";

                temp->user_name = USER_NAME;
                temp->contact_No = CONTACT_NO;
                temp->address = ADDRESS;
                count++;
            }
            temp = temp->next;
        }

        if (count == 0)
        {
            SetConsoleTextAttribute(console, 12);
            cout << "\n\n\t\t\t\t\t\t\t\tUser Not Found\n\n\n\t\t\t\t\t\t\t\t";
            SetConsoleTextAttribute(console, 15);
        }
    }

    system("pause");
}

void EB ::remove_user()                         //Function to remove user node with given id from linked list
{
    system("cls");
    string user_name, id, user_idd, contact_No, address, request;
    SetConsoleTextAttribute(console, 10);
    cout << "\n\n\t\t\t\t\t\t\t\t\t   Delete a User";
    SetConsoleTextAttribute(console, 15);
    cout << "\n\t\t\t\t\t\t\t\t__________________________________";

    if (head == nullptr)                       // If linked list has no node (Empty)
    {
        SetConsoleTextAttribute(console, 12);
        cout << "\n\n\t\t\t\t\t\t\t\t      User file has no data\n\n\t\t\t\t\t\t\t\t ";
        SetConsoleTextAttribute(console, 15);
        goto mark2;
        system("pause");
        return;
    }
    else
    {
        user *p = head;
        user *q = head->next;
        getchar();
        cout << "\n\n\t\t\t\t\t\t\t\tUser ID : ";
        getline(cin, id);
        if (head->user_id == id)              // If linked list has single node
        {
            user *temp = head;
            head = temp->next;
            free(temp);
            system("cls");
            cout << "\n\n\t\t\t\t\t\t\t\t"
                 << "Updating User Record...";
            SetConsoleTextAttribute(console, 10);
            cout << "\n\n\t\t\t\t\t\t\t\tUser is removed successfully...\n\n\n\n\t\t\t\t\t\t\t\t";
            SetConsoleTextAttribute(console, 15);
        }

        else                                 // If linked list has more then one node
        {
            while (q->user_id != id && q->next != nullptr)
            {
                p = p->next;
                q = q->next;
            }

            if (q->user_id == id)           // If ID is matched with any node's user id
            {
                p->next = q->next;
                free(q);
                system("cls");
                cout << "\n\n\t\t\t\t\t\t\t\t"
                     << "Updating User Record...";
                SetConsoleTextAttribute(console, 10);
                cout << "\n\n\t\t\t\t\t\t\t\tUser is removed successfully...\n\n\n\n\t\t\t\t\t\t\t\t";
                SetConsoleTextAttribute(console, 15);
            }

            else                           // If throughout the traversal user id not found
            {
                SetConsoleTextAttribute(console, 12);
                cout << "\n\n\t\t\t\t\t\t\t\t\tUser Not Found...\n\n\t\t\t\t\t\t\t\t\t";
                SetConsoleTextAttribute(console, 15);
            }
        }
    }
mark2:
    system("pause");
}

void EB::add_bill()                         // Function to add power usage of specific user and generate bill for it
{
    system("cls");
    double units = 0;
    long int bill = 0;
    SetConsoleTextAttribute(console, 10);
    cout << "\n\n\t\t\t\t\t\t\t\t\t      ADD BILL";
    SetConsoleTextAttribute(console, 15);
    cout << "\n\t\t\t\t\t\t\t\t__________________________________" << endl;
    cout << "\n\t\t\t\t\t\t\t\tEnter User ID : ";
    string user_id;
    cin >> user_id;

    user *tempd = head;
    int count = 0;

    if (head == nullptr)                     // If linked list is empty
    {
        SetConsoleTextAttribute(console, 12);
        cout << "\n\n\t\t\t\t\t\t\t\tUser file has no data\n\n\n\t\t\t\t\t\t\t\t";
        cout << endl
             << endl;
        SetConsoleTextAttribute(console, 15);
    }
    else                                    // If linked list is not empty
    {
        while (tempd != nullptr)            // Traversal upto end of the linked list
        {
            if (user_id == tempd->user_id)  // If entered id is matched within the linked list
            {
                system("cls");
                cout << "\n\n\t\t\t\t\t\t\t\t    "
                     << "Adding Bill to id ";
                SetConsoleTextAttribute(console, 10);
                cout << user_id;
                SetConsoleTextAttribute(console, 15);
                cout << "\n\t\t\t\t\t\t\t\t__________________________________";
                cout << "\n\n\t\t\t\t\t\t\t\tUser ID : " << tempd->user_id;
                cout << "\n\t\t\t\t\t\t\t\tUser name : " << tempd->user_name;
                cout << "\n\t\t\t\t\t\t\t\tContact : " << tempd->contact_No;
                cout << "\n\t\t\t\t\t\t\t\tAddress : " << tempd->address;
                cout << "\n\t\t\t\t\t\t\t\t__________________________________";
                count++;
                break;
            }
            tempd = tempd->next;
        }
        cout << endl;
        if (count == 0)                     // User ID not matched through out the travesal of linked list
        {
            SetConsoleTextAttribute(console, 12);
            cout << "\n\n\t\t\t\t\t\t\t\tUser Not Found\n\n\n\t\t\t\t\t\t\t\t";
            SetConsoleTextAttribute(console, 15);
            system("pause");
            return;
        }
        cout << "\n\n\t\t\t\t\t\t\t\tEnter Units Consumption : ";
        cin >> units;

        // Structure of billing as per power usage
        if (units <= 100)
        {
            bill = units * 10;
        }
        else if (units <= 200)
        {
            bill = (100 * 10) + (units - 100) * 15;
        }
        else if (units <= 300)
        {
            bill = (100 * 10) + (100 * 15) + (units - 200) * 20;
        }
        else if (units > 300)
        {
            bill = (100 * 10) + (100 * 15) + (100 * 20) + (units - 300) * 25;
        }
        tempd->bill = bill;
        tempd->power_usage = units;
        SetConsoleTextAttribute(console, 10);
        cout << "\n\n\t\t\t\t\t\t\t\tBill added with amount ";
        SetConsoleTextAttribute(console, 11);
        cout << bill << "/-.\n\n\n\t\t\t\t\t\t\t\t";
        SetConsoleTextAttribute(console, 15);
        system("pause");
    }
}

void EB::pay_bill()                           // Function to pay bill and update credit of specific user with given id
{
    system("cls");
    int count = 0;
    string user_name, user_id, contact_No, address, request;
    string temp, line;
    SetConsoleTextAttribute(console, 10);
    cout << "\n\n\t\t\t\t\t\t\t\t\t      PAY BILL";
    SetConsoleTextAttribute(console, 15);
    cout << "\n\t\t\t\t\t\t\t\t__________________________________" << endl;
    user *tempd = head;

    if (head == nullptr)                      // If linked list is empty
    {
        SetConsoleTextAttribute(console, 12);
        cout << "\n\nUser file has no data";
        SetConsoleTextAttribute(console, 15);
    }
    else                                      // If linked list is not empty
    {
        getchar();
        cout << "\n\t\t\t\t\t\t\t\tEnter User ID : ";
        getline(cin, temp);

        while (tempd != nullptr)              // Traversal upto of the linked list
        {
            if (temp == tempd->user_id)       // If entered id is matched within the linked list
            {
                system("cls");
                cout << "\n\n\t\t\t\t\t\t\t\t    "
                     << "Paying Bill for id ";
                SetConsoleTextAttribute(console, 10);
                cout << temp;
                SetConsoleTextAttribute(console, 15);
                cout << "\n\t\t\t\t\t\t\t\t__________________________________";
                cout << "\n\n\t\t\t\t\t\t\t\tUser ID : " << tempd->user_id;
                cout << "\n\t\t\t\t\t\t\t\tUser name : " << tempd->user_name;
                cout << "\n\t\t\t\t\t\t\t\tContact : " << tempd->contact_No;
                cout << "\n\t\t\t\t\t\t\t\tAddress : " << tempd->address;
                cout << "\n\t\t\t\t\t\t\t\t__________________________________";

                count++;
                break;
            }
            tempd = tempd->next;
        }
        cout << endl;
        if (count == 0)                        // User ID not matched through out the travesal of linked list
        {
            SetConsoleTextAttribute(console, 12);
            cout << "\n\n\t\t\t\t\t\t\t\tUser Not Found\n\n\n\t\t\t\t\t\t\t\t";
            SetConsoleTextAttribute(console, 15);
            system("pause");
            return;
        }
        long int amount;                       // Temporary variable to store amount of payment
        cout << "\n\n\t\t\t\t\t\t\t\tPower usage : " << tempd->power_usage << endl;
        cout << "\t\t\t\t\t\t\t\tThis Month Bill : Rs." << tempd->bill << endl;

        SetConsoleTextAttribute(console, 10);
        cout << "\t\t\t\t\t\t\t\tCredit : " << tempd->credit << endl
             << endl;
        SetConsoleTextAttribute(console, 15);

        cout << "\t\t\t\t\t\t\t\tEnter amount to pay : ";
        cin >> amount;
        if (amount < tempd->bill - tempd->credit)
        {
            SetConsoleTextAttribute(console, 12);
            cout << "\n\n\t\t\t\t\t\t\t\t\tError to pay" << endl;
            SetConsoleTextAttribute(console, 15);
        }
        else
        {
            long credit_temp = amount - tempd->bill;
            tempd->bill = 0;
            tempd->power_usage = 0;
            tempd->credit += credit_temp;
            SetConsoleTextAttribute(console, 10);
            cout << "\n\t\t\t\t\t\t\t\tBill Paid !" << endl;
            cout << "\t\t\t\t\t\t\t\tCurrent Credit : " << tempd->credit << "\n\n\n\t\t\t\t\t\t\t\t";
            SetConsoleTextAttribute(console, 15);
        }
        system("pause");
    }
}

void EB::add_request()                       // Function to add request of users in queue
{
    system("cls");
    string request_details, user_id;
    user *tempd = head;
    int flag = 0;
    // getchar();
    SetConsoleTextAttribute(console, 10);
    cout << "\n\n\t\t\t\t\t\t\t\t\t    ADD REQUEST";
    SetConsoleTextAttribute(console, 15);
    cout << "\n\t\t\t\t\t\t\t\t__________________________________" << endl;
    cout << "\n\t\t\t\t\t\t\t\tEnter User ID : ";
    cin >> user_id;

    if (head == nullptr)                     // If there is no user in linked list
    {
        SetConsoleTextAttribute(console, 12);
        cout << "\n\n\t\t\t\t\t\t\t\tUser file has no data\n\n\n\t\t\t\t\t\t\t\t";
        SetConsoleTextAttribute(console, 15);
        system("pause");
        return;
    }
    else
    {
        while (tempd != nullptr)             // Traversal of linked list to find user of given id
        {
            if (user_id == tempd->user_id)
            {
                system("cls");
                cout << "\n\n\t\t\t\t\t\t\t\t    "
                     << "Adding Request for id ";
                SetConsoleTextAttribute(console, 10);
                cout << user_id;
                SetConsoleTextAttribute(console, 15);
                cout << "\n\t\t\t\t\t\t\t\t__________________________________";
                cout << "\n\n\t\t\t\t\t\t\t\tUser ID : " << tempd->user_id;
                cout << "\n\t\t\t\t\t\t\t\tUser name : " << tempd->user_name;
                cout << "\n\t\t\t\t\t\t\t\tContact : " << tempd->contact_No;
                cout << "\n\t\t\t\t\t\t\t\tAddress : " << tempd->address;
                cout << "\n\t\t\t\t\t\t\t\t__________________________________";
                flag++;
                break;
            }
            tempd = tempd->next;
        }
        cout << endl;
        if (flag == 0)                      // If throughout the traversal no user found with given id
        {
            SetConsoleTextAttribute(console, 12);
            cout << "\n\n\t\t\t\t\t\t\t\tUser Not Found\n\n\n\t\t\t\t\t\t\t\t";
            SetConsoleTextAttribute(console, 15);
            system("pause");
            return;
        }
        // system("pause");
    }
    cout << "\n\n\t\t\t\t\t\t\t\tEnter request details : ";
    getchar();
    getline(cin, request_details);
    int request_ID = request_Q.count() + 102100;
    request_node *newnode = new request_node;
    newnode->request_details = request_details;
    newnode->request_ID = itos(request_ID);  // Convert int data type to string
    newnode->user_id = user_id;
    newnode->request_status = "UNSOLVED";
    request_Q.enqueue(newnode);
    SetConsoleTextAttribute(console, 10);
    cout << "\n\n\t\t\t\t\t\t\t   Your request has been successfully Recorded!" << endl;
    SetConsoleTextAttribute(console, 15);
    cout << "\t\t\t\t\t\t\t\t\t Request ID : " << request_ID << endl
         << endl
         << endl
         << "\t\t\t\t\t\t\t\t ";
    system("pause");
}
void EB::view_request()                      // Function to display data of all request nodes of queue
{
    system("cls");
    SetConsoleTextAttribute(console, 10);
    cout << "\n\n\t\t\t\t\t\t\t\t\tALL PENDING REQUESTS";
    SetConsoleTextAttribute(console, 15);
    cout << "\n\t\t\t\t\t\t\t\t__________________________________";
    request_Q.display();
    cout << "\n\n\n\t\t\t\t\t\t\t\t";
    system("pause");
}
void EB::resolve_request()                   // Function to dequeue request node, get status from board employee and push it into stack
{
    system("cls");
    string status;
    SetConsoleTextAttribute(console, 10);
    cout << "\n\n\t\t\t\t\t\t\t\t\tRequest to resolve first" << endl
         << endl;
    SetConsoleTextAttribute(console, 15);
    request_node *temp = request_Q.dequeue();

    if (temp)                                // If dequeued node is not nullptr
    {
        cout << "\n\t\t\t\t\t\t\t\tRequest ID : " << temp->request_ID << endl;
        cout << "\n\t\t\t\t\t\t\t\tUser ID : " << temp->user_id << endl;
        cout << "\n\t\t\t\t\t\t\t\tRequest details :" << temp->request_details << endl;
        SetConsoleTextAttribute(console, 10);
        cout << "\n\t\t\t\t\t\t\t\tEnter Request Status (Solved/Rejected): ";
        SetConsoleTextAttribute(console, 15);
        getchar();
        getline(cin, status);
        temp->request_status = status;
        request_stack.push(temp);
    }
    else
    {
        cout << "\n\t\t\t\t\t\t\t\tAll requests have been resolved";
    }
    cout << "\n\n\n\n\t\t\t\t\t\t\t\t";
    system("pause");
}

void EB::check_request_status()               // Function to check request is solved or not
{
    system("cls");
    string user_id;
    request_node *temp;
    SetConsoleTextAttribute(console, 10);
    cout << "\n\n\t\t\t\t\t\t\t\t\tCHECK REQUEST STATUS";
    SetConsoleTextAttribute(console, 15);
    cout << "\n\t\t\t\t\t\t\t\t__________________________________";
    cout << "\n\n\t\t\t\t\t\t\t\tEnter your user ID : ";
    cin >> user_id;
    cout << "\n\t\t\t\t\t\t\t\tYour request History : " << endl
         << endl;
    SetConsoleTextAttribute(console, 12);
    cout << "\n\t\t\t\t\t\t\t\tUnsolved Request :" << endl;
    SetConsoleTextAttribute(console, 15);
    request_Q.search(user_id);                // If request is found in queue then it will be considered as unsolved

    SetConsoleTextAttribute(console, 10);
    cout << "\n\t\t\t\t\t\t\t\tSolved Request :" << endl;
    SetConsoleTextAttribute(console, 15);
    request_stack.search(user_id);            // If request is found in stack then it will be considered as solved

    cout << "\n\n\n\t\t\t\t\t\t\t\t ";
    system("pause");
}
void EB ::close_program()                     // Function to transfer all data of linked list, queue and stack to files(Permanant store)
{
    fstream file;
    string line;
    file.open("./program_data/userdata.txt", ios::out);
    user *temp = head;

    while (temp != nullptr)                   // Storing data of linked list in userdata.txt file in encrypted form
    {
        file << encrypt(temp->user_id) << ";" << encrypt(temp->user_name) << ";"
        << encrypt(temp->contact_No) << ";" << encrypt(temp->address) << ";"
        << encrypt(itos(temp->power_usage)) << ";" << encrypt(itos(temp->bill)) << ";"
        << encrypt(itos(temp->credit)) << endl;
        temp = temp->next;
    }
    file.close();

    file.open("./program_data/pending_request.txt", ios::out);
    request_node *tmp = request_Q.dequeue();

    while (tmp != nullptr)                   // Storing data of queue in unsolved_request.txt file in encrypted form
    {
        file << encrypt(tmp->user_id) << ";" << encrypt(tmp->request_ID) << ";"
        << encrypt(tmp->request_details) << ";" << encrypt(tmp->request_status) << endl;
        tmp = tmp->next;
    }
    file.close();

    file.open("./program_data/solved_request.txt", ios::out);
    request_node *t = request_stack.pop();

    while (t != nullptr)                    // Storing data of stack in solved_request.txt file in encrypted form
    {
        file << encrypt(t->user_id) << ";" << encrypt(t->request_ID) << ";"
        << encrypt(t->request_details) << ";" << encrypt(t->request_status) << endl;
        t = request_stack.pop();
    }
    file.close();

    system("cls");
    // Print thanks message and terminate the program
    SetConsoleTextAttribute(console, 6);
    cout << "\n\n\n\n\t\t\t\t\t\t\t         _______________________\n";
    cout << "\t\t\t\t\t\t\t\t|\t         \t|\n";
    cout << "\t\t\t\t\t\t\t\t|\tTHANK YOU\t|\n";
    cout << "\t\t\t\t\t\t\t\t|_______________________|\n\n\n\n\n\n";

    exit(0);
}


#endif // ELECTRICITY_BOARD_H_INCLUDED
