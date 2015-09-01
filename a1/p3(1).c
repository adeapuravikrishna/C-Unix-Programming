#include <stdio.h>
#include <math.h>
#include <errno.h>
int main (void)
{
  double x;
   errno=0;x=sqrt(-1);
printf("x=%g \n errno=%i",x,errno);
if (errno!= 0)
        perror("oops failed");
}
