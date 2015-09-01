#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
int main(int argc, char *argv[])
{
long long uid = strtoll( "radepu", 0, 36);
int temp,i,e;
//printf("%lld\n",uid);
e= (uid % 246)+10;
printf("Encryption key is %d \n",e);
for(i=1;i<256;i++)
{
//printf("%d\n",e);
temp=(i*e)%257;
if(temp==1)
printf("Decryption key is :%d \n",i);
}
return 0;
}
