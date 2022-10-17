#include<iostream>
#include <conio.h>
using namespace std;

inline int cube(int r)
{

    return r * r * r;
}

int main()
{

    int r;

    cout << "PROGRAM TO COMPUTE CUBE\n";

    cout << "Enter value to compute cube: ";

    cin >> r;

    cout << "cube of the number: " << cube(r);

    return 0;
}