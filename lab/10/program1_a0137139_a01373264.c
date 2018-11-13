/**********************************************
Lab #: 10

Team #: 11

Name1: Rodrigo Cuevas
ID1: A01370139
Name2: Carlos Carbajal
ID2: A01373264

Program Title: Scheduling algorithms

Brief Description: implementation for some
scheduling algorithms

Compilation command:
gcc -o lab10 program1_a01370139_a01373264.c

Execution command:

./lab10 -fcfs input01.txt -> executes
First-come, First-served algorithm

./lab10 -sjf input01.txt -> executes Shortest
Job First algorithm

./lab10 -rr input01.txt -> executes Round
Robin algorithm

./lab10 -p input01.txt -> executes Priority
scheduling algorithm
**********************************************/

//libraries to import
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readFile(char file[]){
  FILE * fPointer;
  fPointer = fopen(file,"r");
  if(fPointer ==NULL) {
    printf("Empty File \n");
    fclose(fPointer);
    return 1;
  }

  while (!feof(fPointer)){
    fgets(þ);
  }
  fclose(fPointer);
  return 0;
}


int main(int argc, char *argv[]){
  if(argc==3){
    if(strcmp(argv[1],"-fcfs")==0){
       printf("You selected First-Come, First-Served algorithm, the file to open will be %s\n",argv[2]);
       
    }
    if(strcmp(argv[1],"-sjf")==0){
      printf("You selected Shortest Job First algorithm, the file to open will be %s\n",argv[2]);
    }
    if(strcmp(argv[1],"-rr")==0){
       printf("You selected Round Robin algorithm, the file to open will be %s\n",argv[2]);
       int qt;
       printf("Enter the quantum time value: ");
       scanf("%d",&qt);
       printf("\n Time quantum value: %d \n", qt);
    }
    if(strcmp(argv[1],"-p")==0){
       printf("You selected Priority algorithm, the file to open will be %s\n",argv[2]);
    }
    else{
      printf("\n ******* UNKNOWN COMMAND! ******* \n");
    }
  }
}
