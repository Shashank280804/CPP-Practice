#include <iostream>
using namespace std;
class Node
{
public:
    int roll_no;
    float marks;
    Node *prev, *next;
};
class mark_list
{
public:
    Node *head;

    mark_list()
    {
        head = NULL;
    }
    int create();
    void display();
    void bubblesort(int count);
    mark_list mergesort(mark_list l1, mark_list l2);
    Node *swap(Node *p1, Node *p2);
};
int mark_list ::create()

{
    int roll_no, count;
    float marks;
    cout << "\nEnter Total No. Of Students: ";
    cin >> count;

    for (int i = 0; i < count; i++)
    {
        Node *new_Node = new Node;
        cout << "Enter Roll No. of Student: ";
        cin >> new_Node->roll_no;
        cout << "Enter Mark Of Student: ";
        cin >> new_Node->marks;
        cout << endl;

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
void mark_list ::display()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << "\n\t Roll NO : " << temp->roll_no << endl;
        cout << "\t marks : " << temp->marks << endl;
        temp = temp->next;
    }
}
Node *mark_list::swap(Node *p1, Node *p2)
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

void mark_list::bubblesort(int count)
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
mark_list mark_list ::mergesort(mark_list l1, mark_list l2)
{
    {   
        mark_list l3;
        Node *a = l1.head;
        Node *b = l2.head;
        Node *c = NULL;
        if (a == NULL)
        {
            l3.head = b;
            return l3;
        }
        else if (b == NULL)
        {
            l3.head = a;
            return l3;
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
            l3.head = c;
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
            else 
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
        }return l3;
        
    }
}

int main()
{
    mark_list l1, l2, l3;
    int c;
    cout << "\nCreate marks list 1: ";
    l1.create();
    l1.bubblesort(c);
    cout << "\nSorted marks list 1: ";
    l1.display();
    cout << "\nCreate marks list 2: ";
    l2.create();
    l2.bubblesort(c);
    cout << "\nSorted marks list 2: ";
    l2.display();
    cout << "\nFinal sorted list: ";
    l3 = l3.mergesort(l1, l2);
    l3.display();
}
