#include <stdio.h>

void iprint();
int i=0;

int main()
{
  int j;

  for (j=0; j<50; j++)
    {
      iprint();
      printf("%d\n",i);
    }
}

void iprint()
{
  i +=1;  
  /* No local variable i is defined, so i refers to the global variable. */
  //printf("%d\n",i); 
}