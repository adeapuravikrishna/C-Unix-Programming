// test fork/execlp/pipe
//
// run with args: ./p1 ./p2, same as: ./p1 | ./p2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
// print error message and exit
//
void error( const char msg[])
{
  fprintf( stderr, "%s", msg);
  if( errno) fprintf( stderr, ": %s", strerror( errno));
  fprintf( stderr, "\n");
  exit(1);
}
int main()
{
  pid_t pid;
  int pipefd[2], pipefd1[2];
  char *prog1, *prog2;
  prog1 ="./p2";
  prog2 = "./p1";
 // create pipe
 //
  if( pipe( pipefd) < 0) error( "pipe");
  if( pipe( pipefd1) < 0) error( "pipe");
 // create child process
 //
  if( (pid = fork()) < 0) error( "fork");
  if( pid) // parent
  {
    if( dup2( pipefd[1], 1) < 0) error( "dup2");
    close( pipefd[0]);
    close( pipefd[1]);
    if( dup2( pipefd1[0], 0) < 0) error( "dup2");
    close( pipefd1[0]);
    close( pipefd1[1]);
    execlp( prog1, prog1, 0);
    error( prog1);
  }
  else // child
  {
    if( dup2( pipefd[0], 0) < 0) error( "dup2");
    close( pipefd[0]);
    close( pipefd[1]);
    if( dup2( pipefd1[1], 1) < 0) error( "dup2");
    close( pipefd1[0]);
    close( pipefd1[1]);
    execlp( prog2, prog2, 0);
    error( prog2);
  }
  return 0;
}
