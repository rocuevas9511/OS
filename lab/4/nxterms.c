/*
 * Nxterms.c
 * 
 * Author:       Raúl Monroy
 * Requirements: None
 * Usage:        Nxterms N, condition: N \in {1,...,5} 
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>
#include <sys/signal.h>

int main(int argc, char *argv[])
{ 
  int i, j, ppid = getpid(), pids[7]; 
  char Num[1]; 

  // Check valid usage
  if (argc!=2) {
    printf("Error: Bad Usage\n");
    exit(-1);
  }

  j=atoi(argv[1]);

  // Notice 1 < argc < 5
  if (j<=1 | j>5) {
    printf("Error: Illegal Input Value\n");
    exit(-1);
  }
  
  for (i=1; i<=j; i++) {
    pids[i] = fork();
    switch(pids[i]) {
    case 0: sprintf(Num, "%d", i);
            execlp("xterm", "xterm", "-e", "tcsh", 0);
	    printf("Error: Process Execution\n");
	    exit(-1);
    case -1: printf("Error: Process Creation\n");
            exit(-1);
    }
  }
  printf("\nParent Process ID = %d\n", ppid);
  getchar();
  for (i=1; i<=j; i++) {
    printf("Child %d killed\n", pids[i]); kill(pids[i],SIGKILL);
  }
}
