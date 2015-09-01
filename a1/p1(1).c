#include<stdio.h>
#include<limits.h>
#define print( format, name) \
  printf( #name " = " format "\n", name)
int main(void)
{
   print("%d", CHAR_BIT);
   print("%d",MB_LEN_MAX);
   print("%i", CHAR_MIN);
   print("%d", CHAR_MAX);
   print("%d", SCHAR_MIN);
   print("%d", SCHAR_MAX);
   print("%d", UCHAR_MAX);
   print("%d", SHRT_MIN);
   print("%d", SHRT_MAX); 
   print("%u",USHRT_MAX);
   print("%i", INT_MIN);
   print("%i", INT_MAX);
   print("%u", UINT_MAX);
   print("%ld", LONG_MIN);
   print("%ld", LONG_MAX);
   print("%lu", ULONG_MAX);
print( "%lli", LLONG_MAX);
print( "%lli", LLONG_MIN);
print( "%llu", ULLONG_MAX);
  
   
  return 0;
}
