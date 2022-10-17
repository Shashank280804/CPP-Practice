#include<iostream>
#include<cstring>

using namespace std;

class my_string{
   private:
        
           char str[30];
   public:
  
         
          void getdata();
          void display();
          void operator== (my_string str1);
          int operator= (my_string str1);
          void operator+ (my_string str1);
          void operator<< (my_string str1);
          void operator>> (my_string str1);
          
};



void my_string::getdata()
{
  cout<<"\nEnter the string : ";
  cin>>str;
}



void my_string::display()
{
   cout<<"\n"<<str;
}




void my_string::operator== (my_string str1)
{
   strcpy(str1.str,str);
   cout<<"\n\tCopied String is : "<<str1.str;
}



int my_string::operator= (my_string str1)
{
   if(strcmp(str,str1.str)==0)
     return 1;  
	 
     return 0;  
}




void my_string::operator+ (my_string str1)
{
   strcat(str,str1.str);
   cout<<"\n\t--String After Concat is : "<<str;
}




void my_string::operator<< (my_string str1)
{
   cout<<"\n\t--The string you entered is :"<<str1.str;
}





void my_string::operator>> (my_string str1)
{
   int i;
   cout<<"\n\t--The string after reversing is : ";
   for(i=strlen(str1.str);i>=0;i--)
     cout<<str1.str[i];
}


int main()
{
    int opt,c,opt1=1;
	
	
    my_string a,b;
	
    while(opt1==1 && opt!=8)
	{
	
	
    cout<<"\n\t\t\t---Main Menu---\n\t1.Equality\n\t2.String Copy\n\t3.Concat";
    cout<<"\n\t4.Display\n\t5.Reverse\n\t";
    cout<<"\n\t8.Exit\n\t\t--Enter your choice-->";
	

    cin>>opt;

     switch(opt)
      {
             case 1:
                      cout<<"\nEnter the 1st string-\n";
                      a.getdata();
                      cout<<"\nEnter the 2nd string-\n";
                      b.getdata();
                       c=a=b;
                       if(c==1)
                           cout<<"\n\t---Strings are Equal---\n";
                       else
                           cout<<"\n\t---Strings are not Equal---\n";
                       break;
             case 2:
                       a.getdata();
					   
					   
                       a==b;
                       break;
             case 3:  
                      cout<<"\nEnter the 1st string-\n";
                      a.getdata();
                      cout<<"\nEnter the 2nd string-\n";
                      b.getdata();
					 
					
                     a+b;  
                     break;
             case 4:
                     a.getdata();
                      b<<a;
                      break;
             case 5:
                     a.getdata();
					 
					 
                      b>>a;
                      break;
            
            case 8: return 0;
			 
			 default: cout<<"Invalid choice..try again\n";
      } 
       if(opt!= 8){
       cout<<"\n\n\tDo you want to continue(Press 1 to continue)";
       cin>>opt1;}
     }

    return 0;
}
/*OUTPUT:
 ---Main Menu---

        1.Equality
        2.String Copy
        3.Concat
        4.Display
        5.Reverse

        8.Exit
                --Enter your choice-->1

Enter the 1st string-

Enter the string : shashank

Enter the 2nd string-

Enter the string : shashank

        ---Strings are Equal---


        Do you want to continue(Press 1 to continue)1

                        ---Main Menu---
        1.Equality
        2.String Copy
        3.Concat
        4.Display
        5.Reverse

        8.Exit
                --Enter your choice-->2

Enter the string : patil

        Copied String is : patil

        Do you want to continue(Press 1 to continue)1

                        ---Main Menu---
        1.Equality
        2.String Copy
        3.Concat
        4.Display
        5.Reverse

        8.Exit
                --Enter your choice-->3

Enter the 1st string-

Enter the string : shashank

Enter the 2nd string-

Enter the string : patil

        --String After Concat is : shashankpatil

        Do you want to continue(Press 1 to continue)1

                        ---Main Menu---
        1.Equality
        2.String Copy
        3.Concat
        4.Display
        5.Reverse

        8.Exit
                --Enter your choice-->4

Enter the string : shashank

        --The string you entered is :shashank

        Do you want to continue(Press 1 to continue)1

                        ---Main Menu---
        1.Equality
        2.String Copy
        3.Concat
        4.Display
        5.Reverse

        8.Exit
                --Enter your choice-->5

Enter the string : Patil

        --The string after reversing is : litaP

        Do you want to continue(Press 1 to continue)
*/