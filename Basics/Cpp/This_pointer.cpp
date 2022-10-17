#include <iostream>
using namespace std;
class employee
{
    public:
    int age, salary, emp_id;
    employee(int age, int salary, int emp_id)
    {
        this->age = age;
        this->salary = salary;
        this->emp_id = emp_id;
    }
    
    void display()
    {
        cout << "age\n" << age << "salary\n" << salary << "emp_id\n" << emp_id;
    }
};
int main(){
    employee e1(22,30000,4);
    e1.display();

    return 0;
}