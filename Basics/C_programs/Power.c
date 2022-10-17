#include<stdio.h>
#include<math.h>
int main(){
int a,b;
float c;

printf("Enter the Value of a and b ");
scanf("%d%d",&a,&b);

c=pow(a,b);

printf("The Value of a raised to the power b is %f",c);
return 0;
}