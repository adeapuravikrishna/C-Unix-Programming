#include<time.h>
#include<stdio.h>
#include<stdlib.h>
void function1(long long f)
{
long long x=time(0);
long long y;
y=f-x;
int z=(int)y;
int days=z/86400;
int temp1=z%86400;
int hours=temp1/3600;
int minutes=(temp1%3600)/60;
int seconds=(temp1%3600)%60;
printf("%d days, %d hours, %d minutes, %d seconds \n ",days,hours,minutes,seconds);
}
int main(int argc, char *argv[])
{
if(argc==1)
{
function1(1393045199);
}
else if(argc==2)
{
long long x=atol(argv[1]);
function1(x);
}
else
printf("Too many arguments \n");
return 0;
}
