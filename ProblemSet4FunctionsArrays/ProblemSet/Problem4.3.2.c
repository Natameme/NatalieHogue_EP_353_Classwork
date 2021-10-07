#include <stdio.h>

int main(){

//THE ONLY CHANGE TO THIS CODE IS THE USE OF INTEGERS INSTEAD OF CHARS

//VARIABLES
int pitches[8] = {74, 68, 54, 28, 89, 51, 35};
int pitch;
int bucketOne;
int bucketTwo;
int arrSize = sizeof(pitches)/ sizeof(int) - 1;
int index;
//input pitch value
  printf("Enter a new MIDI Pitch Value (integer between 0-127): ");
  scanf(" %d", &pitch);
//input index value
  printf("Select an Index to insert your selected pitch value: ");
  scanf("%i", &index);

//call i for use in all 3 consecutive loops
  int i = 0;
//while i is less than index, do nothing and increment i
  while (i < index){
    i++;
  }
//while i is equal to index, place the present value in bucketOne and place input pitch at index
  while (i == index){
    bucketOne = pitches[i];
    pitches[i] = pitch;
    i++;
  }
//push every value forward by one index
  while (i <= arrSize){
    bucketTwo = pitches[i];
    pitches[i] = bucketOne;
    bucketOne = bucketTwo;
    i++;
  }

//print results
  printf("The new pitches are:\n   ");

  for(int i = 0; i <= arrSize; i++){
    printf("%d ", pitches[i]);
  }

  printf("\n");
//end of program
  return 0;
}
