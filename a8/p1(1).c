#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[BUFSIZ], s1[BUFSIZ], s2[BUFSIZ], *p,*q;
int length,count;
char *strdog( const char s1[], char s2[])
{
  // printf("%s\n",s1);
  // printf("%s\n",s2);
 int i,j,size1,size2;
size1=strlen(s1); 
size2=strlen(s2);
  for(i = size1 - 1; i>= 0; i--)
  {
    for(j = size2 + size1; j >= 0; j--)
    {
      if(j > 0)
      {
	s2[j] = s2[j - 1];
      }
      else if(j == 0)
	s2[j] = s1[i];
    }
  }
  s2[size1 + size2] = '\0';
  return s2;
} 
char *strrm( char s1[], const char s2[])
{
int size1= strlen(s1);
   int size2= strlen(s2);
    for (int j=0; j<size2; j++){
        for (int i=0; i<size1; i++){
             if (s2[j]==s1[i])
{
s1[i]=' ';
}
                 
        }
    }
int size3=strlen(s1);
int t=0;
for(int k=0;k<size3;k++){
if(s1[k]==' '){
for(t=k;t<size3;t++){
s1[t]=s1[t+1];
} k--;
}
}
return s1;
} 
char *strcrm( char s1[], const char s2[])
{
int size1= strlen(s1);
   int size2= strlen(s2);
//printf("\n%d",size2);
//printf("\n%d",size1);
    for (int j=0; j<size1; j++){
        for (int i=0; i<size2; i++){
             if (s1[j]==s2[i])
{
//printf("\n%d",j);
}else{
}
//printf("\n%s",s1);
                 
        }
    }
int size3=strlen(s1);
int t=0;
for(int k=0;k<size3;k++){
if(s1[k]==' '){
for(t=k;t<size3;t++){
s1[t]=s1[t+1];
} k--;
}
}
return s1;
} 
char *strrev( char s[])
{
int c,i,j,length=0;
while(s[length]!='\0') 
    {
        length++;
    }
for(i=0,j=length-1;i<j;i++,j--)
{
c=s[i];s[i]=s[j];
s[j]=c;
}
return s;
}
int main()
{
  strcpy(s2, "efg");
  p = strdog("abc", s2);
  printf("output for strdog function p= %s\n", p);
  strcpy(s, "ravikrishna");
  p = strrev(s);
  printf("output for strrev function p= %s\n", p);
  strcpy(s1, "AABZBAADZDAA");
  p = strrm(s1, "ZA");
  printf("output for strrm function p= %s\n", p);
  strcpy(s1, "AABZBAADZDAA");
  p = strcrm(s1, "ZA");
  printf("output for strcrm function p= %s\n", p);
}
