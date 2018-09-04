#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int simpleGrep(char *f, char *word, int caso)
{
    FILE *openFile;
    int line =1, count=0;
    char currLine[512];
    if((openFile = fopen(f,"r"))==NULL)
    {
	printf("Empty file! \n");
	return (0);
    }
    while(fgets(currLine, 512, openFile)!=NULL)
    {
        if(caso!=2){
	    if(strstr(currLine,word)!=NULL)
	    {
	        printf("\n %s \n",currLine);
	        count++;
	    }
	    line++;
	}
	else
	{
	    if(strstr(currLine,word)==NULL)
	    {
	        printf("\n %s \n",currLine);
	    }
	    line++;
	}
    }
    if(caso!=2 && count==0)
    {
	printf("No match found! \n");
    }
    if(caso==1)
    {
	printf("Times the word was found: %d \n", count);
    }
    fclose(openFile);
    return(0);
}

int main(int argc, char *argv[]){
    if (argc ==3)
    {
        printf("The file to open is %s the word to search is %s\n", argv[1], argv[2]);
        simpleGrep(argv[1], argv[2],0);
    }
    else if(argc == 4)
    {
	if(strcmp(argv[3],"count")==0)
        {
            printf("The file to open is %s the word to search is %s and the action to do is %s\n ",argv[1], argv[2], argv[3]);
            simpleGrep(argv[1], argv[2], 1);
	}
	else if(strcmp(argv[3],"invert")==0)
	{
	    printf("The file to open is %s the word to search is %s and the action to do is %s \n",
		argv[1],argv[2],argv[3]);
	    simpleGrep(argv[1],argv[2],2);
	}
	else
	{
	    printf("Last argument unkwown! \n");
	}
    }
    else if(argc>3)
    {
        printf("Too many arguments supplied. \n");
    }
    else {
        printf("Please enter a file and a word. \n");
    }
}
