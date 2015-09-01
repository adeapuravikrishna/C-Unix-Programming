#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <gsl/gsl_poly.h>
int main()
{
double x,y,z,a, b, c, y0, y1, y2;
int i,count;
x=-2;
for(i=1;i<=101;i++)
{
a=0;
b=-3*x;
c=x*x*x;
count = gsl_poly_solve_cubic( a, b, c, &y0, &y1, &y2);
if(count!=1)
{
break;
}
else
{
printf("%lf %lf\n",x,y0);
}
x=x+0.04;
}
y=x;
for(i=1;i<=101;i++)
{
a=0;
b=-3*x;
c=x*x*x;
count = gsl_poly_solve_cubic( a, b, c, &y0, &y1, &y2);
if(count!=3)
{
break;
}
else
{
printf("%lf %lf\n",x,y1);
}
x=x+0.04;
}
z=x-0.04;
for(i=1;i<=101;i++)
{
a=0;
b=-3*z;
c=z*z*z;
count = gsl_poly_solve_cubic( a, b, c, &y0, &y1, &y2);
if(count!=3)
{
break;
}
else
{
printf("%lf %lf\n",z,y2);
}
z=z-0.04;
}
for(i=1;i<=101;i++)
{
a=0;
b=-3*y;
c=y*y*y;
count = gsl_poly_solve_cubic( a, b, c, &y0, &y1, &y2);
if(count!=3)
{
break;
}
else
{
printf("%lf %lf\n",y,y0);
}
y=y+0.04;
}
for(i=1;i<=101;i++)
{
a=0;
b=-3*y;
c=y*y*y;
count = gsl_poly_solve_cubic( a, b, c, &y0, &y1, &y2);
if(y>2)
{
break;
}
else
{
printf("%lf %lf\n",y,y0);
}
y=y+0.04;
}
}
