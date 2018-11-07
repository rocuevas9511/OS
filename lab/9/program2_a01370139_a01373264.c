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
