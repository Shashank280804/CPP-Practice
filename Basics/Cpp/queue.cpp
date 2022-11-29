#include <iostream>
using namespace std;
#define max 50
class fooditems
{
public:
    string item;
    int price;
    int quantity;
    fooditems()
    {
        item = "";
        price = 0;
        quantity = 0;
    }
};
class AQueue
{
    fooditems Q[max];                   //size of queue
    int rear, front;                    

public:
    AQueue()
    {
        front = -1;             //list is empty,so keeping pointer at random location
        rear = -1;
    }
    bool isempty()
    {
        if (front == -1)        //list empty
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isfull()
    {
        if (rear == (max - 1))      //0psun start zali yamule (max-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void enqueue()
    {
        if (rear == (max - 1))
        {
            cout << "full" << endl;
        }
        else
        {
            rear++;         //magun add kel
            cout << "Enter the item name : " << endl;
            cin >> Q[rear].item;        //rear shashank vr gela{0}
            cout << "Enter the price : " << endl;
            cin >> Q[rear].price;
            cout << "Enter the Quantity : " << endl;
            cin >> Q[rear].quantity;
            if (front == -1)        //front shashankvr gela{0} front smor nela phele -1 vr hota tr tithe koni navta tyamule.//he hrvels nhi honar ekda q[1] vr alyvr
            {
                front++;  //shashank{0}
            }
        }//ata front ani rear eka ch jagi point krt ahe nntr front shashank la ch rahil but rear smor jat rahil,
        // delete krtani shashank psun delete hoil mhanje front psun delete hot rahil ani front++ hot rahil mgg 2nd la vaishnavi ahe ti ata 1st la rahil
        // mhanje front vaishnavi la point krel
    }
    string dequeue()
    {
        if (front == -1)
        {
            cout << "Empty" << endl;
            return 0;
        }
        else
        {
            string item = Q[front].item;  //front valyach ch nav ghetla shjashank ch nav vghetla
            if (front == rear)          //front ani rear ekach jagi ahe ka check krt ahe
            {
                front = -1;             //1 ch jan queue mdhe asel tr dequeue kelyvr list empty hoil so tyamule front ani rear reset hoil so -1. 
                rear = -1;
            }
            else
            {
                front++;            //incase 3 jan ahe(shashank 0,vaishanvi 1,ayush 2)
                                    //shashank gela baher ticket kadun queue chya tymule front++ mhanje front vaishnavi Q[1]vr gela.
            }
            return item;        //shashank baher gela so cout mdhe <<shashank has been removed from queue; vala part ahe
        }
    }
    void display()
    {
        if (front == -1)
        {
            cout << "Empty" << endl;
        }
        else
        {           //i=vaishnavi Q[1];i<=ayush Q[2];i++;  vaishnavi psun ayush paryant display krt rahil
            for (int i = front; i <= rear; i++)
            {
                cout << "Item name : " << Q[i].item << endl;
                cout << "Item price : " << Q[i].price << endl;
                cout << "Item Quantity : " << Q[i].quantity << endl;
            }
        }
    }
};
class node
{
public:
    string item;
    int price, quantity;
    node *next;
};
class LQueue
{
    node *front, *rear;

public:
    LQueue()
    {
        front = NULL;
        rear = NULL;
    }
    void enqueue()
    {
        node *temp;
        temp = new node;
        cout << "Enter the name of item : " << endl;
        cin >> temp->item;
        cout << "Enter the Price : " << endl;
        cin >> temp->price;
        cout << "Enter the Quantity : " << endl;
        cin >> temp->quantity;
        temp->next = NULL;
        if (isempty())
        {
            front = temp;
            rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = rear->next;
        }
    }
    string dequeue()
    {
        string x;
        if (isempty())
        {
            cout << "Queue is empty " << endl;
            return 0;
        }
        else
        {
            node *t = front;
            x = front->item;
            if (front == rear)
            {
                front = NULL;
                rear = NULL;
            }
            else
            {
                front = front->next;
                delete t;
            }
            return x;
        }
    }
    bool isempty()
    {
        if (front == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void display()
    {
        if (isempty())
        {
            cout << "Queue is empty!!!" << endl;
        }
        else
        {
            node *t;
            t = front;
            while (t != NULL)
            {
                cout << "Item Name : " << t->item << endl;
                cout << "Item Price : " << t->price << endl;
                cout << "Item Quatity : " << t->quantity << endl;
                t = t->next;
            }
        }
    }
};
class CAQueue
{
    fooditems CQ[max];
    int front, rear;

public:
    CAQueue()
    {
        front = -1;
        rear = -1;
    }
    int isfull()
    {
        if ((front == 0 && rear == max - 1) || front == (rear + 1))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int isempty()
    {
        if (front == -1 && rear == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void enqueue()
    {
        if (isfull())
        {
            cout << "Queue is full " << endl;
        }
        else
        {
            if (isempty())
            {
                front = 0;
                rear = 0;
            }
            else if (rear == (max - 1))
            {
                rear = 0;
            }
            else
            {
                rear++;
            }
            cout << "Enter the item name : " << endl;
            cin >> CQ[rear].item;
            cout << "Enter the price : " << endl;
            cin >> CQ[rear].price;
            cout << "Enter the Quantity : " << endl;
            cin >> CQ[rear].quantity;
        }
    }
    string dequeue()
    {
        string a = "Queue is empty";
        if (isempty())
        {
            return a;
        }
        else
        {
            a = CQ[front].item;
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            else if (front == max - 1)
            {
                front = 0;
            }
            else
            {
                front++;
            }
            return a;
        }
    }
    void display()
    {
        if (isempty())
        {
            cout << "Queue is empty!!!" << endl;
        }
        else
        {
            if (rear >= front)
            {
                for (int i = front; i <= rear; i++)
                {
                    cout << "Item name : " << CQ[i].item << endl;
                    cout << "Item price : " << CQ[i].price << endl;
                    cout << "Item Quantity : " << CQ[i].quantity << endl;
                }
            }
            else
            {
                for (int i = front; i < max; i++)
                {
                    cout << "Item name : " << CQ[i].item << endl;
                    cout << "Item price : " << CQ[i].price << endl;
                    cout << "Item Quantity : " << CQ[i].quantity << endl;
                }
                for (int i = 0; i <= rear; i++)
                {
                    cout << "Item name : " << CQ[i].item << endl;
                    cout << "Item price : " << CQ[i].price << endl;
                    cout << "Item Quantity : " << CQ[i].quantity << endl;
                }
            }
        }
    }
};
class CLQueue
{
public:
    node *front, *rear;
    CLQueue()
    {
        front = NULL;
        rear = NULL;
    }
    bool isempty()
    {
        if (front == NULL && rear == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void enqueue()
    {
        node *temp;
        temp = new node;
        cout << "Enter the name of item : " << endl;
        cin >> temp->item;
        cout << "Enter the Price : " << endl;
        cin >> temp->price;
        cout << "Enter the Quantity : " << endl;
        cin >> temp->quantity;
        temp->next = temp;
        if (isempty())
        {
            front = temp;
            rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = rear->next;
            rear->next = front;
        }
    }
    string dequeue()
    {
        string x;
        if (isempty())
        {
            cout << "Empty Queue" << endl;
        }
        else
        {
            node *t = front;
            x = front->item;
            if (front == rear)
            {
                front = NULL;
                rear = NULL;
            }
            else
            {
                front = front->next;
                rear->next = front;
            }
            delete t;
            return x;
        }
    }
    void display()
    {
        node *t = front;
        do
        {
            cout << "Item Name : " << t->item << endl;
            cout << "Item Price : " << t->price << endl;
            cout << "Item Quatity : " << t->quantity << endl;
            t = t->next;
        } while (t != front);
    }
};
int main()
{
    LQueue l;
    AQueue a;
    CAQueue ca;
    CLQueue cl;
    char ch = 'y';
    int choice1, choice2;

    cout << "What you want to perform ???" << endl;
    cout << "1. Queue using array \n 2. Queue using Linked list \n 3.Circular Queue using array \n 4. Circular Queue using Linked List "<<endl;
        cout
         << "Enter your choice : " << endl;
    cin >> choice1;
    switch (choice1)
    {
    case 1:
        while (ch == 'y')
        {
            cout << "1. Insert \n 2. Delete \n 3. Display " << endl;
            cin >> choice2;
            switch (choice2)
            {
            case 1:
                a.enqueue();
                break;
            case 2:
                cout << a.dequeue() << " item deleted" << endl;
                break;
            case 3:
                cout << "Your Ordered Items are : " << endl;
                a.display();
                break;
            }
            cout << "Do you want to continue : " << endl;
            cin >> ch;
        }
        break;
    case 2:
        while (ch == 'y')
        {
            cout << "1. Insert \n 2. Delete \n 3. Display " << endl;
            cin >> choice2;
            switch (choice2)
            {
            case 1:
                l.enqueue();
                break;
            case 2:
                cout << l.dequeue() << " item deleted" << endl;
                break;
            case 3:
                cout << "Your Ordered Items are : " << endl;
                l.display();
                break;
            }
            cout << "Do you want to continue : " << endl;
            cin >> ch;
        }
        break;
    case 3:
        while (ch == 'y')
        {
            cout << "1. Insert \n 2. Delete \n 3. Display " << endl;
            cin >> choice2;
            switch (choice2)
            {
            case 1:
                ca.enqueue();
                break;
            case 2:
                cout << ca.dequeue() << " item deleted" << endl;
                break;
            case 3:
                cout << "Your Ordered Items are : " << endl;
                ca.display();
                break;
            }
            cout << "Do you want to continue : " << endl;
            cin >> ch;
        }
        break;
    case 4:
        while (ch == 'y')
        {
            cout << "1. Insert \n 2. Delete \n 3. Display " << endl;
            cin >> choice2;
            switch (choice2)
            {
            case 1:
                cl.enqueue();
                break;
            case 2:
                cout << cl.dequeue() << " item deleted" << endl;
                break;
            case 3:
                cout << "Your Ordered Items are : " << endl;
                cl.display();
                break;
            }
            cout << "Do you want to continue : " << endl;
            cin >> ch;
        }
        break;
    }
}
