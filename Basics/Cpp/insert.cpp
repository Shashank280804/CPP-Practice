#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Node
{
public:
    string name;
    float cgpa;
    string company_name;
    float previous_package;

    Node *next;
};
class sll
{
public:
    Node *head;
    int len;
    sll()
    {
        head = NULL;
        len = 0;
    }
    void create();
    void display();
    void insert();
    void delet();
};
void sll ::create()
{

    Node *temp, *p;
    char ch;
    do
    {
        temp = new Node;

        cout << "Enter employee name";
        cin >> temp->name;
        cout << "Enter cgpa";
        cin >> temp->cgpa;
        cout << "Enter previous company name";
        cin >> temp->company_name;
        cout << "Enter previous package";
        cin >> temp->previous_package;

        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            p = head;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp;
        }
        cout << "do you want to add more nodes(y/n)" << endl;
        cin >> ch;
    } while (ch == 'y');
}
void sll ::display()
{
    Node *p;
    p = head;
    while (p != NULL)
    {
        cout << "Name of the employee  : " << p->name << endl;
        cout << " Name of the company : " << p->company_name << endl;
        cout << " cgpa : " << p->cgpa << endl;
        cout << " The previous Package : " << p->previous_package << endl;
        p = p->next;
    }
}
void sll ::insert()
{
    Node *temp, *p;
    int pos;
    temp = new Node;
    cout << "Give the position where you want to enter this information :" << endl;
    cin >> pos;
    cout << "Name of the employee: " << endl;
    cin >> temp->name;
    cout << "Name of the previous company : " << endl;
    cin >> temp->company_name;
    cout << "Enter the previous package : " << endl;
    cin >> temp->previous_package;
    cout << "Enter the cgpa" << endl;
    cin >> temp->cgpa;
    temp->next = NULL;

    if (pos == 1)
    {
        temp->next = head;
        head = temp;
    }

    else if (pos >= len)
    {
        p = head;

        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
    else
    {
        p = head;

        for (int i = 1; i < pos - 1; i++)
        {
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;
    }

    len++;
    cout << "Data inserted " << endl;
}
void sll ::delet()
{
    Node *temp, *p;
    int pos;
    cout << "Enter the position of employee's info you want to delete : " << endl;
    cin >> pos;
    if (pos > len)
    {
        cout << "The position doesn't exist" << endl;
    }
    else if (pos == 1)
    {
        temp = head;
        head = head->next;
        delete temp;
        len--;
    }
    else if (pos == len)
    {
        p = head;
        for (int i = 1; i < len - 1; i++)
        {
            p = p->next;
        }
        temp = p->next;
        p->next = NULL;
        delete temp;
        len--;
    }
    else
    {
        p = head;
        for (int i = 1; i < pos - 1; i++)
        {
            p = p->next;
        }
        temp = p->next;
        p->next = temp->next;
        delete temp;
        len--;
    }
}

int main()
{
    sll a;

    a.create();
    a.display();
    a.insert();
    a.delet();
    return 0;
}