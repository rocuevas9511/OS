/*
  Team 11
  Rodrigo Cuevas
  Carlos Carbajal

*/
#include <stdio.h>
void foo1(int xval)
{
  int x;
  x =xval;
  printf("Value of xval: %d \t Address of xval: %p \n", x, (void*)&x);
}

void foo2(int dummy)
{
  int y;
  printf("Value of y: %d \t Address of y: %p \n", y,(void *)&y);
}

int main()
{
  foo1(7);
  foo2(11);
  return 0;
}
