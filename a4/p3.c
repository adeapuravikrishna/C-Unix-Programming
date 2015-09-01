#include<stdio.h>
#include<math.h>
int main( void)
{
  int s; // scanf return status
 
  double t,y;
 
 int i=0;
 double t0,t1,t2,y0,y1,y2;
        t1=t2=y1=y2=0;
  while( 1) // until end-of-file or error
  {
     
    s = scanf("%lf %lf",&t,&y); // try to read one double
    if( s != 2) // could not read one double, must be end-of-file or error
    break;
	
 printf( "%g %g\n", t,y);
        
        t0=t1; t1=t2; t2=t; y0=y1;y1=y2; y2=y;
	if(i > 1)
	{
		if((y1>y2)&&(y1>y0))
		{
    double x0 = t0 - t1; 
    double x2 = t2 - t1;
		
		double a= ( x2 *( y0 - y1 ) + x0* ( y1 - y2 ) ) / ( x0 * x2 * ( x0 - x2 ) );
		double b = (y0 - y1 - (a*pow(x0,2))) / x0 ;
		double x = (-b)/(2*a);
		double yp = (a*pow(x,2)) + (b* x) + y1;
		double tp = t1- (b/(2*a));
                printf("     \n");
                printf("%g %g\n",tp,0.0);
		printf( "%g %g\n", tp,1.5*yp);
                printf("     \n");
                printf( "%g %g\n", t,y);
		}
		
	}
	i++;
  }
 
  return 0;
}
