#include <stdio.h>
int main( void)
{
  int c;  // must use int variable with getchar()
  while( 1) // until end-of-file
  {
    c = getchar(); // if it works c will be a value from 0 to 255
     if(c==0)
     { c=256;
      }
    c=(c*13)%257;
    if(c==256)
      {
       c=0;
      }
    if( c < 0) break; // end-of-file
    putchar( c);
  }
  return 0;
}
