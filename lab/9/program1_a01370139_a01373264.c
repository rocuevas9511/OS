/**********************************************
Lab #: 9

Team #: 11

Name1: Rodrigo Cuevas
ID1: A01370139
Name2: Carlos Carbajal
ID2: A01373264

Program Title: goodcnt

Brief Description: good version of badcnt

Compilation command:
gcc -o goodcnt program1_a01370139_a01373264.c
-lpthread -lrt

Execution command:
./goodcnt
**********************************************/

//libraries to import
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

//NITER variable to multiply
#define NITER 1000000

//unsigned variable to save the counter
unsigned int cnt;

//our semaphore used throughout the program
sem_t mutex;

//function that threads will execute
void *count(void *arg)
{
  int i;
  for(i=0; i<NITER;i++){
    sem_wait(&mutex);
    cnt++;
    sem_post(&mutex);
  }
  return NULL;
}


int main()
{
  //threads we'll use
  pthread_t tid1, tid2;
  //initialization of our semaphore -> mutex=1
  sem_init(&mutex, 0, 1);
  //creation of the threads, function they'll execute
  pthread_create(&tid1, NULL, count, NULL);
  pthread_create(&tid2, NULL, count, NULL);
  //we reunite the data of both threads
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);

  if(cnt != (unsigned)NITER*2)
    printf("BOOM! cnt= %d \n", cnt);
  else
    printf("OK cnt=%d\n", cnt);
  exit(0);
}
