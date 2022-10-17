#include<stdio.h>

int main(){
int radius,height;
float pi=3.14,Vol_cylinder;

printf("The radius and height of the cylinder are");
scanf("%d%d",&radius,&height);

Vol_cylinder=pi*radius*radius*height;

printf("The Volume of the given Cylinder is %f",Vol_cylinder);
return 0;
}