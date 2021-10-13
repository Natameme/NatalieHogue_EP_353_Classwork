#include <stdio.h>
#include <stdlib.h>

void setArray(int *numbers, int value, int size);

void setArray(int *numbers, int value, int size){
    for(int i = 0; i <= size; i++){
      numbers[i] = value;
    }
  printf("The The 'numbers' array is now initialized to %i: \n\n", value);
    for(int i = 0; i <= size; i++){
      printf("%i ", numbers[i]);
    }
    printf("\n");
}

int main(){
//variables
  int value;
  int numbers[8];
  int size = sizeof(numbers)/sizeof(int);
//User Input Prompt
  system("clear");
  printf("Enter an integer to initialize the array: ");
  scanf("%i", &value);
//Outside Function
  setArray(numbers, value, size);
//End of Program
  return 0;
}
