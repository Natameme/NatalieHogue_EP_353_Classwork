#include <stdio.h>

//MAIN PROGRAM
int main(){

/*
 CHARACTER ARRAY USED,
 BUT CREATING BUG IN WHICH
 THE 2ND DIGIT OF A 2 DIGIT
 INTEGER IS NOT READ,
 FOR INSTANCE:
 IN ORDER TO CORRECTLY DISPLAY MIDDLE C (MIDI NOTE 69)
 USER HAS TO INPUT E, WHICH IS ASCII DEC CODE 69. IF 69 IS ENTERED,
 ONLY THE 6 IS READ, AND DISPLAYED AS ASCII CODE 54
 Problem4.3.2.c SOLVES THIS PROBLEM BY USING AN INTEGER ARRAY
*/

//VARIABLES
char pitches[8] = {74, 68, 54, 28, 89, 51, 35};
char pitch;
char bucketOne;
char bucketTwo;
int arrSize = sizeof(pitches)/ sizeof(char) - 1;
int index;
//input pitch value
  printf("Enter a new MIDI Pitch Value (integer between 0-127): ");
  scanf(" %s", &pitch);
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

/*DEPRECATED CODE

//calling broader scope of i for use in both loops
int static i ;
//Reindexing Loop
  for(int i = 0; i <= index; i++){
    if (i == index){
      bucketOne = pitches[i];
      pitches[i] = pitch;
    } else {
      //do nothing
    }
  }
  //index each previous value forward
  while(i <= arrSize){
    bucketTwo = pitches[(i+1)];
    pitches[(i+1)] = bucketOne;
    bucketOne = bucketTwo;
    i++;
  }


}
*/
