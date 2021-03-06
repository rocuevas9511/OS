/*
  Team 11
  Rodrigo Cuevas
  Carlos Carbajal
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct employee {
  char name[80];
  int age;
  char address[256];
};

void func1(struct employee *employee_ptr)
{
  strcpy(employee_ptr->name,"harry houdini");
}

void func2(struct employee employee_copy)
{
  strcpy(employee_copy.name,"Theodore Roosevelt");
  printf("my emloyee has a new name %s.\n",employee_copy.name);
}

/*Function 1 directs the name pointer to a new value, while
function 2 copies the new value to the old value*/

//Function 3

void func3(struct employee *employee, struct employee *nemployee)
{
  printf("\n ***Coping data to new employee*** \n");
  strcpy(nemployee->name,employee->name);
  nemployee->age = employee->age;
  strcpy(nemployee->address, employee->address);
}

void main()
{

  struct employee joe = {"joe blow",32,"222 main street, nowhere, US"};

  struct employee *eptr;

  printf("the starting address of joe is %p.\n",&joe);
  eptr = &joe;
  printf("eptr holds %p.\n",eptr);
  printf("the full name of joe is %s.\n",joe.name);
  printf("the full name of joe is %s.\n",eptr->name);
  printf("the full name of joe is %s.\n",(*eptr).name);

  func1(&joe);
  printf("the full name of joe is now %s.\n",joe.name);
  printf("the full name of joe is now %s.\n",eptr->name);

  func2(joe);
  printf("the full name of joe is now %s.\n",joe.name);
  printf("the full name of joe is now %s.\n",eptr->name);

  struct employee nemp;
  struct employee *neptr;
  neptr=&nemp;

  func3(eptr,neptr);
  printf("name copied %s\n",neptr->name);
  printf("age copied %d\n",neptr->age);
  printf("address copied %s\n",neptr->address);
}
