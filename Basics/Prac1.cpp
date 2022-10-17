#include<iostream>
#include<stdlib.h>
using namespace std;

class sneaker
{
    public:
    int price;
    string sneaker_name;
    int size;

    void read()
    {
        cout<<"\nEnter sneaker Name: \nsize.: \n price ";
        cin>>price>>sneaker_name>>size;
    }
    void display();
};

void sneaker::display()
{
    cout<<"\n"<<sneaker_name<<"\t"<<price<<"\t"<<size;  
}

int main()
{
    sneaker s[200];
    string key;
    int choice,n,i,j,l,flag=0;

    do
    {
        cout<<"\nEnter your choice: \n1]Read\n2]Display\n3]Insert\n4]Search\n5]Delete\n6]Update\n7]exit";
        cin>>choice;

        switch(choice)
        {
            case 1:
            cout<<"Enter the name of the sneaker you want ";
            cin>>n;
            for(i=0;i<n;i++)
            {
                s[i].read();
            }
            break;

            case 2:
            cout<<"Sneaker_name\tprice\tsize";

            for(i=0;i<n;i++)
            {
                s[i].display();
            }
            break;

            case 3:
            cout<<"Enter size of the shoes";
            cin>>l;

            for(i=n-1;i>=1;i--)
            {
                s[i+1]=s[i];
            }
            s[1].read();
            n++;
            break;

            case 4:
            cout<<"Enter size of the shoes for search ";
            cin>>key;

            for(i=0;i<n;i++)
            {
                if(key ==s[i].size)
                {
                    cout<<"\nSneaker is present!";
                    flag=1;
                    break;
                }
            };
            if(flag==0)
            {
                cout<<"\nSneaker is not present!";
            }
            else
            {}
            break;

            case 5:
            cout<<"Enter the size to delete the record of the sneaker ";
            cin>>key;

            for(i=0;i<n;i++)
            {
                if(key ==s[i].size)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                cout<<"\nSneaker is not present!";
            }
            else
            {
                for(j=i+1;j<=n;j++)
                {
                    s[j-1]=s[j];
                }
                n--;
            }
            break;

            case 6:
            cout<<"Enter size to update information of the sneaker: ";
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
                cout<<"\nSneaker is not present!";
            }
            else
            {}
            break;

            case 7:
            cout<<"Exit";
            exit(0);

            default:
            cout<<"\nEnter correct Choice!!!";
        }  
    }
    while(choice!=7);
}