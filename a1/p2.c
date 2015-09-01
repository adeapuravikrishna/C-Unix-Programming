#include<stdio.h>
#include<float.h>
#define print( format, name) \
  printf( #name " = " format "\n", name)
int main(void)
{
 
   print("%e", FLT_MIN);
   print("%e", FLT_MAX);
   print("%g", FLT_EPSILON);
   print("%le",  DBL_MIN);
   print("%le", DBL_MAX);
   print("%le", DBL_EPSILON); 
   print("%Lg", LDBL_MIN);
   print("%Lg", LDBL_MAX);
   print("%Lg", LDBL_EPSILON); 
  return 0;
}
