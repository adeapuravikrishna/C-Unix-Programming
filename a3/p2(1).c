#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int dealer(int RandomNum)
{
int guess;
int low=0,
high=101;
while(1)
{
guess=(high+low)/2;
if (guess==RandomNum)
{
   
printf("guess = %d, correct! \n",guess);
 
  return 0;
}
else if(guess<RandomNum)
{
 
 printf("guess = %d, lower! \n",guess);
  
 low=guess;
}
else if(guess>RandomNum)
{
 
  printf("guess = %d, higher! \n",guess);
 
  high=guess; 
  }
}
}
int main()
{
srand(time(0));
unsigned RandomNum = (rand() % 100)+1;
//printf("dealer number is %d\n",RandomNum);
dealer(RandomNum);
return 0;
}
