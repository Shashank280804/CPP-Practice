#include<iostream>
using namespace std;

class Union
{
	public:
		void read(string S,int a[],int n);
};

void Union :: read(string S,int a[],int n)
{ int i;
	//cout<<"Enter fruits quantity to store in basket :\n";
	cout<<"Enter the friuts type you want to buy :\n";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}

}


int intersection2(int a[],int b[],int n1,int n2) // a n b
{
	int i,j,k=0,c[100];
	
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			if(a[i]==b[j])
			{
				c[k]=a[i];
			    k++;
				break;
			}
		}
	}

	return k;
}

int intersection3(int a[],int b[],int c[],int n1,int n2,int n3) // a n b n c
{
	int i,m=0,j,k,d[100];
	
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			if(a[i]==b[j])
			{
             for(k=0;k<n3;k++)
             {
             	if(c[k]==b[j])
             	{
             	  d[m]=c[k];
             	  m++;
             	  break;
				 }
			 }
			}
		}
	}
	return m;
}

int intersection4(int a[],int b[],int c[],int d[],int n1,int n2,int n3,int n4) // a n b n c
{
	int l,i,m=0,j,k,e[100];
	
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			if(a[i]==b[j])
			{
             for(k=0;k<n3;k++)
             {
             	if(c[k]==b[j])
             	{
             		for(l=0;l<n4;l++)
             		{
             	    if(d[l]==b[j])
					 {
					   e[m]=d[l];
             	       m++;
             	       break;
					  }
					}

				 }
			 }
			}
		}
	}
	return m;
}


int main()
{  Union P1;
 int a[100],b[100],c[100],d[100],i,k,k1,k2,k3,n1,n2,n3,n4,ch; 
 int k4,k5,k6,k7,k8,k9,k10;
 string S,S1,S2,S3;
    do{
	cout<<"Your options are\n1.2 object union\n2.3 object union\n3.4 object union\n4.Exit\n\nEnter your choice :";
	cin>>ch;
	
	switch(ch)
	{
		case 1:
			cout<<"Enter first flavour of your juices :";
			cin>>S;
			cout<<"Enter total no of "<<S<<" bottle :";
			cin>>n1;
			P1.read(S,a,n1);
	
			cout<<"\nEnter second flavour of your juices  :";
			cin>>S1;
			cout<<"Enter total no of "<<S1<<" bottle :";		
			cin>>n2;			
			P1.read(S1,b,n2);
			k=intersection2(a,b,n1,n2);
	        cout<<"\nThe union is "<<(n1+n2)-k<<"\n\n";
			break;
		case 2:
			cout<<"Enter first flavour of your juices  :";
			cin>>S;
			cout<<"Enter total no of "<<S<<" bottle :";
			cin>>n1;
			P1.read(S,a,n1);
	
			cout<<"Enter second flavour of your juices  :";
			cin>>S1;
			cout<<"Enter total no of "<<S1<<" bottle :";	
			cin>>n2;			
			P1.read(S1,b,n2);
	
			cout<<"Enter third flavour of your juices  :";
			cin>>S2;
			cout<<"Enter total no of "<<S2<<" bottle :";
			cin>>n3;			
			P1.read(S2,c,n3);
			k=intersection2(a,b,n1,n2);
			k1=intersection2(b,c,n2,n3);
			k2=intersection2(a,c,n1,n3);
			k3=intersection3(a,b,c,n1,n2,n3);			
            cout<<"\nThe union is "<<(n1+n2+n3)-k-k1-k2+k3<<"\n\n";
			break;
			
		case 3:
			cout<<"Enter first flavour of your juices :";
			cin>>S;
			cout<<"Enter total no of "<<S<<" bottle :";
			cin>>n1;
			P1.read(S,a,n1);
	
		    cout<<"Enter second flavour of your juices  :";
			cin>>S1;
			cout<<"Enter total no of "<<S1<<" bottle :";	
			cin>>n2;			
			P1.read(S1,b,n2);
	
			cout<<"Enter third flavour of your juices  :";
			cin>>S2;
			cout<<"Enter total no of "<<S2<<" bottle :";
			cin>>n3;			
			P1.read(S2,c,n3);

			cout<<"Enter flavour of your juices  :";
			cin>>S3;
			cout<<"Enter total no of "<<S3<<" bottle :";
			cin>>n4;			
			P1.read(S3,d,n4);	
			k=intersection2(a,b,n1,n2);
			k1=intersection2(a,c,n1,n3);
			k2=intersection2(a,d,n1,n4);
			k3=intersection2(b,c,n2,n3);
			k4=intersection2(b,d,n2,n4);
			k5=intersection2(c,d,n3,n4);
			k6=intersection3(a,b,c,n1,n2,n3);
			k7=intersection3(a,b,d,n1,n2,n4);
			k8=intersection3(a,c,d,n1,n3,n4);
			k9=intersection3(b,c,d,n2,n3,n4);
			k10=intersection4(a,b,c,d,n1,n2,n3,n4);	
            cout<<"\nThe union is "<<(n1+n2+n3+n4)-(k+k1+k2+k3+k4+k5)+(k6+k7+k8+k9)-k10<<"\n\n";					
			break;
		case 4:
		  cout<<"Exited";
		  exit(0);
		default:
		  cout<<"Enter correct choice!!!" ; 			
			
	}
 }while(ch!=4);
}

/*OUTPUT:
Your options are
1.2 object union
2.3 object union
3.4 object union
4.Exit

Enter your choice :1
Enter first flavour of your juices :Banana
Enter total no of bottle :4
Enter the friuts type you want to buy :
1 2 3 5

Enter second  flavour of your juices :Mango
Enter total no of Mango flavours :3
Enter the friuts type you want to buy:
2 3 6

The union is 5

Your options are
1.2 object union
2.3 object union
3.4 object union 
4.Exit

Enter your choice :2
Enter first flavour of your juices :Banana
Enter total no of Banana flavours :6
Enter the friuts type you want to buy :
1 2 3 4 5 6
Enter second  flavour of your juices :Mango
Enter total no of Mango flavours :4
Enter the friuts type you want to buy :
5 6 2 3
Enter third flavour of your juices :Berry
Enter total no of Berry flavours :2
Enter the friuts type you want to buy :
1 3

The union is 6

Your options are
1.2 object union
2.3 object union
3.4 object union
4.Exit

Enter your choice :3
Enter first flavour of your juices :Banana
Enter total no of Banana flavours :3
Enter the friuts type you want to buy :
2 3 6
Enter second flavour of your juices :Mango
Enter total no of Mango flavours :5
Enter the friuts type you want to buy :
1 2 3 4 5
Enter third flavour of your juices :Berry
Enter total no of Berry flavours :4
Enter the friuts type you want to buy :
2 3 5 6
Enter fourth flavour of your juices :Kiwi
Enter total no of Kiwi flavours :2
Enter the friuts type you want to buy :
1 3

The union is 6

Your options are
1.2 object union
2.3 object union
3.4 object union
4.Exit

Enter your choice :4
Exited
--------------------------------
Process exited after 125.6 seconds with return value 0
Press any key to continue . . .*/