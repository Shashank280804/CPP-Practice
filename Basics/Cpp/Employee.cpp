#include <iostream>
using namespace std;

class employee{

    public:
        char employee[10];
        int salary;
        char gender;

            void get_data()
            {
                cout << "Enter name of the employee " << "\n";
                cin >> employee;
                cout << "Enter salary of the employee " << "\n";
                cin >> salary;
                cout<< "Enter gender of that employee " << "\n";
                cin>> gender;
            };
            void display()
            {
                cout<< "employee Name: " << employee <<"\n" << "salary: Rs" << salary << "\n"<< "gender" << gender;
            };
};

int main(){

    int n;
    cout << "How many employees data you want:";
    cin >> n;
    employee e1[10];

    for(int i = 0;i<n;i++){

        e1[i].get_data();

    };
    cout << "What action  you want to do?" << "\n";
    cout <<"1.INSERT " << "\n" << "2.DELETE " <<"\n" << "3.SORT" << "\n";
    cout << "4.UPDATE" << "\n" << "5.DISPLAY";

    int ch; 
    
    cin >> ch;

switch (ch)
{

case 1:
    int pos_ins;
    cout << "Where do you want to enter the element? : ";
    cin >> pos_ins;

    if (pos_ins > 10)
    {
        cout << "Enter a position less than 10!";
        break;
    }
    else 
    {
    for (int i = n; i > pos_ins; i--)
    {
    
        e1[i] = e1[i-1];
    };

    e1[pos_ins].get_data();
     n++;
    for(int i = 0;i<n;i++){

    cout << i+1 << "\n";
    e1[i].display();

    }
    }
    break; 
case 2:
    int pos_delete;
    cout << "Which element do you want delete? :";
    cin >> pos_delete;
    if (pos_delete>10)
    {
        cout<<"Enter a position less than 10";
        break;
    }
    else
    {
     int i;
    for (i = pos_delete; i < n ; i++)
        e1[i] = e1[i + 1];
    n--;
    for(int i = 0;i<n;i++){

    cout << i+1 << "\n";
    e1[i].display();

    }    

    return 0;

    }
    
case 3: 
    int pos_search;
    cout<<"Enter position to sort";
    cin>> pos_search;
    if (pos_search>10)
    {
        cout<<"position must be less than 10";
    }
    else
    {
        
    }
    

    

    break; 

case 4:
    
    break;


case 5:

    break;

case 6:
    for(int i = 0;i<n;i++){

    cout << i+1 << "\n";
    e1[i].display();

    }

    break;

}    

    return 0;
}