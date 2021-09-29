#include <stdio.h>  //standard library
#include <stdlib.h> //library for system commands

int main(){
  int number;
  system("clear");
  printf("\nPick a number, any number: ");
  scanf("%d", &number);
//LOOP
  for(int i = number; i > 0; i--){
    if(i % 2 == 1){
      printf("%d", i);//PRINT ODD NUMBERS
    } else {
      printf(" ");//PRINT SPACES FOR EVEN NUMBERS
    }//END IF ELSE
  }//END LOOP
printf("\n");//new line
return 0;//EXIT PROGRAM
}
