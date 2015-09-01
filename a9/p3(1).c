// from w10: dynamically allocated linked-list stack
//
// new: change to strings
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SPACE " \t\v\f\r\n" // whitespace
typedef struct element { char *str; struct element *next; } E;
// s -> { word, next -> { word, next -> ... { word, 0 } }
E *s = NULL; // the stack
void list( void)
{
  printf( "stack:\n");
  for( E *p = s; p != 0; p = p->next ) printf( "\t%s\n", p->str);
}
// my strdup
//
char *new_str( char *str)
{
  char *p = malloc( strlen(str) + 1);
  
  if( p) strcpy( p, str);
  return p;
}
E *new_E( char *str)
{
  E *e = malloc( sizeof(E));
  if( e == NULL) abort();
  e->str = new_str( str);
  if( e->str == NULL) abort();
  return e;
}
void push( char *str)
{
  E *p = new_E( str);
  p->next = s; // insert p at head of the list
  s = p;
}
char *pop( void)
{
 //  if( s == NULL) { printf( "stack is empty\n"); return 0; }
   E *p = s;		// temporary copy of s
   char *r = s->str;	// temporary copy of the data
   s = s->next;		// remove s from the list
   free(p);		// free the allocated structure
   return r;		// the string data is still allocated
}
void clear( void)
{
  char *p = pop();
  while( p) { free(p); p = pop(); }
} 
// convert word to double and push onto the stack
//
void process_word( char *word)
{
  push( word);
}
// parse line into separate words using strtok
//
void process_line( char line[])
{
  char *word = strtok( line, SPACE);
  if( word != NULL) do { process_word( word); }
   while( (word = strtok( NULL, SPACE)) != NULL);
  list();
}
int main( void)
{
  char line[BUFSIZ];
  
  while( fgets( line, BUFSIZ, stdin) )
  {
    process_line( line);
    clear();
  }
  
  return 0;
}
