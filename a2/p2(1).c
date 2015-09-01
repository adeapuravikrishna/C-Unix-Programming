#include<stdio.h>
#include<time.h>
long long function1()
  {
  struct timespec rt;
  clock_gettime(CLOCK_REALTIME, &rt);
  long long realtime;
  realtime=((rt.tv_sec)*1e6)+(rt.tv_nsec*1e-3);  
return realtime;
}
int main()
{
long long x=function1();
printf("TIME(0) is %lld SECONDS \n",(long long)time(0));
printf("Realtime is %lld MICROSECONDS \n",x);
//secs = 1391340826
//usecs = 1391340826323473
}
