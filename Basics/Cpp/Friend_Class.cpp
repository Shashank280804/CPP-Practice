#include<iostream>
using namespace std;
class B
{
private:
    int a;
public:
    B(){
        a=10;
        

    }
    friend class c;
};

class c
{
    public:  void display(B v)
        {
            cout<<endl<<"The value of a="<<v.a;
        } 
};
int main(){
    B _a;
    C _a;
    C.display(_a);
    return 0;

}