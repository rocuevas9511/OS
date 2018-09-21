/*
  Team 11
  Rodrigo Cuevas
  Carlos Carbajal
*/
#include <stdio.h>
int main()
{
    double  firstVal = 3.141592653;
    int secondVal = 31416;
    char thirdVal= 'k';
    double* firstPtr = &firstVal;
    int* secondPtr= &secondVal;
    char* thirdPtr= &thirdVal;
    printf("The address of the double %f is %p\n",firstVal, &firstVal);
    printf("The address of the int %i is %p\n", secondVal, &secondVal);
    printf("The address of the char %c is %p\n", thirdVal, &thirdVal);
    printf("The address of the *double %f is %p\n", *firstPtr, &firstPtr);
    printf("The address of the *int %i is %p\n", *secondPtr, &secondPtr);
    printf("The address of the *char %c is %p\n", *thirdPtr, &thirdPtr);
    printf("\n ******************************************** \n");
    printf("The value of the double %f is %f \n", firstVal, firstVal);
    printf("The value of the int %i is %i \n", secondVal, secondVal);
    printf("The value of the char %c is %c \n", thirdVal, thirdVal);
    printf("The value of the *double %p is %f \n", firstPtr, *firstPtr);
    printf("The value of the *int %p is %i \n", secondPtr, *secondPtr);
    printf("The value of the *char %p is %i \n", thirdPtr, *thirdPtr);
    printf("\n ******************************************** \n");
    printf("The size of double is %li bytes\n",sizeof(firstVal));
    printf("The size of int is %li bytes\n",sizeof(secondVal));
    printf("The size of char is %li bytes\n",sizeof(thirdVal));
    printf("The size of *double is %li bytes\n",sizeof(firstPtr));
    printf("The size of *int is %li bytes\n",sizeof(secondPtr));
    printf("The size of *char is %li bytes\n",sizeof(thirdPtr));
}
