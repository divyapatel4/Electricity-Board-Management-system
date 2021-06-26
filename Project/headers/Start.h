#ifndef START_H_INCLUDED
#define START_H_INCLUDED
#include "Electricity_Board.h"

void electricityboardrecord()              // Function to load all data from files to linked list, queue and stack and drive the program using switch
{
    int choice;
    char x;

    electricity_board p;
    fstream file;
    string name, id, contact, addr, usage, BILL, cred;
    string line;
    file.open("./program_data/userdata.txt", ios::in);

    // Load data from userdata.txt file to linked list in decrypted form
    if (!file)
    {
        goto here;
    }

    else
    {
        while (getline(file, line))
        {
            stringstream ss(line);
            getline(ss, id, ';');
            getline(ss, name, ';');
            getline(ss, contact, ';');
            getline(ss, addr, ';');
            getline(ss, usage, ';');
            getline(ss, BILL, ';');
            getline(ss, cred, ';');

            user *newnode = new user;
            user *temp = p.head;

            newnode->user_id = decrypt(id);
            newnode->user_name = decrypt(name);
            newnode->contact_No = decrypt(contact);
            newnode->address = decrypt(addr);
            double i;
            istringstream(decrypt(usage)) >> i;
            newnode->power_usage = i;
            long int j;
            istringstream(decrypt(BILL)) >> j;
            newnode->bill = j;
            istringstream(decrypt(cred)) >> j;
            newnode->credit = j;

            newnode->next = nullptr;

            if (p.head == nullptr)
            {
                p.head= newnode;
            }
            else
            {
                while (temp->next != nullptr)
                {
                    temp = temp->next;
                }
                temp->next = newnode;
            }
        }
    }
    file.close();

here:
    string id1, id2, request, status;
    file.open("./program_data/pending_request.txt", ios::in);

    // Load data from unsolved_request.txt file to queue in decrypted form
    if (!file)
    {
        goto here2;
    }

    else
    {
        while (getline(file, line))
        {
            stringstream ss(line);
            getline(ss, id1, ';');
            getline(ss, id2, ';');
            getline(ss, request, ';');
            getline(ss, status, ';');

            request_node *newnod = new request_node;

            newnod->user_id = decrypt(id1);
            newnod->request_ID = decrypt(id2);
            newnod->request_details = decrypt(request);
            newnod->request_status = decrypt(status);

            p.request_Q.enqueue(newnod);
        }
    }
    file.close();

here2:
    file.open("./program_data/solved_request.txt", ios::in);

    // Load data from solved_request.txt file to stack in decrypted form
    if (!file)
    {
        goto here3;
    }

    else
    {
        while (getline(file, line))
        {
            stringstream ss(line);
            getline(ss, id1, ';');
            getline(ss, id2, ';');
            getline(ss, request, ';');
            getline(ss, status, ';');

            request_node *newnod = new request_node;

            newnod->user_id = decrypt(id1);
            newnod->request_ID = decrypt(id2);
            newnod->request_details = decrypt(request);
            newnod->request_status = decrypt(status);

            p.request_stack.push(newnod);
        }
    }
    file.close();

here3:
    while (1)                              //Driver menu
    {
        p.control_panel();
        cout << "\n\n\t\t\t\t\t\t\t\t Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            p.add_new_user();
            break;
        case 2:
            p.view_user();
            break;
        case 3:
            p.check_user();
            break;
        case 4:
            p.update_user();
            break;
        case 5:
            p.remove_user();
            break;
        case 6:
            p.add_bill();
            break;
        case 7:
            p.pay_bill();
            break;
        case 8:
            p.add_request();
            break;
        case 9:
            p.view_request();
            break;
        case 10:
            p.check_request_status();
            break;
        case 11:
            p.resolve_request();
            break;
        case 12:
            p.close_program();
            break;
        default:
            SetConsoleTextAttribute(console, 12);
            cout << "\n\n\t\t\t\t\t\t\t\t\tINVALID CHOICE\n";
            SetConsoleTextAttribute(console, 15);
            break;
        }
    }
}
void start_program()                  // Show welcome message on terminal window
{
    system("cls");
    cout << endl
         << endl
         << "\t\t\t\t\t\t\t ______________________________________" << endl
         << "\t\t\t\t\t\t\t|                                      |";
    cout << "\n\t\t\t\t\t\t\t|     ";
    SetConsoleTextAttribute(console, 6);
    cout << "Welcome to Electricity Board";
    SetConsoleTextAttribute(console, 15);
    cout << "     |";
    cout << "\n\t\t\t\t\t\t\t|______________________________________|";

    cout << endl
         << endl
         << endl
         << "\t\t\t\t\t\t\t     ";
    system("pause");
    electricityboardrecord();
}



#endif // START_H_INCLUDED
