/*Name:Shashank Patil
  Roll no:27
  PRN No: 202101040077
  Division:A
  Batch:A2

  Design and implement a program to read, display, insert,update and delete operation 
  on data objects for customer information supply chain management system using an array

*/

#include<iostream>
#include<stdlib.h>
using namespace std;

class student
{
    public:
    int roll;
    string prn, name;
    float cgpa;

    void read()
    {
        cout<<"\nEnter Name: \nRoll no.: \nPRN no.: \nCGPA: ";
        cin>>name>>roll>>prn>>cgpa;
    }
    void display();
};

void student::display()
{
    cout<<"\n"<<name<<"\t"<<roll<<"\t"<<prn<<"\t"<<cgpa;  
}

int main()
{
    student s[200];
    string key;
    int choice,n,i,j,l,flag=0;

    do
    {
        cout<<"\nEnter your choice: \n1]Read\n2]Display\n3]Insert\n4]Search\n5]Delete\n6]Update\n7]exit";
        cin>>choice;

        switch(choice)
        {
            case 1:
            cout<<"Enter no. of students you want to store in data: ";
            cin>>n;
            for(i=0;i<n;i++)
            {
                s[i].read();
            }
            break;

            case 2:
            cout<<"Name\tRoll No.\tPRN\tCGPA";

            for(i=0;i<n;i++)
            {
                s[i].display();
            }
            break;

            case 3:
            cout<<"Enter location to insert students details: ";
            cin>>l;

            for(i=n-1;i>=1;i--)
            {
                s[i+1]=s[i];
            }
            s[1].read();
            n++;
            break;

            case 4:
            cout<<"Enter PRN no. to search it is present or not: ";
            cin>>key;

            for(i=0;i<n;i++)
            {
                if(key==s[i].prn)
                {
                    cout<<"\nStudent is present!";
                    flag=1;
                    break;
                }
            };
            if(flag==0)
            {
                cout<<"\nStudent is not present!";
            }

            break;

            case 5:
            cout<<"Enter PRN no. to delete the information of the student: ";
            cin>>key;

            for(i=0;i<n;i++)
            {
                if(key==s[i].prn)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                cout<<"\nStudent is not present!";
            }
            else
            {
                for(j=i+1;j<=n;j++)
                {
                    s[j-1] = s[j];
                  //s[2-1] = s[2];
                  //s[3-1] = s[3];
                }
                n--;
            }
            break;

            case 6:
            cout<<"Enter PRN to update information of the student: ";
            cin>>key;

            for(i=0;i<n;i++)
            {
                if(key==s[i].prn)
                {
                    flag=1;
                    s[i].read();
                    break;
                }
            }
            if(flag==0)
            {
                cout<<"\nStudent is not present!";
            }
            break;

            case 7:
            cout<<"Quiting the job) Bye......";
            exit(0);

            default:
            cout<<"\nEnter correct Choice!!!";
        }  
    }
    while(choice!=7);
}


/*Enter your choice:                                                                                                                         1]Read
2]Display
3]Insert
4]Search
5]Delete
6]Update
7]exit1
Enter no. of students you want to store in data: 3

Enter Name: 
Roll no.: 
PRN no.: 
CGPA: 
Shashank
27
0077
8.4

Enter Name: 
Roll no.: 
PRN no.: 
CGPA: 
Sankalpk
24
0987
8.1

Enter Name: 
Roll no.: 
PRN no.: 
CGPA: 
Hitanshu
179
0876
7.6

Enter your choice:
1]Read
2]Display
3]Insert
4]Search
5]Delete
6]Update
7]exit2
Name    Roll No.        PRN     CGPA
Shashank        27      0077    8.4
Sankalpk        24      0987    8.1
Hitanshu        179     0876    7.6
Enter your choice:
1]Read
2]Display
3]Insert
4]Search
5]Delete
6]Update
7]exit
3
Enter location to insert students details: 3

Enter Name:
Roll no.:
PRN no.:
CGPA:
AtharvaW
30
0879
9

Enter your choice:
1]Read
2]Display
3]Insert
4]Search
5]Delete
6]Update
7]exit2
Name    Roll No.        PRN     CGPA
Shashank        27      0077    8.4
AtharvaW        30      0879    9
Sankalpk        24      0987    8.1
Hitanshu        179     0876    7.6
Enter your choice:
1]Read
2]Display
3]Insert
4]Search
5]Delete
6]Update
7]exit4
Enter PRN no. to search it is present or not: 0077

Student is present!
Enter your choice:
1]Read
2]Display
3]Insert
4]Search
5]Delete
6]Update
7]exit5
Enter PRN no. to delete the information of the student: 0876

Enter your choice:
1]Read
2]Display
3]Insert
4]Search
5]Delete
6]Update
7]exit2
Name    Roll No.        PRN     CGPA
Shashank        27      0077    8.4
AtharvaW        30      0879    9
Sankalpk        24      0987    8.1
Enter your choice:
1]Read
2]Display
3]Insert
4]Search
5]Delete
6]Update
7]exit6
Enter PRN to update information of the student: 0879

Enter Name:
Roll no.:
PRN no.:
CGPA:
AtharvaW
30
Quiting the job) Bye......
c:\Shashank\Code\C Language\Basics\Cpp>
*/