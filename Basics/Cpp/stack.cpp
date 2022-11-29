
#include <iostream>
#include <string.h>
using namespace std;
#define MAX 1000

class Stack
{   
    int top;
    public:
    string a[MAX]; 
    Stack() { top = -1; }
    bool push(string res);
    string pop();
    string peek();
    bool isEmpty();
    void display(Stack s);
};

bool Stack::push(string res)
{
    if (top  >= (MAX - 1))
    {
        cout << "Stack Overflow";
        return false;
    }
    else
    {
        a[++top] = res;
        cout << res << "\n";
        return true;
    }
}

string Stack::pop()
{
    if (top < 0)
    {
        cout << "Stack Underflow";
        return "underflow" ;
    }
    else
    {
        string res = a[top--];
        return res;
    }
}


bool Stack::isEmpty()
{
    return (top < 0);
}

void Stack::display(Stack s){
        while (!s.isEmpty())
    {
    
        s.pop();
    }

}

int main()
{
    class Stack s;
    cout << "Elements present in stack are : ";
    s.push("Shashank");
    s.push("Vedant");
    s.push("Atharva");
    cout << s.pop() << " Popped from stack\n";
    cout << "Top element is : " << s.peek() << endl;

    s.display(s);
    return 0;
}
