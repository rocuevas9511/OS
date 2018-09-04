#include <stdio.h>
#include <stdlib.h>

int recursive(int n, int res)
{
    if(n==0)
    {
        printf("Your total sum is: %d \n",res);
        return(0);
    }
    else
    {
	res=res+n;
        printf("It: %d \t Total: %d \n",n, res);
	recursive(n-1,res);
    }
}
int main(int argc, char *argv[])
{
    if(argc==2)
    {
	system("clear");
	printf("Sum between 0 and %s...\n",argv[1]);
	recursive(atoi(argv[1]),0);
    }
    else
    {
	printf("Could not execute! \n");
	return(0);
    }
}
