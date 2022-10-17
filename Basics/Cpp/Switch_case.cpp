#include <iostream>
using namespace std;
int main()
{
    int age;
    cout << "Tell your age:\n";
    cin >> age;
    switch (age)
    {
    case 18:
        cout << "You are eligible for license\n";
        break;
    case 8:
        cout << "You are not eligible\n";
        break;

    default:
        cout << "done";
        break;
    }

    return 0;
}