/**********************************************
Lab #: 9

Team #: 11

Name1: Rodrigo Cuevas
ID1: A01370139
Name2: Carlos Carbajal
ID2: A01373264

Program Title: Producer-consumer problem

Brief Description: an implementation of the
producer-consumer problem with the code
previously given

Compilation command:
gcc -o proCon program2_a01370139_a01373264.c
-lpthread -lrt

Execution command:
./proCon
**********************************************/

//libraries to import
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

//maximum buffer size
#define BUFF_SIZE 4

char buffer[BUFF_SIZE];
int nextIn = 0;
int nextOut = 0;

sem_t empty_slots;
sem_t full_slots;

void Put(char item)
{
  sem_wait(&empty_slots);
  buffer[nextIn] = item;
  nextIn = (nextIn + 1) % BUFF_SIZE;
  printf("Producing %c ...\n", item);
  sem_post(&full_slots);
}

void * Producer()
{
    int i;

    for(i = 0; i < 10; i++)
    {
      Put((char)('A'+ i % 26));
    }
}

//this function will be called by the consumer
void Get(){
  //the item it'll consume
  int item;
  //the semaphore waits until it can start consuming
  sem_wait(&full_slots);
  //the buffer will throw the item to consume
  item=buffer[nextOut];
  //it checks which item follows
  nextOut=(nextOut+1)%BUFF_SIZE;
  printf("Consuming %c... \n", item);
  sem_post(&empty_slots);
}

//consumer function
void * Consumer(){
  int i;
  for (i=0;i<10;i++) Get();
}

int main(){
  //threads we'll use
  pthread_t tid1,tid2;
  //semaphore initialization, both semaphores share memory
  sem_init(&empty_slots, 1, 4);
  sem_init(&full_slots, 1, 0);
  //creation of threads
  pthread_create(&tid1,NULL, Producer, NULL);
  pthread_create(&tid2,NULL,Consumer, NULL);
  //reunite data from both threads
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  exit(0);
}
