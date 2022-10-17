#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"Enter the value of a and b:\n";
    cin>>a>>b;

    cout<<"The value of a == b is "<<(a==b);//0
    cout<<"\nThe value of a != b is "<<(a!=b);// 1
    cout<<"\nThe value of a >= b is "<<(a>=b);//0
    cout<<"\nThe value of a <= b is "<<(a<=b);//1
    cout<<"\nThe value of a < b is "<<(a<b);//1
    cout<<"\nThe value of a > b is "<<(a>b);//0
    
    return 0;
}