#include<iostream>
 using namespace std;

 int main(){
    int a=3;
    int* b = &a;
    cout<<"The address of a is\n"<<&a<<endl;
    cout<<"The address of a is\n"<<b<<endl;
    cout<<"The value at address b is\n"<<*b<<endl;
  return 0;
 }