#include <iostream>
using namespace std;
int main()
{
    int marks[] = {12, 32, 45, 65};
    // for(int i=0;i<4;i++)
    // {
    //     cout<<"The value of marks"<<i<<"is"<<marks[i]<<endl;
    // }

    int *p = marks;
    cout << "The value at [0] is " << *(p) << endl;
    cout << "The value at [p+1] is " << *(p + 1) << endl;
    cout << "The value at [p+2] is " << *(p + 2) << endl;
    cout << "The value at [p+3] is " << *(p + 3) << endl;

    return 0;
}
