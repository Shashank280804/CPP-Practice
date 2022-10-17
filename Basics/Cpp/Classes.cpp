#include <iostream>
using namespace std;

class employee
{
public:
     string employee_s;
    int eID;
    int salary;
    
};

int main()
{
    employee e1;
    e1.employee_s = "shashank";
        e1.eID = 5;
            e1.salary = 6767;

            cout<<"The employee name is "<<e1.employee_s<<endl;
            cout<<"The employee Id is "<<e1.eID<<endl;
            cout<<"The salary of the employee is "<<e1.salary<<endl;
            
}