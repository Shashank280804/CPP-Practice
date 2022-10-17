#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int a=3,b=32,c=3456;

    cout<<"  The value of a is: "<<setw(4)<<a;
    cout<<"\nThe value of b is: "<<setw(4)<<b;
    cout<<"\nThe value of c is: "<<setw(4)<<c;

    cout<<"\nThe value of a without setw is: "<<a;
    cout<<"\nThe value of b without setw is: "<<b;
    cout<<"\nThe value of c without setw is: "<<c;

    return 0;
    }