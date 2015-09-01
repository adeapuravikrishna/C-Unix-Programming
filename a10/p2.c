#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <errno.h>
#include<time.h>
void dealer();
int high=101, low=0,guess=0;
void init( void)
{   
   guess =(low+high)/2;
   fprintf(stderr,"player: guess = %d\n",guess);
}
int player(char answer[100])
{     
 if(strcmp("h",answer)==0 || strcmp("higher",answer)==0)
     {
       low = guess;
       fprintf(stderr, "player:trying higher\n");
       guess=guess+(high-guess)/2;
       fprintf(stderr,"Player guess=%d\n",guess);
     }
    else if(strcmp("l",answer)==0 || strcmp("lower",answer)==0)
     {
       high = guess;
       fprintf(stderr, "player:trying lower\n");
       guess=guess-(guess-low)/2;
       fprintf(stderr,"Player guess=%d\n",guess);
     }
     else if(strcmp("c",answer)==0 || strcmp("correct",answer)==0)
     {
       fprintf(stderr, "player:correct!\n"); exit(0);
     }     
return 0;
}
void dealer()
{
fprintf(stdout,"%d\n",guess);
char answer[100];
do{
scanf("%s",answer); 
player (answer);
fprintf(stdout,"%d\n",guess);
}while(1);
}
int main()
{
setbuf( stdout, 0);
init(); 
dealer();
return 0;
}
