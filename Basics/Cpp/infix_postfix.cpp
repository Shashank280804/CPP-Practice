#include <bits/stdc++.h>
#include <iostream>
using namespace std;


struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};


int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(string s)
{

    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;

        else if (c == '(')
            st.push('(');

        else if (c == ')')
        {
            while (st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }

        else
        {
            while (!st.empty() && prec(s[i]) <= prec(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    cout << result << endl;
}

bool isOperator(char x)
{
    switch (x)
    {
    case '+':
    case '-':
    case '/':
    case '*':
        return true;
    }
    return false;
}

string postToPre(string post_exp)
{
    stack<string> s;

    int length = post_exp.size();

    for (int i = 0; i < length; i++)
    {

        if (isOperator(post_exp[i]))
        {

            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();

            string temp = post_exp[i] + op2 + op1;

            s.push(temp);
        }

        else
        {

            s.push(string(1, post_exp[i]));
        }
    }

    string ans = "";
    while (!s.empty())
    {
        ans += s.top();
        s.pop();
    }
    return ans;
}


struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));

    if (!stack)
        return NULL;

    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));

    if (!stack->array)
        return NULL;

    return stack;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

char peek(struct Stack *stack)
{
    return stack->array[stack->top];
}

char pop(struct Stack *stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}

void push(struct Stack *stack, char op)
{
    stack->array[++stack->top] = op;
}

int evaluatePostfix(char *exp)
{

    struct Stack *stack = createStack(strlen(exp));
    int i;

    if (!stack)
        return -1;

    for (i = 0; exp[i]; ++i)
    {

        if (isdigit(exp[i]))
            push(stack, exp[i] - '0');

        else
        {
            int val1 = pop(stack);
            int val2 = pop(stack);
            switch (exp[i])
            {
            case '+':
                push(stack, val2 + val1);
                break;
            case '-':
                push(stack, val2 - val1);
                break;
            case '*':
                push(stack, val2 * val1);
                break;
            case '/':
                push(stack, val2 / val1);
                break;
            }
        }
    }
    return pop(stack);
}


int main()
{
    string post_exp = "ABC/-AK/L-*";
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    char exp[] = "231*+9-";
    infixToPostfix(exp);
    cout << "postfix evaluation: " << evaluatePostfix(exp);
    cout << "Prefix : " << postToPre(post_exp);
    return 0;
}
