#include<stdio.h>

int main(){
int a;

do{
   printf("%d\n",a); 
   a++;
   if (a==5)
   {
       break;
   }
   
}while(a<10);

return 0;
}