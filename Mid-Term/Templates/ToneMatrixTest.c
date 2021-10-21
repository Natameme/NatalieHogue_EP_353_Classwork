#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
void shuffle(int *array, size_t n);
unsigned int randomInt(int min, int max);
void saveMatrix(int *matrix, int rowSize);

// Functions to implement
void initFirstRow(int *matrix, int rowSize);
void generateMatrix(int *matrix, int rowSize);

int main(){

  // Ask the user to enter the size of tone row
  int rowSize;
  system("clear");
  printf("Enter Desired Size of Tone Tow: ");
  scanf("%i", &rowSize);

  // Allocate the memory space for the matrix using rowSize
  int *matrix;
  matrix = malloc(sizeof(int) * pow(rowSize, 2));

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

  // TODO: Free the memory space allocated
  free(matrix);
  return 0;
}

void initFirstRow(int *matrix, int rowSize)
{
  // Intialize the first row in the matrix
  // You can either randomly do so using the shuffle function
  // or ask the user to enter each tone up to rowSize
  system("clear");
  printf("Enter Values between 0 - %i: \n", rowSize);
  //variables
  int i = 0;
  int usrIn;
  // loop prompts user to enter values
  while(i < rowSize){
    int j = (i + 1);//i + 1 for use with printf below
    printf("enter value # %i : ", j);
    scanf("%i", &usrIn);//take user input

    /*
    loop checks to see if value is between upper and lower bounds
    as well as if a value is already present in the list,
    making sure each value only occurs once
    */
    for(int k = 0; k < i; k++){
      //conditional logic
        if(usrIn == matrix[k]){
          printf("That note has already been used please enter another \n");
          printf("enter value # %i : ", j);
          scanf("%i", &usrIn);
        } else if (usrIn >= rowSize || usrIn < 0 ){ //tests if value is within bounds
          printf("That note is outside the specified bounds, please enter another \n");
          printf("enter value # %i : ", j);
          scanf("%i", &usrIn);
        } else {/*do nothing*/}
    }//end of k loop
    matrix[i] = usrIn;
    i++;
  }//end of i loop
}//end of initFirstRow function

void generateMatrix(int *matrix, int rowSize){
  // Keep a reference to the root tone (First tone in P0)
  int tonic = matrix[0];
  // TODO: Fix the pitch class to make the first tone start from 0

  //Get the inversion of P0 and populate I0
  for (int i = 1; i < rowSize; i++)
  {
  	  matrix[i * rowSize] = abs(matrix[i]-12);
  }
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
        printf("%i, ", array[i]);
      }
  }
}
