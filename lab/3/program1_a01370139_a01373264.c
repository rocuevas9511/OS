//Team 11 Carlos Carbajal - Rodrigo Cuevas
#include <stdio.h>
#include <stdlib.h>
//declaration of our recursive function
int recursive(int n, int res)
{
    //base case, when no sum left
    if(n==0)
    {
        printf("Your total sum is: %d \n",res);
        return(0);
    }
    //adding the numbers 'til reaching n
    else
    {
	res=res+n;
        printf("It: %d \t Total: %d \n",n, res);
	recursive(n-1,res);
    }
}

int main(int argc, char *argv[])
{
    //receiving the value of n
    if(argc==2)
    {
	system("clear");
	printf("Sum between 0 and %s...\n",argv[1]);
	//stariting with the first sum
	recursive(atoi(argv[1]),0);
    }
    else
    {
	printf("Could not execute! \n");
	return(0);
    }
}
