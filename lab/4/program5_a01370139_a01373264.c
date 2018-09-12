#include <stdio.h>
#include <string.h>
#include <unistd.h>
/*Team 11
Rodirigo Cuevas
Carlos Carbajal*/
int main(int argc,char *argv[] )
{
  if(!(argc==3 | argc==2))
  {
    printf("Check the arguments given \n");
  }
  else
  {
    execlp(argv[1],argv[1], argv[2], NULL);
  }
}



