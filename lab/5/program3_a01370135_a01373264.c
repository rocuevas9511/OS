/*
  Team 11
  Rodrigo Cuevas
  Carlos Carbajal
*/
#include <stdio.h>
int main()
{
    char c = 'Z';
    char *cp = &c;
    printf("cp is 0x%08x\n", cp);
    printf("The character at cp is %c\n", *cp);

    /*Pointer arithmetic - see what cp+1 is */
    cp=cp+1;
    printf("cp is 0x%08x\n",cp);

    printf("\n ******************** \n");

    int i = 12;
    int *ip = &i;
    printf("ip is 0x%08x\n", ip);
    printf("The character at ip is %i\n", *ip);

    /*Pointer arithmetic - see what cp+1 is */
    ip=ip+2;
    printf("ip is 0x%08x\n",ip);

    printf("\n ******************** \n");

    double d = 3.14159265359;
    double *dp = &d;
    printf("dp is 0x%08x\n", dp);
    printf("The character at dp is %f\n", *dp);

    /*Pointer arithmetic - see what cp+1 is */
    dp=dp+3;
    printf("dp is 0x%08x\n",dp);
    return 0;
}
