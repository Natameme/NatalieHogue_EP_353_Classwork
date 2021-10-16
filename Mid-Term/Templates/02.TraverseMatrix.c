#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum Mode {
  prime = 1, invert, retrograde, retrogradeInvert
} Mode;

unsigned int randomInt(int min, int max);
int getRowSize();
void readMatrix(int *matrix, int rowSize);
void append2File(int value);

// Functions to implement
void randomWalk(int *value, int maxStep, int size);
int getPrime(int *matrix, int rowSize, int row, int column);
int getInvert(int *matrix, int rowSize, int row, int column);
int getRetrograde(int *matrix, int rowSize, int row, int column);
int getRetrogradeInvert(int *matrix, int rowSize, int row, int column);

int main(){

  // Remove the series.txt file if it exist
  system("rm -f series.txt");

  int *matrix = NULL, rowSize = 0;

  rowSize = getRowSize(); // Get the row size from the matrix.txt file.

  if(rowSize == 0){ // Check if the row size is not 0.
    printf("the matrix.txt file does not exist or nothing is in the file...\n");
    return 1;
  }

  // TODO: allocate the memory space to hold all values in the matrix

  if(matrix == NULL){ // Check if matrix is not a null pointer
    printf("Matrix is empty...\n");
    return 1;
  }  

  // Read values from the matrix.txt file and assign them to the matrix
  readMatrix(matrix, rowSize);

  printf("Let's create a series of numbers based on your tone matrix.\n");
  // TODO: Interactively ask the user to generate tone series
  // Make sure to use all the functions you are supposed to implement

  // TODO: Free the memory space 

  return 0;
}

void randomWalk(int *value, int maxStep, int size){

}

int getPrime(int *matrix, int rowSize, int row, int column){
  return -1;
}

int getInvert(int *matrix, int rowSize, int row, int column){
  return -1;
}

int getRetrograde(int *matrix, int rowSize, int row, int column){
  return -1;
}

int getRetrogradeInvert(int *matrix, int rowSize, int row, int column){
  return -1;
}

//-------------------- Utility Functions --------------------
void append2File(int value){
  FILE *file;
  file = fopen("series.txt", "a");
  fprintf(file, "%d ", value);
  fclose(file);
}

int getRowSize(){
  FILE *file;
  file = fopen("matrix.txt", "r");

  if(file == NULL){
    printf("matrix.txt could not be opened...\n");
    return 0;
  }

  int value, count = 0;
  while(fscanf(file, "%d", &value) != EOF) count++;

  fclose(file);

  return sqrt(count);
}

void readMatrix(int *matrix, int rowSize){
  FILE *file;
  file = fopen("matrix.txt", "r");

  if(file == NULL){
    printf("matrix.txt could not be opened...\n");
    return;
  }

  for (int i = 0; i < rowSize * rowSize; i++) {
    fscanf(file, "%d", &matrix[i]);
  }

  fclose(file);
}

unsigned int randomInt(int min, int max){
  unsigned int randval;
  FILE *f;

  f = fopen("/dev/random", "r");
  fread(&randval, sizeof(randval), 1, f);
  fclose(f);

  return (randval % (max - min)) + min;
}