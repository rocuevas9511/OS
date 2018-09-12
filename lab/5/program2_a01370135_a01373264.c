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
  printf("Value of xval: %d \t Address of xval: %p", x, (void*)&x);
}

int main()
{
  foo1(7);
  return 0;
}
