#include<stdio.h>
#include<math.h>
#include<stdlib.h>
double zero( double (*f)(double x), double x1, double x3)
{
double x2;
int count=0;
f=sin;
printf("zero:\n");
   while(f(x1)>0 && f(x3)<0)
     {          
          x2=(x1+x3)/2;
          
          printf("%d:  ",count);
          printf("x2=%.20f f2=%g\n",x2,f(x2));
          if(x2 <= x1 || x2 >= x3 ||f(x2) == 0)
           {
             break;
           }
         
          count++;     
         if(f(x2) > 0)
           {
             x1 = x2;
           }
         else if(f(x2)!=0&&f(x2)<0)
           {
             x3 = x2;
           }
     }
return x2;
}
int main()
{
double x,diff,pi=4*atan(1);
x=zero(sin,2,4);
if(x==pi)
{
printf("main:\n");
printf("\t x= %.20f\n",x);
printf("\t pi= %.20f\n",pi);
diff=x-pi;
printf("\t diff= %.20f\n",diff);
}
}
