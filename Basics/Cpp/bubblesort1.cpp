#include<iostream>
using namespace std;
class Node
{
public:
    int roll_no;
    float marks;
    Node *prev, *next;
};
class marklist
{
public:
    Node *head;
    int len;

    marklist()
    {
        head = NULL;
    }
    int create();
    void display();
    void bubblesort(int count);
    void mergesort(marklist l1, marklist l2);
    Node *swap(Node *p1, Node *p2);
};

int marklist ::create()
{
    int roll_no, count;
    float marks;
    cout << "\n Enter total no of students : ";
    cin >> count;

    for (int i = 0; i < count; i++)
    {
        Node *new_Node = new Node;
        cout << "\n Enter roll no of student ";
        cin >> new_Node->roll_no;
        cout << " Enter mark of student ";
        cin >> new_Node->marks;

        new_Node->prev = NULL;
        new_Node->next = NULL;
        if (head == NULL)
        {
            head = new_Node;
        }
        else
        {
            new_Node->next = head;
            head = new_Node;
        }
    }
    return count;
}
void marklist ::display()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << "\n\t Roll NO : " << temp->roll_no << endl;
        cout << "\t marks : " << temp->marks << endl;
        temp = temp->next;
    }
}
Node *marklist::swap(Node *p1, Node *p2)
{
    if (p1->prev == NULL)
    {
        Node *temp = p2->next;
        p2->next = p1;
        p2->prev = p1->prev;
        p1->next = temp;
        p1->prev = p2;
        temp->prev = p1;
        return p2;
    }
}

void marklist::bubblesort(int count)
{
    Node **h;
    int swapped, i, j;
    for (i = 0; i < count; i++)
    {
        h = &(head);
        swapped = 0;
        for (j = 0; j < count - i - 1; j++)
        {
            Node *p1 = *h;
            Node *p2 = p1->next;
            if (p1->marks < p2->marks)
            {
                *h = swap(p1, p2);
                swapped = 1;
            }
            h = &(*h)->next;
        }
        if (swapped == 0)
        {
            break;
        }
    }
}
void marklist ::mergesort(marklist l1, marklist l2)
{
    {
        Node *a = l1.head;
        Node *b = l2.head;
        len = l1.len + l2.len;
        Node *c = NULL;
        if (a == NULL)
        {
            head = b;
        }
        else if (b == NULL)
        {
            head = a;
        }
        else if (a != NULL && b != NULL)
        {
            if (a->marks < b->marks)
            {
                c = a;
                a = a->next;
            }
            else
            {
                c = b;
                b = b->next;
            }
            head = c;
        }
        while (a != NULL && b != NULL)
        {
            if (a->marks <= b->marks)
            {
                c->next = a;
                a->prev = c;
                c = a;
                a = a->next;
            }
            else if (a->marks > b->marks)
            {
                c->next = b;
                b->prev = c;
                c = b;
                b = b->next;
            }
        }
        if (a == NULL)
        {
            c->next = b;
            b->prev = c;
        }
        else if (b == NULL)
        {
            c->next = a;
            a->prev = c;
        }
    }
}

int main()
{
    marklist l1, l2, l3;
    int c;
    cout << "\n\t create marks list 1 : ";
    l1.create();
    l1.bubblesort(c);
    cout << "\n\tSorted marks list 1 : \n\n";
    l1.display();
    cout << "\n\n\t create marks list 2 : ";
    l2.create();
    l2.bubblesort(c);
    cout << "\n\tSorted marks list 2 : \n\n ";
    l2.display();
    l3.mergesort(l1, l2);
    l3.bubblesort(c);
    cout << "\n\n\tfinal sorted list \n";
    l3.display();
}