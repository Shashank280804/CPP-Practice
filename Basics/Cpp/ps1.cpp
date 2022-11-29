#include <iostream>
#include <strings.h>
#include <math.h>
#include <sstream>
using namespace std;
#define max 50
class stack
{
public:
    string str[max];
    int top;
    stack()
    {
        top = -1;
    }
    bool isempty()
    {
        return top == -1;
    }
    bool isfull()
    {
        return top == max - 1;
    }
    void push(string item)
    {
        if (isfull())
        {
            cout << "The Stack is Full" << endl;
            return;
        }
        top++;
        str[top] = item;
    }
    string pop()
    {
        string t = "";
        if (isempty())
        {
            cout << "The Stack is Empty" << endl;
            return t;
        }
        t = str[top];
        top--;
        return t;
    }
};
class expression
{
public:
    string infix, postfix;
    stack s;
    void infix_to_postfix();
    void postfix_to_prefix();
    bool isoperator(string ch);
    int precedence(string j);
};
bool expression::isoperator(string ch)
{
    if (ch == "+" || ch == "*" || ch == "-" || ch == "/" || ch == "^")
    {
        return true;
    }
    else
    {
        return false;
    }
}
int expression::precedence(string j)
{
    if (j == " + " || j == "-")
    {
        return 1;
    }
    else if (j == "*" || j == "/")
    {
        return 2;
    }
    else if (j == "^")
    {
        return 3;
    }
    else
        return 0;
}

void expression::infix_to_postfix()
{
    cout << "Enter infix expression: " << endl;
    cin >> infix;
    for (int i = 0; i < infix.length(); i++)
    {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || infix[i] >= 'A' && infix[i] <= 'Z')
        {
            postfix += infix[i];
        }
        else if (infix[i] == '(')
        {
            s.push("(");
        }
        else if (infix[i] == ')')
        {

            while (s.top != -1 && s.str[s.top] != "(")
            {
                string t = s.str[s.top];
                s.pop();
                postfix += t;
            }
            if (s.str[s.top] == "(")
            {
                s.pop();
            }
        }
        else
        {
            while (s.top != -1 && (precedence(string(1, infix[i])) <= precedence(s.str[s.top])))
            {
                string t = s.str[s.top];
                s.pop();
                postfix += t;
            }
            s.push(string(1, infix[i]));
        }
    }
    while (s.top != -1)
    {
        string t = s.str[s.top];
        s.pop();
        postfix += t;
    }
    cout << "Your postfix   " << postfix << endl;
}

void expression::postfix_to_prefix()
{
    string pref;
    string post1;
    cout << "Enter Postfix Expression: " << endl;
    cin >> post1;
    for (int i = 0; i < post1.length(); i++)
    {
        if (isoperator(string(1, post1[i])))
        {
            string op1 = s.pop();
            string op2 = s.pop();
            string t = post1[i] + op2 + op1;
            s.push(t);
        }
        else
        {
            s.push(string(1, post1[i]));
        }
    }
    pref = s.pop();
    cout << "Prefix Expression: " << pref << endl;
}



int main()
{
    expression p;
    int a;
    int b;
    do
    {
    
        cout << "1. Infix to Postfix\n";
        cout << "2.Postfix to Prefix\n";
        cout << "Enter your choice: ";
        cin >> a;
        switch (a)
        {
        case 1:
            p.infix_to_postfix();
            break;
        case 2:
            p.postfix_to_prefix();
            break;
       

        default:
            cout << "Enter a valid choice..." << endl;
            break;
        }
        cout << "Press 1 to continue: ";
        cin >> b;
    } while (b == 1);
    return 0;
}