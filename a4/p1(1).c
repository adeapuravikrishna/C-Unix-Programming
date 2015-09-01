#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#define N 51	                        // number of points to generate
#define pi 3.141592653589793
int first=0;
double RandomGenrator(double min, double max) 
{  if(first==0)
   srand(time(NULL));
   first++;                         //srand() called only once for randomized noise r
   return rand() * (max - min) / RAND_MAX + min;
}
int main(int argc, char *argv[])
{
double i=0,phase,a1,a2,y;
double noise;
phase =RandomGenrator(0,2*pi);
    if( argc == 2 )
   {
     if(0 == strcmp("s",argv[1]))              //sum of two sine waves
       {
       while( i < N) // i will go from 0 to N-1
       {
        noise = RandomGenrator(-0.75,0.75);
        a1=(2*pi*1100*(i/8000))+phase;
        a2=(2*pi*1600*(i/8000))+phase;
        y=sin(a1)+sin(a2)+noise;
        printf("%g %g\n",i,y);
        ++i;
        }   
    }
     else if(0 ==strcmp("p",argv[1]))          //product of two sine waves
     {
       while( i < N) // i will go from 0 to N-1
        {
       noise = RandomGenrator(-0.75,0.75);
       a1=(2*pi*1100*(i/8000))+phase;
       a2=(2*pi*1600*(i/8000))+phase;
       y=sin(a1)*sin(a2)+noise;
       printf("%g %g\n",i,y);
       ++i;
        }
     } 
    else
     printf("Enter p or s only\n");             // arguments other than p and s
   }
   else if( argc > 2 )
   {
      printf("Too many arguments supplied.\n");
   }
   else                                        // when no argument given
   { 
       while( i < N) // i will go from 0 to N-1
        {
       noise = RandomGenrator(-0.75,0.75);
       a1=(2*pi*1100*(i/8000))+phase;
       y=sin(a1)+noise;
       printf("%g %g\n",i,y);
       ++i;
        }
   }
  return 0;
}
