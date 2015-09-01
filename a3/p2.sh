#!/bin/sh
dealer() 
{
#echo "Argument 1:" . $1
rand=$1;
low=0
high=101
while :
do
  
  guess=`expr $low + $high`
  guess=`expr $guess / 2`
  if [ $guess -eq $rand ]
  then
       echo "guess = $guess, correct! \n"
       exit 0   
 elif [ $guess -lt $rand ]
  then
       echo "guess = $guess, lower! \n" 
       low=$guess
                       
  else 
       echo "guess = $guess, higher! \n" 
       high=$guess
 fi
done
}
answer=$(echo hi | awk '{ srand(); print int(1+100*rand()); }')
dealer $answer
