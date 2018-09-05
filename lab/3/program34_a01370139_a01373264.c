//Team 11 Carlos Carbajal - Rodrigo Cuevas 
//libraries will use in this code
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//declarartion of simpleGrep, needs name of file, word to search, and which extra argument to execute
int simpleGrep(char *f, char *word, int caso)
{
    //declare a file, a variable to count coincidences, and an array to archive the current line of the file
    FILE *openFile;
    int count=0;
    char currLine[512];
    //check if file isn't empty
    if((openFile = fopen(f,"r"))==NULL)
    {
	printf("Empty file! \n");
	return (0);
    }
    //while the file has lines, look for coincidences
    while(fgets(currLine, 512, openFile)!=NULL)
    {
        //print lines that contain the word
        if(caso!=2){
	    if(strstr(currLine,word)!=NULL)
	    {
	        printf("\n %s \n",currLine);
	        count++;
	    }
	}
	else
	{
	    //invert search, print lines without matching elements
	    if(strstr(currLine,word)==NULL)
	    {
	        printf("\n %s \n",currLine);
	    }
	}
    }
    //if it isn't inverse search and no matching elements we're found, alert the user
    if(caso!=2 && count==0)
    {
	printf("No match found! \n");
    }
    //let the user know how many matching elements were on the line if he asks for it
    if(caso==1)
    {
	printf("Times the word was found: %d \n", count);
    }
    fclose(openFile);
    return(0);
}

int main(int argc, char *argv[]){
    //if 3 arguments received, only looks for coincidences
    if (argc ==3)
    {
        printf("The file to open is %s the word to search is %s\n", argv[1], argv[2]);
        simpleGrep(argv[1], argv[2],0);
    }
    //if 4 arguments received, prints coincidences or inverted search
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
	//argument unknown
	else
	{
	    printf("Last argument unknown! \n");
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

