#include <iostream>
using namespace std;
class node
{
public:
    int coeff;
    int expo;
    node *next;
};
class poly
{
public:
    node *head;
    poly()
    {
        head = NULL;
    }
    void display();
    void sorted_create(node *temp);
    void add(poly p1, poly p2);
};

void poly::sorted_create(node *temp)
{
    node *p;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {

        if (temp->expo > head->expo)
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
        else
        {
            if (temp->expo == head->expo)
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
                    else if ((temp->expo < p->expo && temp->expo > p->next->expo) || p->next == head)
                    {
                        f = 1;
                        break;
                    }
                    p = p->next;
                }

                if (f == 1)
                {
                    temp->next = p->next;
                    p->next = temp;
                }
            }
        }
    }
}
void poly::display()
{
    node *p = head;
    do
    {
        cout << p->coeff << "x^" << p->expo << "+";
        p = p->next;
    } while (p->next != head);
    cout << p->coeff << "x^" << p->expo << "= 0";
}
void poly::add(poly p1, poly p2)
{
    node *t1, *t2, *t3;
    t1 = p1.head;
    t2 = p2.head;
    do
    {
        t3 = new node;
        t3->coeff = t1->coeff;
        t3->expo = t1->expo;
        t3->next = t3;
        sorted_create(t3);
        t1 = t1->next;
    } while (t1 != p1.head);
    do
    {
        t3 = new node;
        t3->coeff = t2->coeff;
        t3->expo = t2->expo;
        t3->next = t2;
        sorted_create(t3);
        t2 = t2->next;
    } while (t2 != p2.head);
}

int main()
{
    node *temp;
    temp = new node;
    poly p1, p2, p3;
    int ans;
    cout << "Enter the polynomials " << endl;
    do
    {
        temp = new node;
        cout << "Enter the coefficients:\n";
        cin >> temp->coeff;
        cout << "Enter the exponents:\n";
        cin >> temp->expo;
        temp->next = temp;
        p1.sorted_create(temp);

        cout << "Do you want to add more:(1/0):\n";
        cin >> ans;
    } while (ans == 1);
    p1.display();
    cout << "\n"<< endl;
    cout << "Polynomial 2: " << endl;
    do
    {
        temp = new node;
        cout << "Enter the co-efficient for 2nd polynomial: ";
        cin >> temp->coeff;
        cout << "Enter the exponent for 2nd polynomial: ";
        cin >> temp->expo;
        temp->next = temp;
        p2.sorted_create(temp);
        cout << "\nPress 1 to continue or press 0 to show the polynomial" << endl;
        cin >> ans;
        cout << "\n";
    } while (ans == 1);
    p2.display();
    cout << "\n"<< endl;

    cout << "The addition of two polynomials is : " << endl;
    p3.add(p1, p2);
    cout << endl;
    p3.display();
}