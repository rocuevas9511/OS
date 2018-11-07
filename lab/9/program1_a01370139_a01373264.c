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

void *count(void *arg);

//un
unsigned int cnt;
sem_t mutex;

int main()
{
  pthread_t tid1, tid2;
  sem_init(&mutex, 0, 1);
  pthread_create(&tid1, NULL, count, NULL);
  pthread_create(&tid2, NULL, count, NULL);
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);

  if(cnt != (unsigned)NITER*2)
    printf("BOOM! cnt= %d \n", cnt);
  else
    printf("OK cnt=%d\n", cnt);
  exit(0);
}

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
