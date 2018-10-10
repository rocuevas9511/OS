/*
  Team 11
  Rodrigo Cuevas
  Carlos Carbajal
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/* mycopy requires the caller to insure instr is NULL-terminated
and outstr has enough space to hold a copy of instr. */
void mycopy(char *instr, char *outstr)
{
  for(int i=0; instr[i]!='\0' ;i++)
  {
    outstr[i]=instr[i];
  }
}

/* slen returns the length of the string instr. instr is NULL-terminated */
int slen(char *instr)
{
  int len;
  for(int i=0; ; i++)
  {
    if(instr[i]!='\0')
    {
      len++;
    }
    else
      break;
  }
  return len;
}

int func3(char *str, char *w)
{
  int idx,i,j;
  for (i=0; str[i]; i++)
  {
    if (str[i] == w[j])
    {
      if (!j) idx = i;
      j++;
    }
    else
      j = 0;
    if (w[j] == '\0')
      break;
   }
    if (w[j] != '\0')
      return(-1);
    else
      return(idx);
}

void main()
{
  char name[80];
  char quote[256];
  char name_copy[80];
  int id;

  strcpy(name,"Michael Daconta");
  strcpy(quote,"The C language has brought forth a new era in computing");
  printf("name is %s.\n",name);

  mycopy(name,name_copy);
  printf("name_copy is %s.\n",name_copy);
  printf("the length of :\n%s\n is %d.\n",quote,slen(quote));
  printf("the length of :\n%s\n is %d.\n",name_copy,slen(name_copy));

  id = func3(quote, "forth");
  if (id != -1)
   NULL; // print results accordingly
  else
    NULL;// print results accordingly
}

