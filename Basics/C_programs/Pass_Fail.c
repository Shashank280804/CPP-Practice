#include<stdio.h>

int main(){
int maths,physics,chemistry;
float total;

printf("Enter the Maths marks:\n");
scanf("%d",&maths);

printf("Enter the Physics marks:\n");
scanf("%d",&physics);

printf("Enter the Chemistry marks:\n");
scanf("%d",&chemistry);

total=(maths+physics+chemistry)/3;
if ((total<40) || maths<40 || physics<40 ||chemistry<40)
{
    printf("You got %f percentage and you are fail\n",total);
}
else{
    printf("You got %f percentage and you are pass\n",total);
}

return 0;
}