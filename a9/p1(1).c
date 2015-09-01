#include <sys/types.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
int dir_search(const char *root, char *dir)
{
  struct stat sbuf;
  char *path = malloc(strlen(dir) + strlen(root) + 2);
  sprintf(path, "%s/%s", root, dir);	//sends formatted output to a string pointed to 
  stat(path, &sbuf);
  if(S_ISDIR(sbuf.st_mode))
    printf("d\t");
  else
    printf("\t");
  printf("%lu\t%s\n", (unsigned long) sbuf.st_size, path);
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
      sprintf(next, "%s/%s", dir, entry_name);	////sends formatted output to a string pointed to
      scan(next);
      free(next);
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
  return 0;
}
