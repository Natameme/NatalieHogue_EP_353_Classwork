#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
void shuffle(int *array, size_t n);
unsigned int randomInt(int min, int max);
void saveMatrix(int *matrix, int rowSize);

int inArray(int *matrix, int ursIn, int rowSize); //makes sure that each value in initFirstRow is only used once

// Functions to implement
void initFirstRow(int *matrix, int rowSize);
void generateMatrix(int *matrix, int rowSize);


int main(){

  // Ask the user to enter the size of tone row
  int rowSize = 0;
  printf("Enter Size of Tone Row: ");
  scanf("%i", &rowSize);

  // Allocate the memory space for the matrix using rowSize
  int toneArr[rowSize][rowSize];
  int *matrix = toneArr;


  if(matrix == NULL){
    printf("Memory allocation failed...\n");
    return 1;
  }

  // Initialize the first row (P0) in the matrix
  initFirstRow(matrix, rowSize);

  // Generate the rest of the matrix based on the first row
  generateMatrix(matrix, rowSize);

  // Save the matrix to the text file
  saveMatrix(matrix, rowSize);

  // Free the memory space allocated
  free(matrix);
  return 0;
}

void initFirstRow(int *matrix, int rowSize){
  // TODO: Intialize the first row in the matrix
  // You can either randomly do so using the shuffle function
  // or ask the user to enter each tone up to rowSize
  printf("Initialize the tone matrix with values 0 - %i, using each note only once: ", rowSize);

  int i = 0;
  int usrIn;
  while(i <= rowSize){
    //take user input
    scanf("%i", &usrIn);
    //test if value is already in array
      switch(inArray(matrix, usrIn, rowSize)){
        case 1:
          printf("That Value is already in use, please choose another. \n");
          break;
        case 0:
          //do nothing
          break;
      }
    i++;
  }
}

void generateMatrix(int *matrix, int rowSize){
  // TODO; Keep a reference to the root tone (First tone in P0)

  // TODO: Fix the pitch class to make the first tone start from 0

  // TODO: Get the inversion of P0 and populate I0

  // TODO: Fill out the rest of transposition

  // TODO: Add back the root tone to the matrix
}

//-------------------- Utility Functions --------------------
void saveMatrix(int *matrix, int rowSize){
  FILE *file; // Keep a reference to a text file
  file = fopen("matrix.txt", "w"); // open a text file in the write mode

  if(file == NULL){ // Check if the file opened
    printf("matrix.txt file could not be opened...\n");
    return;
  }

  // Go through the matrix and write the values in the text file
  for(int r = 0; r < rowSize; r++){
    for(int c = 0; c < rowSize; c++){
      fprintf(file, "%d ", matrix[r * rowSize + c]);
    }
    fprintf(file, "\n");
  }

  fclose(file); // Close the text file
}

unsigned int randomInt(int min, int max){
  unsigned int randval;
  FILE *f;

  f = fopen("/dev/random", "r");
  fread(&randval, sizeof(randval), 1, f);
  fclose(f);

  return (randval % (max - min)) + min;
}

void shuffle(int *array, size_t n)
{
  if (n > 1)
  {
      size_t i;
      for (i = 0; i < n - 1; i++)
      {
        size_t j = i + randomInt(0, UINT_MAX) / (UINT_MAX / (n - i) + 1);
        int t = array[j];
        array[j] = array[i];
        array[i] = t;
      }
  }
}

int inArray(int *matrix, int usrIn, int rowSize){

  for(int i = 0; i <= rowSize; i++){
    if (*matrix[i][0] == usrIn){
      return 1; //enter a different value
    } else{
      return 0; //everything's fine, move forward
    }
  }
}
