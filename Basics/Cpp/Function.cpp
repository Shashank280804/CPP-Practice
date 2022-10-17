#include<iostream>
using namespace std;

int sum(int a,int b) {
    return a+b;
}
int main(){
    int num1,num2;
    cout<<"The value of first and second number is:"<<endl;
    cin>>num1>>num2;

    cout<<"The sum is"<<sum(num1,num2);

    return 0;

}