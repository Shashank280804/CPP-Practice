#include<stdio.h>

int main(){
int principle,rate,years;
float simple_interest;

printf("The price,rate and years are:");
scanf("%d%d%d",&principle,&rate,&years);

simple_interest=(principle*rate*years)/100;

printf("The Simple Interest is %f",simple_interest);
return 0;
}