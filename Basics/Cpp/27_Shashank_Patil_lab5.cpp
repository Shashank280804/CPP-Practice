/*
    Name: Shashank Patil
    Roll no: 27
    PRN :202101040077
    Batch: A2
    Division : A

Aim:Design and implement a program for sorting two given lists and merging these two sorted lists
 of marks scored for technical skill examination of recruitment cell using a doubly linked list.
*/



#include <iostream>
using namespace std;
class node 
{
public:
    int roll_no;
    float marks;
    node *prev, *next;
};
class Marklist 
{
public:
    node *head;
    int len;
    Marklist()
    {
        head = NULL;
        len = 0;
    }
    void create();  
    void display(); 
    void sort();   
    node *swap(node *ptr1, node *ptr2);
    void merge(Marklist l1, Marklist l2);
};
void Marklist ::create() 

{
    int size, roll_no;
    float marks;
    node *curr;
    cout << "\n Enter Total No Of Students : ";
    cin >> size;
    len = size;
    for (int data_of_student = 0; data_of_student < size;
         data_of_student++)
    {
        cout << "\n Enter Roll No of Student " << data_of_student + 1 << ":";
        cin >> roll_no;
        cout << " Enter Mark Of Student " << data_of_student + 1 << " : ";
        cin >> marks;
        node *new_node = new node;
        new_node->roll_no = roll_no;
        new_node->marks = marks;
        new_node->prev = NULL;
        new_node->next = NULL;
        if (head == NULL)
        {
            head = new_node;
            curr = new_node;
        }
        else
        {
            curr->next = new_node;
            new_node->prev = curr;
            curr = new_node;
        }
    }
}
void Marklist ::display() 
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << "\n\t Roll NO : " << temp->roll_no << endl;
        cout << "\t marks : " << temp->marks << endl;
        temp = temp->next;
    }
}
void Marklist::sort() 
{
    node **h;
    int swapped, i, j;
    for (i = 0; i < len; i++)
    {
        h = &(head);
        swapped = 0;
        for (j = 0; j < len - i - 1; j++)
        {
            node *p1 = *h;
            node *p2 = p1->next;
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
node *Marklist::swap(node *ptr1, node *ptr2)
{
    if (ptr1->prev == NULL)
    {
        node *temp = ptr2->next;
        ptr2->next = ptr1;
        ptr2->prev = NULL;
        ptr1->next = temp;
        ptr1->prev = ptr2;
        temp->prev = ptr1;
        return ptr2;
    }
    else if (ptr2->next == NULL)
    {
        node *temp = ptr1->prev;
        ptr2->next = ptr1;
        ptr2->prev = temp;
        ptr1->prev = ptr2;
        ptr1->next = NULL;
        temp->next = ptr2;
        return ptr2;
    }
    else
    {
        node *temp1 = ptr1->prev;
        node *temp2 = ptr2->next;
        ptr2->next = ptr1;
        ptr2->prev = temp1;
        ptr1->prev = ptr2;
        ptr1->next = temp2;
        temp2->prev = ptr1;
        temp1->next = ptr2;
        return ptr2;
    }
}
void Marklist ::merge(Marklist l1,Marklist l2)
{
    node *a = l1.head;
    node *b = l2.head;
    len = l1.len + l2.len;
    node *c = NULL;
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
int main()
{
    Marklist list1, list2, list3;
    cout << "\n\t create marks list 1 : ";
    list1.create();
    list1.sort();
    cout << "\n\tSorted marks list 1 : \n\n";
    list1.display();
    cout << "\n\n\t create marks list 2 : ";
    list2.create();
    list2.sort();
    cout << "\n\tSorted marks list 2 : \n\n ";
    list2.display();
    list3.merge(list1, list2);
    list3.sort();
    cout << "\n\n\tfinal sorted list \n";
    list3.display();
}

/*
OUTPUT:c:\Shashank\Code\C Language\Basics\Cpp>cd "c:\Shashank\Code\C Language\Basics\Cpp\" && g++ 27_Shashank_Patil_lab5.cpp -o 27_Shashank_Patil_lab5 && "c:\Shashank\Code\C Language\Basics\Cpp\"27_Shashank_Patil_lab5

        create marks list 1 :
Enter Total No Of Students : 5

Enter Roll No of Student 1:1
Enter Mark Of Student 1 : 25

Enter Roll No of Student 2:2
Enter Mark Of Student 2 : 16

Enter Roll No of Student 3:14
Enter Mark Of Student 3 : 36

Enter Roll No of Student 4:13
Enter Mark Of Student 4 : 37

Enter Roll No of Student 5:12
Enter Mark Of Student 5 : 18

       Sorted marks list 1 :


        Roll NO : 13
        marks : 37

        Roll NO : 14
        marks : 36

        Roll NO : 1
        marks : 25

        Roll NO : 12
        marks : 18

        Roll NO : 2
        marks : 16


        create marks list 2 :
Enter Total No Of Students : 4

Enter Roll No of Student 1:17
Enter Mark Of Student 1 : 16

Enter Roll No of Student 2:19
Enter Mark Of Student 2 : 46

Enter Roll No of Student 3:21
Enter Mark Of Student 3 : 78

Enter Roll No of Student 4:24
Enter Mark Of Student 4 : 32

       Sorted marks list 2 :


        Roll NO : 21
        marks : 78

        Roll NO : 19
        marks : 46

        Roll NO : 24
        marks : 32

        Roll NO : 17
        marks : 16


       final sorted list

        Roll NO : 21
        marks : 78

        Roll NO : 19
        marks : 46

        Roll NO : 13
        marks : 37

        Roll NO : 14
        marks : 36

        Roll NO : 24
        marks : 32

        Roll NO : 1
        marks : 25

        Roll NO : 12
        marks : 18

        Roll NO : 2
        marks : 16

        Roll NO : 17
        marks : 16

c:\Shashank\Code\C Language\Basics\Cpp>
*/