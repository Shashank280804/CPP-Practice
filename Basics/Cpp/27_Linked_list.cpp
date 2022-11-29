/*Name:Shashank Patil
  Roll number: 27
  Division: A
  Batch : A2
  PRN No: 202101040077

  Aim:Design and develop a program for insertion,deletion,updating,searching,sorting,listing operations using
  singly linked list for a placement information sysytem

*/
#include <iostream>
#include <string.h>
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
    void search(void);
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
        cout << "Enter the name of previous company" << endl;
        cin >> temp->company_name;
        temp->next = NULL;    
        len++;
        if (head == NULL)  //captain koni ch nhi ahe
        {
            head = temp;  //shashank pahla ala mhanun captain krun takla
        }
        else
        {
            p = head;  //baburao la head point krt ahe  ani toh list traverse krel johparyant ekhadya node cha next null bhetat nhi tohparyant
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp; //jithe pudhchya node cha address null bhetla tithe temp attach kela
        }
        cout << "Do you want to add more employee? " << endl;
        cin >> ch;
    } while (ch == 'y');
}
void sll ::display(void)
{
    node *p;
    p = head;    
    while (p != NULL)   //swatah null ahe ka nsel tr swatha cha data print krr ani baburao la smor dhaklel check krayla
    {

        cout << " Employee Name : " << p->employee_name << endl;
        cout << " Cgpa : " << p->cgpa << endl;
        cout << " previous package : " << p->previous_pack << endl;
        cout << "  previous company name: " << p->company_name << endl;
        p = p->next;  //swatha cha data lihun baburao la smor pathavla register gheun
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

    cout << "Enter the position where you want to enter this information : " << endl;
    cin >> pos;
    if (pos == 1)  //head la enter  kraych asel navin node tr pos == 1 
    {
        temp->next = head; //ayush point krt shashank (previous captain)
        head = temp;   //ayush(navin node) la captain banavla
    }
    else if (pos > len) //insert at last
    {
        p = head;  //baburao chk krt rahil last paryant jithe address null sapadla tithe temp la attach kela
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
    else  //insert at given position
    {
        p = head;   
        for (int i = 1; i < pos - 1; i++) //pos==4,
                                                //then i=1;1<4-1;i++; true                                                
                                                    //  i=2;2<4-1;i++; true
        {                                           //  i=3;3<4-1;i++; false  //hence number of passes =2 therefore pos-1;
            p = p->next;                            //  p=p->next is executing 2 times for position 4
        }
        temp->next = p->next; //diagram
        p->next = temp;
    }
    len++;    //increasing the size of the list after the insertion
    cout << "your data is inserted " << endl;
}
void sll ::dele(void)
{
    node *temp, *p;
    int pos;
    cout << "Enter the position of employee in list you want to delete : " << endl;
    cin >> pos;
    if (pos > len) //list ahe 4 janachi incase user ni 6 number delete krayla sangitl tr position does not exist
    {
        cout << "The position do not exist" << endl;
    }
    else if (pos == 1) //delete at first
    {
        temp = head;       //ayush la delete kraych ahe mhanun ayush la temp mdhe save kel
        head = head->next; //captain shashank la banavla(head la smor dhaklla)
        delete temp;       //ayush la delete kel
        len--;             // size kami keli
    }
    // else if (pos == len)    //insert at last
    // {
    //     p = head;       // baburao traverse krnyasathi
    //     for (int i = 1; i < len - 1; i++) //same as insert at middle
    //     {
    //         p = p->next;
    //     }
    //     temp = p->next;  //
    //     p->next = NULL;   //
    //     delete temp;
    //     len--;
    // }
    else if(pos == len)
    {
        p = head;
        while(p->next->next!=NULL){
            p = p->next;
        }
        temp = p->next;
        p->next = NULL;
        delete temp;
        len --;
    }
    else //insert at middle
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
void sll ::search(void)
{
    string s;
    node *p;
    int flag = 0, pos = 1;
    cout << "Enter the name of employee's information that you want to search :  " << endl;
    cin >> s;
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

int main()
{
    sll a;
    int choice;
    a.create();
    a.display();

    do
    {
        cout << "What action you want to perform ??" << endl;
        cout << " 1)Insert \n 2)Delete \n 3) Search \n 4) Display \n 5) Exit \n " << endl;
        cout << "Enter your choice : " << endl;
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
            a.search();
            a.display();
            break;
        case 4:
            a.display();
            break;
        case 5:
            cout << "Thanks for the information" << endl;
            break;

        default:
            cout << "does not exist" << endl;
        }
    } while (choice != 5);
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