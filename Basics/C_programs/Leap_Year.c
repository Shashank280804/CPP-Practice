#include<stdio.h>

int main(){
int a;

printf("Enter the Year :\n");
 scanf("%d",&a);
    if (((a%4==0) && (a%100!=0))|| (a%400==0))
    {
        printf("%d is Leap Year",a);
        
    }
    else{
        printf("%d is not Leap Year",a);
    }

return 0;
}