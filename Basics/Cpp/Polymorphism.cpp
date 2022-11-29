
#include <iostream>

using namespace std;
class shashank
{
public:
    void func(int x)
    {
        cout << "value of x is " << x << endl;
    
    }

    void func(float x)
    {
        cout << "value of x is " << x << endl;
       
    }

    void func(int x, int y)
    {
        cout << "value of x and y is " << x << ", " << y << endl;
    }
};

int main()
{
    shashank obj1;

    obj1.func(7,8);

    obj1.func(9.1,7.8);

    obj1.func(85, 64);
    return 0;
}
