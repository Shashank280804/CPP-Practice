/*
Name: Shashank Patil 
Roll no: 27
Batch: A2
Div: A 
PRN: 202101040077
Aim- Design and develop a program for polynomial addition , multiplication operations 
    for disease information using circular linked list.*/

#include <iostream>
using namespace std;

class node
{
public:
    int coeff;
    int expo;
    node *next;
};

class Polynomial
{
public:
    node *head;
    Polynomial()
    {
        head = NULL;
    }

    void sort_create(node *temp);
    void display();
    void add(Polynomial p1, Polynomial p2);
    void mul(Polynomial p1, Polynomial P2);
};

void Polynomial::sort_create(node *temp)
{
    node *p;
    if (head == NULL)
    {
        head = temp;
    }
    else if (temp->expo > head->expo)
    {
        temp->next = head;
        p = head;

        while (p->next != head)
        {
            p = p->next;
        }
        p->next = temp;
        head = temp;
    }
    else if (temp->expo == head->expo)
    {
        head->coeff += temp->coeff;
    }
    else
    {
        p = head;
        int f = 0;
        while (1)
        {
            if (p->expo == temp->expo)
            {
                p->coeff += temp->coeff;
                f = 2;
                break;
            }
            else if ((p->expo > temp->expo && temp->expo > p->next->expo) || (p->next == head))
            {
                f = 1;
                break;
            }
            else

                p = p->next;
        }
        if (f == 1)
        {
            temp->next = p->next;
            p->next = temp;
        }
    }
}

void Polynomial::display()
{
    node *p = head;
    while (p->next != head)
    {
        cout << p->coeff << "x^" << p->expo << "+";
        p = p->next;
    }
    cout << p->coeff << "x^" << p->expo << "=0";
}

void Polynomial::add(Polynomial p1, Polynomial p2)
{
    node *t1, *t2, *t3;
    t1 = p1.head;
    t2 = p2.head;

    if (p1.head == NULL && p2.head == NULL)
    {
        cout << "Both Polynomial are empty" << endl;
        return;
    }

    do
    {
        t3 = new node;
        t3->coeff = t1->coeff;
        t3->expo = t1->expo;

        t3->next = t3;
        sort_create(t3);
        t1 = t1->next;
    } while (t1 != p1.head);

    do
    {
        t3 = new node;
        t3->coeff = t2->coeff;
        t3->expo = t2->expo;

        t3->next = t3;
        sort_create(t3);
        t2 = t2->next;
    } while (t2 != p2.head);
}

void Polynomial ::mul(Polynomial p1, Polynomial p2)
{
    node *t1, *t2, *t3;
    t1 = p1.head;
    t2 = p2.head;
    if (p1.head == NULL && p2.head == NULL)
    {
        cout << "Both Polynomial are empty" << endl;
        return;
    }

    do
    {
        t2 = p2.head;
        do
        {

            t3 = new node;
            t3->coeff = t1->coeff * t2->coeff;
            t3->expo = t1->expo + t2->expo;
            t3->next = t3;
            sort_create(t3);
            t2 = t2->next;
        } while (t2 != p2.head);
        t1 = t1->next;
    } while (t1 != p1.head);
}

int main()
{
    Polynomial p1, p2, p3, p4;
    int ans, choice, ch;
    node *t;

    cout << "Polynomial 1: " << endl;
    do
    {
        t = new node;
        cout << "Please enter the co-efficient: ";
        cin >> t->coeff;
        cout << "Please enter the exponent: ";
        cin >> t->expo;
        t->next = t;
        p1.sort_create(t);

        cout << "\nEnter 1 to continue or 0" << endl;
        cin >> ans;

    }

    while (ans == 1);
    p1.display();
    cout<<"\n"<<endl;
    cout << "Polynomial 2: " << endl;
    do
    {
        t = new node;
        cout << "Please enter the co-efficient: ";
        cin >> t->coeff;
        cout << "Please enter the exponent: ";
        cin >> t->expo;
        t->next = t;

        p2.sort_create(t);

        cout << "\nEnter 1 to continue or press 0 " << endl;
        cin >> ans;

    } while (ans == 1);
    p2.display();
    cout << "\n\n"
         << endl;

    do
    {
        
        cout << "1) Addition \n2) Multiplication\n"<< endl;
        cout << "Enter the choice : ";
        cin >> choice;

        switch (choice)
        {

        case 1:
        {
            cout << "The Addition of the Polynomial is : " << endl;
            p3.add(p1, p2);
            cout << endl;
            p3.display();
            break;
        }
        case 2:
        {
            cout << "The Multiplication of the Polynomialn is:" << endl;
            p4.mul(p1, p2);
            cout << endl;
            p4.display();
            break;
        }
        }
        cout<<"\n press 1 else press 0 whether to stop: ";
        cin>>ch;
        cout<<"\n";
    }

    while (ch == 1);
    return 0;
}

/*OUTPUT
Polynomial 1: 
Please enter the co-efficient: 
5
Please enter the exponent: 
2


Enter 1 to continue or 0
1
Please enter the co-efficient: 
4
Please enter the exponent: 
1

Enter 1 to continue or 0
0
5x^2+4x^1=0

Polynomial 2: 
Please enter the co-efficient: 
6
Please enter the exponent: 2

Enter 1 to continue or press 0
1
Please enter the co-efficient:
7
Please enter the exponent: 1

Enter 1 to continue or press 0
0
6x^2+7x^1=0


1) Addition
2) Multiplication

Enter the choice : 1
The Addition of the Polynomial is :

11x^2+11x^1=0
 press 1 else press 0 whether to stop: 1

1) Addition
2) Multiplication

Enter the choice : 2
The Multiplication of the Polynomialn is:

30x^4+59x^3+28x^2=0
 press 1 else press 0 whether to stop: 0


c:\Shashank\Code\C Language\Basics\Cpp>
*/