#include <iostream>
#include <string>
using namespace std;
class employee
{
public:
    int employee_id;
    string employee_name;
    int employee_age;

    void read();
    void print()
    {
        cout << "\nEmployee ID is : " << employee_id << endl;
        cout << " Name of the employee is : " << employee_name << endl;
        cout << " Age of the employee is : " << employee_age;
    }
};
void employee::read()
{
    cout << "Enter Student Id :";
    cin >> employee_id;
    cout << "\nEnter student_name :";
    cin >> employee_name;
    cout << "\nEnter student_age :";
    cin >> employee_age;
}

int main()
{
    employee e1;
    e1.read();
    e1.print();
}

/*OUTPUT:
Shashank\Code\C Language\Basics\Cpp\"Cpp_lab1
Enter Student Id :3


Enter student_name :shashank

Enter student_age :20

Employee ID is : 3
 Name of the employee is : shashank
 Age of the employee is : 20
c:\Shashank\Code\C Language\Basics\Cpp>*/
