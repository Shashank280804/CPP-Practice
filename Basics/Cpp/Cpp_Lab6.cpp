
#include <iostream>
using namespace std;

class room
{

public:
    float area;

    room()
    {
        area = 0;
    }

    room(int a, int b)
    {
        area = a * b;
    }

    void disp()
    {
        cout << area << endl;
    }
};

int main()
{

    room r;
    room r2(15, 30);

    r.disp();
    r2.disp();
    return 1;
}
// OUTPUT:
// 0
// 450

// c:\Shashank\Code\C Language\Basics\Cpp>
