#include <stdio.h>

void emptyString(char str[]);
void emptyString(char str[]){
  str[0] = '\0';

}

int main(){
char sTring[128];
  printf("Enter a String: ");
  scanf("%s", sTring);
  emptyString(sTring);
  printf("\n%s", sTring);

  return 0;
}
