#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//compile with " clang 02.TraverseMatrix.c -o TraverseMatrix "

typedef enum Mode {
  prime = 1, invert, retrograde, retrogradeInvert
} Mode;

unsigned int randomInt(int min, int max);
int getRowSize();
void readMatrix(int *matrix, int rowSize);
void append2File(int value);

// Functions prototypes
void randomWalk(int *value, int maxStep, int size);
int getPrime(int *matrix, int rowSize, int row, int column);
int getInvert(int *matrix, int rowSize, int row, int column);
int getRetrograde(int *matrix, int rowSize, int row, int column);
int getRetrogradeInvert(int *matrix, int rowSize, int row, int column);

/////////////////////
////MAIN FUNCTION////
/////////////////////

int main(){

  // Remove the series.txt file if it exist
  system("rm -f series.txt");

  int *matrix = NULL, rowSize = 0;

  rowSize = getRowSize(); // Get the row size from the matrix.txt file.

  // Check if the row size is not 0.
  if(rowSize == 0){
    printf("the matrix.txt file does not exist or nothing is in the file...\n");
    return 1;
  }

  // allocate the memory space to hold all values in the matrix
  matrix = malloc(sizeof(int) * pow(rowSize, 2));

  // Check if matrix is not a null pointer
  if(matrix == NULL){
    printf("Matrix is empty...\n");
    return 1;
  }

  // Read values from the matrix.txt file and assign them to the matrix
  readMatrix(matrix, rowSize);
  printf("Let's create a series of numbers based on your tone matrix.\n");

  // Interactively ask the user to generate tone series
  // Make sure to use all the functions you are supposed to implement
  int usrIn;//user input
  int i = 0;//for indexing while loop

  //User prompt
      printf("Choose Transformation Mode: \n1: Prime \n2: Inversion \n3: Retrograde \n4: Retrograde Inversion\n> ");
      scanf("%i", &usrIn);

    //tests value
      while(i < 1){
        if(usrIn < 1){
          printf("Program Exited: invalid input");
          return 1;
        } else if(usrIn > 4){
          printf("Program Exited: invalid input");
          scanf("%i", &usrIn);
        } else {
          i++;// exit loop
        }
      }

  //variables
  int hi = rowSize - 1;//prompts user with upper bounds of playable rows
  int rowIn; //takes input for selected row
  int colIn; //takes input for selected column
  int k = 0; //indexing for while loop

  /////////////////////////////
  ////TRANSFORMATION SWITCH////
  /////////////////////////////

  //value pointer for use with randomWalk;
  int *value = malloc(sizeof(int));

  switch(usrIn){
    case 1:
          //Prime
          printf("Choose a row between 0 - %i to play: ", hi);
          scanf("%i", &rowIn);

        while(k<1){

            if (rowIn > rowSize){
              printf("Value Outside Bounds, Please choose another:");
            scanf("%i", &rowIn);

          } else if (rowIn == 0){
              printf("0 is an invalid character, program exited with code 1");
              return 1;

          } else if (rowIn < 0){
            int maxStep = abs(rowIn);
              randomWalk(value, maxStep, rowSize);
              rowIn = *value;
              getPrime(matrix, rowSize, rowIn, colIn);
              k++; //exit loop

          } else {
            getPrime(matrix, rowSize, rowIn, colIn);
            k++; //exit loop
          }
        }
        break;
    case 2:
          //Inversion
          printf("Choose a column between 0 - %i to play: ", hi);
          scanf("%i", &colIn);

        while(k<1){

          if (rowIn > rowSize){
            printf("Value Outside Bounds, Please choose another:");
          scanf("%i", &colIn);

        } else if (colIn == 0){
            printf("0 is an invalid character, program exited with code 1");
            return 1;

        } else if (colIn < 0){
          int maxStep = abs(colIn);
            randomWalk(value, maxStep, rowSize);
            colIn = *value;
            getInvert(matrix, rowSize, rowIn, colIn);
            k++;//exit loop

        } else {
          getInvert(matrix, rowSize, rowIn, colIn);
          k++;//exit loop
        }
      }
        break;
    case 3:
          //Retrograde
          printf("Choose a row between 0 - %i to play: ", hi);
          scanf("%i", &rowIn);

        while(k<1){

            if (rowIn > rowSize){
              printf("Value Outside Bounds, Please choose another:");
              scanf("%i", &rowIn);

          } else if (rowIn == 0){
              printf("0 is an invalid character, program exited with code 1");
              return 1;

          } else if (rowIn < 0){
              int maxStep = abs(rowIn);
              randomWalk(value, maxStep, rowSize);
              rowIn = *value;
              getRetrograde(matrix, rowSize, rowIn, colIn);
              k++;//exit loop

          } else {
              getRetrograde(matrix, rowSize, rowIn, colIn);
              k++;//exit loop
          }
        }
        break;
    case 4:
          //Retrograde Inversion//
          printf("Choose a column between 0 - %i to play: ", hi);
          scanf("%i", &colIn);

        while(k<1){

          if (colIn > rowSize){
            printf("Value Outside Bounds, Please choose another:");
            scanf("%i", &colIn);

        } else if (colIn == 0){
            printf("0 is an invalid character, program exited with code 1");
            return 1;

        } else if (colIn < 0){
            int maxStep = abs(colIn);
            randomWalk(value, maxStep, rowSize);
            colIn = *value;
            getRetrogradeInvert(matrix, rowSize, rowIn, colIn);
            k++;//exit loop

        } else {
          getRetrogradeInvert(matrix, rowSize, rowIn, colIn);
          k++;//exit loop
        }
      }
        break;
      }//end of switch

  // Free the memory space
  free(matrix);

  system("./MappingToneMatrix");
  return 0;

}//end of main()

void randomWalk(int *value, int maxStep, int size){
  //assigns a random integer to value pointer
  *value = randomInt(0, maxStep);
} // end of randomWalk()

int getPrime(int *matrix, int rowSize, int row, int column){

  //two variables for indexing matrix
  int rowPlay = row * rowSize;
  int colPlay = 0;
  int value; //stores value to write into append2File();

  //loop prints out each
  for(colPlay = 0; colPlay < rowSize; colPlay++){
    value = matrix[rowPlay+colPlay];
    append2File(value);
  }
  return -1;
} //end of getPrime

int getInvert(int *matrix, int rowSize, int row, int column){

  //two variables for indexing matrix
  int rowPlay;
  int value; //stores value to write into append2File();

  //loop prints out each
  for(rowPlay = 0; rowPlay < rowSize; rowPlay++){
    //initialize colPlay variable
    int colPlay = ((rowPlay * rowSize) + column);
    value = matrix[colPlay];
    append2File(value);
  }
  return -1;
} //end of getInvert

int getRetrograde(int *matrix, int rowSize, int row, int column){

  //two variables for indexing matrix
  int hi = rowSize-1;
  int rowPlay = row * rowSize;
  int colPlay = 0;
  int value; //stores value to write into append2File();

  //loop prints out each
  for(colPlay = hi; colPlay >= 0; colPlay--){
    value = matrix[rowPlay+colPlay];
    append2File(value);
  }
  return -1;
} // end of getRetrograde

int getRetrogradeInvert(int *matrix, int rowSize, int row, int column){

  //two variables for indexing matrix
  int hi = rowSize - 1;
  int rowPlay;
  int value; //stores value to write into append2File();

  //loop prints out each
  for(rowPlay = hi; rowPlay >= 0; rowPlay--){
    //initialize colPlay variable
    int colPlay = ((rowPlay * rowSize) + column);
    value = matrix[colPlay];
    append2File(value);
  }
  return -1;
}//end of getRetrogradeInvert()

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
