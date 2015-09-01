// copy doubles from standard input to standard output
 
#include <stdio.h>
 
int main( void)
{
  int s; // scanf return status
 
  double y0,y1,y2,t,y,a;
  y1=y2=0.0;
 
  while( 1) // until end-of-file or error
  {
    s = scanf("%lf %lf",&t,&y); // try to read one double
    if( s != 2) // could not read one double, must be end-of-file or error
    break;
    y0=y1; y1=y2; y2=y;
    a=(y0+y1+y2)/3;
    printf( "%g %g\n", t,a);
  }
 
  return 0;
}
