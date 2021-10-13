#include <stdio.h>
#include <stdlib.h>

void countCharacter(char *string);
void countCharacter(char *string)
{
  int strSize = *(&string + 1) - string;
  printf("The string \"%s\" , has %i characters\n", string, strSize);
}

int main()
{
  char string[100];
  char *sI = string;

  system("clear");
  printf("Enter a String: ");
  scanf("%[^\n]", sI);
  countCharacter(sI);
  return 0;
}
