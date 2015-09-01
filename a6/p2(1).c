#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "p2.h"
double min( double (*f)(double x), double x1, double x3, double x5)
{
double x2,x4;
int count=1;
printf("min:\n");
   while(1)
     {
         printf("%d:  ",count);
         printf("x3=%.20f f3=%f\n",x3,f(x3));
          x2 = (x1+x3)/2;
          x4 = (x3+x5)/2;        
          count++;
     if(x2 <= x1 || x2 >= x3 || x4 <= x3 || x4 >= x5)
             break;
     if(f(x2) < f(x3))
           {
             x5 = x3;
             x3 = x2;
           }
      else if(f(x4) < f(x3))
           {
             x1 = x3;
             x3 = x4; 
           }
      else
           {
             x1 = x2;
             x5 = x4;
           }
     }
return x3;
}
double error(double x)
{
double err[80],mean_square_error,mean=0,fs=8000.0;
for(int i=0;i<nz;i++)
{
err[i]=z[i]-sin((2*4*atan(1)*x*i)/fs);
mean=mean+(err[i]*err[i]);
}
mean_square_error=mean/nz;
return mean_square_error;
}
int main()
{
double x;
x=min(error,1160.0,1280.0,1320.0);  //x1 = 1160.0, x3 = 1280.0, x5 = 1320.0
printf("main:\n");
printf("\t x=%.20f",x);
}
