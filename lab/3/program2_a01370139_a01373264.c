/*Team 11 Carlos Carbajal - Rodrigo Cuevas*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*<summary>
*Will try to read the content of the file, in case of failure, it will notify the user
*</summary>
*<param name="fileToRead">The filename to be read and displayed</param>
*/
int tryRead(char *fileToRead)
{
    FILE *openFile;
    openFile=fopen(fileToRead,"r");
    if(openFile==NULL)
    {
        /* cannot read cotnents of file*/
        printf("Empty File \n");
        fclose(openFile);
        return(1);
    }
    else
    {
        /*closes file and return control to caller*/
        fclose(openFile);
        return(0);
    }
}
/*<summary>
*Will read the content of the file, and print 20 lines waiting for an input to continue and show the next 20
*</summary>
*<param name="fileToRead">The filename to be read and displayed</param>
*/
int read20(char *fileToRead)
{
    FILE *openFile;
    int line =0;
    char currLine[512];
    openFile=fopen(fileToRead,"r");
    /* read line by line and print it*/
    while(fgets(currLine, 512, openFile)!=NULL)
    {
        /*if line counter is 20 it waits for user input*/
        if(line==20)
        {

            (void)getchar();
            printf("%s",currLine);
            line=1;
        }
        else
        {
            /*if not , it print the line and ups the count*/
            printf("%s",currLine);
            line++;
        }
    }
    fclose(openFile);
}
/*<summary>
*Will call a function to verify that the file is readable and the call a function to read and print its contents
*</summary>
*<param name="fileToRead">The filename to be read and displayed</param>
*/
int readFile(char *fileToRead)
{
    int tryReadResult;
    printf("the file to open %s \n",fileToRead);
    tryReadResult = tryRead(fileToRead);
    if(tryReadResult==0)
    {
        read20(fileToRead);
        return(1);
    }
    else
    {
        /* cannot read cotnents of file*/
        printf("operation failed \n");
        return(0);
    }
}
/*<summary>
*Entry point of execution
*</summary>
*<param name="argc">number of arguments</param>
*<param name="argv">array of arguments</param>
*/
int main(int argc, char *argv[])
{
    /*
    *Given a file, it will read it and display it 
    * content 20 lines at a time
    */

   /*if only one argument is passed it executes*/
    if(argc==2)
    {   
        readFile(argv[1]);  
    }
    else if(argc>=3)/*promt a message if more than one argument is passed*/
    {
        printf("Provide only one argument \n");
    }
    return(0);
}

