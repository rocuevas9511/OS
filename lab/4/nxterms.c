#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[])
{ 
  int i, j, pid = getpid(), pids[5]; 
  char Num[1]; 

  if (argc!=2) {
    printf("Error: Bad Usage\n");
    exit(-1);
  }

  j=atoi(argv[1]);
  if (j<1 | j>6) {
    printf("Error: [%d] Illegal Input Value\n",j);
    exit(-1);
  }

  printf("\nMain Process ID = %d\n",pid);  

  for (i=1; i<=j; i++) {
    pids[i] = fork();
    switch(pids[i]) {
    case 0: 
      sprintf(Num, "%d", i);
      execlp("./hprog",Num,NULL);
      printf("Error: Process Execution\n");
      exit(-1);
    case -1: printf("Error: Process Creation\n");
      exit(-1);
    }
  }
  
  getchar();
  
  for (i=1; i<=j; i++) {
    printf("Child %d killed\n", pids[i]); kill(pids[i],SIGKILL);
  }
  
}
