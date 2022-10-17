/*Name:Shashank Patil
  Roll number: 27
  Division: A
  Batch : A2
  PRN No: 202101040077

  Aim:Design and develop a program for insertion,deletion,updating,searching,sorting,listing operations using 
  singly linked list for a placement information sysytem
  
*/
#include <iostream>
#include<string.h>
using namespace std;
class node
{
public:
    string employee_name;
    float cgpa;
    float previous_pack;
    string company_name;
    node *next;
};
class sll
{
public:
    node *head;
    int len;

    sll()
    {
        head = NULL;
        len = 0;
    }
    void create(void);
    void display(void);
    void insert(void);
    void dele(void);
    void update(void);
    void search(void);
    void sort(void);
};
void sll ::create(void)
{
    node *temp, *p;
    char ch;

    do
    {
        temp = new node;
        
        cout << "Enter Name of the employee : " << endl;
        cin >> temp->employee_name;
        cout << "Enter the cgpa : " << endl;
        cin >> temp->cgpa;
        cout << "Enter the previous package  : " << endl;
        cin >> temp->previous_pack;
        cout<<"Enter the name of previous company"<<endl;
        cin >> temp->company_name;
        temp->next = NULL;
        len++;
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
        cout << "Do you want to add more employee? " << endl;
        cin >> ch;
    } while (ch == 'y');
}
void sll ::display(void)
{
    node *p;
    p = head;
    while (p != NULL)
    {
        
        cout << " Employee Name : " << p->employee_name << endl;
        cout << " Cgpa : " << p->cgpa << endl;
        cout << " previous package : " << p->previous_pack << endl;
        cout << "  previous company name: "<<p->company_name<<endl;
        p = p->next;
    }
}
void sll ::insert()
{
    node *temp, *p;
    int pos;
    temp = new node;
    
    cout << "Enter the employee name : " << endl;
    cin >> temp->employee_name;
    cout << "Enter the cgpa : " << endl;
    cin >> temp->cgpa;
    cout << "Enter the previous package : " << endl;
    cin >> temp->previous_pack;
    cout << "Enter the previous company name : " << endl;
    cin >> temp->company_name;
    temp->next = NULL;
    cout << "Enter the position where you want to enter this information : "<<endl;
    cin >> pos;
    if (pos == 1)
    {
        temp->next = head;
        head = temp;
    }
    else if (pos > len)
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
    cout << "your data is inserted " << endl;
}
void sll ::dele(void)
{
    node *temp, *p;
    int pos;
    cout << "Enter the position of employee in list you want to delete : " << endl;
    cin >> pos;
    if (pos > len)
    {
        cout << "The position do not exist" << endl;
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
void sll ::update(void)
{
    node *p;
    int pos, choice;
    cout << "Enter the position of employee in list whose infoermation has to be  update : "<<endl;
     cin >>pos;
    cout << "What information you want to update : " << endl;
    cout << "1. Name \n 2.previous package \n 3. cgpa 4.company name" << endl;
    cout << "Enter your choice : " << endl;
    cin >> choice;
    if (pos > len)
    {
        cout << "Position does'nt exist !!" << endl;
    }
    else if (pos == 1)
    {
        p = head;
    }
    else
    {
        p = head;
        for (int i = 1; i < pos; i++)
        {
            p = p->next;
        }
    }
    switch (choice)
    {
    case 1:
        cout << "Enter the updated name : " << endl;
        cin >> p->employee_name;
        break;
    case 2:
        cout << "Enter the updated roll number : " << endl;
        cin >> p->cgpa;
        break;
    case 3:
        cout << "Enter the updated package : " << endl;
        cin >> p->previous_pack;
        break;
    case 4:
        cout<< "Enter the updated company name: "<<endl;
        cin>> p->company_name;
    default:
        cout << " Choice is invalid" << endl;
    }
    cout << "Information has been updated " << endl;
}
void sll ::search(void)
{
    string s;
    node *p;
    int flag = 0, pos = 1;
    cout << "Enter the name of employee's information that you want to search :  "<<endl;
            cin >>  s;
    p = head;
    while (p != NULL)
    {
        if (p->employee_name == s)
        {
            flag++;
            break;
        }
        else
        {
            p = p->next;
        }
        pos++;
    }
    if (flag == 0)
    {
        cout << "The employee is not in our record" << endl;
    }
    else
    {
    
        cout << " Employee name : " << p->employee_name << endl;
        cout << " cgpa : " << p->cgpa << endl;
        cout << " previous package : " << p->previous_pack << endl;
        cout << "Position in record : " << pos << endl;
    }
}
void sll ::sort()
{
    node *prev, *curr;
    int c, p;
    string n;

    for (int i = 0; i < len; i++)
    {
        prev = head;
        curr = head->next;
        while (curr != NULL)
        {
            if (prev->cgpa > curr->cgpa)
            {
                n = curr->employee_name;
                p = curr->previous_pack;
                c = curr->cgpa;
                curr->employee_name = prev->employee_name;
                curr->cgpa = prev->cgpa;
                curr->previous_pack = prev->previous_pack;
                prev->employee_name = n;
                prev->cgpa = c;
                prev->previous_pack = p;
                prev = prev->next;
                curr = curr->next;
            }
            else
            {
                prev = prev->next;
                curr = curr->next;
            }
        }
    }
    display();
}
int main()
{
    sll a;
    int choice;
    a.create();
    a.display();

    do
    {
        cout << "What action you want to perform ??" << endl;
 cout<<" 1)Insert \n 2)Delete \n 3) Update \n 4) Search \n 5) Sort \n 6) Exit"<<endl;
 cout<<"Enter your choice : "<<endl;
 cin >> choice;
 switch (choice)
 {
 case 1:
     a.insert();
     a.display();
     break;
 case 2:
     a.dele();
     a.display();
     break;
 case 3:
     a.update();
     a.display();
     break;
 case 4:
     a.search();
     a.display();
     break;
 case 5:
     a.sort();
     a.display();
     break;
 case 6:
     cout << "Thanks for the information" << endl;
     break;
 default:
     cout << "does not exist" << endl;
 }
    } while (choice != 6);
}
/*
Enter Name of the employee : 
shashank
Enter the cgpa : 
9
Enter the previous package  : 
800000
Enter the name of previous company
tavisca
Do you want to add more employee? 
y
Enter Name of the employee : 
sankalp
Enter the cgpa : 
9
Enter the previous package  : 
900000
Enter the name of previous company
microsoft
Do you want to add more employee? 
n
 Employee Name : shashank
 Cgpa : 9
 previous package : 800000
  previous company name: tavisca
 Employee Name : sankalp
 Cgpa : 9
 previous package : 900000
  previous company name: microsoft
What action you want to perform ??
 1)Insert
 2)Delete
 3) Update
 4) Search
 5) Sort
 6) Exit
Enter your choice :
1
Enter the employee name :
Hitanshu
Enter the cgpa :
8
Enter the previous package :
89000
Enter the previous company name :
capgemini
Enter the position where you want to enter this information :
2
your data is inserted
 Employee Name : shashank
 Cgpa : 9
 previous package : 800000
  previous company name: tavisca
 Employee Name : Hitanshu
 Cgpa : 8
 previous package : 89000
  previous company name: capgemini
 Employee Name : sankalp
 Cgpa : 9
 previous package : 900000
  previous company name: microsoft
What action you want to perform ??
 1)Insert
 2)Delete
 3) Update
 4) Search
 5) Sort
 6) Exit
Enter your choice :
2
Enter the position of employee in list you want to delete :
2
 Employee Name : shashank
 Cgpa : 9
 previous package : 800000
  previous company name: tavisca
 Employee Name : sankalp
 Cgpa : 9
 previous package : 900000
  previous company name: microsoft
What action you want to perform ??
 1)Insert
 2)Delete
 3) Update
 4) Search
 5) Sort
 6) Exit
Enter your choice :
3
Enter the position of employee in list whose infoermation has to be  update :
2
What information you want to update :
1. Name
 2.cgpa
 3. previous package 4.company name
Enter your choice :
3
Enter the updated package :
78000
Information has been updated
 Employee Name : shashank
 Cgpa : 9
 previous package : 800000
  previous company name: tavisca
 Employee Name : sankalp
 Cgpa : 9
 previous package : 78000
  previous company name: microsoft
What action you want to perform ??
 1)Insert
 2)Delete
 3) Update
 4) Search
 5) Sort
 6) Exit
Enter your choice :
4
Enter the name of employee's information that you want to search :
shashank
 Employee name : shashank
 cgpa : 9
 previous package : 800000
Position in record : 1
 Employee Name : shashank
 Cgpa : 9
 previous package : 800000
  previous company name: tavisca
 Employee Name : sankalp
 Cgpa : 9
 previous package : 78000
  previous company name: microsoft
What action you want to perform ??
 1)Insert
 2)Delete
 3) Update
 4) Search
 5) Sort
 6) Exit
Enter your choice :
5
 Employee Name : shashank
 Cgpa : 9
 previous package : 800000
  previous company name: tavisca
 Employee Name : sankalp
 Cgpa : 9
 previous package : 78000
  previous company name: microsoft
 Employee Name : shashank
 Cgpa : 9
 previous package : 800000
  previous company name: tavisca
 Employee Name : sankalp
 Cgpa : 9
 previous package : 78000
  previous company name: microsoft
What action you want to perform ??
 1)Insert
 2)Delete
 3) Update
 4) Search
 5) Sort
 6) Exit
Enter your choice :
5
 Employee Name : shashank
 Cgpa : 9
 previous package : 800000
  previous company name: tavisca
 Employee Name : sankalp
 Cgpa : 9
 previous package : 78000
  previous company name: microsoft
 Employee Name : shashank
 Cgpa : 9
 previous package : 800000
  previous company name: tavisca
 Employee Name : sankalp
 Cgpa : 9
 previous package : 78000
  previous company name: microsoft
What action you want to perform ??
 1)Insert
 2)Delete
 3) Update
 4) Search
 5) Sort
 6) Exit
Enter your choice :
5
 Employee Name : shashank
 Cgpa : 9
 previous package : 800000
  previous company name: tavisca
 Employee Name : sankalp
 Cgpa : 9
 previous package : 78000
  previous company name: microsoft
 Employee Name : shashank
 Cgpa : 9
 previous package : 800000
  previous company name: tavisca
 Employee Name : sankalp
 Cgpa : 9
 previous package : 78000
  previous company name: microsoft
What action you want to perform ??
 1)Insert
 2)Delete
 3) Update
 4) Search
 5) Sort
 6) Exit

What action you want to perform ??
 1)Insert
 2)Delete
 3) Update
 4) Search
 5) Sort
 6) Exit
Enter your choice :
6*/