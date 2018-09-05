#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tryRead(char *fileToRead)
{
    FILE *openFile;
    openFile=fopen(fileToRead,"r");
    if(openFile==NULL)
    {
        printf("Empty File \n");
        fclose(openFile);
        return(0);
    }
    else
    {
        fclose(openFile);
        return(1);
    }
}

int read20(char *fileToRead)
{
    FILE *openFile;
    int line =0;
    char currLine[512];
    openFile=fopen(fileToRead,"r");
    while(fgets(currLine, 512, openFile)!=NULL)
    {
        if(line==20)
        {
            (void)getchar();
            printf("%s",currLine);
            line=1;
        }
        else
        {
            printf("%s",currLine);
            line++;
        }
    }
    fclose(openFile);
}

int readFile(char *fileToRead)
{
    int tryReadResult;
    printf("the file to open %s \n",fileToRead);
    tryReadResult = tryRead(fileToRead);
    if(tryReadResult==1)
    {
        read20(fileToRead);
    }
    else
    {
        printf("operation failed \n");
    }
}

int main(int argc, char *argv[])
{
    if(argc==2)
    {   
        readFile(argv[1]);  
    }
    return(0);
}

