#include<stdio.h>

int main(){
int age;

printf("Enter the Age\n");
scanf("%d",&age);

if(age>=18 && age<=70){
    printf("You can drive\n",age);

}
else{
    printf("You cannot drive\n",age);
}
return 0;
}