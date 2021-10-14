#include <stdio.h>
#include <stdlib.h>

//prototype
void countCharacter(char *string);

//Counts Characters in a string
void countCharacter(char *string)
{

//increments i until \0 marker is reached
    for(int i = 0; string[i] != '\0'; i++){
        //does nothing but increment i
    }

  //print result
  printf("The string \"%s\", has %i characters\n", string, i);
}

int main()
{
  char string[100];
  char *sI = string;

// initialize program state
  system("clear");
  printf("Enter a String: ");

// user input
  scanf("%[^\n]", sI);

// Count Function
  countCharacter(sI);

//end of program
  return 0;
}
