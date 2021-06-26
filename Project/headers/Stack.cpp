
#include "Stack.h"

int Stack::count()          //counts the number of "SOLVED" requests
{
    int count = 0;
    request_node *temp = top;
    if (empty())
        return 0;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

Stack ::Stack()                 // class constructor
{
    top = nullptr;
}

bool Stack ::empty() // return true if stack is empty
{
    if (top == nullptr)
        return true;
    else
        return false;
}
void Stack ::push(request_node *value)  //function to push the request node into the stack when the request is solved
{
    if (empty())
    {
        value->next = nullptr;
        top = value;
    }
    else
    {
        top->next = value;
        top = value;
    }
}
request_node *Stack ::pop()             //function to pop the request node from the stack
{
    request_node *Temp = top;
    if (empty())
    {
        return nullptr;
    }
    else
    {
        top = top->next;
        return (Temp);
    }
}
request_node *Stack::peek()             //function to peek the request node from the stack
{
    if (!empty())
    {
        return top;
    }
    else
    {
        return nullptr;
    }
}
void Stack ::display()                   //displays all solved requests
{
    request_node *temp = top;
    cout << endl;
    while (temp != nullptr)
    {
        cout << "\n\n\t\t\t\t\t\t\t      ->User ID : " << temp->user_id << endl;
        cout << "\n\t\t\t\t\t\t\t\tRequest ID : " << temp->request_ID << endl;
        cout << "\n\t\t\t\t\t\t\t\tRequest details : " << temp->request_details << endl
             << endl;

        temp = temp->next;
    }
}
void Stack ::search(string ID)              //searches and displays all "SOLVED" requests
{
    request_node *temp = top;
    cout << endl;
    while (temp != nullptr)
    {
        if (temp->user_id == ID)
        {
            cout << "\n\n\t\t\t\t\t\t\t      ->User ID : " << temp->request_ID << endl;
            cout << "\n\t\t\t\t\t\t\t\tRequest Details :" << temp->request_details << endl;
            cout << "\n\t\t\t\t\t\t\t\tRequest Status : " << temp->request_status;
        }

        temp = temp->next;
    }
}


