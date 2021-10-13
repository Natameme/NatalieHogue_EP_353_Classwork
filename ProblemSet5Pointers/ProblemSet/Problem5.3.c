#include<stdio.h>
#include<stdlib.h>

void copyString(char *str1, char *str2);

void copyString(char *str1, char *str2){
  *str2 = *str1;
}

int main(){
  char str1;
  char str2;

  system("clear");
  printf("Input a string: ");
  scanf("%[^\n]", &str1);

  copyString(&str1, &str2);
  printf("String 1: %s \n", &str1);
  printf("String 2: %s", &str2);
  return 0;
}
