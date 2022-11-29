#include<iostream>
using namespace std;

class Node {
    public:
        string emp_name;
        float cgpa;
        float prev_pack;
        string cmp_name;
        Node *next;
};

class SLL {
    public:
     Node *head;
     int len;
     SLL() {
        head = NULL;
        len = 0;
     }
        void create();
        void display();
};


// data = d 
// next = NULL




 void SLL :: create() {
    Node *temp = new Node;
    char ch;

    do {
        cout << "Enter Name of the employee : " << endl;
        cin >> temp->emp_name;
        cout << "Enter the cgpa : " << endl;
        cin >> temp->cgpa;
        cout << "Enter the previous package  : " << endl;
        cin >> temp->prev_pack;
        cout << "Enter the name of previous company" << endl;
        cin >> temp->cmp_name;

        temp->next = NULL;
        len++;
        
        if (head == NULL)
        {
            head = temp;
        }
    } while(ch == 'y');

    
 }

int main() {
    

   
    

    return 0;
}