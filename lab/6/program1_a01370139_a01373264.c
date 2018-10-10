/*********************************
Lab #: 6

Team #: 11
Name1: Rodrigo Cuevas
ID1: A01370139
Name2: Carlos Carbajal
ID2: A01373264

Program Title: Processes on C

Brief Description: this program
executes a procress so you can
watch how it may turn unto a
zombie, how to suspend it, and
how to terminate it

Compilation Command:
gcc -o <programName>
program1_a01370139_a01373264.c

Execution Command:
- To see a zombie:
./<programName> -z

- To see a suspended one:
./<programName> -s

- To terminate a process:
./<programName> -t

*********************************/

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>

int zombieProcess()
{
  //We use PID to know the process ID
  pid_t pid;
  //Creating a child process
  pid=fork();

  if(pid==0)
  {
  //Where the child process dies and becomes a zombie
    exit(0);
  }
  //Parent process waiting on the user to end
  else
  {
    sleep(1);
    system("ps -eo pid,ppid,stat,cmd");
  }
}

int terminateProcess()
{
  pid_t pid;
  pid=fork();
  if(pid==0)
  {
      printf("Watch me on the table! I'm process: %d", pid);
      sleep(2);
      system("ps -eo pid,ppid,stat,cmd");
  }
  else
  {
    printf("Terminating process: %d", pid);
    kill(pid, SIGTERM);
    sleep(2);
    system("ps -eo pid,ppid,stat,cmd");
  }
}

int suspendProcess()
{
  pid_t pid;
  pid=fork();
  if(pid==0)
  {
      printf("Watch me on the table! I'm process: %d", pid);
      sleep(2);
      system("ps -eo pid,ppid,stat,cmd");
  }
  else
  {
    printf("Suspending process: %d", pid);
    kill(pid, SIGINT);
    sleep(2);
    system("ps -eo pid,ppid,stat,cmd");
    printf("Terminatinng process: %d", pid);
    kill(pid, SIGTERM);
    sleep(2);
    system("ps -eo pid,ppid,stat,cmd");
  }
}

int main(int argc, char *argv[])
{
  if (argc == 2)
  {
    if (strcmp(argv[1],"-z")==0)
    {
      zombieProcess();
    }
    else if(strcmp(argv[1],"-s")==0)
    {
      suspendProcess();
    }
    else if(strcmp(argv[1], "-t")==0)
    {
      terminateProcess();
    }
    else
    {
      printf("************ Unknown command! ********** \n");
    }
  }
  else
  {
    printf("\n ************ Unknown command! *************** \n");
  }
}
