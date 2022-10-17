#include<stdio.h>

int main(){
int a;

printf("Enter the number ");
scanf("%d",&a);

if(a%2==0){
    printf("%d is Even number\n",a);

}
else{
    printf("%d is odd number\n",a);
}
return 0;
}