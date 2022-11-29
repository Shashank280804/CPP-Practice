#include <iostream>
using namespace std;

class Student
{
public:
    int roll;
    string name;
    Student *next;
    Student *prev;
};

//  prev -> data ->next

class DLL
{
public:
    Student *head;
    int len;
    DLL()
    {
        head = NULL;
        len = 0;
    }
    void create();
    void display();
    void insertAtPos();
    void deleteatpos();
};
void DLL ::create()
{
    Student *temp;
    Student *p;
    char ch;
    do
    {
        temp = new Student;
        cout << "Enter name" << endl;
        cin >> temp->name;
        cout << "Enter roll" << endl;
        cin >> temp->roll;
        temp->next = NULL;
        temp->prev = NULL;

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
            temp->prev = p;
        }
        len++;

        cout << "Do you want to add more students(y/n)";
        cin >> ch;

    } while (ch == 'y');
}
void DLL ::insertAtPos()
{

    Student *temp = new Student();
    cout << "Enter Name: ";
    cin >> temp->name;
    cout << "Enter Roll: ";
    cin >> temp->roll;
    temp->next = NULL;
    temp->prev = NULL;

    int pos;
    cout << "Enter Pos at which u want to insert: ";
    cin >> pos;

    // 1st pos
    // last pos
    // middle pos
    if (head == NULL)
    {
        head = temp;
    }
    else if (pos == 1)
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    else if (pos > len)
    {
        Student *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
        temp->prev = p;
    }
    else
    {
        Student *p = head;
        for (int i = 1; i < pos - 1; i++)
        {
            p = p->next;
        }
        p->next->prev = temp;
        temp->next = p->next;
        p->next = temp;
        temp->prev = p;
    }
    len++;
}
void DLL ::deleteatpos()
{
    Student *temp = new Student;
    Student *curr;
    Student *p;
    int pos;
    cout << "Enter the position of employee in list you want to delete : " << endl;
    cin >> pos;
    if (pos > len)
    {
        cout << "The position do not exist" << endl;
    }
    else if (pos == 1)
    {
        curr = head;
        head = head->next;
        head->prev = NULL;
        delete curr;
        len--;
    }
    else if (pos == len)
    {
        curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->prev->next = NULL;
        delete curr;
        len--;
    }
    else
    {
        Student *curr, *prev;
        prev = head;
        curr = head->next;
        for (int i = 1; i < pos - 1; i++)
        {
            curr = curr->next;
            prev = prev->next;
        }
        curr->next->prev = curr->prev;
        prev->next = curr->next;
        delete curr;
        len--;
    }
}

void DLL ::display()
{
    Student *temp = head;
    while (temp != NULL)
    {
        cout << "Name: " << temp->name << " ";
        cout << "Roll: " << temp->roll << endl;
        temp = temp->next;
    }
}

int main()
{
    DLL std;
    int choice;
    std.create();
    std.display();

    do
    {
        cout << "What action you want to perform ??" << endl;
        cout << " 1)Insert \n 2)Delete \n";
        cout << "Enter your choice : " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            std.insertAtPos();
            std.display();
            break;
        case 2:
            std.deleteatpos();
            std.display();
            break;

        default:
            cout << "does not exist" << endl;
        }
    } while (choice != 3);
    return 0;
}
