// test osp/a8 string functions
//
#include <stdio.h>
#include <string.h>

void check( const char *what, int t1, int t2)
{
  static const char *p = "pass", *f = "FAIL";

  printf( "%s: %s %s\n", what, t1 ? p : f, t2 ? p : f);
}

int main( void)
{
  char s[BUFSIZ], s1[BUFSIZ], s2[BUFSIZ], *p;

  strcpy( s2, "efg");

  p = strdog( "abc", s2);

    check( "strdog", strcmp( s2, "abcefg") == 0, p == s2);

  strcpy( s1, "AABZBAADZDAA");

  p = strrm( s1, "ZA");

    check( "strrm", strcmp( s1, "BBDD") == 0, p == s1);

  strcpy( s1, "AABZBAADZDAA");

  p = strcrm( s1, "ZA");

    check( "strcrm", strcmp( s1, "AAZAAZAA") == 0, p == s1);

  strcpy( s, "abcde");

  p = strrev( s);

    check( "strrev", strcmp( s, "edcba") == 0, p == s);

  return 0;
}
