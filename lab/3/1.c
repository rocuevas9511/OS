#include <stdio.h>

int recursive(int n,int x)
{
    if(x==n)
    {
        printf("%d",x);
        x+=1;
        printf("%d",x);
    }
    
}
int main(int argc, char *argv[])
{
    printf("%d",n);
    recursive(n,0);
}