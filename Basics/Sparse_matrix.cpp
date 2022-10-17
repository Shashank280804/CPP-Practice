
#include<iostream>
using namespace std;
#define max 20

class sparse_matrix
{
    int data[max][3];
    int len;
    public:
    sparse_matrix(int r,int c,int l){
        data[0][0]=r;
        data[0][1]=c;
        data[0][2]=l;
        len=0;
    }
    void insert(int r,int c,int l);
    void print();
};


    void sparse_matrix ::insert(int r,int c,int val)
    {
    if ( r>data[0][0] ||  c>data[0][1])
    {
        cout<<"wrong entry";
    }
    else
    {
        data[len+1][0]=r;
        data[len+1][1]=c;
        data[len+2][2]=val;
        len++;
    }
    
    }
    void sparse_matrix ::print()
    {
        cout<<"\nDimension of given Sparse matrix is: "<<data[0][0]<<" "<<data[0][1];
        cout<<"row"<<"\t"<<"column"<<"\t"<<"value";

        for (int i = 0; i <=len; i++)
        {
            cout<<data[i][0]<<"\t"<<data[i][1]<<"\t"<<data[i][2]<<endl;
        }
        

    }

   int main() {
 		
 		int r,c,l,val;
 		cout<<"enter the number of rows: ";
 		cin>>r;
 		cout<<"Enter the number of columns: ";
 		cin>>c;
 		cout<<"Enter the number of non zero values: ";
 		cin>>l;
 		
 		sparse_matrix s(r,c,l);
        for (int i=1; i <=l; i++)
        {
            cout<<"Enter the row value: ";
            cin>>r;
            cout<<"Enter the column value: ";
            cin>>c;
            cout<<"Enter the non zero entry: ";
            cin>>val;
            s.insert(r,c,val);

            
        }
        
 		s.print();
 		
 	
 	return 0;
 }
 