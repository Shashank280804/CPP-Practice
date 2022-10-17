
// #include <iostream>
// using namespace std;
// class employee
// {
// public:
//     int a, b;

//     employee()
//     {
//         a = 150;
//         b = 25;
//     }
// };
// int main()
// {

//     employee e1;
//     cout << "a: " << e1.a << endl
//          << "b: " << e1.b;
//     return 1;
// }

/*OUTPUT:
a: 150
b: 25
c:\Shashank\Code\C Language\Basics\Cpp>
*/
// #include <iostream>
// using namespace std;
// class circle
// {
// public:
//     int x, y,r;

// public:

//     circle(int x1, int y1,int r1)
//     {
//         x = x1;
//         y = y1;
//         r = r1;
//     }
//     int getX()
//     {
//         return x;
//     }
//     int getY()
//     {
//         return y;
//     }
//      int getr()
//     {
//         return r;
//     }
// };
// int main()
// {

//     circle c1(30, 15,20);

//     cout << "c1.x= " << c1.getX()<<endl;
//     cout << "c1.y= " << c1.getY()<<endl;
//     cout << "c1.r= " << c1.getr();
//     return 0;
// }
// OUTPUT:
// c1.x= 30
// c1.y= 15
// c1.r= 20
// c:\Shashank\Code\C Language\Basics\Cpp>
// #include <iostream>
// using namespace std;
// class Sample
// {
//     char name;

// public:
//     void init(char x)
//     {
//         name = x;
//     }
//     Sample() {}
//     Sample(Sample &n)
//     {
//         name = n.name;
//     }
//     void display()
//     {
//         cout << endl  << "Name =" << name;
//          cin>> name;
//     }
// };
// int main()
// {
//     Sample obj1;
//     obj1.init(10);
//     obj1.display();
//     Sample obj2(obj1);

// }
// OUTPUT
// Name =
// shashank

// c:\Shashank\Code\C Language\Basics\Cpp>
#include <bits/stdc++.h>
using namespace std;
class Student
{
    
    string name, DOB;
    int rollNo, Year;

public:
    string getName()
    {
        return name;
    }

    void setDOB(string newDOB)
    {
        DOB = newDOB;
    }

    void promote()
    {
        Year++;
    }

    void setYear(int newYear)
    {
        Year = newYear;
    }

    int getYear()
    {
        return Year;
    }
};

int main()
{

    Student s1, s2;

    s1.setYear(2);

    cout << "S1 is in " << s1.getYear() << " Year of course\n";


    s1.promote();

    cout << "After promoting, S1 is in " << s1.getYear() << " Year of course";

    return 0;
}
// OUTPUT :
// S1 is in 2 Year of course
// After promoting, S1 is in 3 Year of course
// c:\Shashank\Code\C Language\Basics\Cpp>