#include<stdio.h>

int main(){
char a;
printf("Enter the Character :\n");
scanf("%c",&a);
if (a<=122 && a>=97)
{
    printf("It is a lowercase letter");
}
else
{
    printf("It is an uppercase letter");
}


return 0;
}