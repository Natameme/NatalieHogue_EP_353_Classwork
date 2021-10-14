#include <stdio.h>
#include <stdlib.h>

void setArray(int *numbers, int value, int size);

void setArray(int *numbers, int value, int size){

  //set all array values to int value
      for(int i = 0; i <= size; i++){
        numbers[i] = value;
      }

  //print result
    printf("The The 'numbers' array is now initialized to %i: \n\n", value);
  //loop
    for(int i = 0; i <= size; i++){
      printf("%i ", numbers[i]); //print values of array
    }
  printf("\n"); //new line
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
