#include <stdio.h>
#include <string.h>
#include <unistd.h>
/*Team 11
Rodirigo Cuevas
Carlos Carbajal*/
int main(int argc,char *argv[] )
{
  char echo[5];
  strcpy(echo, "echo");
  if(argc!=3)
  {
    printf("Check the arguments given \n");
  }
  else
  {
    if(strcmp(argv[1], echo)==0)
    {
      execlp("echo","echo", argv[2], NULL);
    }
    else
    {
      printf("Unknown command \n");
    }
  }
}

