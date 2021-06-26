#include<bits/stdc++.h>
#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

using namespace std;

struct request_node             //structure for storing request information
{
    string user_id;
    string request_ID;
    string request_details;
    request_node *next;
    string request_status;
};
class Queue                             //class for storing "UNSOLVED" request information
{
    request_node *Front;
    request_node *Rear;
    public:
    Queue();
    bool empty();
    void enqueue(request_node *value);
    request_node *dequeue();
    request_node *front();
    void display();
    int count();
    void search(string ID);
};

int Queue::count()          //counts the number of active unsolved requests
{
    int count = 0;
    request_node *temp = Front;
    if (empty())
        return 0;
    while (temp != Rear)
    {
        count++;
        temp = temp->next;
    }
    return count + 1;
}

Queue ::Queue()             //class constructor
{
    Rear = nullptr;
    Front = nullptr;
}

bool Queue ::empty()        // return true if queue is empty
{
    if (Front == NULL)
        return true;
    else
        return false;
}
void Queue ::enqueue(request_node *value)   // enqueue the request node into the queue when new request is received
{
    value->next = NULL;
    if (empty())
    {
        Rear = Front = value;
    }
    else
    {
        Rear->next = value;
        Rear = value;
    }
}
request_node *Queue ::dequeue()         //function to dequeue request node when request is solved
{
    request_node *Temp = Front;
    if (empty())
    {
        return (NULL);
    }
    else
    {
        Front = Front->next;
        return (Temp);
    }
}
request_node *Queue ::front()   // returns pointer to front
{
    if (!empty())
    {
        return Front;
    }
    else
    {
        return nullptr;
    }
}
void Queue ::display()          //displays all active unsolved requests
{
    request_node *temp = Front;
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
void Queue ::search(string ID)  //searches and displays all active unsolved requests for given user ID
{
    request_node *temp = Front;
    while (temp != nullptr)
    {
        if (temp->user_id == ID)
        {
            cout << "\n\n\t\t\t\t\t\t\t      ->User ID : " << temp->user_id << endl;
            cout << "\n\t\t\t\t\t\t\t\tRequest ID : " << temp->request_ID << endl;
            cout << "\n\t\t\t\t\t\t\t\tRequest details : " << temp->request_details << endl;
        }

        temp = temp->next;
    }
}

#endif // QUEUE_H_INCLUDED
