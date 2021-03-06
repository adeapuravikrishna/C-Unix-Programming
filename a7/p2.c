#include <stdio.h>	// for fgets()
#include <string.h>	// for strtok()
#include <stdlib.h>	// for strtod()
#include <errno.h>	// for errno
#include<math.h>
#define SPACE " \t\v\f\r\n"	// whitespace
#define SIZE 100	// stack size
double s[SIZE];			// the stack
int n = 0;			// number of elements on the stack
double pop(void)
{
  if(n == 0)
  {
    printf("stack is empty\n");
    return 0;
  }
  --n;
  return s[n];
}
void list(void)
{
printf("\n");
  for(int i = 0; i <n;i++)
    printf("\t%g\n", s[i]);
}
void push(double x)
{
  if(n >= SIZE)
  {
    printf("stack is full\n");
    return;
  }
  s[n] = x;
  ++n;
}
void dup()
{
 push(s[n - 1]);
}
void sqrt1()
{
    pop();
    s[n] = sqrt(s[n]);
    push(s[n]);
}
void divi()
	{
	double div = s[n - 2]/s[n - 1];
    pop();
    pop();
    push(div);
	}
void prod()
	{
	 pop();
  double mul = s[n] * s[n - 1];
    pop();
   push(mul);
	}
void clear()
	{
	for(int i = 0; i < n; i++)
    {
      pop();
    }
	}
void sum()
	{
double sum = s[n - 1] + s[n - 2];
    pop();
    pop();
    push(sum);
	}
void sub()
{
   double sub = s[n - 1] - s[n - 2];
    pop();
    pop();
   push(sub);
	}
void quit(){ exit(0); }
void end() { exit(0);}
typedef void (*Func)();
typedef struct { const char *name; Func f; } Table;
Table t[] =
{
  { "+",   sum },
  { "-",  sub },
  { "/",  divi },
  { "*",  prod },
  { "clear",   clear  },
  { "quit",     quit  },
  { "exit",  end },
  { "sqrt",     sqrt1 },
  {    "dup",     dup  }
};
Func lookup( const char name[])
{
  for( int i = 0; t[i].name != 0; ++i)
   if( strcmp( name, t[i].name) == 0) return t[i].f;
  return NULL;
}
void process_word(const char *word)
{
char *endptr;
  errno = 0;
printf("%s ", word);
  if(errno)
    perror("strtod");
    double x = strtod(word, &endptr);
  if(x!=0) 
 push(x);
if(endptr == word)
{  
  Func f = lookup( word);
f();
 } 
    
}
// parse line into separate words using strtok
//
void process_line(char line[])
{
  char *word;
//
// abc efg
// ^  0        strtok will put '\0' at end of each word in line
//
  word = strtok(line, SPACE);	// first call to strtok, give it the line
  if(word != NULL)
    do
    {
      process_word(word); 
    }
    while((word = strtok(NULL, SPACE)) != NULL);
  // subsequent calls to strtok, give it NULL to continue with the same line
  list();
}
int
main(void)
{
  char line[BUFSIZ];
  while(fgets(line, BUFSIZ, stdin))
    // fputs( line, stdout);
    process_line(line);
  return 0;
}
