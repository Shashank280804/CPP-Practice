#include <iostream>
using namespace std;
void swappointer(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    
}

int main()
{
    int a, b;
    cout<<"Enter the value of a and b: "<<endl;
    cin >> a >> b;
    cout << "The value of a and b before swapping is "<<a<<" "<<b<<endl;
  
    swappointer(&a, &b);
    cout << "The value of a and b after swapping is "<<a<<" "<<b<<endl;

    return 0;
}