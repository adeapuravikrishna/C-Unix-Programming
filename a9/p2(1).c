#include <sys/types.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct element { char *str; double d; struct element *next; } E;
E *s = NULL; // the stack
void list( void)
{
E *u=NULL;
  printf( "stack:\n");
  for( E *p = s; p != 0; p = p->next )
{
double l;
printf("%g   %s",p->d,p->str);
u=p->next;
if(u)
{
l=p->d;
while(u->d==l)
{
printf("\t%s\t",u->str);
u=u->next;
}
printf("\n");
 }
}}
char *new_str( char *str)
{
  char *p = malloc( strlen(str) + 1);
  if( p) strcpy( p, str);
 
  return p;
}
E *new_E( char *str,double du)
{
E *e=malloc( sizeof(E));
  if( e == NULL) abort();
  e->str =str;
  e->d=du;
return e;
}
void push( char *str,double d)
{
  E *p = new_E( str,d);
  p->next = s; // insert p at head of the list
  s = p;
}
int dir_search(const char *root, char *dir)
{
  struct stat sbuf;
  char *path = malloc(strlen(dir) + strlen(root) + 2);
  sprintf(path, "%s/%s", root, dir);	
  stat(path, &sbuf);
  if(!(S_ISDIR(sbuf.st_mode)))
{
double z=(unsigned long) sbuf.st_size;
 push(path,z);
} 
  return S_ISDIR(sbuf.st_mode);
}
void scan(const char *dir)
{
  DIR *dp = opendir(dir);
  if( dp == NULL) { perror( dir); return; }
  struct dirent *de;
  while((de = readdir(dp)))
  {
  char *entry_name = de->d_name;
    if(!strcmp(".", entry_name) || !strcmp("..", entry_name))
      continue;
    if(dir_search(dir, entry_name))	//recursively scanning directories
    {
     char *next = malloc(strlen(dir) + strlen(entry_name) + 2);
      sprintf(next, "%s/%s", dir, entry_name);	//sends formatted output to a string pointed to
      scan(next);
    //  free(next);
    }
  }
  closedir(dp);
}
int main(int argc, char *argv[])
{
  if(argc > 1)
    for(int i = 1; i < argc; ++i)
      scan(argv[i]);
  else
    scan(".");
list();
  return 0;
}
