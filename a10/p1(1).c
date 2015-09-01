#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
 
 // global variables
 //
 int answer, high, low,guess,r;
 
 // initialize answer and bounds
 //
 void init( void)
 {
   answer = 1 + rand() % 100;
 
 }
 
 // check guess
 //
 int dealer( int guess)
 {
   int r = answer - guess;
fprintf( stderr,"dealer:guess = %d\n",guess);
 
   if( r > 0) return 1; else if( r < 0) return -1; else return 0;
 }
int player(void)
{
 do
   {
     scanf("%d",&guess); 
     r = dealer( guess);   
     if( r > 0)
     {
       fprintf(stderr,"dealer: higher\n");
       fprintf(stdout,"higher\n");
       
     }
     else if( r < 0)
     {
       fprintf(stderr,"dealer: lower\n");
       fprintf(stdout,"lower\n");
     }
     else // r == 0
     {
       fprintf(stderr,"dealer: correct!\n");
        fprintf(stdout,"correct\n");
     }
   }
   while( r != 0);
 
   if( r != 0)
   {
     fprintf( stdout,"dealer is cheating!\n");
   }
return 0;
} 
int main( void)
 {
   setbuf( stdout, 0);
   setbuf(stderr,0);
   init();
   player();
   return 0;
 }
