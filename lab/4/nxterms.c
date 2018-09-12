/*
 * Nxterms.c
 * 
 * Author:       Raúl Monroy
 * Requirements: None
 * Usage:        Nxterms N, condition: N \in {1,...,5} 
 *
 * Team 11
 * Rodrigo Cuevas
 * Carlos Carbajal
 */

//Libraries we're going to use in this code
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>
#include <sys/signal.h>

//Declaration of the main function
int main(int argc, char *argv[])
{
  /*Variables we're going to use throught this code
  j will store the numerical value of the argument given by the user
  ppid is the process ID of the father
  and pids[] will be the array were we'll store the process IDs of the forks*/
  int i, j, ppid = getpid(), pids[7];
  //array of chars with len 2 called Num
  char Num[1];

  // Check valid usage
  //Verifies that the user only inputs 1 argument
  if (argc!=2) {
    printf("Error: Bad Usage\n");
    exit(-1);
  }
  //Checks the argument given by the user and converts it to integer
  j=atoi(argv[1]);

  // Notice 1 < argc < 5
  //The integer given must have a value from 1 to 4
  if (j<=1 | j>5) {
    printf("Error: Illegal Input Value\n");
    exit(-1);
  }

  //Loop that will execute only the times that j is equivalent to
  for (i=1; i<=j; i++) {
    //As we create child processes, the ids of these will enter to an array
    pids[i] = fork();
    //Switch case that will check the process that was created before
    switch(pids[i]) {
    //case 0 will occur whenever the process created is a child process
    case 0:
	    //turns the int i into a string and stores it in Num
	    sprintf(Num, "%d", i);
	    /*executes the num.c program that we compiled as hprog
	    and enter the Num value as the argument given*/
            execlp("./hprog","./hprog",Num, (char *)NULL);
	    //prints an error if the process could not execute
	    printf("Error: Process Execution\n");
	    //kills the process
	    exit(-1);
    //switch case -1 applies when the process could not be created
    case -1:
	   	 printf("Error: Process Creation\n");
            exit(-1);
    }
  }
  //prints the pid of the father
  printf("\nParent Process ID = %d\n", ppid);
  //waits for the user to enter a key to kill all the processes created
  getchar();
  //when the user enters the key, this loop occurs and kills all the child processes
  for (i=1; i<=j; i++) {
    printf("Child %d killed\n", pids[i]); kill(pids[i],SIGKILL);
  }
}
