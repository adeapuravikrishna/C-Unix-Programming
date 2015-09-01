#include <stdio.h>
#include <time.h>
#include<limits.h>
 
int main(void)
{
  time_t t = 0;
  time_t t1 = INT_MAX-1;
  time_t t2 = INT_MAX;
  time_t t3 = (unsigned) INT_MAX+1;
  time_t t4 = -1;
  time_t t5 = INT_MIN;
  printf( "t = %lli, ctime = %s", (long long)t, ctime(&t));
  printf( "t1 = %lli, ctime = %s", (long long)t1, ctime(&t1));
  printf( "t2 = %lli, ctime = %s", (long long)t2, ctime(&t2));
  printf( "t3 = %lli, ctime = %s", (long long)t3, ctime(&t3));
  printf( "t4 = %lli, ctime = %s", (long long)t4, ctime(&t4));
  printf( "t5 = %lli, ctime = %s", (long long)t5, ctime(&t5));
  return 0;
}
